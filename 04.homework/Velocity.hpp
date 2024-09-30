#pragma once
#include "Point.hpp"
#include <cmath>

class Velocity {
  public:
    inline Velocity() = default;

    // TODO: комментарии
    inline Velocity(double x, double y) {
        // const double x = std::cos(angle);
        // const double y = std::sin(angle);
        // vec = Point{x, y} * abs;
        vec = Point{x, y};
    }

    inline Velocity(const Point& vector) {
        setVector(vector);
    }

    inline void setVector(const Point& vector) {
        vec = vector;
    }

    inline Point vector() const {
        return vec;
    }

  private:
    Point vec;
};
