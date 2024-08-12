// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Referenzen als Parameter</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Referenzen als Parameter.cpp -->
// <!-- slides/module_130_pointers/topic_200_reference_args.cpp -->

// %% [markdown]
//
// ## Referenzen als Funktionsparameter
//
// - Referenzen können als Funktionsparameter verwendet werden.
// - Damit sparen wir uns das Kopieren von Objekten.
// - Wenn wir das übergebene Objekt nicht verändern wollen, verwenden wir eine
//   Referenz auf Const.

// %%

// %%

// %%

// %%

// %%


// %% [markdown]
//
// - [CG: F.16: For "in" parameters, pass cheaply-copied types by value and
//   others by reference to
//   `const`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f16-for-in-parameters-pass-cheaply-copied-types-by-value-and-others-by-reference-to-const)
// - [CG: F.60: Prefer `T*` over `T&` when "no argument" is a valid
//   option](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f60-prefer-t-over-t-when-no-argument-is-a-valid-option)

// %% [markdown]
//
// - Wenn wir ein Argument verändern wollen, verwenden wir eine
//   (nicht-konstante) Referenz.

// %%
#include <iostream>

// %%

// %%

// %%

// %%

// %%


// %% [markdown]
//
// - Wenn eine Funktion Argumente als Referenz erwartet, können wir keine
//   Konstanten oder temporären Objekte übergeben.
// - Const Referenzen können hingegen auf Konstanten und temporäre Objekte
//   verweisen

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Konstante Referenzen können nicht an Funktionen übergeben werden, die
//   Referenzen auf nicht konstante Objekte erwarten:

// %%


// %% [markdown]
//
// - Es ist üblich, Structs als Referenz auf const zu übergeben.

// %%
struct Point {
    double x;
    double y;
};

// %%

// %%
Point p{1.0, 2.0};

// %%

// %% [markdown]
//
// ## Mini-Workshop: Abstand zwischen Punkten
//
// - Schreiben Sie eine Funktion `distance`, die den Abstand zwischen zwei
//   Punkten berechnet.
// - Übergeben Sie die Punkte als Referenz auf const.

// %%
#include <cmath>

// %%
Point p1{1.0, 2.0};
Point p2{4.0, 6.0};

// %%

// %%


// %% [markdown]
//
// ## Mini-Workshop: Vertauschen von Werten
//
// Schreiben Sie eine Funktion `swap()`, die zwei `int`-Werte vertauscht.
// - Übergeben Sie die Werte als Referenz.
// - Testen Sie die Funktion.

// %%

// %%
int a{1};
int b{2};

// %%
std::cout << "a = " << a << ", b = " << b << "\n";

// %%
// Fügen Sie hier den Aufruf von `swap()` ein.

// %%
std::cout << "a = " << a << ", b = " << b << "\n";

// %% [markdown]
//
// - Schreiben Sie eine Funktion `swap()`, die zwei `Point`-Werte vertauscht.
// - Schreiben Sie eine Funktion `swap_coordinates()`, die die `x`- und
//   `y`-Koordinaten eines `Point`-Werts vertauscht.
// - Übergeben Sie die Werte als Referenz.
// - Testen Sie die Funktionen.

// %%

// %%
Point p1{1.0, 2.0};
Point p2{3.0, 4.0};

// %%
print(p1);
std::cout << "\n";
print(p2);

// %%
// Fügen Sie hier den Aufruf von `swap()` ein.

// %%
print(p1);
std::cout << "\n";
print(p2);

// %%

// %%
print(p1);

// %%
// Fügen Sie hier den Aufruf von `swap_coordinates()` ein.

// %%
print(p1);
