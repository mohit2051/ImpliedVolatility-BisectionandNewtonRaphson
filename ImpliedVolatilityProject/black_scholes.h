#ifndef __BLACK_SCHOLES_H
#define __BLACK_SCHOLES_H

class BlackScholes {
protected:
    double S;  // Underlying asset price
    double K;  // Strike price
    double r;  // Risk-free rate
    double T;  // Time to maturity

public:
    BlackScholes(double _S, double _K,
        double _r, double _T);
    virtual ~BlackScholes();
    virtual double operator()(double sigma) const = 0;
    
};

class BlackScholesCall: public BlackScholes {
public:
    BlackScholesCall(double _S, double _K, double _r, double _T);
    virtual ~BlackScholesCall();
    virtual double operator()(double sigma) const;
    double option_price(double sigma) const;
    double option_vega(double sigma) const;

};

class BlackScholesPut : public BlackScholes {
public:
    BlackScholesPut(double _S, double _K, double _r, double _T);
    virtual ~BlackScholesPut();
    virtual double operator()(double sigma) const;

};
#endif