#include "Matrix.h"

Matrix::Matrix(int m_size) : size(m_size) {
    for (int i = 0; i < size; ++i) {
        vector<int> row;
        for (int j = 0; j < size; ++j)
            row.push_back(0);
        m.push_back(row);
    }
}

Matrix::Matrix(int m_size, const int *data) : size(m_size) {
    for (int i = 0; i < size; ++i) {
        vector<int> row;
        for (int j = 0; j < size; ++j) {
            row.push_back(data[i*3+j]);
        }
        m.push_back(row);
    }
}


Matrix::Matrix(int m_size, vector<int> data) : size(m_size) {
    for (int i = 0; i < size; ++i) {
        vector<int> row;
        for (int j = 0; j < size; ++j) {
            row.push_back(data[i*3+j]);
        }
        m.push_back(row);
    }
}

vector<int> Matrix::operator[](int i) const {
    return m[i];
}

vector<int>& Matrix::operator[](int i) {
    return m[i];
}

ostream &operator<<(ostream &out, Matrix mx) {
    for (int i = 0; i < mx.size; ++i) {
        out << "|";
        for (int j = 0; j < mx.size; ++j)
            out << " " << mx[i][j];
        out << " |" << endl;
    }
    return out;
}


Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix result(a.size);
    for (int i = 0; i < a.size; ++i) {
        for (int j = 0; j < a.size; ++j) {
            for (int k = 0; k < a.size; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::pwr(int exp) const {
    Matrix mx(*this);
    for (int i = 1; i < exp; ++i) {
        mx = mx * *this;
    }
    return mx;
}

bool Matrix::has_zero() {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (m[i][j] == 0) return true;
        }
    }
    return false;
}

