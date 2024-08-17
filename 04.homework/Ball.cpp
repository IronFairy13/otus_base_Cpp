#include "Ball.hpp"
#include <cmath>


/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
Ball::Ball(const Point& center,const Velocity& velocity,const Color& color, double& radius)
{
    Ball::setCenter(center);
    Ball::setVelocity(velocity);
    Ball::setColor(color);
    Ball::b_radius = radius;
}

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    // TODO: место для доработки
    b_velocity = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    // TODO: место для доработки
    return b_velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    // TODO: место для доработки
    painter.draw(b_center, b_radius, b_color);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    // TODO: место для доработки
    b_center = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    // TODO: место для доработки
    return b_center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    // TODO: место для доработки
    return b_radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3. 
 */
double Ball::getMass() const {
    // TODO: место для доработки

    return (4.0/3.0 * M_PI * std::pow(b_radius, 3));
}

/**
 * @brief Задает цвет шара 
 */
void Ball::setColor(const Color& color)
{
    Ball::b_color = color;
}