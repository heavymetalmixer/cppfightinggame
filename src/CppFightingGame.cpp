

#include "utils/math.hpp"
#include "GameSimulation.hpp"

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int32_t screenWidth = 800;
    const int32_t screenHeight = 450;

    // rl.initWindow(screenWidth, screenHeight, "raylib-zig [core] example - basic window");
    // defer rl.closeWindow(); // Close window and OpenGL context

    // rl.setTargetFPS(60); // Set our game to run at 60 frames-per-second
    // //--------------------------------------------------------------------------------------

    // // Our game state
    // GameSimulation::Gamestate gameState {};

    // gameState.Init();

    // // Initialize our game object
    // gameState.physicsComponents[0].position = { 400, 200 };

    // // Main game loop
    // while (!rl.windowShouldClose()) { // Detect window close button or ESC key
    //     // var PressingUp: bool = false;
    //     // var PressingDown: bool = false;
    //     // var PressingLeft: bool = false;
    //     // var PressingRight: bool = false;

    //     // Reset input to not held down before polling
    //     gameState.inputComponents[0].inputCommand.Reset();

    //     if (rl.isWindowFocused() and rl.isGamepadAvailable(0)) {
    //         if (rl.isGamepadButtonDown(0, rl.GamepadButton.left_face_up)) {
    //             gameState.inputComponents[0].inputCommand.Up = true;
    //         }

    //         if (rl.isGamepadButtonDown(0, rl.GamepadButton.left_face_down)) {
    //             gameState.inputComponents[0].inputCommand.Down = true;
    //         }

    //         if (rl.isGamepadButtonDown(0, rl.GamepadButton.left_face_left)) {
    //             // PressingLeft = true;

    //             gameState.inputComponents[0].inputCommand.Left = true;
    //         }

    //         if (rl.isGamepadButtonDown(0, rl.GamepadButton.left_face_right)) {
    //             // PressingRight = true;

    //             gameState.inputComponents[0].inputCommand.Right = true;
    //         }
    //     }

    //     // Game simulation
    //     {
    //         // Update position of object based on player's input
    //         {
    //             GameSimulation::PhysicsComponent* entity = &gameState.physicsComponents[0];

    //             if (gameState.inputComponents[0].inputCommand.Up) {
    //                 entity->velocity.y = -1;
    //             } else if (gameState.inputComponents[0].inputCommand.Down) {
    //                 entity->velocity.y = 1;
    //             } else if (gameState.inputComponents[0].inputCommand.Left) {
    //                 entity->velocity.x = -1;
    //             } else if (gameState.inputComponents[0].inputCommand.Right) {
    //                 entity->velocity.x = 1;
    //             } else {
    //                 entity->velocity.y = 0;
    //                 entity->velocity.x = 0;
    //             }
    //         }

    //         gameState.UpdateGame();
    //     }

    //     // Draw
    //     //----------------------------------------------------------------------------------
    //     rl.beginDrawing();
    //     defer rl.endDrawing();

    //     rl.clearBackground(rl.Color.white);

    //     // rl.drawText("Congrats! You created your first window!", 190, 200, 20, rl.Color.brown);

    //     // Reflect the position of out game object on screen
    //     rl.drawCircle(gameState.physicsComponents[0].position.x, gameState.physicsComponents[0].position.y, 50, rl.Color.maroon);
    //     //----------------------------------------------------------------------------------
    // }
}
