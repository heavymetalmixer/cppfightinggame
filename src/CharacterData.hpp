#ifndef CHARACTER_DATA_HPP
#define CHARACTER_DATA_HPP

#include <cstdint>
#include <cstddef>
#include <vector>

namespace CharacterData {
    struct Hitbox {
        int32_t top {};
        int32_t left {};
        int32_t bottom {};
        int32_t right {};
    };

    struct HitboxGroup {
        int32_t StartFrame { 0 };
        int32_t Duration { 1 };
        std::vector<Hitbox> Hitboxes {};

        bool IsActiveOnFrame(int32_t frame) {
            return (frame >= StartFrame) && (frame < (StartFrame + Duration));
        }
    };

    struct ActionProperties {
        int32_t Duration { 0 };
        std::vector<HitboxGroup> VulnerableHitboxGroups {};
        std::vector<HitboxGroup> AttackHitboxGroups {};
    };

    struct CharacterProperties {
        int32_t MaxHealth { 10000 };
        std::vector<ActionProperties> Actions {};
    };
}



#endif // CHARACTER_DATA_HPP
