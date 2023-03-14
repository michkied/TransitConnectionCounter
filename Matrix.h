#ifndef TRANSITCONNECTIONCOUNTER_MATRIX_H
#define TRANSITCONNECTIONCOUNTER_MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    int size;
    vector<vector<int>> m;
public:
    Matrix(int m_size);
    Matrix(int m_size, const int* data);
    Matrix(int m_size, vector<int> data);
    vector<int> operator[](int i) const;
    vector<int>& operator[](int i);
    Matrix pwr(int exp) const;
    bool has_zero();
    friend Matrix operator*(const Matrix& a, const Matrix& b);
    friend ostream& operator<<(ostream& out, Matrix mx);
};

#endif //TRANSITCONNECTIONCOUNTER_MATRIX_H
