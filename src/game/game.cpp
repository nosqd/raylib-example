//
// Created by nosquad on 12/29/2023.
//
#include <game/game.h>

Vector2 Game_GetWindowSize() {
    return {1366, 768};
}

char* Game_GetTitle() {
    return "Game";
}

int Game_GetTickrate() {
    return 128;
}

void Game_PreInit() {

}

void Game_PostInit() {

}

void Game_Update(std::queue<int>* key_queue, bool* debug_menu) {
    for (; !key_queue->empty(); key_queue->pop()) {
        int key = key_queue->front();
        if (key == 0) continue;
        if (key == KEY_F9) {
            *(debug_menu) = !(*debug_menu);
        }
    }
}

void Game_Draw() {
    ClearBackground(RAYWHITE);

    DrawFPS(5,5);
}

void Game_DrawDebug() {
    ImGui::Begin("Game Tests");
        ImGui::Text("FPS: %d", GetFPS());
    ImGui::End();
}

void Game_Exit() {
}
