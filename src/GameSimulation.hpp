#ifndef GAME_SIMULATION_HPP
#define GAME_SIMULATION_HPP

#include "utils/math.hpp"
#include "Component.hpp"
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

    struct Gamestate {
        int32_t frameCount { 0 };
        int32_t entityCount { 5 };
        Component::PhysicsComponent physicsComponents[10] {};
        StateMachineComponent stateMachineComponents[10] {};
        InputComponent inputComponents[2] {};

        void Init() {
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
