#include "raylib.h"

#if defined(PLATFORM_WEB)
    #define CUSTOM_MODAL_DIALOGS
    #include <emscripten/emscripten.h>
#endif
#include "resources/player.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { 
    SCREEN_LOGO = 0, 
    SCREEN_TITLE, 
    SCREEN_GAMEPLAY, 
    SCREEN_ENDING
} GameScreen;

static const int screenWidth = 800;
static const int screenHeight = 450;

static RenderTexture2D target = { 0 };
Player player(Vector2{0.0});
static void UpdateDrawFrame(void);

int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE);
#endif

    InitWindow(screenWidth, screenHeight, "Lospace");
    
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif

    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}

void UpdateDrawFrame(void)
{
    BeginDrawing();
    ClearBackground(WHITE);
    player.Update();
    EndDrawing();
}
