// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius_;
    double ference_;
    double area_;

 public:
    explicit Circle(double radius);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;

    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
};

#endif // INCLUDE_CIRCLE_H_
