//
//  main.cpp
//  lab02
//
//  Created by Кирилл Кузнецов on 18.11.2021.
//
#include <iostream>
#include "rhombus.cpp"

using namespace std;

int main() {
    point b = {3, 3};
    rhombus rhombus_1 = rhombus(b, 3, 4);
    cout << rhombus_1.getSemiAxises()[1] << endl;
    cout << rhombus_1.getSquare() << endl;;
    rhombus rhombus_2 = rhombus(b, 1, 5);
    rhombus rhombus_3 = rhombus_1 + rhombus_2;
    cout << rhombus_1;
    cout << rhombus_2.getSemiAxises()[1];
    cout << rhombus_3.getSemiAxises()[1]<< endl;
    cout << rhombus_3;
    return 0;
}
