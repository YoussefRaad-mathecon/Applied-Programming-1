#include "5_4.h"
#include <cmath>
#include <limits>

// Function to calculate mean
double calc_mean(double a[], int length) {
    if (length == 0) { // Check for empty array to avoid division by zero
        return 0.0; 
    }

    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        sum += a[i];
    }
    return sum / length; 
}

// function to calculate the SD (in 2 steps)
double calc_std(double a[], int length) {
    if (length <= 1) { //  avoid division by zero
        return 0.0; 
    }

    double mean = calc_mean(a, length); 
    double sum_of_squares = 0.0;

    for (int i = 0; i < length; ++i) {
        sum_of_squares += std::pow(a[i] - mean, 2);
    }

    return std::sqrt(sum_of_squares / (length - 1)); 
}
