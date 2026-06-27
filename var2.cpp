// Вариант 2. Двумерный динамический массив int, заполнение случайными числами от -3 до 10
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int ROWS = 100;
    const int COLS = 200;

    int** arr = new int*[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        arr[i] = new int[COLS];
    }

    srand((unsigned int)time(0));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = -3 + rand() % (10 - (-3) + 1);
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
