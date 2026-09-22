# Bernoulli ODE Numerical Solver (C++ & Python)

A modular, high-performance C++ framework designed for numerical solution and stability analysis of Bernoulli differential equations, paired with a Python visualization suite.

---

## 📐 Mathematical Background
The solver targets non-linear ordinary differential equations of the Bernoulli form:

$$\frac{dy}{dx} + P(x)y = Q(x)y^\alpha$$

The framework implements two primary numerical methods:
1. **Euler's Method** (First-order approximation)
2. **Runge-Kutta 4th Order (RK4)** (High-precision fourth-order approximation)

---

## 🗂️ Project Structure
```text
bernoulli-ode-solver/
│
├── Config.hpp                # Central configuration (Parameters, P(x), Q(x))
├── BernoulliSolver.hpp       # Class declaration & function interfaces
├── BernoulliSolver.cpp       # Core numerical algorithms & stability guardians
├── main.cpp                  # Execution driver & CSV data export
├── analyze_results.py        # Python visualization & error analysis script
└── .gitignore                # Git exclusion rules

## 🚀 Getting Started & Usage

### 1. Customizing the Problem (`Config.hpp`)
To test custom function families or change simulation parameters, modify **only** the `Config.hpp` file without touching the core algorithms. 

Open `Config.hpp` and adjust:
* **Grid Bounds & Resolution:** `x_start`, `x_end`, `N_points`
* **Initial Conditions & Parameters:** `y_0`, `alpha`, `omega`
* **Mathematical Functions:** Define your custom $P(x)$ and $Q(x)$ models inside their respective static methods using standard C++ `<cmath>` syntax:

```cpp
namespace Config {
    constexpr double x_start = 1.0;
    constexpr double x_end = 10.0;
    constexpr int N_points = 100;
    constexpr double y_0 = 2.0;
    constexpr double alpha = 2.0;
    constexpr double omega = 1.0;

    static double P(double x) {
        return std::sin(omega * x); // Example: Periodic function
    }

    static double Q(double x) {
        return std::cos(omega * x); // Example: Periodic function
    }
}

