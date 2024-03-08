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
//  <b>Function Templates</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Function Templates.cpp -->
// <!-- slides/module_400_templates/topic_140_function_templates.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Funktionen können ebenfalls Templates sein
//   - Aufruf: `max<int>(1, 2)`
// - In vielen Fällen muss beim Aufruf von Template-Funktionen der Typ nicht
//   explizit angegeben werden
//   - Compiler kann den Typ aus den Argumenten ableiten
//   - Aufruf: `max(1, 2)`

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include "type_name.hpp"

using namespace std::string_literals;

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
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

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
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

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
ns::describe(1);

// %% tags=["keep"]
ns::describe(1.0);

// %% tags=["keep"]
ns::describe(true);

// %% tags=["keep"]
ns::describe("Hello World!");

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int i{0};
int& ir{i};

// %% tags=["keep"]
ns::describe(i);

// %% tags=["keep"]
ns::describe(ir);

// %% tags=["keep"]
const int j{0};
const int& jr{j};

// %% tags=["keep"]
ns::describe(j);

// %% tags=["keep"]
ns::describe(jr);
