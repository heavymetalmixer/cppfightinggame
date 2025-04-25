#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "utils/math.hpp"
#include <cstddef>

namespace Component {
    struct PhysicsComponent {
        math::IntVector2D position {};
        math::IntVector2D velocity {};
        math::IntVector2D acceleration {};
    };
}

struct HitEvent {
    std::size_t attacker;
    std::size_t defender;
};

constexpr int32_t MAX_HIT_EVENTS_PER_ENTITY { 10 };
struct HitEventComponent {
    HitEvent events[MAX_HIT_EVENTS_PER_ENTITY] {};
    std::size_t eventCount { 0 };
};

#endif // COMPONENT_HPPCOMPONENT_HPP
