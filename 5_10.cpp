#include "5_10.h"

void gaussian_elimination(double **A, double *b, double *u, int n) {
    //
    for (int k = 0; k < n - 1; ++k) {
        //  find the row with the maximum element in column k
        int maxRow = k;
        for (int i = k + 1; i < n; ++i) {
            if (std::abs(A[i][k]) > std::abs(A[maxRow][k])) {
                maxRow = i;
            }
        }
        // swap the maxRow with current row k in matrix A and vector b
        if (maxRow != k) {
            std::swap(A[k], A[maxRow]);
            std::swap(b[k], b[maxRow]);
        }

        // elimination process for column k
        for (int i = k + 1; i < n; ++i) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= A[k][j] * factor;
            }
            b[i] -= b[k] * factor;
        }
    }

    // back substitution
    for (int i = n - 1; i >= 0; --i) {
        u[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            u[i] -= A[i][j] * u[j];
        }
        u[i] /= A[i][i];
    }
}
