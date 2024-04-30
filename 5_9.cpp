#include "5_9.h"


void solve3by3(double **A, double *b, double *u) {
    // determinant of the matrix
    double detA = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
                  A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
                  A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);


    // create matrix copies for finding determinants of modified matrices
    double A1[3][3], A2[3][3], A3[3][3];

    // copy A to Ai
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A1[i][j] = A[i][j];

            A2[i][j] = A[i][j];
            
            A3[i][j] = A[i][j];
        }
    }

    // replace columns with vector b to form new matrices
    for (int i = 0; i < 3; ++i) {
        A1[i][0] = b[i];

        A2[i][1] = b[i];

        A3[i][2] = b[i];
    }

    // calculate the determinants of these matrices directly
    double detA1 = A1[0][0] * (A1[1][1] * A1[2][2] - A1[1][2] * A1[2][1]) -
                   A1[0][1] * (A1[1][0] * A1[2][2] - A1[1][2] * A1[2][0]) +
                   A1[0][2] * (A1[1][0] * A1[2][1] - A1[1][1] * A1[2][0]);

    double detA2 = A2[0][0] * (A2[1][1] * A2[2][2] - A2[1][2] * A2[2][1]) -
                   A2[0][1] * (A2[1][0] * A2[2][2] - A2[1][2] * A2[2][0]) +
                   A2[0][2] * (A2[1][0] * A2[2][1] - A2[1][1] * A2[2][0]);

    double detA3 = A3[0][0] * (A3[1][1] * A3[2][2] - A3[1][2] * A3[2][1]) -
                   A3[0][1] * (A3[1][0] * A3[2][2] - A3[1][2] * A3[2][0]) +
                   A3[0][2] * (A3[1][0] * A3[2][1] - A3[1][1] * A3[2][0]);

    // calculate vector u as asked ot
    u[0] = detA1 / detA;

    u[1] = detA2 / detA;

    u[2] = detA3 / detA;
}
