#include "2_6.h" 


double newton_Raphson(double initialGuess, double epsilon) {
    int max_iterations = 100;
    double x_prev = initialGuess;
    double x_next;
    int iteration = 0;
    do {
        x_next = x_prev - (exp(x_prev) + pow(x_prev, 3) - 5) / (exp(x_prev) + 3 * pow(x_prev, 2));
        std::cout << "Iteration " << iteration + 1 << ": x = " << x_next << std::endl;
        if (fabs(x_next - x_prev) < epsilon) {
            std::cout << "Converged at iteration " << iteration + 1 << std::endl;
            break;
        }
        x_prev = x_next; 
        iteration++;
    } while (iteration < max_iterations);
    return x_next;
}
