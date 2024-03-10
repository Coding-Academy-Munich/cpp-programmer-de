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
//  <b>Kopieren von Objekten</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 11 Kopieren von Objekten.cpp -->
// <!-- slides/module_150_classes/topic_163_copy_construction.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Kopierkonstruktor
//
// - Bisher: Konstruktion aus Werten für die Member-Variablen.
// - Wir würden gerne Objekte aus anderen Objekten konstruieren.
// - Das geht mit dem Kopierkonstruktor.

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include "print.h"

// %% tags=["alt"]
struct S2 {
    int m1;
    int m2;


    S2(int m1 = 11, int m2 = 22) : m1{m1}, m2{m2} {
        std::cout << "S2(" << m1 << ", " << m2 << ") " << addr(*this) << "\n";
    }

    S2(const S2& other) : m1{other.m1}, m2{other.m2} {
        std::cout << "S2(const S2&) " << addr(*this) << " <- " << addr(other) << "\n";
    }

    S2& operator=(const S2& other) {
        m1 = other.m1;
        m2 = other.m2;
        std::cout << "operator=(const S2&) " << addr(*this) << " <- " << addr(other) << "\n";
        return *this;
    }
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
S2 s1{2, 4};

// %% tags=["keep"]
print("S2", s1);

// %% tags=["keep"]
S2 s2{s1.m1, s1.m2};

// %% tags=["keep"]
print("S2", s2);

// %% tags=["keep"]
S2 s3{s1};

// %% tags=["keep"]
print("S2", s3);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
S2 s4{};

// %% tags=["keep"]
print("S2", s4);

// %% tags=["keep"]
s4 = s1;

// %% tags=["keep"]
print("S2", s4);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Der Kopierkonstruktor wird aufgerufen, wenn ein Objekt aus einem anderen
//   Objekt des gleichen Typs konstruiert wird.
// - Er ist durch den Parametertyp `const T&` gekennzeichnet.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Kopierzuweisungsoperator
//
// - Mit dem Kopierkonstruktor können wir definieren, wie die Konstruktion eines
//   neuen Objekts aus einem bestehenden erfolgt.
// - Das sollten wir auch für die Zuweisung von Objekten tun können.
// - Das geht mit dem Kopierzuweisungsoperator (Copy Assignment Operator).

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Der Kopierzuweisungsoperator wird aufgerufen, wenn ein Objekt einem anderen
//   zugewiesen wird.
// - Er ist durch die Signatur `T& operator=(const T&)` gekennzeichnet.
// - Er gibt eine Referenz auf das Objekt zurück, dem neue Attribut-Werte
//   zugewiesen wurden.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - In C++ können wir mehrere Zuweisungen hintereinander schreiben:

// %% tags=["keep"]
S2 s4, s5;

// %% tags=["keep"]
print("S2: s3", s3);
print("S2: s4", s4);
print("S2: s5", s5);

// %%
s5 = s4 = s3;

// %% tags=["keep"]
print("S2: s3", s3);
print("S2: s4", s4);
print("S2: s5", s5);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Der Zuweisungsoperator wird von rechts nach links ausgewertet.
// - Daher muss das Ergebnis der Zuweisung `s4 = s3` ein Objekt sein, das an
//   `s5` zugewiesen werden kann.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können auch destruktive Operationen auf dem Ergebnis einer Zuweisung
//   ausführen:

// %% tags=["keep"]
s3.m1 = 12;

// %%
++(s4 = s3).m1;

// %% tags=["keep"]
print("S2: s3", s3);
print("S2: s4", s4);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Kopierkonstruktor und Kopierzuweisungsoperator
//
// - Wann immer eine Klasse einen benutzerdefinierten Kopierkonstruktor hat
//   sollte sie auch einen benutzerdefinierten Kopierzuweisungsoperator haben,
//   und umgekehrt.
// - Sie sollte dann auch einen Destruktor haben (siehe später).

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Workshop: Kopieren von Objekten
//
// Gegeben seien die folgenden Structs `MyStruct` und `YourStruct`:

// %% tags=["keep"]
struct MyStruct {
    int ms_int;
    bool ms_bool;

