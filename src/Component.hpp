#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "utils/math.hpp"

namespace Component {
    struct PhysicsComponent {
        math::IntVector2D position {};
        math::IntVector2D velocity {};
        math::IntVector2D acceleration {};
    };
}

#endif // COMPONENT_HPPCOMPONENT_HPP
