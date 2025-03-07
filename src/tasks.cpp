// Copyright 2022 UNN-CS

#include "tasks.h"
#include "circle.h"

double task1(double radius) {
    Circle circle(radius);
    circle.setFerence(circle.getFerence() + 1);
    return circle.getRadius() - radius;
}

double task2(double radius,
             double price_per_sq_m,
             double price_per_m,
             double width) {
    Circle inner(radius);
    Circle outer(radius + width);
    return ((outer.getArea() - inner.getArea()) * price_per_sq_m)
        + (outer.getFerence() * price_per_m);
}
