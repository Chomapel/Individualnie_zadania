// Вариант 3. Машинный ноль и машинный эпсилон для float и double
#include <iostream>

int main() {
    float epsF = 1.0f;
    while (1.0f + epsF / 2.0f != 1.0f) {
        epsF /= 2.0f;
    }
    std::cout << "Машинный эпсилон (float): " << epsF << std::endl;

    double epsD = 1.0;
    while (1.0 + epsD / 2.0 != 1.0) {
        epsD /= 2.0;
    }
    std::cout << "Машинный эпсилон (double): " << epsD << std::endl;

    float zeroF = 1.0f;
    while (zeroF / 2.0f != 0.0f) {
        zeroF /= 2.0f;
    }
    std::cout << "Машинный ноль (float): " << zeroF << std::endl;

    double zeroD = 1.0;
    while (zeroD / 2.0 != 0.0) {
        zeroD /= 2.0;
    }
    std::cout << "Машинный ноль (double): " << zeroD << std::endl;

    return 0;
}
