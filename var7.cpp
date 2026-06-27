// Вариант 7. Числа-перевертыши (палиндромы) до N
#include <iostream>
#include <vector>
#include <string>

bool isPalindrome(int num) {
    std::string s = std::to_string(num);
    int left = 0;
    int right = (int)s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

std::vector<int> findPalindromes(int N) {
    std::vector<int> result;
    for (int i = 0; i <= N; ++i) {
        if (isPalindrome(i)) {
            result.push_back(i);
        }
    }
    return result;
}

void test() {
    std::cout << "Тест 1 (121, ожидается перевертыш): " << (isPalindrome(121) ? "OK" : "FAIL") << std::endl;
    std::cout << "Тест 2 (123, ожидается не перевертыш): " << (!isPalindrome(123) ? "OK" : "FAIL") << std::endl;
    std::cout << "Тест 3 (7, ожидается перевертыш): " << (isPalindrome(7) ? "OK" : "FAIL") << std::endl;
}

int main() {
    test();

    int N;
    std::cout << "Введите N: ";
    std::cin >> N;

    std::vector<int> palindromes = findPalindromes(N);

    std::cout << "Числа-перевертыши до " << N << ":" << std::endl;
    for (int p : palindromes) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}
