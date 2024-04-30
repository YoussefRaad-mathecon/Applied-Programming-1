#include "5_3.h"

void swap_pointer(double *a, double *b) {
    double swap = *a;
    *a = *b;
    *b = swap;
}

void swap_ref(double &a, double &b) {
    double swap = a;
    a = b;
    b = swap;
}