    MyStruct(int ms_int = 33, bool ms_bool = true) : ms_int{ms_int}, ms_bool{ms_bool} {
        std::cout << "MyStruct(" << ms_int << ", " << ms_bool << ")\n";
    }

    void print() const {
        std::cout << "MyStruct(" << ms_int << ", " << ms_bool << ") " << addr(*this) <<"\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct YourStruct {
    int ys_int;
    MyStruct ys_ms;

    YourStruct(int ys_int, const MyStruct& ys_ms) : ys_int{ys_int}, ys_ms{ys_ms} {
        std::cout << "YourStruct(" << ys_int << ", " << ys_ms.ms_int << ", " << ys_ms.ms_bool << ")\n";
    }

    void print() const {
        std::cout << "YourStruct(" << ys_int << ", " << ys_ms.ms_int << ", " << ys_ms.ms_bool << ") "
                  << addr(*this) << "\n";
    }
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Erweitern Sie `MyStruct` und `YourStruct` um Kopierkonstruktoren und Kopierzuweisungsoperatoren.
// - Überprüfen Sie, ob die nachfolgenden Ausdrücke korrekt kompilieren und das
//   erwartete Ergebnis liefern:

// %% tags=["alt"]
struct MyStruct {
    int ms_int;
    bool ms_bool;

    MyStruct(int ms_int, bool ms_bool) : ms_int{ms_int}, ms_bool{ms_bool} {
        std::cout << "MyStruct(" << ms_int << ", " << ms_bool << ")\n";
    }

    void print() const {
        std::cout << "MyStruct(" << ms_int << ", " << ms_bool << ") " << addr(*this) <<"\n";
    }

    MyStruct(const MyStruct& other) : ms_int{other.ms_int}, ms_bool{other.ms_bool} {
        std::cout << "MyStruct(const MyStruct&)\n";
    }

    MyStruct& operator=(const MyStruct& other) {
        ms_int = other.ms_int;
        ms_bool = other.ms_bool;
        std::cout << "operator=(const MyStruct&)\n";
        return *this;
    }
};

// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
struct YourStruct {
    int ys_int;
    MyStruct ys_ms;

    YourStruct(int ys_int, const MyStruct& ys_ms) : ys_int{ys_int}, ys_ms{ys_ms} {
        std::cout << "YourStruct(" << ys_int << ", " << ys_ms.ms_int << ", " << ys_ms.ms_bool << ")\n";
    }

    void print() const {
        std::cout << "YourStruct(" << ys_int << ", " << ys_ms.ms_int << ", " << ys_ms.ms_bool << ") "
                  << addr(*this) << "\n";
    }

    YourStruct(const YourStruct& other) : ys_int{other.ys_int}, ys_ms{other.ys_ms} {
        std::cout << "YourStruct(const YourStruct&)\n";
    }

    YourStruct& operator=(const YourStruct& other) {
        ys_int = other.ys_int;
        ys_ms = other.ys_ms;
        std::cout << "operator=(const YourStruct&)\n";
        return *this;
    }
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
MyStruct ms1{1, false};
ms1.print();

// %% tags=["keep"]
MyStruct ms2{ms1};
ms2.ms_int = 2;
ms2.print();

// %% tags=["keep"]
YourStruct ys1{3, ms1};
ys1.print();

// %% tags=["keep"]
YourStruct ys2{ys1};
ys2.ys_ms.ms_int = 44;
ys2.ys_int = 4;
ys2.print();

// %% tags=["keep"]
ys1.ys_ms.ms_int = 55;
ys1.ys_int = 5;
ys1.print();
ys2.print();

// %% tags=["keep"]
ms1 = ms2;
ms1.print();

// %% tags=["keep"]
ys2 = ys1;
ys2.print();

// %% tags=["keep"]
ms1.print();
ms2.print();
ys1.print();
ys2.print();
