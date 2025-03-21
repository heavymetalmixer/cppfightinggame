#ifndef CHARACTER_DATA
#define CHARACTER_DATA

#include <cstdint>
#include <vector>

struct CharacterProperties {
    int32_t MaxHealth {};
};

struct Hitbox {
    int32_t top {};
    int32_t left {};
    int32_t width {};
    int32_t height {};
};

struct HitboxGroup {
    int32_t StartFrame {};
    int32_t Duration {1};
    std::vector<Hitbox> Hitboxes();
};

struct ActionProperties {
    int32_t Duration {};
};

#endif // CHARACTER_DATA
