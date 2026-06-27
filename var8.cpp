// Вариант 8. Максимум функции на интервале [a, b]
#include <iostream>
#include <cmath>

double f(double x) {
    return -x * x + 4.0 * x + 1.0;
}

double findMax(double (*func)(double), double a, double b, double step) {
    double maxVal = func(a);
    for (double x = a; x <= b; x += step) {
        double val = func(x);
        if (val > maxVal) {
            maxVal = val;
        }
    }
    return maxVal;
}

void test() {
    double result1 = findMax(f, -10.0, 10.0, 0.0001);
    std::cout << "Тест 1 (максимум параболы, ожидается ~5): " << result1
               << (std::fabs(result1 - 5.0) < 0.01 ? " OK" : " FAIL") << std::endl;

    double result2 = findMax(sin, 0.0, M_PI, 0.0001);
    std::cout << "Тест 2 (максимум sin(x) на [0,pi], ожидается ~1): " << result2
               << (std::fabs(result2 - 1.0) < 0.01 ? " OK" : " FAIL") << std::endl;
}

int main() {
    test();

    double a, b;
    std::cout << "Введите границы интервала a и b: ";
    std::cin >> a >> b;

    double maxVal = findMax(f, a, b, 0.0001);
    std::cout << "Максимальное значение функции на [" << a << ", " << b << "]: " << maxVal << std::endl;

    return 0;
}
