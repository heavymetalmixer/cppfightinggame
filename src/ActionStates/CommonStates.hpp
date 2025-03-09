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
            printf("Standing.OnUpdate()\n");
        }

        void OnEnd(StateMachine::CombatStateContext* context) override {
            printf("Standing.OnEnd()\n");
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
