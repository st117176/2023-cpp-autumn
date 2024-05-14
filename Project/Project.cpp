#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <regex>

class Equation {
public:

    Equation(double a, double b, double c, double d, double e) : a(a), b(b), c(c), d(d), e(e) {}

    ~Equation()
    {
        a = b = c = d = e = p_f = q_f = r_f = Q_f = R_f = D_f = S_f = T_f = theta_f = p_c = q_c = D_c = D_s = 0;
    }

    Equation(const Equation&& other) noexcept : a(other.a), b(other.b), c(other.c), d(other.d), e(other.e) {}

    void solve(double a, double b, double c, double d, double e);

private:
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    double e = 0.0;

    double p_f = (-3 * b * b) / (8 * a * a) + c / a;
    double q_f = b * b * b / (8 * a * a * a) - b * c / (2 * a * a) + d / a;
    double r_f = (-3 * b * b * b * b) / (256 * a * a * a * a) + b * b * c / (16 * a * a * a) - b * d / (4 * a * a) + e / a;

    double Q_f = (3 * q_f - p_f * p_f) / 9;
    double R_f = (9 * p_f * q_f - 27 * r_f - 2 * p_f * p_f * p_f) / 54;
    double D_f = Q_f * Q_f * Q_f + R_f * R_f;

    double S_f = pow(R_f + sqrt(D_f), 1.0 / 3);
    double T_f = pow(R_f - sqrt(D_f), 1 / 3);

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
        double gamma1 = cbrt(q_c + sqrt(D_c));
        double gamma2 = cbrt(q_c - sqrt(D_c));
        double offset = c / (3 * b);

        std::cout << "x1: " << gamma1 + gamma2 - offset << '\n';

        double re = -0.5 * (gamma1 + gamma2) - offset;
        double im = 0.5 * (gamma1 - gamma2) * sqrt(3.0);

        if (D_c == 0.0) {
            std::cout << "x2: " << re << '\n';
            std::cout << "x3: " << re << '\n';
        }
        else {
            std::cout << "x2: " << re << " + " << im << "i\n";
            std::cout << "x3: " << re << " - " << im << "i\n";
        }
    };

    void CDiscriminantNegative() {
        double offset = c / (3 * b);
        double theta_c = acos(q_c / (p_c * sqrt(p_c)));
        double r_c = 2 * sqrt(p_c);
        for (int n = 0; n < 3; ++n) {
            std::cout << "x: " << r_c * cos((theta_c + 2 * n * PI) / 3) - offset << '\n';
        }
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

    void ferrari(double a, double b, double c, double d, double e);

    void cardano(double b, double c, double d, double e);

    void square(double c, double d, double e);

    void linear(double d, double e);
};

void Equation::solve(double a, double b, double c, double d, double e) {
    return a != 0 ? ferrari(a, b, c, d, e) : (b != 0 ? cardano(b, c, d, e) : (c != 0 ? square(c, d, e) : linear(d, e)));
}

void Equation::ferrari(double a, double b, double c, double d, double e) {
    D_f >= 0 ? FDiscriminantPositive() : FDiscriminantNegative();
}

void Equation::cardano(double b, double c, double d, double e) {
    D_c > 0 ? CDiscriminantPositive() : CDiscriminantNegative();
}

void Equation::square(double c, double d, double e) {
    D_s > 0 ? SDiscriminantPositive() : (D_s == 0 ? SDiscriminantZero() : ZeroSolutions());
}

void Equation::linear(double d, double e) {
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

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");

    std::ifstream file("equation.txt");
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }
    std::string line;
    std::getline(file, line);
    file.close();

    std::regex coeff_regex(R"(([-+]?)(\d*\.?\d*)\*?x(?:\^(\d+))?|([-+]?\d+\.?\d*))");

    std::smatch matches;
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    double e = 0;

    std::string::const_iterator searchStart(line.cbegin());
    while (std::regex_search(searchStart, line.cend(), matches, coeff_regex)) {
        int sign = (matches[1].matched && matches[1] == "-") ? -1 : 1;
        double coeff = matches[2].matched ? (matches[2].length() == 0 ? 1 : std::stod(matches[2])) : std::stod(matches[0]);
        int power = matches[3].matched ? std::stod(matches[3]) : (matches[2].matched ? 1 : 0);
        coeff *= sign;
        switch (power) {
        case 4: a = coeff; break;
        case 3: b = coeff; break;
        case 2: c = coeff; break;
        case 1: d = coeff; break;
        case 0: e = std::stod(matches[4]); break;
        default: break;
        }

        searchStart = matches.suffix().first;
    }

    std::cout << "Коэффициенты: a = " << a
        << ", b = " << b
        << ", c = " << c
        << ", d = " << d
        << ", e = " << e << std::endl;

    auto equation = new Equation(a, b, c, d, e);
    equation->solve(a, b, c, d, e);

    delete equation;

    return 0;
}