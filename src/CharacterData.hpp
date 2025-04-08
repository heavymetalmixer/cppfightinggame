#ifndef CHARACTER_DATA_HPP
#define CHARACTER_DATA_HPP

#include <cstdint>
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
        std::vector<Hitbox> Hitboxes;
    };

    struct ActionProperties {
        int32_t Duration {};
        std::vector<HitboxGroup> HitboxGroups;
    };

    struct CharacterProperties {
        int32_t MaxHealth {};
        std::vector<ActionProperties> Actions;
    };
}



#endif // CHARACTER_DATA_HPP
