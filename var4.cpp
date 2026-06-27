// Вариант 4. Длина n-мерного вектора (евклидова норма, теорема Пифагора)
#include <iostream>
#include <cmath>

double vectorLength(const double* vec, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += vec[i] * vec[i];
    }
    return std::sqrt(sum);
}

void test() {
    double v1[] = {3.0, 4.0};
    double v2[] = {1.0, 0.0, 0.0};
    double v3[] = {0.0, 0.0};

    double r1 = vectorLength(v1, 2);
    double r2 = vectorLength(v2, 3);
    double r3 = vectorLength(v3, 2);

    std::cout << "Тест 1 (ожидается 5): " << r1 << (std::fabs(r1 - 5.0) < 1e-9 ? " OK" : " FAIL") << std::endl;
    std::cout << "Тест 2 (ожидается 1): " << r2 << (std::fabs(r2 - 1.0) < 1e-9 ? " OK" : " FAIL") << std::endl;
    std::cout << "Тест 3 (ожидается 0): " << r3 << (std::fabs(r3 - 0.0) < 1e-9 ? " OK" : " FAIL") << std::endl;
}

int main() {
    test();

    int n;
    std::cout << "Введите размерность вектора: ";
    std::cin >> n;

    double* vec = new double[n];
    std::cout << "Введите " << n << " координат вектора:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    double len = vectorLength(vec, n);
    std::cout << "Длина вектора: " << len << std::endl;

    delete[] vec;
    return 0;
}
