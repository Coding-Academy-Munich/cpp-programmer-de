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
//  <b>For-Schleifen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 For-Schleifen.cpp -->
// <!-- slides/module_120_basics/topic_164_for.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - C++ hat Prä- und Postinkrement-Operatoren `++` und `--`:
//     - `++i` und `i++` erhöhen `i` um 1
//     - `--i` und `i--` verringern `i` um 1
// - `++i` und `--i` geben eine Referenz auf das inkrementierte bzw.
//   dekrementierte Objekt zurück.
// - `i++` und `i--` geben eine Kopie des Objekts zurück, bevor es inkrementiert
//   bzw. dekrementiert wurde.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
int i{0};

// %%
++i

// %%
i

// %%
i++

// %%
i


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # `for`-Schleifen
//
// - Wie können wir die Zahlen von 0 bis 4 ausgeben?

// %% tags=["keep"]
#include <iostream>

// %%
for (int i{0}; i < 5; ++i) {
    std::cout << "i = " << i << "\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Square numbers
//
// Schreiben Sie eine `for`-Schleife, die die Quadratzahlen von 1 bis 5
// in der folgenden Form ausgibt:
//
// ```
// 1^2 = 1
// 2^2 = 4
// 3^2 = 9
// 4^2 = 16
// 5^2 = 25
// ```

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %%
for (int i{1}; i <= 5; ++i) {
    std::cout << i << "^2 = " << i * i << "\n";
}
