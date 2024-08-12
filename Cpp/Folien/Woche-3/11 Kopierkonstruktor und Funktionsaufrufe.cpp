// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Kopierkonstruktor und Funktionsaufrufe</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 11 Kopierkonstruktor und Funktionsaufrufe.cpp -->
// <!-- slides/module_150_classes/topic_164_copy_and_call.cpp -->

// %% [markdown]
//
// ## Call by Value
//
// - In C++ werden Argumente per Wert übergeben
// - Dabei wird der Kopierkonstruktor aufgerufen
// - Das gilt nicht für Referenzen und Zeiger

// %%
#include <iostream>
#include "print.h"

// %%
struct S3 {
    S3() {
        std::cout << "S3() " << addr(*this) << "\n";
    }

    S3(const S3& other) {
        std::cout << "S3(const S3&) " << addr(*this) << "\n";
    }
};

// %%
S3 s;

// %%
void by_value(S3 s) {
    std::cout << "f(S3)\n";
}

// %%
by_value(s);

// %%
void by_pointer(const S3* s) {
    std::cout << "f(const S3*) " << addr(*s) << "\n";
}

// %%
by_pointer(&s);

// %%
void by_reference(const S3& s) {
    std::cout << "f(const S3&) " << addr(s) << "\n";
}

// %%
by_reference(s);

// %% [markdown]
//
// ## Standard-Kopierkonstruktor
//
// - Wenn für eine Klasse kein Kopierkonstruktor definiert ist, wird ein
//   Standard-Kopierkonstruktor generiert, wenn das möglich ist.
// - Dieser kopiert alle Member-Variablen.
// - Wenn eine Member-Variable nicht kopierbar ist, wird der
//   Standard-Kopierkonstruktor nicht generiert.
// - Ebenso für den Zuweisungsoperator.

// %% [markdown]
//
// ## Löschen des Kopierkonstruktors
//
// - Der Kopierkonstruktor kann explizit gelöscht werden.
// - Das verhindert das Kopieren von Objekten.
// - Das ist nützlich, wenn das Kopieren nicht sinnvoll ist.
// - Dann können Objekte nur per Referenz oder Zeiger übergeben werden.

// %%
struct S4 {
    S4() = default;
    S4(const S4&) = delete;
    S4& operator=(const S4&) = delete;
};

// %%
S4 s4a;
addr(s4a)

// %%
// S4 s4b{s4a};

// %%
S4 s4c;

// %%
// s4c = s4a;

// %%
void by_value(S4 s) {
    std::cout << "f(S4) " << addr(s) << "\n";
}

// %%
// by_value(s4a);

// %%
void by_pointer(const S4* s) {
    std::cout << "f(const S4*) " << addr(*s) << "\n";
}

// %%
by_pointer(&s4a);

// %%
void by_reference(const S4& s) {
    std::cout << "f(const S4&) " << addr(s) << "\n";
}

// %%
by_reference(s4a);

// %% [markdown]
//
// ## Workshop: Funktionsaufrufe
//
// Gegeben seien die folgenden Klassen und Funktionen:

// %%
struct A {
    int j{};

    A(const A&) = delete;
    A& operator=(const A&) = delete;
}

// %%
struct B {
    A a{};
    int i{};
}

// %%
void f(A a) {
    std::cout << "f(A)\n";
}

// %%
void g(B b) {
    std::cout << "g(B)\n";
}

// %% [markdown]
//
// - Welche der folgenden Variablendefinitionen sind gültig?
// - Welche der folgenden Aufrufe sind gültig?

// %%
// A a;
// B b;

// %%
// f(a);

// %%
// g(b);

// %% [markdown]
//
// - Modifizieren Sie die Klassen so, dass sich die Variablen erzeugen lassen.
// - Modifizieren Sie die Funktionen so, dass alle Aufrufe gültig sind.
//
// *Hinweis*: Sie müssen das Notebook wahrscheinlich dazu neu starten, wenn Sie
// die existierenden Definitionen bereits evaluiert haben.

// %%
struct A {
    int j{};

    A() = default;
    A(const A&) = delete;
    A& operator=(const A&) = delete;
}

// %%
struct B {
    A a{};
    int i{};
}


// %%
void f(const A& a) {
    std::cout << "f(const A&)\n";
}

// %%
void g(const B& b) {
    std::cout << "g(const B&)\n";
}

// %%
A a;
B b;

// %%
f(a);

// %%
g(b);
