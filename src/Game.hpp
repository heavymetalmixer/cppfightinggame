#ifndef GAME_HPP
#define GAME_HPP

#include <cassert>
#include "raylib.h"
#include "utils/math.hpp"
#include "GameSimulation.hpp"

namespace Game {
    void GameLoop() {
        // The arena allocator should go here, or in the same like as gameState

        // Our game state
        GameSimulation::GameState gameState {};

        gameState.Init();

        // Initialize our game object
        gameState.physicsComponents[0].position = { 400000, 200000 };

        // Main game loop
        while (!WindowShouldClose()) { // Detect window close button or ESC key

            // Reset input to not held down before polling
            gameState.inputComponents[0].inputCommand.Reset();

            if (IsWindowFocused() && IsGamepadAvailable(0)) {
                if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) {
                    gameState.inputComponents[0].inputCommand.Up = true;
                }

                if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
                    gameState.inputComponents[0].inputCommand.Down = true;
                }

                if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
                    // PressingLeft = true;

                    gameState.inputComponents[0].inputCommand.Left = true;
                }

                if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
                    // PressingRight = true;

                    gameState.inputComponents[0].inputCommand.Right = true;
                }
            }

            // Game simulation
            {
                gameState.UpdateGame();
            }

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            ClearBackground(WHITE);

            const int32_t ScreenX { math::WolrdToScreen(gameState.physicsComponents[0].position.x) };
            const int32_t ScreenY { math::WolrdToScreen(gameState.physicsComponents[0].position.y) };

            // Reflect the position of out game object on screen
            DrawCircle(ScreenX, ScreenY, 50, MAROON);

            if (!gameState.gameData.HitboxGroup.Hitboxes.empty()) {
                CharacterData::Hitbox hitbox { gameState.gameData.HitboxGroup.Hitboxes[0] };
                DrawRectangleLines(hitbox.left,
                                hitbox.top,
                                hitbox.right - hitbox.left,
                                hitbox.top - hitbox.bottom,
                                RED
                );
            }

            EndDrawing();
            //----------------------------------------------------------------------------------
        }
    }
}

#endif // GAME_HPP
