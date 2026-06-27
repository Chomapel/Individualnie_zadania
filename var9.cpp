// Вариант 9. Произведение матриц
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrix;

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int n = (int)A.size();
    int m = (int)A[0].size();
    int p = (int)B[0].size();

    Matrix result(n, std::vector<double>(p, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            double sum = 0.0;
            for (int k = 0; k < m; ++k) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void test() {
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};
    Matrix C = multiplyMatrices(A, B);

    bool ok = (C[0][0] == 19 && C[0][1] == 22 && C[1][0] == 43 && C[1][1] == 50);
    std::cout << "Тест умножения матриц: " << (ok ? "OK" : "FAIL") << std::endl;
    std::cout << "Результат теста:" << std::endl;
    printMatrix(C);
}

int main() {
    test();

    int n, m, p;
    std::cout << "Введите размеры матриц (n m p), где A: n x m, B: m x p: ";
    std::cin >> n >> m >> p;

    Matrix A(n, std::vector<double>(m));
    Matrix B(m, std::vector<double>(p));

    std::cout << "Введите элементы матрицы A (" << n << "x" << m << "):" << std::endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> A[i][j];

    std::cout << "Введите элементы матрицы B (" << m << "x" << p << "):" << std::endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            std::cin >> B[i][j];

    Matrix C = multiplyMatrices(A, B);

    std::cout << "Результат произведения матриц:" << std::endl;
    printMatrix(C);

    return 0;
}
