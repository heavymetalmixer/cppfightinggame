#include "Game.hpp"

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    constexpr int32_t screenWidth = 800;
    constexpr int32_t screenHeight = 450;

    // InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // while (!WindowShouldClose())
    // {
    //     BeginDrawing();
    //         ClearBackground(RAYWHITE);
    //         DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    //     EndDrawing();
    // }

    // CloseWindow();

    // return 0;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Run the game
    Game::GameLoop();

    CloseWindow();

    return 0;
}
