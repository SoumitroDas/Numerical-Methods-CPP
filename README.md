# Numerical Methods in C++

This repository contains a collection of C++ programs implementing various numerical methods, developed as part of my 4th-year academic coursework at the University of Rajshahi. These programs solve problems in curve fitting, root finding, ordinary differential equations (ODEs), numerical integration, linear systems, interpolation, and partial differential equations (PDEs) mainly Heat equation and wave equation.

## About
 This project showcases my skills in C++ and numerical computing, applied to real-world mathematical problems. Each program is designed to be user-friendly, with input prompts and clear output formatting.

## Repository Structure
- **Curve-Fitting**: Polynomial curve fitting using Gaussian elimination.
- **Root-Finding**: Methods like Newton-Raphson, Bisection, and Iteration for solving equations.
- **ODE-Solvers**: Runge-Kutta (4th order), Euler, and Modified Euler for ODEs.
- **Integration**: Simpson’s 1/3, 3/8, and Trapezoidal rules for definite integrals.
- **Linear-Systems**: Jacobi, Gauss-Seidel, and Gauss Elimination for linear equations.
- **Interpolation**: Newton’s Divided Difference, Lagrange, Forward, and Backward interpolation.
- **PDE-Solvers**: Finite difference methods for 1D heat and wave equations.

## Features
- **Interactive**: Each program prompts for user input (e.g., points, initial conditions, accuracy).
- **Accurate**: Includes percentage error calculations for most methods.
- **Well-Documented**: Code comments explain key steps (to be enhanced in future updates).
- **Academic Focus**: Designed for educational purposes, with applications in computational mathematics.

## How to Use
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/Numerical-Methods-CPP.git
   cd Numerical-Methods-CPP
   ```
2. **Compile and Run**:
   - Use a C++ compiler (e.g., g++).
   - Example for curve fitting:
     ```bash
     g++ Curve-Fitting/curve_fit.cpp -o curve_fit
     ./curve_fit
     ```
3. **Dependencies**: C++11 or later, standard libraries (`iostream`, `iomanip`, `cmath`).
4. **Input Format**: Follow on-screen prompts to enter data (e.g., x/y values, initial guesses, step sizes).

## Example
**Curve Fitting**:
- Input: Number of points, x and y values.
- Output: Coefficients of a cubic polynomial.
```cpp
Enter the number of points to be entered
4
Enter the x values
0 1 2 3
Enter the y values
1 2 4 8
The required polynomial is
y = 1.000000 + 0.500000x + 0.500000x^2 + 0.166667x^3
```

## Future Improvements
- Add unit tests for each method.
- Include visualizations using libraries like Matplotlib (via Python bindings).
- Enhance documentation with mathematical explanations.

## About Me
I’m an Applied Mathematics student at the University of Rajshahi, with interests in Mathematical Biology (Perticularly Epidemiology), Data Science, and AI Automation. Connect with me on LinkedIn: www.linkedin.com/in/soumitro-kumar-das or email me at sdasshuvro@gmail.com.

