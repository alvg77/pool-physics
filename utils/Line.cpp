#include "Line.h"

#include <iostream>

Line::Line(const Point& p, const Vector& v) {
    this->A = v.y;
    this->B = -v.x;
    this->C = p.y * v.x - p.x * v.y;
}

Line::Line(const Point& p1, const Point& p2) {
    Vector v(p1, p2);

    this->A = v.y;
    this->B = -v.x;
    this->C = p1.y * v.x - p1.x * v.y;
}

Line::Line(const Line& other) 
    : A(other.A), B(other.B), C(other.C)
{}

bool Line::are_parallel(const Line& other) const {
    Vector v1(-this->B, this->A);
    Vector v2(-other.B, other.A);
    return v1.is_colinear(v2);
}

bool Line::is_orthogonal(const Line& other) const {
    return ((-this->B) * this->A + other.A * (-other.B)) == 0;
}

Vector Line::colinear() const { return Vector(-this->B, this->A); }

Vector Line::orthogonal() const { return Vector(this->A, this->B); }

Line Line::parallel(const Point p) const { return Line(p, this->colinear()); }

Line Line::orthogonal(const Point p) const {
    std::cout << this->A << " " << this->B << std::endl;
    return Line(p, this->orthogonal());
}

double Line::getA() const {
    return A;
}

double Line::getB() const {
    return B;
}

double Line::getC() const {
    return C;
}

void Line::setA(double A) {
    this->A = A;
}

void Line::setB(double B) {
    this->B = B;
}

void Line::setC(double C) {
    this->C = C;
}

inline std::ostream& operator<<(std::ostream& out, const Line& l) {
    out << l.A << "x + " << l.B << "y + " << l.C << " = 0 ";
    return out;
}

inline std::istream& operator>>(std::istream& in, Line& l) {
    in >> l.A;
    in >> l.B;
    in >> l.C;
    return in;
}