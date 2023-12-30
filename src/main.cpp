#include <raylib.h>
#include <game/game.h>
#include <imgui/styles.h>

static double tickTimer;
static std::queue<int> keyQueue = std::queue<int>();
static bool debugMenu = false;
static Vector2 windowSize = Game_GetWindowSize();
static RenderTexture gameTexture;// = LoadRenderTexture((int)windowSize.x, (int)windowSize.y);
static RenderTexture debugTexture;// = LoadRenderTexture((int)windowSize.x/1.5, (int)windowSize.y/1.5);

int main() {
    Game_PreInit();
    SetWindowState(FLAG_MSAA_4X_HINT);
    InitWindow((int) windowSize.x, (int) windowSize.y, Game_GetTitle());
    rlImGuiSetup(true);

    gameTexture = LoadRenderTexture((int) windowSize.x, (int) windowSize.y);
    debugTexture = LoadRenderTexture((int) windowSize.x / 1.5, (int) windowSize.y / 1.5);
    Rectangle source = {0, -windowSize.y / 1.5f, windowSize.x / 1.5f,
                        -windowSize.y / 1.5f}; // - Because OpenGL coordinates are inverted
    Rectangle dest = {0, 0, (float) windowSize.x, (float) windowSize.y};

    Game_PostInit();
    embraceTheDarkness(); // imgui theme

    while (!WindowShouldClose()) {
        if (GetTime() - tickTimer > 1000 / Game_GetTickrate() / 1000) {
            tickTimer = GetTime();
            Game_Update(&keyQueue, &debugMenu);
        }

        keyQueue.push(GetKeyPressed());
        BeginTextureMode(gameTexture);
        ClearBackground(BLACK);
        Game_Draw();
        EndTextureMode();
        BeginDrawing();
        rlImGuiBegin();
        ClearBackground(BLACK);


        if (debugMenu) {
            BeginTextureMode(debugTexture);
            DrawTexturePro(gameTexture.texture, source, dest, {0, 0}, 0.f, RAYWHITE);
            EndTextureMode();

            Game_DrawDebug();

            ImGui::Begin("Game", &debugMenu, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
            rlImGuiImageRenderTexture(&debugTexture);
            ImGui::End();

        } else {
            DrawTexturePro(gameTexture.texture,
                           source, dest,
                           {0, 0}, 0.f, WHITE);
        }
        rlImGuiEnd();
        EndDrawing();

    }

    Game_Exit();
    return 0;
}
