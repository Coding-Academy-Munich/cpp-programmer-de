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
//  <b>Parameter (Teil 1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Parameter (Teil 1).cpp -->
// <!-- slides/module_120_basics/topic_184_parameters_1.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Übergabe von Parametern
//
// - In C++ werden die meisten Objekte standardmäßig *by value* übergeben.
// - Das bedeutet, dass eine Kopie des Objekts an die Funktion übergeben wird.

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %%

// %% tags=["keep"]
int arg{1};
arg

// %%

// %%


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/call-01.png" width="30%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/call-02.png" width="50%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/call-03.png" width="50%">


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Das gilt auch für Structs und Klassen:

// %% tags=["keep"]
struct Point {
    double x;
    double y;
};

// %% tags=["keep"]
void print(Point p)
{
    std::cout << "Point{" << p.x << ", " << p.y << "}";
}

// %% tags=["keep"]
Point my_point{1.0, 2.0};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/call-11.png" width="40%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/call-12.png" width="50%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/call-13.png" width="50%">


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - In vielen Fällen ist call-by-value eine gute Wahl:
//   - Die Funktion kann das Objekt nicht verändern.
//   - Für kleine Objekte ist kopieren schnell.
// - In anderen Fällen wollen wir die Kopie vermeiden:
//   - Die Funktion soll das Objekt verändern.
//   - Das Objekt ist groß und kopieren ist langsam.
//   - Wir wollen Vererbung nutzen.
// - Das können wir mit Zeigern und Referenzen erreichen.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Call by Value
//
// - Welche Ausgabe erzeugt der folgende Code? Warum?
// - Handelt es sich dabei um eine sinnvolle Implementierung eines Zählers?

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
struct Counter {
    int value;
};

// %% tags=["keep"]
void increment(Counter c)
{
    ++c.value;
    std::cout << "New counter value is: " << c.value << "\n";
}

// %% tags=["keep"]
Counter c{0};
std::cout << "Counter value before call is: " << c.value << "\n";
increment(c);
std::cout << "Counter value after call is: " << c.value << "\n";
