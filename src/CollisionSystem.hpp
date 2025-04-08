#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include "math.hpp"
#include "CharacterData.hpp"
#include "GameSimulation.hpp"

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

// It needs to use a GameSimulation::GameState object
void CollisionSystem(GameSimulation::GameState* gameState) {
    // Preprocessing step. Generated hitboxes to actually check collisions
    // std::size_t entity { 0 };

    // while (entity < gameState->entityCount) {
    //     const math::IntVector2D entityOffset { gameState->physicsComponents[entity].position };
    //     // Get active hitboxes and offset them
    //     // GetActiveAttackHitboes(entity);

    //     TranslateHitbox(hitbox, entityOffset);

    //     entity += 1;
    // }

    const CharacterData::HitboxGroup AttackBoxes[10] {};
    const CharacterData::HitboxGroup VulnerableBoxes[10] {};

    std::size_t attackEntity { 0 };

    while (attackEntity < gameState->entityCount) {
        const CharacterData::HitboxGroup attackBox { AttackBoxes[attackEntity] };

        std::size_t defendEntity { 0 };

        while (defendEntity < gameState->entityCount) {
            // Don't compare an attacker against itself
            if (attackEntity == defendEntity) {
                continue;
            }

            const CharacterData::HitboxGroup vulnerableBox { VulnerableBoxes[defendEntity] };

            if (DoHitboxesOverlap(attackBox, vulnerableBox)) {
                // Generate hit event
            }

            defendEntity += 1;
        }

        attackEntity += 1;
    }
}

#endif // COLLISION_SYSTEM_HPP
