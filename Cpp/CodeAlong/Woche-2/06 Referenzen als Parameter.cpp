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
//  <b>Referenzen als Parameter</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Referenzen als Parameter.cpp -->
// <!-- slides/module_130_pointers/topic_200_reference_args.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Referenzen als Funktionsparameter
//
// - Referenzen können als Funktionsparameter verwendet werden.
// - Damit sparen wir uns das Kopieren von Objekten.
// - Wenn wir das übergebene Objekt nicht verändern wollen, verwenden wir eine
//   Referenz auf Const.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - [CG: F.16: For "in" parameters, pass cheaply-copied types by value and
//   others by reference to
//   `const`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f16-for-in-parameters-pass-cheaply-copied-types-by-value-and-others-by-reference-to-const)
// - [CG: F.60: Prefer `T*` over `T&` when "no argument" is a valid
//   option](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f60-prefer-t-over-t-when-no-argument-is-a-valid-option)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wenn wir ein Argument verändern wollen, verwenden wir eine
//   (nicht-konstante) Referenz.

// %% tags=["keep"]
#include <iostream>

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wenn eine Funktion Argumente als Referenz erwartet, können wir keine
//   Konstanten oder temporären Objekte übergeben.
// - Const Referenzen können hingegen auf Konstanten und temporäre Objekte
//   verweisen

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Konstante Referenzen können nicht an Funktionen übergeben werden, die
//   Referenzen auf nicht konstante Objekte erwarten:

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Es ist üblich, Structs als Referenz auf const zu übergeben.

// %% tags=["keep"]
struct Point {
    double x;
    double y;
};

// %%

// %% tags=["keep"]
Point p{1.0, 2.0};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Abstand zwischen Punkten
//
// - Schreiben Sie eine Funktion `distance`, die den Abstand zwischen zwei
//   Punkten berechnet.
// - Übergeben Sie die Punkte als Referenz auf const.

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <cmath>

// %% tags=["keep"]
Point p1{1.0, 2.0};
Point p2{4.0, 6.0};

// %%

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Vertauschen von Werten
//
// Schreiben Sie eine Funktion `swap()`, die zwei `int`-Werte vertauscht.
// - Übergeben Sie die Werte als Referenz.
// - Testen Sie die Funktion.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["keep"]
int a{1};
int b{2};

// %% tags=["keep"]
std::cout << "a = " << a << ", b = " << b << "\n";

// %% lang="de" tags=["start"]
// Fügen Sie hier den Aufruf von `swap()` ein.

// %% tags=["keep"]
std::cout << "a = " << a << ", b = " << b << "\n";

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Schreiben Sie eine Funktion `swap()`, die zwei `Point`-Werte vertauscht.
// - Schreiben Sie eine Funktion `swap_coordinates()`, die die `x`- und
//   `y`-Koordinaten eines `Point`-Werts vertauscht.
// - Übergeben Sie die Werte als Referenz.
// - Testen Sie die Funktionen.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["keep"]
Point p1{1.0, 2.0};
Point p2{3.0, 4.0};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
print(p1);
std::cout << "\n";
print(p2);

// %% lang="de" tags=["start"]
// Fügen Sie hier den Aufruf von `swap()` ein.

// %% tags=["keep"]
print(p1);
std::cout << "\n";
print(p2);

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["keep"]
print(p1);

// %% lang="de" tags=["start"]
// Fügen Sie hier den Aufruf von `swap_coordinates()` ein.

// %% tags=["keep"]
print(p1);
