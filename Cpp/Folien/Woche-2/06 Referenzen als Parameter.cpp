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
#include <iostream>

// %%
void pass_by_const_reference(const int& i)
{
    std::cout << "pass_by_const_reference: " << i << '\n';
}

// %%
int i{1};
int& ri{i};

// %%
pass_by_const_reference(i);

// %%
pass_by_const_reference(ri);


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
void pass_by_reference(int& i)
{
    ++i;
    std::cout << "pass_by_reference: " << i << '\n';
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
pass_by_reference(i);

// %%
i

// %%
pass_by_reference(ri);

// %%
i


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wenn eine Funktion Argumente als Referenz erwartet, können wir keine
//   Konstanten oder temporären Objekte übergeben.
// - Const Referenzen können hingegen auf Konstanten und temporäre Objekte
//   verweisen

// %%
// pass_by_reference(1);

// %%
// pass_by_reference(1 + 2);

// %%
pass_by_const_reference(1);

// %%
pass_by_const_reference(1 + 2);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Konstante Referenzen können nicht an Funktionen übergeben werden, die
//   Referenzen auf nicht konstante Objekte erwarten:

// %%
// pass_by_reference(cri);


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Es ist üblich, Structs als Referenz auf const zu übergeben.

// %% tags=["keep"]
struct Point {
    double x;
    double y;
};

// %%
void print(const Point& p)
{
    std::cout << "Point{" << p.x << ", " << p.y << "}";
}

// %% tags=["keep"]
Point p{1.0, 2.0};

// %%
print(p);

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
double distance(const Point& p1, const Point& p2)
{
    double dx{p2.x - p1.x};
    double dy{p2.y - p1.y};
    return std::sqrt(dx * dx + dy * dy);
}

// %%
distance(p1, p2);


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Vertauschen von Werten
//
// Schreiben Sie eine Funktion `swap()`, die zwei `int`-Werte vertauscht.
// - Übergeben Sie die Werte als Referenz.
// - Testen Sie die Funktion.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
void swap(int& a, int& b)
{
    int tmp{a};
    a = b;
    b = tmp;
}

// %% tags=["keep"]
int a{1};
int b{2};

// %% tags=["keep"]
std::cout << "a = " << a << ", b = " << b << "\n";

// %% tags=["alt"]
swap(a, b);

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
void swap(Point& a, Point& b)
{
    Point tmp{a};
    a = b;
    b = tmp;
}

// %% tags=["keep"]
Point p1{1.0, 2.0};
Point p2{3.0, 4.0};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
print(p1);
std::cout << "\n";
print(p2);

// %% tags=["alt"]
swap(p1, p2);

// %% tags=["keep"]
print(p1);
std::cout << "\n";
print(p2);

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
void swap_coordinates(Point& p)
{
    double tmp{p.x};
    p.x = p.y;
    p.y = tmp;
}

// %% tags=["keep"]
print(p1);

// %% tags=["alt"]
swap_coordinates(p1);

// %% tags=["keep"]
print(p1);
