// Вариант 5. Поиск всех простых чисел до N (решето Эратосфена)
#include <iostream>
#include <vector>

std::vector<int> findPrimes(int N) {
    std::vector<int> primes;
    if (N < 2) return primes;

    std::vector<bool> isComposite(N + 1, false);

    for (int i = 2; i <= N; ++i) {
        if (!isComposite[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= N; j += i) {
                isComposite[j] = true;
            }
        }
    }
    return primes;
}

void test() {
    std::vector<int> p1 = findPrimes(10);
    std::vector<int> expected1 = {2, 3, 5, 7};
    bool ok1 = (p1 == expected1);
    std::cout << "Тест 1 (простые до 10): " << (ok1 ? "OK" : "FAIL") << std::endl;

    std::vector<int> p2 = findPrimes(1);
    std::cout << "Тест 2 (простые до 1, ожидается пусто): " << (p2.empty() ? "OK" : "FAIL") << std::endl;
}

int main() {
    test();

    int N;
    std::cout << "Введите N: ";
    std::cin >> N;

    std::vector<int> primes = findPrimes(N);

    std::cout << "Простые числа до " << N << ":" << std::endl;
    for (int p : primes) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}
