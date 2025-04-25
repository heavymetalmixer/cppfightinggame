#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include "GameSimulation.hpp"

namespace Collisions {
    // Create a new htibox, translated by the offset provided.
    CharacterData::Hitbox TranslateHitbox(CharacterData::Hitbox hitbox, math::IntVector2D offset) {
        return CharacterData::Hitbox {  hitbox.top      + offset.y,
                                        hitbox.left     + offset.x,
                                        hitbox.bottom   + offset.y,
                                        hitbox.right    + offset.x
        };
    }

    // Check if 2 hitboxes overlap
    bool DoHitboxesOverlap(CharacterData::Hitbox a, CharacterData::Hitbox b) {
        const bool IsNotOverlapping { (a.left > b.right)
                                || (b.left > a.right)
                                || (a.bottom > b.top)
                                || (b.bottom > a.top)
        };

        return !IsNotOverlapping;
    }

    CharacterData::HitboxGroup* GetActiveAttackHitboxes(GameSimulation::GameState* gameState, std::size_t entity) {
        // if (gameState->gameData) {
        //     gameState->gameData.CharacterProperties[entity];
        // }

        return nullptr;
    }

    struct ScratchHitboxSet {
        CharacterData::Hitbox hitboxStore[10];
        std::vector<CharacterData::Hitbox> hitboxes;
    };

    struct CollisionSystem {
        // Working memory to pass between the collision system stages
        // std::vector<CharacterData::HitboxGroup> AttackerEntityBoxes {}; // Here the allocator for gameState could be used
        // std::vector<CharacterData::HitboxGroup> DefenderEntityBoxes {}; // Here the allocator for gameState could be used

        std::vector<ScratchHitboxSet> AttackerEntityBoxes{}; // Here the allocator for gameState could be used
        std::vector<ScratchHitboxSet> DefenderEntityBoxes {}; // Here the allocator for gameState could be used

        CollisionSystem() { // The allocator should go here as a parameter
            AttackerEntityBoxes.reserve(10);
            DefenderEntityBoxes.reserve(10);
        }

        void PrepareHitbox(GameSimulation::GameState* gameState) {

        }

        // It needs to use a GameSimulation::GameState object
        // void Execute(GameSimulation::GameState* gameState) {
        //     // Preprocessing step. Generated hitboxes to actually check collisions

        //     for (std::size_t attackerIndex { 0 }; attackerIndex < AttackerEntityBoxes.size(); attackerIndex++) {
        //         // AttackerEntityBoxes[attackerIndex] is "AttackBoxes"
        //         auto& AttackBoxes { AttackerEntityBoxes[attackerIndex] };

        //         for (std::size_t ahIndex { 0 }; ahIndex < AttackBoxes.Hitboxes.size(); ahIndex++) {
        //             auto& attackBox { AttackBoxes.Hitboxes[ahIndex] };

        //             for (std::size_t defenderIndex { 0 }; defenderIndex < DefenderEntityBoxes.size(); defenderIndex++) {
        //                 auto& VulnerableBoxes { DefenderEntityBoxes[defenderIndex] };

        //                 // Don't compare an attacker against itself
        //                 if (attackerIndex == defenderIndex) {
        //                     continue;
        //                 }

        //                 for (std::size_t vhIndex { 0 }; vhIndex < VulnerableBoxes.Hitboxes.size(); vhIndex++) {
        //                     auto& vulnerableBox { VulnerableBoxes.Hitboxes[vhIndex] };

        //                     if (DoHitboxesOverlap(attackBox, vulnerableBox)) {
        //                         // Generate hit event
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }

        void Execute(GameSimulation::GameState* gameState) {
            // Preprocessing step. Generated hitboxes to actually check collisions

            for (std::size_t attackerIndex { 0 }; attackerIndex < AttackerEntityBoxes.size(); attackerIndex++) {
                // AttackerEntityBoxes[attackerIndex] is "AttackBoxes"
                ScratchHitboxSet& AttackBoxes { AttackerEntityBoxes[attackerIndex] };

                for (std::size_t ahIndex { 0 }; ahIndex < AttackBoxes.hitboxes.size(); ahIndex++) {
                    CharacterData::Hitbox& attackBox { AttackBoxes.hitboxes[ahIndex] };

                    for (std::size_t defenderIndex { 0 }; defenderIndex < DefenderEntityBoxes.size(); defenderIndex++) {
                        ScratchHitboxSet& VulnerableBoxes { DefenderEntityBoxes[defenderIndex] };

                        // Don't compare an attacker against itself
                        if (attackerIndex == defenderIndex) {
                            continue;
                        }

                        for (std::size_t vhIndex { 0 }; vhIndex < VulnerableBoxes.hitboxes.size(); vhIndex++) {
                            CharacterData::Hitbox& vulnerableBox { VulnerableBoxes.hitboxes[vhIndex] };

                            if (DoHitboxesOverlap(attackBox, vulnerableBox)) {
                                // Generate hit event
                            }
                        }
                    }
                }
            }
        }
    };
}



#endif // COLLISION_SYSTEM_HPP
