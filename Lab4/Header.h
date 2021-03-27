#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:

    double r;
    double phi;
  
public:

    Complex()
    {
        r = 0;
        phi = 0;
    }

    Complex(double r)
    {
        this->r = r;
        phi = 0;
    }

    Complex(double r, double phi)
    {
        this->r = r;
        this->phi = phi;
    }

    double Re() const
    {
        return r * cos(phi);
    }
    double Im() const
    {
        return r * sin(phi);
    }
    double R() const
    {
        return r;
    }
    double Phi() const
    {
        return phi;
    }

    operator double()
    {
        return r;
    }

    friend Complex operator+(const Complex& z1, const Complex& z2);
    friend Complex operator-(const Complex& z1, const Complex& z2);
    friend Complex operator*(const Complex& z1, const Complex& z2);
    friend Complex operator/(const Complex& z1, const Complex& z2);

    Complex poww(const Complex& z1, const Complex& z2);
    Complex y(const Complex& z);
};