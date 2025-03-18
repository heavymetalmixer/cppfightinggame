#ifndef COMMON_STATES_HPP
#define COMMON_STATES_HPP

#include "StateMachine.hpp"
#include <stdio.h>

namespace CommonStates {
    struct Standing : StateMachine::CombatStateCallbacks {
        void OnStart(StateMachine::CombatStateContext* context) override {
            printf("Standing.OnStart()\n");
        }

        void OnUpdate(StateMachine::CombatStateContext* context) override {
            // Stop character movement on standing
            if (context->PhysicsComponent) {
                StateMachine::CombatStateContext physicsComponent {};
                physicsComponent.PhysicsComponent = context->PhysicsComponent;

                physicsComponent.PhysicsComponent->velocity.x = 0;
            }

            if (context->InputCommand.Right) {
                context->bTransition = true;
                context->NextState = StateMachine::CombatStateID::WalkingForward;
            }
        }

        void OnEnd(StateMachine::CombatStateContext* context) override {
            printf("Standing.OnEnd()\n");
        }
    };

    struct WalkingForward : StateMachine::CombatStateCallbacks {
        void OnStart(StateMachine::CombatStateContext* context) override {
            printf("WalkingForward.OnStart()\n");
        }

        void OnUpdate(StateMachine::CombatStateContext* context) override {
            // Move the character right when the player presses right on the controller
            if (context->PhysicsComponent) {
                StateMachine::CombatStateContext physicsComponent {};
                physicsComponent.PhysicsComponent = context->PhysicsComponent;

                physicsComponent.PhysicsComponent->velocity.x = 2000;
            }

            if (context->InputCommand.Right) {
                context->bTransition = true;
                context->NextState = StateMachine::CombatStateID::Standing;
            }
        }

        void OnEnd(StateMachine::CombatStateContext* context) override {
            printf("WalkingForward.OnEnd()\n");
        }
    };

    struct Crouching : StateMachine::CombatStateCallbacks {
        void OnStart(StateMachine::CombatStateContext* context) override {
            printf("Crouching.OnStart()\n");
        }

        void OnUpdate(StateMachine::CombatStateContext* context) override {
            printf("Crouching.OnUpdate()\n");
        }

        void OnEnd(StateMachine::CombatStateContext* context) override {
            printf("Crouching.OnEnd()\n");
        }
    };
}

#endif // COMMON_STATES_HPP
