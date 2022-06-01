#ifndef __BLACK_SCHOLES_CPP
#define __BLACK_SCHOLES_CPP

#include "black_scholes.h"
#include "bs_prices.h"

BlackScholes::BlackScholes(double _S, double _K,double _r, double _T) : S(_S), K(_K), r(_r), T(_T) {}
BlackScholes::~BlackScholes(){}

BlackScholesCall::BlackScholesCall(double _S, double _K,double _r, double _T) : BlackScholes(_S,_K,_r,_T ) {}
BlackScholesCall::~BlackScholesCall() noexcept{}

double BlackScholesCall::operator()(double sigma) const 
{
    return call_price(S, K, r, sigma, T);
}

BlackScholesPut::BlackScholesPut(double _S, double _K, double _r, double _T) : BlackScholes(_S, _K, _r, _T) {}
BlackScholesPut::~BlackScholesPut() noexcept {}

double BlackScholesPut::operator()(double sigma) const
{
    return put_price(S, K, r, sigma, T);
}

// Renamed from operator() to option_price()
double BlackScholesCall::option_price(double sigma) const {
    return call_price(S, K, r, sigma, T);
}

// New method added, which calls call_vega 
// to obtain the actual price
double BlackScholesCall::option_vega(double sigma) const {
    return call_vega(S, K, r, sigma, T);
}
#endif