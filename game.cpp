#include "game.hpp"
#include <algorithm>
#include "include/raymath.h"

Game::Game() {
    /* Initialize raylib*/

    windowWidth = 1280;
    windowHeight = 720;

    // Enable config flags for resizable window and vertical synchro
    //SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    title = "rayPong";
    InitWindow(windowWidth, windowHeight, title.c_str());
    SetWindowMinSize(canvasWidth, canvasHeight);
    // Render texture initialization, used to hold the rendering result so we can easily resize it
    canvas = LoadRenderTexture(canvasWidth, canvasHeight);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT);  // Texture scale filter to use
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    scale = std::min((float)GetScreenWidth()/canvasWidth, (float)GetScreenHeight()/canvasHeight);

}

void Game::Initialize() {


}

void Game::Update() {

}

void Game::Draw() {
    BeginTextureMode(canvas);
        ClearBackground(BLACK);  // Clear render texture background color
        // draw stuff

    EndTextureMode();

    BeginDrawing();
        ClearBackground(RAYWHITE);     // Clear screen background

        // Draw render texture to screen, properly scaled
        DrawTexturePro(canvas.texture, (Rectangle){ 0.0f, 0.0f, (float)canvas.texture.width, (float)-canvas.texture.height },
                        (Rectangle){ (GetScreenWidth() - ((float)canvasWidth*scale))*0.5f, (GetScreenHeight() - ((float)canvasHeight*scale))*0.5f,
                        (float)canvasWidth*scale, (float)canvasHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
    EndDrawing();


}

void Game::HandleInput() {

}


Game::~Game() {
    UnloadFont(font);
    UnloadRenderTexture(canvas);
    CloseWindow();
}
