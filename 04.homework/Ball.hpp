#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Color setColor(const Color& color);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;

private:
    Velocity b_velocity;
    Point b_center;
    Color b_color;
    double b_radius = 3;
    double b_mass;

};
