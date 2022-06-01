#ifndef __MAIN_CPP
#define __MAIN_CPP

#include "black_scholes.h"
#include "interval_bisection.h"
#include "newton_raphson.h"
#include <iostream>

int main(int argc, char** argv) {
	// First we create the parameter list
	double S = 100.0;  // Underlying spot price
	double K = 100.0;  // Strike price
	double r = 0.05;   // Risk-free rate (5%)
	double T = 1.0;    // One year until expiry
	double C_M = 10.5; // Option market price

	// Create the Black-Scholes Call functor
	BlackScholesCall bsc(S, K, r, T);

	// Interval Bisection parameters
	double low_vol = 0.05;
	double high_vol = 0.35;
	double epsilon = 0.001;
	// Newton Raphson Parameter
	double init = 0.3;  // Our guess impl. vol of 30%
	double sigma;


	int selectNumericalMethod;
	std::cout << "Enter your choice for the Numerical Method for calculation of Implied Vol" << std::endl;
	std::cout << "1. Interval Bisection Method\n";
	std::cout << "2. Newton-Raphson Method\n";
	
	while (1) {
		std::cin >> selectNumericalMethod;
		if (selectNumericalMethod == 1) {
			// Calculate the implied volatility
			sigma = interval_bisection(C_M, low_vol, high_vol, epsilon, bsc);

			// Output the values
			std::cout << "IB method - Implied Vol: " << sigma << std::endl;
			break;
		}

		else if (selectNumericalMethod == 2) {
			// Calculate the implied volatility
			sigma = newton_raphson<BlackScholesCall, &BlackScholesCall::option_price, &BlackScholesCall::option_vega>(C_M, init, epsilon, bsc);

			// Output the values
			std::cout << "NR method - Implied Vol: " << sigma << std::endl;
			break;
		}

		else {
			std::cout << "Invalid choice! Please enter again\n";
			std::cout << "1. Interval Bisection Method\n";
			std::cout << "2. Newton-Raphson Method\n";
		}
	}
	
	return 0;
}
#endif