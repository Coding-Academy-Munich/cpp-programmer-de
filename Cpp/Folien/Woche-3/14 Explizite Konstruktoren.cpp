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
//  <b>Explizite Konstruktoren</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 14 Explizite Konstruktoren.cpp -->
// <!-- slides/module_150_classes/topic_175_explicit_constructors.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Vorsicht!
//
// - C++ führt an vielen Stellen implizite Konvertierungen durch.
// - Wir haben das beim Funktionsaufruf mit Zahlen gesehen.
// - Konvertierende Konstruktoren mit einem Argument werden für implizite
//   Konvertierungen verwendet:

// %% tags=["keep"]
#include <iostream>

namespace imc {
struct Vec
{
    Vec()                 { std::cout << "imc::Vec()\n"; }
    Vec(const Vec& v)     { std::cout << "imc::Vec(const Vec&)\n"; }
    Vec(std::size_t size) { std::cout << "imc::Vec(std::size_t)\n"; }
};
} // namespace imc

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
imc::Vec v{5};

// %% tags=["keep"]
imc::Vec v = 5;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
namespace imc {
void f(Vec v)
{
    std::cout << "imc::f(Vec)\n";
}
}

// %% tags=["keep"]
imc::f(5);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
namespace imc {
Vec g()
{
    std::cout << "imc::g()\n";
    return 5;
}
}

// %% tags=["keep"]
imc::g()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Das kann mit `explicit` verhindert werden:
//
// ```cpp
// explicit Vec(std::size_t size);
// ```

// %% tags=["keep"]
#include <iostream>

namespace exc {
struct Vec
{
    Vec()                          { std::cout << "exc::Vec()\n"; }
    Vec(const Vec& v)              { std::cout << "exc::Vec(const Vec&)\n"; }
    explicit Vec(std::size_t size) { std::cout << "exc::Vec(std::size_t)\n"; }

};
} // namespace exc


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
exc::Vec v{5};

// %% tags=["keep"]
// exc::Vec v = 5;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
namespace exc {
void f(Vec v)
{
    std::cout << "exc::f(Vec)\n";
}
}

// %% tags=["keep"]
// exc::f(5);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
namespace exc {
// Vec g()
// {
//     std::cout << "exc::g()\n";
//     return 5;
// }
}
