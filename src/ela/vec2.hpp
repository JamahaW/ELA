#pragma once

#include <cmath>
#include <rs/Option.hpp>


namespace ela {

template<typename T> struct vec2 {

    using Value = T;

    T x, y;

    vec2() :
        x{0}, y{0} {}

    vec2(T x, T y) :
        x{x}, y{y} {}

    // Арифметические операторы
    vec2 operator+(const vec2 &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    vec2 operator-(const vec2 &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    vec2 operator*(T scalar) const {
        return {x * scalar, y * scalar};
    }

    // Безопасное деление с использованием Option
    rs::Option<vec2> operator/(T scalar) const {
        if (scalar == 0) { return {}; } // None
        return vec2{x / scalar, y / scalar};
    }

    // Присваивающие операторы
    vec2 &operator+=(const vec2 &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    vec2 &operator-=(const vec2 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    // Геометрические операции с обработкой ошибок

    T length() const {
        return std::hypot(x, y);
    }

    rs::Option<vec2> normalized() const {
        T len = length();
        if (len == 0) { return {}; } // None
        return vec2{x / len, y / len};
    }

    T dot(const vec2 &other) const {
        return x * other.x + y * other.y;
    }

    bool isZero() const {
        return x == 0 && y == 0;
    }
};

// Псевдонимы для распространённых типов
using vec2f = vec2<float>;
using vec2i = vec2<int>;
using vec2d = vec2<double>;

} // namespace ela