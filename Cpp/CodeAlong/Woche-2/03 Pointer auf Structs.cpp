// -*- coding: utf-8 -*-
// %% [markdown]
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

// %% [markdown]
//
// - Wir können auch Pointer auf komplexere Typen, wie z.B. Structs haben:


// %%
struct Point {
    double x;
    double y;
};

// %%
#include <iostream>

// %%
void print(Point p)
{
    std::cout << "Point{" << p.x << ", " << p.y << "}";
}

// %%
Point my_point{1.0, 2.0};

// %%

// %%

// %%

// %% [markdown]
//
// ## Zugriff auf Member-Variablen
//
// - Zugriff auf Member ist auch über Pointer möglich.
// - Allerdings müssen wir Klammern verwenden:

// %%

// %% [markdown]
//
// - Daher bietet C++ den Operator `->` an:

// %%

// %% [markdown]
//
// - Der Operator `->` ist eine Abkürzung für `(*pp).x`.
// - Operator `->` kann auch zur Zuweisung verwendet werden:

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: Pointer auf Structs
//
// Gegeben seien die beiden Punkte `p1` und `p2`:

// %%
Point p1{1.0, 2.0};
Point p2{3.0, 4.0};

// %% [markdown]
//
// Definieren Sie eine Variable `pp`, die auf `p1` zeigt.

// %%

// %% [markdown]
//
// Verwenden Sie `pp` um die Werte von `p1.x` und `p1.y` auf dem Bildschirm
// auszugeben.

// %%

// %% [markdown]
//
// Verwenden Sie `pp` um die Werte von `p1.x` und `p1.y` auf die Werte 10.0 und
// 20.0 zu setzen.

// %%

// %%
print(p1);
print(p2);

// %% [markdown]
//
// Verwenden Sie `pp` um die Werte von `p2.x` und `p2.y` auf die Werte 30.0 und
// 40.0 zu setzen.

// %%

// %%
print(p1);
print(p2);


