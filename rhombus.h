//
//  Header.h
//  lab02
//
//  Created by Кирилл Кузнецов on 17.11.2021.
//
#include <iostream>
#include <cmath>
using namespace std;

struct point{ double_t x; double_t y; };

class rhombus{
private:
    point center;
    double_t xSemiAxis;
    double_t ySemiAxis;
public:
    rhombus(){
        center = {0, 0};
        xSemiAxis = 0;
        ySemiAxis = 0;
    }
    rhombus(point otherCenter, double_t xSemiAxisLength, double_t ySemiAxisLength){
        center = otherCenter;
        xSemiAxis = xSemiAxisLength;
        ySemiAxis = ySemiAxisLength;
    }
    rhombus(const rhombus& other){
        center = other.center;
        xSemiAxis = other.xSemiAxis;
        ySemiAxis = other.xSemiAxis;
    }
    point getCenter();
    void setCenter(const point);
    double_t* getSemiAxises();
    void setSemiAxises(double_t length_x, double_t length_y);
    point* getPoints();
    double_t getSquare();
    float_t getPerimeter();
    point* getPoints90();
    friend istream& operator>>(istream& stream, rhombus& object);
    friend ostream& operator<<(ostream& stream, const rhombus& object);
    rhombus operator+(rhombus);
};

istream& operator>>(istream& stream, rhombus& object)
{
    cout << "Enter coordinates of center: \n";
    stream >> object.center.x >> object.center.y;
    cout << endl;
    cout << "Enter sizes of semi-axises: \n";
    stream >> object.xSemiAxis >> object.ySemiAxis;
    return stream;
};

ostream& operator<<(ostream& stream, const rhombus& object)
{
    stream << "(" << object.center.x << ", " << object.center.y << ")\n";
    stream << "Ox semi-axis: " << object.xSemiAxis << ", Oy semi-axis: " << object.ySemiAxis << "\n";
    return stream;
};
