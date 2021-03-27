#include "Header.h"

Complex operator+(const Complex& z1, const Complex& z2)
{
    Complex result;
    result.phi = 1 / tan((z1.Re() + z2.Re()) / z1.Im() + z2.Im());
    result.r = (z1.Re() + z2.Re()) / cos(result.phi);
    return result;
}

Complex operator-(const Complex& z1, const Complex& z2)
{
    Complex result;
    result.phi = 1 / tan((z1.Re() - z2.Re()) / (z1.Im() - z2.Im()));
    result.r = (z1.Re() - z2.Re()) / cos(result.phi);
    return result;
}

Complex operator*(const Complex& z1, const Complex& z2)
{
    Complex result;
    result.r = z1.r * z2.r;
    result.phi = z1.phi + z2.phi;
    return result;
}

Complex operator/(const Complex& z1, const Complex& z2)
{
    Complex result;
    result.r = z1.r / z2.r;
    result.phi = z1.phi - z2.phi;
    return result;
}

Complex Complex::poww(const Complex& z1, const Complex& z2)
{
    Complex result;
    double x1, y1, x2, y2;
    x1 = z1.Re();
    y1 = z1.Im();
    x2 = z2.Re();
    y2 = z2.Im();

    result.r = exp(x2 * log(sqrt(pow(x1,2) + pow(y1, 2))) - y2 * atan(y1 / x1));
    result.phi = x2 * atan(y1 / x1) + y2 * log(sqrt(pow(x1, 2) + pow(y1, 2)));

    return result;
}

Complex Complex::y(const Complex& z)
{
    Complex result;
    Complex a1(sqrt(27));
    Complex a2(sqrt(5), atan(2));
    Complex a3(2);
    Complex a4(sqrt(5), atan(-2));
    Complex a5(5, -1.5708);

    result = poww(z, a1) + a2 * poww(z, a3) + a4 * poww(z, a5);

    return result;
}

int main()
{
    setlocale(LC_ALL, "ru");

    double r, phi;

    cout << "Введите модуль и аргумент комплексного числа" << endl;
    cin >> r;
    cin >> phi;

    Complex complex(r, phi);
    Complex answer;

    answer = answer.y(complex);

    double r1 = complex; 
    double r2 = answer;

    cout << "Действительная часть исходного комплексного числа: " << complex.Re() << endl;
    cout << "Мнимая часть исходного комплексного числа: " << complex.Im() << endl;
    cout << "Модуль исходного комплексного числа: " << complex.R() << endl;
    cout << "Аргумент исходного комплексного числа: " << complex.Phi() << endl << endl;

    cout << "Действительная часть посчитанного комплексного числа: " << answer.Re() << endl;
    cout << "Мнимая часть посчитанного комплексного числа: " << answer.Im() << endl;
    cout << "Модуль посчитанного комплексного числа: " << answer.R() << endl;
    cout << "Аргумент посчитанного комплексного числа: " << answer.Phi() << endl << endl;

    cout << "Модуль исходного комплексного числа, выведенный с помощью функции преобразованияу: " << r1 << endl;
    cout << "Модуль посчитанного комплексного числа, выведенный с помощью функции преобразованияу: " << r2 << endl;
}