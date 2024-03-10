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
//  <b>Iteratoren</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 19 Iteratoren.cpp -->
// <!-- slides/module_200_stl_collections/topic_120_iterators.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Die C++ Standardbibliothek bietet eine Reihe von Algorithmen, die auf
//   verschiedenen Containern arbeiten.
// - Die Algorithmen sind von den Details der Container unabhängig.
// - Das wird durch die konsequente Verwendung von Iteratoren erreicht.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Ein Iterator ist ein Objekt, das auf ein Element in einem Container zeigt.
//   - Iteratoren können mit dem Dereferenzierungsoperator `*` dereferenziert
//     werden.
//   - Iteratoren können mit dem Inkrementoperator `++` inkrementiert werden.
//   - Iteratoren können mit dem Vergleichsoperator `==` verglichen werden.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Iteratoren können in mehrere Kategorien eingeteilt werden:
//   - Output-Iterator (`*i = m`, `++i`, `i++`)
//   - Input-Iterator (`!=`, `*i`, `i->m`, `++i`, `i++`)
//   - Forward-Iterator (Multipass Input-Iterator)
//   - Bidirectional-Iterator (Forward-Iterator, `--i`, `i--`)
//   - Random-Access-Iterator (Bidirectional-Iterator, `i+n`, `i-n`, `i+=n`,
//     `i-=n`, `i[n]`, `i<i`, `i<=i`, `i>i`, `i>=i`)
//   - Contiguous-Iterator (Iterator, der auf zusammenhängende Speicherbereiche
//     zeigt)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Iteratoren können mit dem `begin()`- und `end()`-Memberfunktionen eines
//   Containers erzeugt werden.
// - `begin()` liefert einen Iterator auf das erste Element des Containers.
// - `end()` liefert einen Iterator auf das Element hinter dem letzten Element
//   des Containers.
// - `std::begin()` und `std::end()` können auch für Arrays verwendet werden.
// - Die Varianten `cbegin()` und `cend()` liefern konstante Iteratoren.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
int ia[]{1, 2};
const int* i{std::cbegin(ia)};
const int* end{std::cend(ia)};
std::cout << i << " " << end << " " << end - i << "\n";

// %% tags=["keep"]
*i++

// %% tags=["keep"]
(i == end)

// %% tags=["keep"]
*i++

// %% tags=["keep"]
(i == end)

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
int ia[]{1, 2, 3, 4, 5 };

// %% tags=["keep"]
for (const int *i{std::cbegin(ia)}; i != std::cend(ia); ++i) {
    std::cout << *i << " ";
}

// %% tags=["keep"]
for (const auto* i{std::cbegin(ia)}; i != std::cend(ia); ++i) {
    std::cout << *i << " ";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <vector>

// %% tags=["keep"]
std::vector<int> v{1, 2, 3, 4, 5};

// %% tags=["keep"]
for (std::vector<int>::const_iterator i{v.cbegin()}; i != v.cend(); ++i) {
    std::cout << *i << " ";
}

// %% tags=["keep"]
for (auto i{std::cbegin(v)}; i != std::cend(v); ++i) {
    std::cout << *i << " ";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <array>

// %% tags=["keep"]
std::array<int, 5> a{1, 2, 3, 4, 5};

// %% tags=["keep"]
for (std::array<int, 5>::const_iterator i{a.cbegin()}; i != a.cend(); ++i) {
    std::cout << *i << " ";
}

// %% tags=["keep"]
for (auto i{std::cbegin(ia)}; i != std::cend(ia); ++i) {
    std::cout << *i << " ";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <set>

// %% tags=["keep"]
std::set<int> s{1, 2, 3, 4, 5};

// %% tags=["keep"]
// s[0]

// %% tags=["keep"]
for (std::set<int>::const_iterator i{s.cbegin()}; i != s.cend(); ++i) {
    std::cout << *i << " ";
}

// %% tags=["keep"]
for (auto i{std::cbegin(s)}; i != std::cend(s); ++i) {
    std::cout << *i << " ";
}

