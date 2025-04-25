#ifndef COMMON_HPP
#define COMMON_HPP

#include <cassert>
#include "CharacterData.hpp"
#include "utils/math.hpp"

namespace common {
    std::size_t GetVulnerableBoxes(std::vector<CharacterData::Hitbox>& hitboxPool, // Out parameter
                                   const CharacterData::ActionProperties& action,
                                   const int32_t frame,
                                   const math::IntVector2D& position) {
        std::size_t poolIndex { 0 };

        // Find all the active hitboxes on the current frame
        for (std::size_t actionIndex { 0 }; actionIndex < action.VulnerableHitboxGroups.size(); actionIndex++) {
            CharacterData::HitboxGroup hitboxGroup { action.VulnerableHitboxGroups[actionIndex] };

            for (std::size_t hitboxIndex { 0 }; hitboxIndex < hitboxGroup.Hitboxes.size(); hitboxIndex++) {
                CharacterData::Hitbox hitbox { hitboxGroup.Hitboxes[hitboxIndex] };

                if (hitboxGroup.IsActiveOnFrame(frame)) {
                    // Maybe it should only be "less than"
                    assert(poolIndex <= hitboxPool.size() && "The hitbox pool index is bigger than the size of the hitbox pool itself!");

                    // If we exceed the hitbox pool size, return the size of the hitbox pool and write no more hitboxes
                    if (poolIndex >= hitboxPool.size()) {
                        return hitboxPool.size();
                    }

                    // Translate the hitbox byt the character position
                    hitboxPool[poolIndex] = CharacterData::Hitbox {
                        hitbox.top + position.y,
                        hitbox.left + position.x,
                        hitbox.bottom + position.y,
                        hitbox.right + position.x
                    };

                    poolIndex += 1;
                }
            }
        }

        return poolIndex;
    }
}

#endif // COMMON_HPP
