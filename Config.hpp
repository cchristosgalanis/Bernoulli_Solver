#ifndef CONFIG_HPP
#define CONFIG_HPP
#include<cmath>

namespace Config {
    // parameters of the Bernoulli function
    constexpr double x_start = 1.0; // start
    constexpr double x_end = 10.0; // end
    constexpr int N_points = 100; // points of grid
    constexpr double y_0 = 2.0; // initial solution for x = x_start
    constexpr double alpha = 2.0; // bernoulli power
    constexpr double omega = 1.0; // parameter for different frequencies

    // functions P(x) & Q(x)
    static double P(double x){

        return std::cos(omega * x);
    }

    static double Q(double x){
        return std::sin(omega * x);
    }
}

#endif