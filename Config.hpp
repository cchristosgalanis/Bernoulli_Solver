#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace Config {
    // parameters of the Bernoulli function
    constexpr double x_start = 1.0; // ceiling
    constexpr double x_end = 5.0; // bottom
    constexpr int N_points = 100; // points of grid
    constexpr double y_0 = 2.0; // initial solution for x = x_start
    constexpr double alpha = 2.0; // bernoulli power

    // functions P(x) & Q(x)
    static double P(double x){
        return 1.0/x;
    }

    static double Q(double x){
        return 1.0;
    }
}

#endif