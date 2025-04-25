#ifndef GAME_SIMULATION_HPP
#define GAME_SIMULATION_HPP

#include <cassert>
#include <cstdio>
#include "utils/math.hpp"
#include "Component.hpp"
#include "CharacterData.hpp"
#include "ActionStates/StateMachine.hpp"
#include "ActionStates/CommonStates.hpp"
#include "Input.hpp"

namespace GameSimulation{

    struct InputComponent {
        Input::InputCommand inputCommand {};
    };

    struct StateMachineComponent {
        StateMachine::CombatStateContext context {};
        StateMachine::CombatStateMachineProcessor stateMachine {};
    };

    // For now our only test state is a global constant. Need to move this to somewhere where
    // character specific data is stored
    CommonStates::Standing StandingCallbacks {};
    CommonStates::WalkingForward WalkingForwardCallbacks {};

    struct GameData {
        CharacterData::HitboxGroup HitboxGroup; // TODO: Temp data, remove later
        std::vector<CharacterData::CharacterProperties> Characters;
        // Here should go a custom allocator for HitboxGroup

        // CharacterData::CharacterProperties CharacterProperties[10];

        GameData InitializeGameData() {
            GameData gameData { {}, {} }; // Here all the GameData members should be initialized with a custom allocator
            // Use std::vector.reserve(x) function here in case more than one hitbox
            // needs to be put inside gameData.HitboxGroup.Hitboxes
            // gameData.HitboxGroup.Hitboxes.push_back(CharacterData::Hitbox { 200, 300, 0, 600 });

            // assert(!gameData.HitboxGroup.Hitboxes.empty() && "The \"Hitboxes\" std::vector of gameData failed to initialize.\n");

            return gameData;
        }

        // void InitializeGameData() {
        //     HitboxGroup.Hitboxes.push_back(CharacterData::Hitbox { 200, -300, 0, 300 });
        // }
    };

    struct GameState {
        int32_t frameCount { 0 };
        int32_t entityCount { 1 };

        Component::PhysicsComponent physicsComponents[10] {};
        StateMachineComponent stateMachineComponents[10] {};
        InputComponent inputComponents[2] {};

        // A custom allocator for GameData should go in here
        GameData gameData {};

        void Init() {
            // Game data initialization
            gameData = gameData.InitializeGameData();

            stateMachineComponents[0].context.PhysicsComponent = &physicsComponents[0];
            stateMachineComponents[0].stateMachine.Context = &stateMachineComponents[0].context;
            stateMachineComponents[0].stateMachine.Registery.RegisterCommonState(StateMachine::CombatStateID::Standing, &StandingCallbacks);
            stateMachineComponents[0].stateMachine.Registery.RegisterCommonState(StateMachine::CombatStateID::WalkingForward, &WalkingForwardCallbacks);
        }

        // Handles moving all entities which have a physics component
        void PhysicsSystem() {
            std::size_t entityIndex { 0 };

            while (entityIndex < entityCount) {
                Component::PhysicsComponent* component { &physicsComponents[entityIndex] };

                // Move position based on the current velocity
                component->position = component->position.Add(component->velocity);
                component->velocity = component->velocity.Add(component->acceleration);

                entityIndex += 1;
            }
        }

        void ActionSystem() {
            std::size_t entityIndex { 0 };

            while (entityIndex < entityCount) {
                StateMachineComponent* component { &stateMachineComponents[entityIndex] };

                component->stateMachine.UpdateStateMachine();

                entityIndex += 1;
            }
        }

        void InputCommandSystem() {
            stateMachineComponents[0].context.InputCommand = inputComponents[0].inputCommand;
        }

        void UpdateGame() {
            InputCommandSystem();
            ActionSystem();
            PhysicsSystem();
            frameCount += 1;
        }
    };
}


#endif // GAME_SIMULATION_HPP
