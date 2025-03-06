#ifndef GAME_SIMULATION_HPP
#define GAME_SIMULATION_HPP

#include "utils/math.hpp"
#include "ActionStates/StateMachine.hpp"
#include "ActionStates/CommonStates.hpp"
#include "Input.hpp"

namespace GameSimulation{
    struct PhysicsComponent {
        math::IntVector2D position {};
        math::IntVector2D velocity {};
        math::IntVector2D acceleration {};
    };

    struct InputComponent {
        Input::InputCommand inputCommand {};
    };

    template <typename T>
    struct StateMachineComponent {
        StateMachine::CombatStateContext context {};
        StateMachine::CombatStateMachineProcessor<T> stateMachine {};
    };

    // For now our only test state is a global constant. Need to move this to somewhere where
    // character specific data is stored
    // void (*OnStart)(CombatStateContext*) { nullptr };

    StateMachine::CombatStateCallbacks<CommonStates::Standing> StandingCallbacks {
        &CommonStates::Standing::OnStart,
        &CommonStates::Standing::OnUpdate,
        &CommonStates::Standing::OnEnd,
    };

    template <typename T>
    struct Gamestate {
        int32_t frameCount { 0 };
        int32_t entityCount { 5 };
        PhysicsComponent physicsComponents[10] {};
        StateMachineComponent<T> stateMachineComponents[10] {};
        InputComponent inputComponents[2] {};

        void Init() {
            stateMachineComponents[0].stateMachine.Context = &stateMachineComponents[0].context;
            stateMachineComponents[0].stateMachine.Registery.RegisterCommonState(StateMachine::CombatStateID::Standing, &StandingCallbacks);
        }

        // Handles moving all entities which have a physics component
        void PhysicsSystem() {
            std::size_t entityIndex { 0 };

            while (entityIndex < entityCount) {
                PhysicsComponent* component { &physicsComponents[entityIndex] };

                // Move position based on the current velocity
                component->position = component->position.Add(component->velocity);
                component->velocity = component->velocity.Add(component->acceleration);

                entityIndex += 1;
            }
        }

        void ActionSystem() {
            std::size_t entityIndex { 0 };

            while (entityIndex < entityCount) {
                StateMachineComponent<T>* component { &stateMachineComponents[entityIndex] };

                component->stateMachine.UpdateStateMachine();

                entityIndex += 1;
            }
        }

        void UpdateGame() {
            ActionSystem();
            PhysicsSystem();
            frameCount += 1;
        }
    };
}


#endif // GAME_SIMULATION_HPP
