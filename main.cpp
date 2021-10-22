#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void fillRandomArray(int* array, int size, int rightBound, int leftBound); // заполнение массива случайными числами

void printArray(int* array, int size); // вывод массива

int bubbleSort(int* array, int size, int &sum); //  сортировка массива методом пузырька

void elementDelete(int* array, int size, int k); // удаление к - ого члена массива со сдвигом остальных

enum class menu{ // реализация меню
    sort,
    elementDelete
};

int main(){
    cout << "Enter the size of array\n";
    int size;
    cin >> size;
    if (size <= 0) {
          // Размер масива должен быть положитлеьным
          cerr << "Invalid size" << endl;
          return 1;
      }
    
    int rightBound; int leftBound;
    cout << "Enter the right bound\n";
    cin >> rightBound;
    cout << "Enter the left bound\n";
    cin >> leftBound;
    if (rightBound < leftBound || rightBound == leftBound){
        // права граница должна быть строго больше левой
        cerr << "Error: invalid bounds" << endl;
        return 1;
    }
    cout << endl;
    
    int* A = new int [size];
    fillRandomArray(A, size, rightBound, leftBound);
    cout << "Your array with random numbers" << endl;
    printArray(A, size);
    cout << endl;
    
    cout << "What do u want to do?\n" << static_cast<int>(menu::sort) << " -sort ur array by bubble method\n" << static_cast<int>(menu::elementDelete) << " -delete an element of array\n";
    int choice;
    cin >> choice;
    try {
        const auto choisen = static_cast<menu>(choice);
        switch(choisen){
            case menu::sort:{
                int sum = 0;
                cout << "Array is sorted by bubble method" << endl;
                bubbleSort(A, size, sum);
                printArray(A, size);
                cout << endl;
                cout << "Sum of min and max value is " << sum << endl;
                cout << endl;
                delete[] A;
                break;
            }
            case menu::elementDelete:{
                int k;
                cout << "Enter the number of element you want to delete\n";
                cin >> k;
                cout << endl;
                if (k <= 0 || k > size){
                    // права граница должна быть строго больше левой
                    cerr << "Error: invalid number of element" << endl;
                    return 1;
                }
                elementDelete(A, size, k);
                printArray(A, size);
                delete[] A;
                break;
            }
            default:{
                cout << "You entered wrong choice!\n";
                return 1;
            }
    return 0;
        }
    }
    catch (out_of_range&)
        {
            cout << "You entered wrong choice!";
            return 1;
        }
}

void fillRandomArray(int* array, int size, int rightBound, int leftBound){
    for (int i = 1; i <= size; i++){
        array[i] = leftBound + rand() % ( (rightBound - leftBound < RAND_MAX? rightBound - leftBound: RAND_MAX >> 1));
    }
}

void printArray(int* array, int size){
    for (int i = 1; i <= size; i++){
        cout << i << ". " << array[i] << "\n";
    }
}

int bubbleSort(int* array, int size, int &sum){
    for (int i = 1; i <= size; i++) {
           for (int j = 1; j <= size - i; j++) {
               if (array[j] > array[j + 1]) {
                   // меняем элементы местами
                   int temp = array[j];
                   array[j] = array[j + 1];
                   array[j + 1] = temp;
               }
           }
       }
    sum = array[1] + array[size];
    return sum;
}

void elementDelete(int* array, int size, int k){
    for (int i = k; i <= size; i++){
        array[i] = array[i+1];
    }
    array[size] = 0;
}
