//
//  rhombus.cpp
//  lab02
//
//  Created by Кирилл Кузнецов on 17.11.2021.
//
#include "rhombus.h"


point rhombus::getCenter(){
    const rhombus rhombus = *this;
    return rhombus.center;
}

void rhombus::setCenter(const point center_1){
    this->center = center_1;
}

double_t* rhombus::getSemiAxises(){
    double_t semiAxises[] = {xSemiAxis, ySemiAxis};
    return semiAxises;
}

void rhombus::setSemiAxises(double_t length_x, double_t length_y){
    this->xSemiAxis = length_x;
    this->ySemiAxis = length_y;
}

point* rhombus::getPoints(){
    point point_1 = {this->center.x, this->center.y + this->ySemiAxis};
    point point_2 = {this->center.x + this->xSemiAxis, this->center.y};
    point point_3 = {this->center.x, this->center.y - this->ySemiAxis};
    point point_4 = {this->center.x - this->xSemiAxis, this->center.y};
    point points[4] = {point_1, point_2, point_3, point_4};
    return points;
}

double_t rhombus::getSquare(){
    return 2*xSemiAxis*ySemiAxis;
}

float_t rhombus::getPerimeter(){
    return 4 * sqrt(pow(xSemiAxis, 2) + pow(ySemiAxis, 2));
}

point* rhombus::getPoints90(){
    point point_1 = {this->center.x, this->center.y + this->xSemiAxis};
    point point_2 = {this->center.x + this->ySemiAxis, this->center.y};
    point point_3 = {this->center.x, this->center.y - this->xSemiAxis};
    point point_4 = {this->center.x - this->ySemiAxis, this->center.y};
    point points90[4] = {point_1, point_2, point_3, point_4};
    return points90;
}

rhombus rhombus::operator+(rhombus rhombus_2){
    return rhombus({this->center.x + rhombus_2.center.x, this->center.y + rhombus_2.center.y}, this->xSemiAxis + rhombus_2.xSemiAxis, this->ySemiAxis + rhombus_2.ySemiAxis);
}
