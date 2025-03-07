// Copyright 2022 UNN-CS
#include <cmath>
#include <numbers> // NOLINT
#include <stdexcept>
#include "circle.h"

Circle::Circle(double radius) {
    setRadius(radius);
}

double Circle::getRadius() const { return radius_; }
void Circle::setRadius(double radius) {
    if (radius < 0.) {
        throw std::invalid_argument("...");
    }

    radius_ = radius;

    ference_ = 2 * std::numbers::pi * radius_;
    area_ = std::numbers::pi * radius * radius;
}

double Circle::getFerence() const { return ference_; }
void Circle::setFerence(double ference) {
    if (ference < 0.) {
        throw std::invalid_argument("...");
    }

    setRadius(ference / (2 * std::numbers::pi));
    ference_ = ference;
}

double Circle::getArea() const { return area_; }
void Circle::setArea(double area) {
    if (area < 0.) {
        throw std::invalid_argument("...");
    }

    setRadius(std::sqrt(area / std::numbers::pi));
    area_ = area;
}
