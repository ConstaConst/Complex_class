#include <iostream>
#include "Complex.h"
#include <fstream>

#define VEC_NUM 2

Complex** create_vectors(std::istream &file, Complex* vectors[], int &n);
Complex *sum_vectors(Complex sum[], const Complex* const vectors[], const int n);
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "ERROR! File name is absents." << std::endl;
        return -1;
    }
    std::ifstream file(argv[1]);
    if (!file) {
        std::cout << "ERROR! File doesn't open." << std::endl;
        return -1;
    }

    int n = 0;
    Complex* vectors[VEC_NUM] = {nullptr, nullptr};

    create_vectors(file, vectors, n);

    Complex sum[n];

    for(int i = 0; i < VEC_NUM; i++) {
        for(int j = 0; j < n; j++)
            std::cout << vectors[i][j] << " ";
        std::cout << std::endl;
    }

    sum_vectors(sum, vectors, n);

    std::cout << std::endl;
    for(int j = 0; j < n; j++)
        std::cout << sum[j] << " ";
    std::cout << std::endl;

    return 0;
}

Complex** create_vectors(std::istream &file, Complex* vectors[], int &n) {
    file >> n;
    if (n <= 0)
        return nullptr;

    for(int i = 0; i < VEC_NUM; i++)
        vectors[i] = new Complex[n];

    file.ignore(1);
    for (int i = 0; i < VEC_NUM; i++) {
        for (int j = 0; j < n; j++) {
            file.ignore(2);
            file >> vectors[i][j];
        }
        file.ignore(3);
    }

    return vectors;
}

Complex *sum_vectors(Complex sum[], const Complex* const vectors[], const int n) {
    for (int i = 0; i < n; i++)
        sum[i] = vectors[0][i] + vectors[1][i];
    return sum;
}