// Вариант 6. Счастливые билеты из 6 цифр (сумма первых 3 цифр = сумме последних 3 цифр)
#include <iostream>
#include <vector>
#include <string>

std::vector<int> findLuckyTickets() {
    std::vector<int> result;
    for (int num = 0; num <= 999999; ++num) {
        int digits[6];
        int temp = num;
        for (int i = 5; i >= 0; --i) {
            digits[i] = temp % 10;
            temp /= 10;
        }
        int sum1 = digits[0] + digits[1] + digits[2];
        int sum2 = digits[3] + digits[4] + digits[5];
        if (sum1 == sum2) {
            result.push_back(num);
        }
    }
    return result;
}

bool isLucky(int num) {
    int digits[6];
    int temp = num;
    for (int i = 5; i >= 0; --i) {
        digits[i] = temp % 10;
        temp /= 10;
    }
    int sum1 = digits[0] + digits[1] + digits[2];
    int sum2 = digits[3] + digits[4] + digits[5];
    return sum1 == sum2;
}

void test() {
    std::cout << "Тест 1 (123132, ожидается счастливый): " << (isLucky(123132) ? "OK" : "FAIL") << std::endl;
    std::cout << "Тест 2 (123456, ожидается не счастливый): " << (!isLucky(123456) ? "OK" : "FAIL") << std::endl;
    std::cout << "Тест 3 (000000, ожидается счастливый): " << (isLucky(0) ? "OK" : "FAIL") << std::endl;
}

int main() {
    test();

    std::vector<int> tickets = findLuckyTickets();
    std::cout << "Количество счастливых билетов: " << tickets.size() << std::endl;

    std::cout << "Первые 10 счастливых билетов:" << std::endl;
    for (int i = 0; i < 10 && i < (int)tickets.size(); ++i) {
        char buf[7];
        snprintf(buf, sizeof(buf), "%06d", tickets[i]);
        std::cout << buf << std::endl;
    }

    return 0;
}
