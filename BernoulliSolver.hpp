#ifndef BERNOULLI_SOLVER_HPP
#define BERNOULLI_SOLVER_HPP

#include "Config.hpp"
#include<cmath>
#include<complex>
#include<vector>

class BernoulliSolver{
    public:
        // function to create 1D grid
        void create_grid(int N_points, double *grid, double x_start, double x_end);

        // euler approach (numerical approach)
        void euler_solver(int N_points, double *psi, double psi_0, double alpha, double x_start, double x_end, double (*P) (double), double (*Q) (double), const double *grid);

        // analytical approach 
        void analytical_method(int N_points, double *psi_analytical, double x_start, double x_end, const double *grid);

        // Runge-Kutta 4th order (Rk4)
        void runge_kutta4(int N_points, double *psi_RK, double psi_0, double alpha, double x_start, double x_end, double (*P) (double), double (*Q) (double), const double *grid);

        // function to compute error of numerical approaches in respect to analytical method for specific function
        void error_compute (int N_points, double *E_euler, double *E_rk, const double *psi, const double *analytical, const double *psi_RK);

};



#endif