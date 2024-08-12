// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Function Templates</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Function Templates.cpp -->
// <!-- slides/module_400_templates/topic_140_function_templates.cpp -->

// %% [markdown]
//
// - Funktionen können ebenfalls Templates sein
//   - Aufruf: `max<int>(1, 2)`
// - In vielen Fällen muss beim Aufruf von Template-Funktionen der Typ nicht
//   explizit angegeben werden
//   - Compiler kann den Typ aus den Argumenten ableiten
//   - Aufruf: `max(1, 2)`

// %%
#include <iostream>
#include "type_name.hpp"

using namespace std::string_literals;

// %%
template <typename T>
T add(T a, T b)
{
    std::cout << "add<" << type_name<T>() << ">(" << a << ", " << b << ")\n";
    return a + b;
}

// %%
add(1, 2)

// %%
add(1.0, 2.0)

// %%
// add(1.0, 2)

// %%
add<int>(1.0, 2)

// %%
add<float>(1.0, 2)

// %%
// add("Hello ", "World!")

// %%
add("Hello "s, "World!"s)

// %%
add<std::string>("Hello ", "World!")

// %% [markdown]
//
// ## Templates und Overload Resolution
//
// - Compiler versucht, den passenden Overload zu finden
// - Templates sind dabei ein schlechterer Match als Nicht-Templates bei exakten
//   Matches
// - Exaktes Match erlaubt [einige
//   Konvertierungen](https://en.cppreference.com/w/cpp/language/overload_resolution#Ranking_of_implicit_conversion_sequences)):
//   - Referenz nach Wert
//   - Const nach Nicht-Const

// %%
namespace ns
{
template <typename T>
void describe(T thing)
{
    std::cout << "describe<" << type_name<T>() << ">()\n";
}

void describe(int i)
{
    std::cout << "describe(int)\n";
}
}

// %%
ns::describe(1);

// %%
ns::describe(1.0);

// %%
ns::describe(true);

// %%
ns::describe("Hello World!");

// %%
int i{0};
int& ir{i};

// %%
ns::describe(i);

// %%
ns::describe(ir);

// %%
const int j{0};
const int& jr{j};

// %%
ns::describe(j);

// %%
ns::describe(jr);
