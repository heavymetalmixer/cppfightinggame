#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <cstdint>
#include <vector>
#include <functional>
#include "../Input.hpp"

namespace StateMachine {
    enum class CombatStateID {
        Standing,
        Crounching,
        WalkingForward,
        WalkingBackwards,
        Jump,
        Attack,
        Special,
        Reaction,
        LaunchReaction,
        GuardReaction,
        GrabReaction,
    };

    struct CombatStateContext {
        bool bTransition { false };
        CombatStateID NextState { CombatStateID::Standing };
        Input::InputCommand InputCommand {};
    };

    // Provides an interface for combat states to respond to various events
    // struct CombatStateCallbacks {
    //     void (*OnStart)(CombatStateContext*);       // Called when starting an action
    //     void (*OnUpdate)(CombatStateContext*);      // Called every frame
    //     void (*OnEnd)(CombatStateContext*);         // Called when finishing an action
    // };

    template <typename T>
    struct CombatStateCallbacks {
        void(T::*OnStart)(CombatStateContext*);       // Called when starting an action
        void(T::*OnUpdate)(CombatStateContext*);       // Called when starting an action
        void(T::*OnEnd)(CombatStateContext*);       // Called when starting an action
    };

    template <typename T>
    struct CombatStateRegistery {
        // static constexpr std::size_t MAX_STATES { 256 };
        #define MAX_STATES 256
        CombatStateCallbacks<T>* CombatStates[MAX_STATES] { nullptr };

        void RegisterCommonState(CombatStateID StateID, CombatStateCallbacks<T>* StateCallbacks) {
            CombatStates[static_cast<std::size_t>(StateID)] = StateCallbacks;
        }
    };

    // Runs and keeps track of a state machine
    template <typename T>
    struct CombatStateMachineProcessor {
        CombatStateRegistery<T> Registery {};
        CombatStateID CurrentState { CombatStateID::Standing };
        CombatStateContext* Context { nullptr };

        void UpdateStateMachine() {
            if (Context) {
                CombatStateContext* context { Context };

                if (Registery.CombatStates[static_cast<std::size_t>(CurrentState)]) {
                    CombatStateCallbacks<T>* State { Registery.CombatStates[static_cast<std::size_t>(CurrentState)] };

                    if (State->OnUpdate) {
                        State->OnUpdate(context);
                    }

                    // Perform a state transition when requested
                    if (context->bTransition) {

                        // Call the OnEnd function of the previous state to do any cleanup required
                        if (State->OnEnd) {
                            State->OnEnd(context);
                        }

                        // Call the OnStart function on the next state to do any setup required
                        if (Registery.CombatStates[static_cast<std::size_t>(context->NextState)]) {
                            CombatStateCallbacks<T>* NextState { Registery.CombatStates[static_cast<std::size_t>(context->NextState)] };

                            if (NextState->OnStart) {
                                NextState->OnStart(context);
                            }
                        }

                        // Make sure the transition isn't performed more than once
                        context->bTransition = false;

                        // Make the next state current
                        CurrentState = context->NextState;
                    }
                }
            }
        }
    };

    template <typename T>
    struct StateExecutor {
        CombatStateRegistery<T> StateRegistery {};
    };

    struct TestContext {
        CombatStateContext base {};
        bool TestVar { true };
        bool TestVar2 { true };
    };
}

#endif // STATE_MACHINE_HPP
