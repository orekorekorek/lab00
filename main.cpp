#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void fillRandomArray(int* array, int size, int rightBound, int leftBound); // заполнение массива случайными числами

void printArray(int* array, int size); // вывод массива

int bubbleSort(int* array, int size, int temp, int &sum); //  сортировка массива методом пузырька

void elementDelete(int* array, int size, int k); // удаление к - ого члена массива со сдвигом остальных

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
    
    int temp = 0;
    int sum = 0;
    cout << "Array is sorted by bubble method" << endl;
    bubbleSort(A, size, temp, sum);
    printArray(A, size);
    cout << endl;
    cout << "Sum of min and max value is " << sum << endl;
    cout << endl;
    
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
    
    return 0;
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

int bubbleSort(int* array, int size, int temp, int &sum){
    for (int i = 1; i <= size; i++) {
           for (int j = 1; j <= size - i; j++) {
               if (array[j] > array[j + 1]) {
                   // меняем элементы местами
                   temp = array[j];
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
