# ELA (Embedded Linear Algebra)

**A minimalist linear algebra library for embedded systems**

## Key Features

- Template-based 2D and 3D vectors with types `float`, `int`, `double`
- Safe operations with error checking through `rs::Option`
- Comprehensive set of operators and geometric functions
- Header-only implementation with zero allocations
- Cross product functionality for 3D vectors

## Usage Example

```cpp
#include "ela/vec2.hpp"
#include "ela/vec3.hpp"

void setup() {
    ela::vec2f a{3.0f, 4.0f};
    ela::vec3f b{1.0f, 2.0f, 3.0f};
    
    // Safe operations
    auto normA = a.normalized();  // rs::Option<vec2f>
    auto divA = a / 2.0f;         // rs::Option<vec2f>
    auto normB = b.normalized();  // rs::Option<vec3f>
    
    // Operators
    ela::vec2f c = a * 2.0f;
    a += c;

    ela::vec3f d = b.cross(ela::vec3f{4.0f, 5.0f, 6.0f}); // Cross product
}
```

## API

### `vec2<T>`

```cpp
// Constructors
vec2();
vec2(T x, T y);

// Operators
vec2 operator+(const vec2 &rhs) const;
vec2 operator-(const vec2 &rhs) const;
vec2 operator*(T scalar) const;
rs::Option<vec2> operator/(T scalar) const;  // None when dividing by 0
vec2 &operator+=(const vec2 &rhs);
vec2 &operator-=(const vec2 &rhs);

// Methods
T length() const;  // Euclidean length
rs::Option<vec2> normalized() const;  // None for zero vector
T dot(const vec2 &other) const;  // Dot product
bool isZero() const;  // Check for (0,0)

// Type aliases
using vec2f = vec2<float>;
using vec2i = vec2<int>;
using vec2d = vec2<double>;
```

### `vec3<T>`

```cpp
// Constructors
vec3();
vec3(T x, T y, T z);

// Operators
vec3 operator+(const vec3 &rhs) const;
vec3 operator-(const vec3 &rhs) const;
vec3 operator*(T scalar) const;
rs::Option<vec3> operator/(T scalar) const;  // None when dividing by 0
vec3 &operator+=(const vec3 &rhs);
vec3 &operator-=(const vec3 &rhs);

// Methods
T length() const;  // Euclidean length
rs::Option<vec3> normalized() const;  // None for zero vector
T dot(const vec3 &other) const;  // Dot product
vec3 cross(const vec3 &other) const;  // Cross product
bool isZero() const;  // Check for (0,0,0)

// Type aliases
using vec3f = vec3<float>;
using vec3i = vec3<int>;
using vec3d = vec3<double>;
```

## Features

**Safe Operations**:

- `operator/` and `normalized()` return `rs::Option`
- Error checking without exceptions

**Integration**:
- Requires [Rustify](https://github.com/JamahaW/Rustify)

[MIT License](LICENSE)