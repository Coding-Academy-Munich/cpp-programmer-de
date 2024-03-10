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
//  <b>Initialisierung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 10 Initialisierung.cpp -->
// <!-- slides/module_150_classes/topic_162_initialization.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Verschiedene Konstruktoren
//
// - Einfache Struktur mit zwei Attributen
// - Verschiedene Arten der Konstruktion/Initialisierung

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include "print.h"

// %% tags=["keep"]
struct S1 {
    int m1;
    int m2;

    S1(int m1 = 11, int m2 = 22) : m1{m1}, m2{m2} {
        std::cout << "S1(" << m1 << ", " << m2 << ")\n";
    }
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
S1 s1;
print("S1", s1);

// %%
// S1 s2();

// %%
S1 s3(5);
print("S1", s3);

// %%
S1 s4(5.6);
print("S1", s4);

// %%
S1 s5(5, 10);
print("S1", s5);

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
S1 s6{};
print("S1", s6);

// %%
S1 s7{5};
print("S1", s7);

// %%
// S1 s8{5.6};

// %%
S1 s9{5, 10};
print("S1", s9);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Workshop: Initialisierung
//
// Gegeben die folgende Struct:

// %% tags=["keep"]
#include <iostream>
#include <iomanip>

// %% tags=["keep"]
struct MyStruct {
    int my_int;
    double my_double;
    bool my_bool;

    MyStruct(int i, double d, bool b) : my_int{i}, my_double{d}, my_bool{b} {}

    void print() {
        // std::cout << std::boolalpha;
        std::cout << "MyStruct{" << my_int << ", " << my_double << ", " << my_bool << "}\n";
    }
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Welche der folgenden Initialisierungen sind gültig?
// - Was sind danach die Werte der Member-Variablen?

// %% tags=["keep"]
// MyStruct ms1{1, 2.3, true};
// ms1.print();

// %% tags=["keep"]
// MyStruct ms2(1, 2.3, true);
// ms2.print();

// %% tags=["keep"]
// MyStruct ms3{1, 2, true};
// ms3.print();

// %% tags=["keep"]
// MyStruct ms4(1, 2, true);
// ms4.print();

// %% tags=["keep"]
// MyStruct ms5{1.0, 2.3, true};
// ms5.print();

// %% tags=["keep"]
// MyStruct ms6(1.0, 2.3, true);
// ms6.print();

// %% tags=["keep"]
// MyStruct ms7{1, 2.3, 3};
// ms7.print();

// %% tags=["keep"]
// MyStruct ms8(1, 2.3, 3);
// ms8.print();

// %% tags=["keep"]
// MyStruct ms9{1, 2.3, 0.0};
// ms9.print();

// %% tags=["keep"]
// MyStruct ms10(1, 2.3, 0.0);
// ms10.print();

// %% tags=["keep"]
// MyStruct ms11{"foo", 2, true};
// ms11.print();

// %% tags=["keep"]
// MyStruct ms12("foo", 2, true);
// ms12.print();
