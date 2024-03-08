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
//  <b>Nullpointer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Nullpointer.cpp -->
// <!-- slides/module_130_pointers/topic_120_nullptr.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die meisten Pointer verweisen auf ein gültiges Objekt:

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `nullptr`
//
// - Manchmal möchte man ausdrücken, dass ein Pointer gerade nicht auf ein
//   gültiges Objekt verweist.
// - Dafür kann man in C++ den Nullpointer `nullptr` verwenden.
// - `nullptr` ist ein spezieller Pointer-Wert, der auf kein Objekt verweist.
// - Der Nullpointer darf nicht dereferenziert werden!

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown] lang="de"
//
// **Falsch!!!**

// %%

// %% [markdown] lang="de"
//
// [CG: ES.65: Don’t dereference an invalid
// pointer](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es65-dont-dereference-an-invalid-pointer)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - In älteren C++-Programmen wird oft das Literal `0` (oder der Macro `NULL`)
//   für den Nullpointer verwendet.
// - Das wird aber für modernen Code nicht mehr empfohlen.
// - [CG: ES.47: Use nullptr rather than `0` or
//   `NULL`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es47-use-nullptr-rather-than-0-or-null)

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Pointer vom gleichen Typ können mit `==` und `!=` verglichen werden.
// - `a == b` ist genau dann wahr, wenn
//   - `a` und `b` beide `nullptr` sind, oder
//   - `a` und `b` beide auf das gleiche Objekt verweisen.

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
int i{1};
int j{1};

// %% tags=["keep"]
int* pi{&i};
int* pj{&j};
int* pn{nullptr};

// %% tags=["keep"]
#include <iostream>
#include <iomanip>

// %% tags=["start"]
std::cout << std::boolalpha;

// %% tags=["start"]
std::cout << std::boolalpha;

// %% tags=["start"]
std::cout << std::boolalpha;

// %% tags=["start"]
std::cout << std::boolalpha;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - In Booleschen Kontexten:
//   - Der Nullpointer ist falsch.
//   - Alle anderen Pointer-Werte sind wahr.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int i{1};
int* pi{&i};
int* my_nullptr{nullptr};

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// [CG: ES.87: Don’t add redundant `==` or `!=` to
// conditions](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es87-dont-add-redundant--or--to-conditions)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: `nullptr`
//
// - Was ist der Wert von `result` nach Ausführung der folgenden Anweisung?
// - Wie können Sie das testen?

// %% tags=["keep"]
int* result{};

// %% [markdown] lang="de" tags=["answer", "subslide"] slideshow={"slide_type": "subslide"}
// *Antwort:* 

// %%

// %%

// %%
