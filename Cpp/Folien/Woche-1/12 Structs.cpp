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
//  <b>Structs</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 Structs.cpp -->
// <!-- slides/module_120_basics/topic_170_structs.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Structs
//
// - Wir behandeln die `x` und `y` Koordinaten von Punkten als unabhängige Werte.
// - Es wäre besser sie zusammenzufassen.
// - Das können wir mit Structs (oder Klassen):

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
struct Point {
    double x{};
    double y{};
}

// %%
Point{1.0, 2.0}

// %%
Point p{1.0, 2.0}

// %%
p.x

// %%
p.y

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Structs sind Datentypen, die aus mehreren Attributen bestehen.
// - Die Attribute können unterschiedliche Typen haben.
// - Structs können wie die eingebauten Datentypen verwendet werden:
//  - Wir können Variablen vom Typ `Point` deklarieren.
//  - Wir können `Point`-Objekte erzeugen.
//  - Wir können Structs als Parameter und Rückgabetypen von Funktionen verwenden.
// - Wir können auf die Attribute zugreifen.

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## `Point` als Funktionsparameter
//
// - Wir können Structs als Parameter von Funktionen verwenden:

// %%
#include <iostream>
void print(Point p)
{
    std::cout << "Point{" << p.x << ", " << p.y << "}";
}

// %%
print(p)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Damit können wir das Interface der `distance()`-Funktion verbessern:

// %%
double distance(Point p1, Point p2)
{
    double dx{p2.x - p1.x};
    double dy{p2.y - p1.y};
    return sqrt(dx * dx + dy * dy);
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
Point p1{1.0, 2.0};
Point p2{4.0, 6.0};

// %%
distance(p1, p2)

// %%
distance(Point{1.0, 2.0}, Point{3.0, 4.0})

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Verändern von Attributen
//
// - Wir können die Werte von Attributen durch Zuweisung verändern.
// - Um das Attribut `x` von `p` zu verändern schreiben wir `p.x` auf die linke
//   Seite einer Zuweisung:

// %%
Point p{0.0, 0.0};

// %%
print(p);

// %%
p.x = 10.0;

// %%
print(p);

// %%
p.y = 20.0;
print(p);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Structs als Argumente
//
// - Funktionsargumente werden als Werte übergeben (d.h., kopiert).
// - Änderungen in der Funktion habe keine Auswirkung auf den übergebenen Wert.
// - Wir werden später sehen, wie wir das ändern können.

// %%
void does_it_change(Point p)
{
    p.x = 2.0 * p.x + 1.0;
    p.y = 3.0 * p.y + 2.0;
    print(p);
}

// %%
print(p);

// %%
does_it_change(p);

// %%
print(p);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Fläche eines Rechtecks
//
// In diesem Workshop wollen wir ein Programm schreiben, das die Fläche eines
// Rechtecks unter Verwendung von C++ Structs berechnet.
//
// Definieren Sie eine Struct `Rectangle`, die die Länge (`length`) und Breite
// (`width`) speichert.
//
// Implementieren Sie eine Funktion `area()`, die ein `Rectangle` als Parameter
// entgegennimmt und die Fläche des Rechtecks berechnet. Die Fläche eines
// Rechtecks wird mit der Formel `Fläche = Länge * Breite` berechnet.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Schreiben Sie ein Programm, das folgende Schritte ausführt:
//
// 1. Einlesen der Länge und Breite eines Rechtecks von der Konsole.
// 2. Speichern der eingelesenen Werte in einer Instanz des `Rectangle`-Structs.
// 3. Berechnen der Fläche des Rechtecks mit der Funktion `area()`.
// 4. Ausgeben der berechneten Fläche.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %%
struct Rectangle {
    double length{};
    double width{};
};

// %%
double area(Rectangle r)
{
    return r.length * r.width;
}

// %% lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
Rectangle r{};
std::cout << "Länge: ";
// std::cin >> r.length;
std::cout << "Breite: ";
// std::cin >> r.width;
std::cout << "Fläche: " << area(r) << "\n";
