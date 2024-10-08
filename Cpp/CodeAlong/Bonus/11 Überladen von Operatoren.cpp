// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Überladen von Operatoren</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 11 Überladen von Operatoren.cpp -->
// <!-- slides/module_190_standard_library/topic_135_operator_overloading.cpp -->

// %% [markdown]
//
// - Wir haben gesehen, dass man in C++ Funktionen überladen kann:

// %%
#include <iostream>

// %%
void f(int i) { std::cout << "f(int): " << i << "\n"; }

// %%
void f(double d) { std::cout << "f(double): " << d << "\n"; }

// %%
f(1);
f(1.0);

// %% [markdown]
//
// Viele Operatoren in C++ werden durch Funktionen implementiert, die überladen
// werden können:

// %%
namespace frac {
struct Fraction
{
    int numerator;
    int denominator;
};
}

// %%
namespace frac {
} // namespace frac

// %%
frac::Fraction half{1, 2};
frac::Fraction third{1, 3};

// %%
frac::Fraction result{third * half};

// %%
std::cout << result.numerator << "/" << result.denominator << "\n";

// %% [markdown]
//
// Welche Operatoren können überladen werden?
//
// - [Viele!](https://en.cppreference.com/w/cpp/language/operators)
//   - Unäre Operatoren: `+`, `-`, `*`, `&`, `!`, `~`, `++`, `--`, ...
//   - Binäre Operatoren: `+`, `-`, `&`, `<<`,`==`, `!=`, `<`, `=`, `+=`, `->`, ...
//   - Funktionsaufruf- und Indexoperator: `()`, `[]`
//   - Allokationssoperatoren: `new`, `new[]`, `delete`, `delete[]`
//   - Typkonvertierungsoperatoren: `T()`
// - Wichtige Ausnahmen:
//   - Member-Zugriff: `.` (Keine Smart-References oder Properties!)
//   - Gültigkeitsbereichsoperator: `::`

// %% [markdown]
//
// ## Definition von Operatoren
//
// - Operatoren können als Member-Funktionen oder als freie Funktionen
//   definiert werden
// - `=`, `->`, `()` und `[]` müssen als Member-Funktionen definiert werden
// - Die anderen Operatoren werden typischerweise als freie Funktionen
//   definiert
//   - Oft als `friend`-Funktionen, um Zugriff auf private Member zu haben

// %% [markdown]
//
// ## Beispiel: Polynome
//
// Wir wollen eine Klasse für Polynome der Form
//
// $$p(x) = a_0 + a_1 x + a_2 x^2 + \ldots + a_n x^n$$
//
// implementieren.
//
// - Die Koeffizienten $a_i$ sollen als `std::vector<double>` gespeichert
//   werden
// - Wir wollen den Funktionsaufruf-Operator `()` überladen, um Polynome
//   auswerten zu können
// - Wir wollen den Ausgabeoperator `<<` überladen, um Polynome ausgeben zu
//   können

// %%
#include <iostream>
#include <vector>

// %%
namespace poly {
    class Polynomial;
}

// %%
namespace poly {
Polynomial::Polynomial(std::vector<double> coefficients)
    : coefficients_{std::move(coefficients)}
{
    if (coefficients_.empty()) {
        throw std::invalid_argument{"Polynomial must have at least one coefficient"};
    }
    if (coefficients_.size() > 1 && coefficients_.back() == 0.0) {
        throw std::invalid_argument{"Leading coefficient must not be zero"};
    }
}
} // namespace poly

// %%
namespace poly {
double Polynomial::operator()(double x) const
{
    double result{0};
    double power_of_x{1};
    for (const auto coeff : coefficients_) {
        result += coeff * power_of_x;
        power_of_x *= x;
    }
    return result;
}
} // namespace poly

// %%
namespace poly {
void write_single_term(std::ostream& os, double coeff, int power, bool is_last_term)
{
    if (coeff != 0.0) {
        if (power == 0) {
            os << coeff;
        }
        else if (power == 1) {
            os << coeff << "x";
        }
        else {
            os << coeff << "x^" << power;
        }
        if (!is_last_term) {
            os << " + ";
        }
    }
    else if (is_last_term) {
        os << "0";
    }
}
} // namespace poly

// %%
namespace poly {
std::ostream& operator<<(std::ostream& os, const Polynomial& p)
{
    int power{0};
    for (auto coeff : p.coefficients_) {
        bool is_last_term{power == p.coefficients_.size() - 1};
        write_single_term(os, coeff, power, is_last_term);
        ++power;
    }
    return os;
}
} // namespace poly

// %%
#include <algorithm>

namespace poly {
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
    auto [smaller_size, larger_size]{
        std::minmax(lhs.coefficients_.size(), rhs.coefficients_.size())};

    std::vector<double> coefficients;
    coefficients.reserve(larger_size);

    for (std::size_t i{0}; i < smaller_size; ++i) {
        coefficients.push_back(lhs.coefficients_[i] + rhs.coefficients_[i]);
    }

    const auto& larger_poly{
        lhs.coefficients_.size() > rhs.coefficients_.size() ? lhs : rhs};
    for (std::size_t i{smaller_size}; i < larger_size; ++i) {
        coefficients.push_back(larger_poly.coefficients_[i]);
    }
    return Polynomial{coefficients};
}
} // namespace poly

// %%
poly::Polynomial p1({1, 2, 0, 4, 3});

// %%

// %%

// %%
poly::Polynomial p2({1, 2, 3});

// %%

// %%

// %%
poly::Polynomial zero({0.0});
poly::Polynomial one({1.0});

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: Komplexe Zahlen
//
// In diesem Workshop implementieren Sie eine Klasse für komplexe Zahlen.
//
// Komplexe Zahlen kann man als Paar zweier `double`-Werte darstellen:
// - Einen Realteil $x$
// - Einen Imaginärteil $y$
// - Man schreibt eine solche Zahl dann als $x + yi$

// %% [markdown]
//
// Die Rechenoperationen auf komplexen Zahlen sind wie folgt definiert:
// - Addition: $(x + yi) + (u + vi) = (x + u) + (y + v)i$
// - Subtraktion: $(x + yi) - (u + vi) = (x - u) + (y - v)i$
// - Multiplikation: $(x + yi) \cdot (u + vi) = (xu - yv) + (xv + yu)i$

// %% [markdown]
//
// Implementieren Sie die Klasse `Complex` mit:
// - Member-Variablen `real_` und `imag_`
// - Einen Konstruktor, der Real- und Imaginärteil als Argumente nimmt
// - Methoden `real()` und `imag()`, die Real- und Imaginärteil zurückgeben


// %%

// %%

// %%

// %% [markdown]
//
// Implementieren Sie für die Klasse `Complex`:
//
// - Operatoren für `+`, `-` und `*`
// - Einen Ausgabeoperator `<<`
// - Optional: Operatoren für `==` und `!=`// - Operators for `+`, `-` and `*`
//
// Müssen Sie die Operatoren als Friend-Funktionen implementieren?

// %%

// %% [markdown]
// *Antwort:* 

// %%

// %%

// %%

// %%

// %%
