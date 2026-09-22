# Bernoulli ODE Numerical Solver (C++)

A modular C++ framework designed for the numerical solution and stability analysis of Bernoulli differential equations, featuring Euler and Runge-Kutta 4th Order (RK4) methods, paired with a Python visualization suite.

---

## 🚀 How to Use & Customize

* **Parameter and Function Configuration:** You can easily test custom function models by modifying the parameters, grid bounds, and the mathematical functions $P(x)$ and $Q(x)$ directly inside the configuration file.
* **Analytical Benchmarking:** If the exact closed-form analytical solution of your differential equation is known, you can implement it within the analytical method routine. This allows the framework to automatically calculate absolute errors for precise method comparison. If no analytical solution is available (for complex or novel systems), you can simply bypass this step and use the high-precision RK4 output as your reference.
* **Execution & Visualization:** Compile and run the C++ source files to export your simulation data into a CSV file, then run the Python visualization script to generate clean comparative performance plots.

---

## 🛡️ Stability Guardians
Both numerical engines include built-in safety checks that detect mathematical singularities, asymptotes, or infinite explosions, safely terminating the execution to maintain data integrity.

---

## 📊 Tested Function Families
The framework has been successfully validated across multiple mathematical function families:
* **Algebraic / Singular Models**
* **Periodic (Trigonometric) Systems**
* **Exponential Families**
* **Polynomial Families**
