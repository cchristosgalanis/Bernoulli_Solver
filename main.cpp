#include "BernoulliSolver.hpp"
#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>

int main(){
    std::cout << "Allocating memory for variables...\n";

    int N_points = Config::N_points;
    std::vector<double> grid(N_points, 0.0);
    std::vector<double> psi(N_points, 0.0);
    std::vector<double> psi_analytical(N_points, 0.0);
    std::vector<double> psi_RK(N_points, 0.0);
    std::vector<double> E_euler(N_points, 0.0);
    std::vector<double> E_rk(N_points, 0.0);

    BernoulliSolver solver;

    // call function to create grid (1D)
    solver.create_grid(N_points,grid.data(),Config::x_start, Config::x_end);

    // call function to compute solution with euler's approach
    solver.euler_solver(N_points, psi.data(), Config::y_0, Config::alpha, Config::x_start, Config::x_end, Config::P, Config::Q, grid.data());

    // call function for analytical solution
    // solver.analytical_method(N_points, psi_analytical.data(), Config::x_start, Config::x_end, grid.data());

    // call function to compute Runge-Kutta 4th order approach
    solver.runge_kutta4(N_points, psi_RK.data(), Config::y_0, Config::alpha, Config::x_start, Config::x_end, Config::P, Config::Q, grid.data());

    // call function to compute error for each numerical metho
    // solver.error_compute(N_points, E_euler.data(), E_rk.data(), psi.data(), psi_analytical.data(), psi_RK.data());


    // // for-loop to get results of each appraoch
    // for (int i=0; i<N_points; i++){
    //     std::cout << "Euler's Method: ";
    //     std::cout << "x:" << grid[i] << " , " << "y:" << psi[i] << "\n";

    //     std::cout << std::endl;
        
    //     std::cout << "Anlytical Method: ";
    //     std::cout << "x:" << grid[i] << " , " << "y:" << psi_analytical[i] << "\n";

    //     std::cout << std::endl;

    //     std::cout << "Runge-Kutta Method:";
    //     std::cout << "x:" << grid[i] << " , " << "y:" << psi_RK[i] << "\n";

    //     std::cout << std::endl;

    //     std::cout << "========================\n";
    // }

    std::ofstream out_file("bernoulli_polynomial_results.csv");
    out_file << "x,Euler,RK4\n";

    for (int i = 0; i < N_points; i++) {
        // Φρουρός: Αν και οι δύο λύσεις μηδενιστούν (λόγω ορίου/ασύμπτωτης), σταματάμε την εγγραφή
        if (i > 0 && psi[i] == 0.0 && psi_RK[i] == 0.0) {
            break;
        }

        out_file << grid[i] << ","
                 << psi[i] << ","
                 << psi_RK[i] << "\n";
    }
    
    out_file.close();

    std::cout << "\n[Success] Polynomial data successfully exported to 'bernoulli_polynomial_results.csv'\n";

//

    // std::ofstream out_file("bernoulli_results.csv");
    // out_file << "x,Euler,Analytical,RK4,Error_Euler,Error_RK4\n";

    // for (int i = 0; i < N_points; i++) {
    //     if (i > 0 && psi[i] == 0.0 && psi_RK[i] == 0.0) {
    //         break;
    //     }

    //     out_file << grid[i] << ","
    //              << psi[i] << ","
    //              << psi_analytical[i] << ","
    //              << psi_RK[i] << ","
    //              << E_euler[i] << ","
    //              << E_rk[i] << "\n";
    // }
    // out_file.close();

    // std::cout << "\n[Success] Data and errors successfully exported to 'bernoulli_results.csv'\n";
}