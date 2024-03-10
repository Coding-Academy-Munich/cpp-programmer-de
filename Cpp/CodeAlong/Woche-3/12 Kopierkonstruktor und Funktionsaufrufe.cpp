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
//  <b>Kopierkonstruktor und Funktionsaufrufe</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 Kopierkonstruktor und Funktionsaufrufe.cpp -->
// <!-- slides/module_150_classes/topic_164_copy_and_call.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Call by Value
//
// - In C++ werden Argumente per Wert übergeben
// - Dabei wird der Kopierkonstruktor aufgerufen
// - Das gilt nicht für Referenzen und Zeiger

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include "print.h"

// %% tags=["keep"]
struct S3 {
    S3() {
        std::cout << "S3() " << addr(*this) << "\n";
    }

    S3(const S3& other) {
        std::cout << "S3(const S3&) " << addr(*this) << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
S3 s;

// %% tags=["keep"]
void by_value(S3 s) {
    std::cout << "f(S3)\n";
}

// %%

// %% tags=["keep"]
void by_pointer(const S3* s) {
    std::cout << "f(const S3*) " << addr(*s) << "\n";
}

// %%

// %% tags=["keep"]
void by_reference(const S3& s) {
    std::cout << "f(const S3&) " << addr(s) << "\n";
}

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Standard-Kopierkonstruktor
//
// - Wenn für eine Klasse kein Kopierkonstruktor definiert ist, wird ein
//   Standard-Kopierkonstruktor generiert, wenn das möglich ist.
// - Dieser kopiert alle Member-Variablen.
// - Wenn eine Member-Variable nicht kopierbar ist, wird der
//   Standard-Kopierkonstruktor nicht generiert.
// - Ebenso für den Zuweisungsoperator.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Löschen des Kopierkonstruktors
//
// - Der Kopierkonstruktor kann explizit gelöscht werden.
// - Das verhindert das Kopieren von Objekten.
// - Das ist nützlich, wenn das Kopieren nicht sinnvoll ist.
// - Dann können Objekte nur per Referenz oder Zeiger übergeben werden.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct S4 {
    S4() = default;
    S4(const S4&) = delete;
    S4& operator=(const S4&) = delete;
};

// %% tags=["keep"]
S4 s4a;
addr(s4a)

// %% tags=["keep"]
// S4 s4b{s4a};

// %% tags=["keep"]
S4 s4c;

// %% tags=["keep"]
// s4c = s4a;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void by_value(S4 s) {
    std::cout << "f(S4) " << addr(s) << "\n";
}

// %%

// %% tags=["keep"]
void by_pointer(const S4* s) {
    std::cout << "f(const S4*) " << addr(*s) << "\n";
}

// %%

// %% tags=["keep"]
void by_reference(const S4& s) {
    std::cout << "f(const S4&) " << addr(s) << "\n";
}

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Workshop: Funktionsaufrufe
//
// Gegeben seien die folgenden Klassen und Funktionen:

// %% tags=["keep"]
struct A {
    int j{};

    A(const A&) = delete;
    A& operator=(const A&) = delete;
}

// %% tags=["keep"]
struct B {
    A a{};
    int i{};
}

// %% tags=["keep"]
void f(A a) {
    std::cout << "f(A)\n";
}

// %% tags=["keep"]
void g(B b) {
    std::cout << "g(B)\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Welche der folgenden Variablendefinitionen sind gültig?
// - Welche der folgenden Aufrufe sind gültig?

// %% tags=["keep"]
// A a;
// B b;

// %% tags=["keep"]
// f(a);

// %% tags=["keep"]
// g(b);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Modifizieren Sie die Klassen so, dass sich die Variablen erzeugen lassen.
// - Modifizieren Sie die Funktionen so, dass alle Aufrufe gültig sind.
//
// *Hinweis*: Sie müssen das Notebook wahrscheinlich dazu neu starten, wenn Sie
// die existierenden Definitionen bereits evaluiert haben.

// %% tags=["start"]
struct A {
    int j{};

    A(const A&) = delete;
    A& operator=(const A&) = delete;
}


// %% tags=["keep"]
struct B {
    A a{};
    int i{};
}


// %% tags=["start"]
void f(A a) {
    std::cout << "f(A)\n";
}

// %% tags=["start"]
void g(B b) {
    std::cout << "g(B)\n";
}

// %% tags=["keep"]
A a;
B b;

// %% tags=["keep"]
f(a);

// %% tags=["keep"]
g(b);
