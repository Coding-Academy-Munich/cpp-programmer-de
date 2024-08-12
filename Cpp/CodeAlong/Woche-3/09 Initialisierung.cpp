// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Initialisierung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Initialisierung.cpp -->
// <!-- slides/module_150_classes/topic_162_initialization.cpp -->

// %% [markdown]
//
// ## Verschiedene Konstruktoren
//
// - Einfache Struktur mit zwei Attributen
// - Verschiedene Arten der Konstruktion/Initialisierung

// %%
#include <iostream>
#include "print.h"

// %%
struct S1 {
    int m1;
    int m2;

    S1(int m1 = 11, int m2 = 22) : m1{m1}, m2{m2} {
        std::cout << "S1(" << m1 << ", " << m2 << ")\n";
    }
}

// %%
S1 s1;
print("S1", s1);

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Workshop: Initialisierung
//
// Gegeben die folgende Struct:

// %%
#include <iostream>
#include <iomanip>

// %%
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

// %% [markdown]
//
// - Welche der folgenden Initialisierungen sind gültig?
// - Was sind danach die Werte der Member-Variablen?

// %%
// MyStruct ms1{1, 2.3, true};
// ms1.print();

// %%
// MyStruct ms2(1, 2.3, true);
// ms2.print();

// %%
// MyStruct ms3{1, 2, true};
// ms3.print();

// %%
// MyStruct ms4(1, 2, true);
// ms4.print();

// %%
// MyStruct ms5{1.0, 2.3, true};
// ms5.print();

// %%
// MyStruct ms6(1.0, 2.3, true);
// ms6.print();

// %%
// MyStruct ms7{1, 2.3, 3};
// ms7.print();

// %%
// MyStruct ms8(1, 2.3, 3);
// ms8.print();

// %%
// MyStruct ms9{1, 2.3, 0.0};
// ms9.print();

// %%
// MyStruct ms10(1, 2.3, 0.0);
// ms10.print();

// %%
// MyStruct ms11{"foo", 2, true};
// ms11.print();

// %%
// MyStruct ms12("foo", 2, true);
// ms12.print();
