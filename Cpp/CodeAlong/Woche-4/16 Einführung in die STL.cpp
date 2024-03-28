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
//  <b>Einführung in die STL</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 16 Einführung in die STL.cpp -->
// <!-- slides/module_200_stl_collections/topic_110_stl_intro.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
// ## Komponenten der STL
//
// - Container
//   - Sequentielle Container (z.B. `std::vector`, `std::list`, `std::deque`)
//   - Assoziative Container (z.B. `std::set`, `std::map`, `std::multimap`)
//   - Container Adapter (z.B. `std::stack`, `std::queue`,
//     `std::priority_queue`)
// - Iteratoren
//   - Eingabe-Iteratoren, Ausgabe-Iteratoren, Forward-Iteratoren,
//     Bidirektionale Iteratoren, Random-Access-Iteratoren
// - Algorithmen
//   - Nicht-modifizierende Sequenzoperationen (z.B. `std::find`, `std::count`)
//   - Modifizierende Sequenzoperationen (z.B. `std::copy`, `std::transform`)
//   - Sortieren und verwandte Operationen (z.B. `std::sort`,
//     `std::binary_search`)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
// ## Beispiel: Verwendung von `std::vector` und Algorithmen

// %% tags=["keep"]
#include <iostream>
#include <vector>
#include <algorithm>


// %% tags=["keep"]
std::vector<int> numbers = {5, 2, 9, 1, 7};

// %% tags=["keep"]
numbers

// %%

// %% tags=["keep"]
numbers

// %%

// %% tags=["keep"]
numbers

