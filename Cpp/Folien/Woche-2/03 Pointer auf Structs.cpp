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
//  <b>Pointer auf Structs</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Pointer auf Structs.cpp -->
// <!-- slides/module_130_pointers/topic_130_pointers_to_struct.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können auch Pointer auf komplexere Typen, wie z.B. Structs haben:


// %% tags=["keep"]
struct Point {
    double x;
    double y;
};

// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
void print(Point p)
{
    std::cout << "Point{" << p.x << ", " << p.y << "}";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Point my_point{1.0, 2.0};

// %%
Point* pp{&my_point};

// %%
pp

// %%
print(*pp);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Zugriff auf Member-Variablen
//
// - Zugriff auf Member ist auch über Pointer möglich.
// - Allerdings müssen wir Klammern verwenden:

// %%
(*pp).x

// %% [markdown] lang="de"
//
// - Daher bietet C++ den Operator `->` an:

// %%
pp->x

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Der Operator `->` ist eine Abkürzung für `(*pp).x`.
// - Operator `->` kann auch zur Zuweisung verwendet werden:

// %%
pp->x = 3.0;

// %%
print(*pp);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Pointer auf Structs
//
// Gegeben seien die beiden Punkte `p1` und `p2`:

// %% tags=["keep"]
Point p1{1.0, 2.0};
Point p2{3.0, 4.0};

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Definieren Sie eine Variable `pp`, die auf `p1` zeigt.

// %%
Point* pp{&p1};

// %% [markdown] lang="de"
//
// Verwenden Sie `pp` um die Werte von `p1.x` und `p1.y` auf dem Bildschirm
// auszugeben.

// %%
std::cout << pp->x << ", " << pp->y << "\n";

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Verwenden Sie `pp` um die Werte von `p1.x` und `p1.y` auf die Werte 10.0 und
// 20.0 zu setzen.

// %%
pp->x = 10.0;
pp->y = 20.0;

// %% tags=["keep"]
print(p1);
print(p2);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Verwenden Sie `pp` um die Werte von `p2.x` und `p2.y` auf die Werte 30.0 und
// 40.0 zu setzen.

// %%
pp = &p2;
pp->x = 30.0;
pp->y = 40.0;

// %% tags=["keep"]
print(p1);
print(p2);


