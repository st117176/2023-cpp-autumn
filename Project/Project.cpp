#include <iostream>
#include <cmath>

class Equation {
public:
    Equation() {}
    Equation(double a, double b, double c, double d, double e) : a(a), b(b), c(c), d(d), e(e) {}
    ~Equation() {}
    void solve(double a, double b, double c, double d, double e);

private:
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    double e = 0.0;

    //s

    double p_f = (-3 * b * b) / (8 * a * a) + c / a;
    double q_f = b * b * b / (8 * a * a * a) - b * c / (2 * a * a) + d / a;
    double r_f = (-3 * b * b * b * b) / (256 * a * a * a * a) + b * b * c / (16 * a * a * a) - b * d / (4 * a * a) + e / a;

    double Q_f = (3 * q_f - p_f * p_f) / 9;
    double R_f = (9 * p_f * q_f - 27 * r_f - 2 * p_f * p_f * p_f) / 54;
    double D_f = Q_f * Q_f * Q_f + R_f * R_f;

    double S_f = pow(R_f + sqrt(D_f), 1.0 / 3);
    double T_f = pow(R_f - sqrt(D_f), 1.0 / 3);

    double theta_f = acos(R_f / sqrt(-Q_f * Q_f * Q_f)) / 3;

    double p_c = d / b - (c * c) / (3 * b * b);
    double q_c = e / b - (c * d) / (3 * b * b) + (2 * c * c * c) / (27 * b * b * b);

    double D_c = q_c * q_c / 4 + p_c * p_c * p_c / 27;

    double D_s = d * d - 4 * c * e;

    const double PI = 3.141592653589793;

    void FDiscriminantPositive() {
        double x1_f = -b / (4 * a) - S_f - T_f;
        double x2_f = -b / (4 * a) + (S_f + T_f) / 2;
        double x3_f = -b / (4 * a) + (S_f + T_f) / 2;
        double x4_f = -b / (4 * a) + sqrt(3.0) * (S_f - T_f) / 2;

        std::cout << "x1 = " << x1_f << std::endl;
        std::cout << "x2 = " << x2_f << std::endl;
        std::cout << "x3 = " << x3_f << std::endl;
        std::cout << "x4 = " << x4_f << std::endl;
    };

    void FDiscriminantNegative() {
        double x1_f = 2 * sqrt(-Q_f) * cos(theta_f) - b / 4 / a;
        double x2_f = 2 * sqrt(-Q_f) * cos(theta_f + 2 * PI / 3) - b / 4 / a;
        double x3_f = 2 * sqrt(-Q_f) * cos(theta_f + 4 * PI / 3) - b / 4 / a;

        std::cout << "x1 = " << x1_f << std::endl;
        std::cout << "x2 = " << x2_f << std::endl;
        std::cout << "x3 = " << x3_f << std::endl;
    };

    void CDiscriminantPositive() {
        double u = cbrt(-q_c / 2 + sqrt(D_c));
        double v = cbrt(-q_c / 2 - sqrt(D_c));

        double y1 = u + v;
        double y2 = -(u + v) / 2 + (u - v) * sqrt(3) / 2;
        double y3 = -(u + v) / 2 - (u - v) * sqrt(3) / 2;

        double x1 = y1 - c / (3 * b);
        double x2 = y2 - c / (3 * b);
        double x3 = y3 - c / (3 * b);

        std::cout << "x1: " << x1 << std::endl;
        std::cout << "x2: " << x2 << std::endl;
        std::cout << "x3: " << x3 << std::endl;
    };

    void CDiscriminantZero() {
        double u = cbrt(-q_c / 2);
        double v = cbrt(-q_c / 2);

        double y1 = u + v;
        double y2 = -(u + v) / 2;

        double x1 = y1 - c / (3 * b);
        double x2 = y2 - c / (3 * b);

        std::cout << "x1: " << x1 << std::endl;
        std::cout << "x2: " << x2 << std::endl;
        std::cout << "x3: " << x2 << std::endl;
    };

    void CDiscriminantNegative() {
        double theta_c = acos(-q_c / 2 * sqrt(-27 / p_c * p_c * p_c) / 2);

        double u1 = 2 * sqrt(-p_c / 3) * cos(theta_c / 3);
        double u2 = 2 * sqrt(-p_c / 3) * cos((theta_c + 2 * PI) / 3);
        double u3 = 2 * sqrt(-p_c / 3) * cos((theta_c + 4 * PI) / 3);

        double y1 = u1;
        double y2 = u2;
        double y3 = u3;

        double x1 = y1 - c / (3 * b);
        double x2 = y2 - c / (3 * b);
        double x3 = y3 - c / (3 * b);

        std::cout << "x1: " << x1 << std::endl;
        std::cout << "x2: " << x2 << std::endl;
        std::cout << "x3: " << x3 << std::endl;
    }

    void SDiscriminantPositive() {
        double x1 = (-d + sqrt(D_s)) / (2 * c);
        double x2 = (-d - sqrt(D_s)) / (2 * c);

        std::cout << "x1: " << x1 << std::endl;
        std::cout << "x2: " << x2 << std::endl;
    }

    void SDiscriminantZero() {
        double x = -d / (2 * c);

        std::cout << "x: " << x << std::endl;
    }

    void ZeroSolutions() {
        std::cout << "Решений нет." << std::endl;
    }

    //e

    void ferrari(double a, double b, double c, double d, double e);
    void cardano(double b, double c, double d, double e);
    void square(double c, double d, double e);
    void linear(double d, double e);
};

void Equation::solve(double a, double b, double c, double d, double e)
{
    return a != 0 ? ferrari(a, b, c, d, e) : (b != 0 ? cardano(b, c, d, e) : (c != 0 ? square(c, d, e) : linear(d, e)));
}

void Equation::ferrari(double a, double b, double c, double d, double e)
{
    D_f >= 0 ? FDiscriminantPositive() : FDiscriminantNegative();
}

void Equation::cardano(double b, double c, double d, double e)
{
    D_c > 0 ? CDiscriminantPositive() : (D_c == 0 ? CDiscriminantZero() : CDiscriminantNegative());
}

void Equation::square(double c, double d, double e)
{
    D_s > 0 ? SDiscriminantPositive() : (D_s == 0 ? SDiscriminantZero() : ZeroSolutions());
}

void Equation::linear(double d, double e)
{
    if (d != 0) {
        double x = -e / d;
        std::cout << "x: " << x << std::endl;
    }
    else {
        if (e == 0) {
            std::cout << "Бесконечное количество решений" << std::endl;
        }
        else {
            std::cout << "Решений нет" << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    Equation equation;

    setlocale(LC_ALL, "Russian");
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    double e = 0.0;

    std::cout << "Введите коэффициенты уравнения (ax^4 + bx^3 + cx^2 + dx + e): " << std::endl;
    std::cin >> a >> b >> c >> d >> e;

    equation.solve(a, b, c, d, e);

    return 0;
}