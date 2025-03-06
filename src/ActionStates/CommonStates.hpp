#ifndef COMMON_STATES_HPP
#define COMMON_STATES_HPP

#include "StateMachine.hpp"
#include <stdio.h>

namespace CommonStates {
    struct Standing {
        void OnStart(StateMachine::CombatStateContext* context){
            printf("Standing.OnStart()\n");
        }

        void OnUpdate(StateMachine::CombatStateContext* context){
            printf("Standing.OnUpdate()\n");
        }

        void OnEnd(StateMachine::CombatStateContext* context){
            printf("Standing.OnEnd()\n");
        }
    };

    struct Crouching {
        void OnStart(StateMachine::CombatStateContext* context){
            printf("Crouching.OnStart()\n");
        }

        void OnUpdate(StateMachine::CombatStateContext* context){
            printf("Crouching.OnUpdate()\n");
        }

        void OnEnd(StateMachine::CombatStateContext* context){
            printf("Crouching.OnEnd()\n");
        }
    };
}

#endif // COMMON_STATES_HPP
