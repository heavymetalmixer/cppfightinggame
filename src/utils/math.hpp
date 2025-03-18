#ifndef MATH_HPP
#define MATH_HPP

#include <cstdint>

namespace math {
    struct IntVector2D {
        int32_t x { 0 };
        int32_t y { 0 };

        IntVector2D Add(const IntVector2D other) {
            return IntVector2D { x + other.x, y + other.y };
        }
    };

    int32_t WolrdToScreen(const int32_t Coordinate) {
        return (Coordinate != 0) ?  Coordinate / 1000 : 0;
    }
}

#endif // MATH_HPP
