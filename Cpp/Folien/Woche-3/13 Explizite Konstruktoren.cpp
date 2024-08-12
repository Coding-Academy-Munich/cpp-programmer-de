// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Explizite Konstruktoren</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 13 Explizite Konstruktoren.cpp -->
// <!-- slides/module_150_classes/topic_175_explicit_constructors.cpp -->

// %% [markdown]
//
// ### Vorsicht!
//
// - C++ führt an vielen Stellen implizite Konvertierungen durch.
// - Wir haben das beim Funktionsaufruf mit Zahlen gesehen.
// - Konvertierende Konstruktoren mit einem Argument werden für implizite
//   Konvertierungen verwendet:

// %%
#include <iostream>

namespace imc {
struct Vec
{
    Vec()                 { std::cout << "imc::Vec()\n"; }
    Vec(const Vec& v)     { std::cout << "imc::Vec(const Vec&)\n"; }
    Vec(std::size_t size) { std::cout << "imc::Vec(std::size_t)\n"; }
};
} // namespace imc

// %%
imc::Vec v{5};

// %%
imc::Vec v = 5;

// %%
namespace imc {
void f(Vec v)
{
    std::cout << "imc::f(Vec)\n";
}
}

// %%
imc::f(5);

// %%
namespace imc {
Vec g()
{
    std::cout << "imc::g()\n";
    return 5;
}
}

// %%
imc::g()

// %% [markdown]
//
// Das kann mit `explicit` verhindert werden:
//
// ```cpp
// explicit Vec(std::size_t size);
// ```

// %%
#include <iostream>

namespace exc {
struct Vec
{
    Vec()                          { std::cout << "exc::Vec()\n"; }
    Vec(const Vec& v)              { std::cout << "exc::Vec(const Vec&)\n"; }
    explicit Vec(std::size_t size) { std::cout << "exc::Vec(std::size_t)\n"; }

};
} // namespace exc


// %%
exc::Vec v{5};

// %%
// exc::Vec v = 5;

// %%
namespace exc {
void f(Vec v)
{
    std::cout << "exc::f(Vec)\n";
}
}

// %%
// exc::f(5);

// %%
namespace exc {
// Vec g()
// {
//     std::cout << "exc::g()\n";
//     return 5;
// }
}
