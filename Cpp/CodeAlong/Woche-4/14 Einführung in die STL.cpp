// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Einführung in die STL</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 14 Einführung in die STL.cpp -->
// <!-- slides/module_200_stl_collections/topic_110_stl_intro.cpp -->

// %% [markdown]
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

// %% [markdown]
// ## Beispiel: Verwendung von `std::vector` und Algorithmen

// %%
#include <iostream>
#include <vector>
#include <algorithm>


// %%
std::vector<int> numbers = {5, 2, 9, 1, 7};

// %%
numbers

// %%

// %%
numbers

// %%

// %%
numbers

