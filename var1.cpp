// Вариант 1. Двумерный динамический массив float, заполнение случайными числами от -1 до 1
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int ROWS = 100;
    const int COLS = 200;

    float** arr = new float*[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        arr[i] = new float[COLS];
    }

    srand((unsigned int)time(0));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = -1.0f + 2.0f * (float)rand() / (float)RAND_MAX;
        }
    }

    std::cout << "Пример значений массива:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < ROWS; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    std::cout << "Память освобождена." << std::endl;
    return 0;
}
