#include <iostream>
#include <numeric>
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

void readAndPrintSqrt() {
    int value; std::cin >> value;
    if (value < 0) std::cout << "no square root" << std::endl;
    else std::cout << "square root of " << value << " is " << sqrt(value) << std::endl;
}

int main() {
    std::cout << "Size of different objects: " << std::endl <<
    "char: " << sizeof(char) << std::endl <<
    "short: " << sizeof(short) << std::endl <<
    "int: " << sizeof(int) << std::endl <<
    "long: " << sizeof(long) << std::endl <<
    "float: " << sizeof(float) << std::endl <<
    "double: " << sizeof(double) << std::endl <<
    "int*: " << sizeof(int*) << std::endl <<
    "double*: " << sizeof(double*) << std::endl;

    std::cout << std::endl;
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<int> c(10);
    Matrix<int, 2> d(10, 10);
    Matrix<int, 3> e(10, 10, 10);
    std::cout << "Size of different matrixes: " << std::endl <<
    "Matrix<int> a(10): " << sizeof(a) << std::endl <<
    "Matrix<int> b(100): " << sizeof(b) << std::endl <<
    "Matrix<int> c(10): " << sizeof(c) << std::endl <<
    "Matrix<int, 2> d(10, 10): " << sizeof(d) << std::endl <<
    "Matrix<int, 3> e(10, 10, 10)0): " << sizeof(e) << std::endl;

    std::cout << std::endl;
    std::cout << "Number of elements in different matrixes: " << std::endl <<
    "Matrix<int> a(10): " << a.size() << std::endl <<
    "Matrix<int> b(100): " << b.size() << std::endl <<
    "Matrix<int> c(10): " << c.size() << std::endl <<
    "Matrix<int, 2> d(10, 10): " << d.size() << std::endl <<
    "Matrix<int, 3> e(10, 10, 10): " << e.size() << std::endl;

    std::cout << std::endl;
    std::cout << "Enter numbers to take the square roots of:" << std::endl;
    for (int i = 0; i < 4; i++) readAndPrintSqrt();

    std::cout << std::endl;
    const int mdsize = 10;
    Matrix<double> md(mdsize);
    std::cout << "Enter numbers (doubles) to be put into a matrix:" << std::endl;
    for (int i = 0; i < mdsize; i++) {
        std::cin >> md[i];
    }
    std::cout << md << std::endl;

    std::cout << std::endl;
    std::cout << "Enter two numbers (ints) for the dimensions of the table:" << std::endl;
    int m, n; std::cin >> m >> n;
    Matrix<double, 2> tablemd(m, n);
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            tablemd(i, j) = i == 0 || j == 0 ? i + j : i * j;
        }
    }
    std::cout << tablemd << std::endl;

    std::cout << std::endl;
    std::cout << "Enter 10 complex numbers (doubles):" << std::endl;
    Matrix<std::complex<double>> mcd(10);
    for (int i = 0; i < mcd.size(); i++) std::cin >> mcd[i];
    const auto sum = std::accumulate(mcd.data(), mcd.data() + mcd.size(), std::complex<double>{});
    std::cout << "Sum of the complex numbers in the matrix is " << sum << std::endl;

    std::cout << std::endl;
    Matrix<int, 2> mi(2, 3);
    std::cout << "Enter 6 numbers (ints) to be put into another matrix:" << std::endl;
    for (int i = 0; i < mi.dim1(); i++) {
        for (int j = 0; j < mi.dim2(); j++) {
            std::cin >> mi[i][j];
        }
    }
    std::cout << mi << std::endl;

    return 0;
}
