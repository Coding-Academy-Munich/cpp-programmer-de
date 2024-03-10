// -*- coding: utf-8 -*-
// ---
// jupyter:
//   jupytext:
//     text_representation:
//       extension: .cpp
//       format_name: percent
//       format_version: '1.3'
//       jupytext_version: 1.16.1
//   kernelspec:
//     display_name: C++17
//     language: C++17
//     name: xcpp17
// ---

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// <div style="text-align:center; font-size:200%;">
//  <b>Einführung in die Fehlerbehandlung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 10 Einführung in die Fehlerbehandlung.cpp -->
// <!-- slides/module_180_error_handling/topic_110_intro_error_handling.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Fehlerbehandlung
//
// Wir wollen eine Funktion `int int_sqrt(int n)` schreiben, die die
// "Ganzzahlige Wurzel" berechnet:
// - Wenn `n` eine Quadratzahl ist, also die Form `m * m` hat, dann soll `m`
//   zurückgegeben werden.
// - Was machen wir, falls `n` keine Quadratzahl ist?
// - Um Exceptions zu motivieren, besprechen wir erst zwei andere Möglichkeiten
//   Fehler zu behandeln


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können versuchen, einen "Fehlerwert" zurückzugeben, der kein gültiges
//   Ergebnis ist.
// - Hier z.B. eine negative Zahl

// %% tags=["keep"]
constexpr int error_value{-1};

// %% tags=["keep"]
int int_sqrt_with_negative_value(int n) {
    for (int m = 0; m <= n; ++m) {
        if (m * m == n) {
            return m;
        }
    }
    return error_value;
}

// %% tags=["keep"]
int_sqrt_with_negative_value(9)

// %% tags=["keep"]
int_sqrt_with_negative_value(8)


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Diese Version ist einfach zu verwenden, aber fehleranfällig:

// %% tags=["keep"]
#include <iostream>

void print_int_sqrt_1(int n)
{
    int root{int_sqrt_with_negative_value(n)};
    std::cout << "The root of " << n << " is " << root << ".\n";
}

// %% tags=["keep"]
print_int_sqrt_1(9)

// %% tags=["keep"]
print_int_sqrt_1(8)


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Code zur Fehlerbehandlung ist mit dem "Erfolgsfall" verwoben

// %% tags=["keep"]
void print_int_sqrt_1_with_error_check(int n)
{
    int root{int_sqrt_with_negative_value(n)};
    if (root == error_value) {
        std::cout << n << " does not have a root!\n";
    } else {
        std::cout << "The root of " << n << " is " << root << ".\n";
    }
}

// %% tags=["keep"]
print_int_sqrt_1_with_error_check(9)

// %% tags=["keep"]
print_int_sqrt_1_with_error_check(8)


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können auch zwei Werte zurückgeben: Ergebnis und ein Erfolg/Fehler Flag

// %% tags=["keep"]
#include <tuple>

// %% tags=["keep"]
std::tuple<int, bool> int_sqrt_with_pair(int n) {
    for (int m = 0; m <= n; ++m) {
        if (m * m == n) {
            return {m, true};
        }
    }
    return {0, false};
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
auto result{int_sqrt_with_pair(9)};

// %% tags=["keep"]
std::get<0>(result)

// %% tags=["keep"]
std::get<1>(result)

// %% tags=["keep"]
auto result{int_sqrt_with_pair(8)};

// %% tags=["keep"]
std::get<0>(result)

// %% tags=["keep"]
std::get<1>(result)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die Probleme bei dieser Lösung sind ähnlich wie bei der vorhergehenden.

// %% tags=["keep"]
void print_int_sqrt_2(int n) {
    auto [root, is_valid] = int_sqrt_with_pair(n);
    if (is_valid) {
        std::cout << "The root of " << n << " is " << root << ".\n";
    } else {
        std::cout << n << " does not have a root!\n";
    }
}

// %% tags=["keep"]
print_int_sqrt_2(9)

// %% tags=["keep"]
print_int_sqrt_2(8)


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
//  Beide Ansätze haben mehrere Probleme:
//  - Die Fehlerbehandlung ist optional. Wird sie nicht durchgeführt, so wird
//    mit einem falschen Wert weitergerechnet.
//  - Kann der Aufrufer den Fehler nicht selber behandeln, so muss der Fehler
//    über mehrere Ebenen von Funktionsaufrufen "durchgereicht" werden.
//  - Das führt zu unübersichtlichem Code, da der "interessante" Pfad nicht vom
//    Code zur Fehlerbehandlung getrennt ist.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Gewünschte Eigenschaften
//
// - Normale Programmlogik wird nicht beeinträchtigt
// - Behandlung von Fehlern wird erzwungen
// - Entdecken eines Fehlers ist entkoppelt von seiner Behandlung
// - Information über den Fehler kann leicht zum Handler kommuniziert werden
