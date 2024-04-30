#include "5_6.h"



// multiply two matrices
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols) {
    for (int i = 0; i < ARows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < ACols; ++k) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


// multiply a vector and a matrix
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols) {
    for (int j = 0; j < BCols; ++j) {
        res[j] = 0;
        for (int i = 0; i < BRows; ++i) {
            res[j] += A[i] * B[i][j];
        }
    }
}



// multiply a matrix and a vector
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows) {
    for (int i = 0; i < ARows; ++i) {
        res[i] = 0;
        for (int j = 0; j < ACols; ++j) {
            res[i] += A[i][j] * B[j];
        }
    }
}

// multiply a scalar and a matrix
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) {
    for (int i = 0; i < BRows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            res[i][j] = scalar * B[i][j];
        }
    }
}


// multiply a matrix and a scalar
void Multiply(double **res, double **B, double scalar, int BRows, int BCols) {
    Multiply(res, scalar, B, BRows, BCols); // Reuse the scalar multiplication function
}