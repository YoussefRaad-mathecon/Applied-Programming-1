#include "3_3.h"


void implicit_Euler(int n) {
    assert(n > 1);  // ensure that the number of grid points >1

    double h = 1.0 / (n - 1); // calculate step size based on the number of grid points (n in our text)

    // using vectors to store x and y values
    std::vector<double> x(n);
    std::vector<double> y(n);

    // initial conditions
    x[0] = 0;
    y[0] = 1;

    // compute the values using the implicit Euler method using yn = yn-1 / (1 + h)
    for (int i = 1; i < n; ++i) {
        x[i] = i * h;
        y[i] = y[i - 1] / (1 + h);
    }

    // writing results to a file
    std::ofstream tofile("xy.dat");
    for (int i = 0; i < n; ++i) {
        tofile << x[i] << "," << y[i] << std::endl; // end1 to assure new line
    }

    tofile.close();
}