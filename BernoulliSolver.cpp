#include "BernoulliSolver.hpp"
#include<iostream>

#include<cmath>

// file for function implementations

// function to create grid
void BernoulliSolver::create_grid(int N_points, double *grid, double x_start, double x_end){
    double dx = (x_end - x_start) / (N_points - 1);

    for (int i=0; i < N_points; i++){
        grid[i] = x_start + i * dx;
    }
}

// analytical approach for Bernoulli ODE
void BernoulliSolver::analytical_method(int N_points, double *psi_analytical, double x_start, double x_end, const double *grid){
    double dx = (x_end - x_start) / (N_points - 1);

    // for-loop to compute analytical method
    for (int i=0; i<N_points; i++){
        double x = grid[i];
        psi_analytical[i] = 1.0 / (x * (0.5 - std::log(x)));
    }
}

// function to compute solution by euler approach
void BernoulliSolver::euler_solver(int N_points, double *psi, double psi_0, double alpha, double x_start, double x_end,double (*P) (double), double (*Q) (double), const double *grid){
    double dx = (x_end - x_start) / (N_points - 1);
     // initial value
    psi[0] = psi_0;

    for (int i=0; i < N_points-1; i++){
        double x = grid[i];
        double curr_psi = psi[i];

        double f_xy = Q(x) * std::pow(curr_psi,alpha) - P(x) * curr_psi;

        // check if there is a divergence
        if (std::abs(f_xy) > 1e10 || std::isnan(f_xy) || std::isinf(f_xy)){
            std::cout << "Euler solver stopped to:";
            std::cout << x << "\n";
            break;
        }

        psi[i+1] = curr_psi + dx * f_xy;
    }   
}

void BernoulliSolver::runge_kutta4(int N_points, double *psi_Rk, double psi_0, double alpha, double x_start, double x_end, double (*P) (double), double (*Q) (double), const double *grid){
    /*
        using Runge-Kutta 4th order approach to compute Bernoulli function 
        y[i+1] = y[i] + dx/6 * (k1 + 2k2 + 2k3 + k4)
    */

    double dx = (x_end - x_start) / (N_points - 1);

    psi_Rk[0] = psi_0;

    for (int i=0; i < N_points-1; i++){
        double x = grid[i];
        double curr_psi = psi_Rk[i];

        // compute k1
        double k1 = Q(x) * std::pow(curr_psi,alpha) - P(x) * curr_psi;

        // compute k2
        double k2 = Q(x + dx/2) * std::pow(curr_psi + dx * k1/2,alpha) - P(x + dx/2) * (curr_psi + dx * k1/2);

        // compute k3
        double k3 = Q(x + dx/2) * std::pow(curr_psi + dx * k2/2, alpha) - P(x + dx/2) * (curr_psi + dx * k2/2);

        // compute k4
        double k4 = Q(x + dx) * std::pow(curr_psi + dx * k3,alpha) - P(x + dx) * (curr_psi + dx * k3);

        // check if there is a divergence
        if (std::abs(k4) > 1e10 || std::isnan(k4) || std::isinf(k4)){
            std::cout << "Runge-Kutta stopped to:";
            std::cout << x << "\n";
            break;
        }

        psi_Rk[i+1] = curr_psi + (dx/6.0) * (k1 + 2.0*(k2 + k3) + k4);
    }
}

// implementation of function to compute error
void BernoulliSolver::error_compute(int N_points, double *E_euler, double *E_rk, const double *psi, const double *analytical, const double *psi_RK){
    
    for (int i=0; i<N_points; i++){

        if (psi[i] != 0.0){
            E_euler[i] = std::abs(analytical[i] - psi[i]);
        }

        if (psi_RK[i] != 0.0){
            E_rk[i] = std::abs(analytical[i] - psi_RK[i]);
        }

        if (psi[i] == 0.0 && psi_RK[i] == 0.0) {
            break;
        }
    }
}
