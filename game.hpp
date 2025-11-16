#pragma once
#include "include/raylib.h"
#include <string>

class Game {
    public:
    int windowWidth;
    int windowHeight;

    int canvasWidth;
    int canvasHeight;

    float scale;
    RenderTexture2D canvas;

    int font_size;
    Font font;

    std::string title;

    Game();
    void Initialize();
    void Update();
    void Draw();
    void HandleInput();
    ~Game();
};
