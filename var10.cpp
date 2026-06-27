// Вариант 10. Трехзначные числа с суммой цифр равной N
#include <iostream>
#include <vector>

std::vector<int> findNumbersWithDigitSum(int N) {
    std::vector<int> result;
    for (int num = 100; num <= 999; ++num) {
        int d1 = num / 100;
        int d2 = (num / 10) % 10;
        int d3 = num % 10;
        if (d1 + d2 + d3 == N) {
            result.push_back(num);
        }
    }
    return result;
}

void test() {
    std::vector<int> r1 = findNumbersWithDigitSum(27);
    bool ok1 = (r1.size() == 1 && r1[0] == 999);
    std::cout << "Тест 1 (сумма цифр = 27, ожидается только 999): " << (ok1 ? "OK" : "FAIL") << std::endl;

    std::vector<int> r2 = findNumbersWithDigitSum(1);
    bool ok2 = (r2.size() == 1 && r2[0] == 100);
    std::cout << "Тест 2 (сумма цифр = 1, ожидается только 100): " << (ok2 ? "OK" : "FAIL") << std::endl;
}

int main() {
    test();

    int N;
    std::cout << "Введите N (сумма цифр): ";
    std::cin >> N;

    std::vector<int> numbers = findNumbersWithDigitSum(N);

    std::cout << "Трехзначные числа с суммой цифр " << N << ":" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Всего найдено: " << numbers.size() << std::endl;

    return 0;
}
