//
// Created by nosquad on 12/29/2023.
//

#ifndef BASE_RAYLIB_GAME_PROJECT_GAME_H
#define BASE_RAYLIB_GAME_PROJECT_GAME_H
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include <cstdio>
#include <queue>

Vector2 Game_GetWindowSize();
char* Game_GetTitle();
int Game_GetTickrate();
void Game_PreInit();
void Game_PostInit();
void Game_Update(std::queue<int>* key_queue, bool* debug_menu);
void Game_Draw();
void Game_DrawDebug();
void Game_Exit();

#endif //BASE_RAYLIB_GAME_PROJECT_GAME_H
