#include "Ball.h"

Ball::Ball(const Point& startingPosition, double radius)
    : position(startingPosition), radius(radius) {}

Ball::~Ball() {}

Point Ball::getPosition() const { return position; }

void Ball::setPosition(const Point &position) {
    this->position = position;
}

double Ball::getRadius() const { return radius; }