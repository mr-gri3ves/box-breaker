#ifndef BOX_BREAKER_MATH_HPP
#define BOX_BREAKER_MATH_HPP

#include <iostream>
#include <stdexcept>
#include <utility>
#include <array>
#include <cmath>

namespace BoxBreaker::Math {
    struct Rect {
        float x, y, w, h;
    };

    struct Vector2f {
        float x, y;
    };

    static constexpr std::array<float, 12> getVertices(const Rect &rect) {
        return {
                rect.x, rect.y, 0.0f,
                rect.x + rect.w, rect.y, 0.0f,
                rect.x + rect.w, rect.y + rect.h, 0.0f,
                rect.x, rect.y + rect.h, 0.0f,
        };
    }

    static constexpr std::array<unsigned int, 6> getIndices(const Rect &rect) {
        return {
                0, 1, 3,
                1, 2, 3
        };
    }

    static constexpr bool rectCollide(const Rect &rect1, const Rect &rect2) {
        return rect1.x < rect2.x + rect2.w &&
               rect1.x + rect1.w > rect2.x &&
               rect1.y < rect2.y + rect2.h &&
               rect1.h + rect1.y > rect2.y;
    }
} // namespace BoxBreaker::Math

#endif //BOX_BREAKER_MATH_HPP
