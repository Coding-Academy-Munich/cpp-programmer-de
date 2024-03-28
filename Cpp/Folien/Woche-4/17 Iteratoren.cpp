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
// <!-- 17 Iteratoren.cpp -->
// <!-- slides/module_200_stl_collections/topic_120_iterators.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Iteratoren
//
// - STL: Algorithmen, die auf verschiedenen Containern arbeiten
// - Algorithmen von Details der Container unabhängig
// - Erreicht durch konsequente Verwendung von Iteratoren

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Iterator-Konzept
//
// - Iterator: Objekt, das auf ein Element in einem Container zeigt.
//   - Dereferenzierungsoperator `*`: Zugriff auf Element
//   - Inkrementoperator `++`: nächstes Element im Container
//   - Vergleichsoperator `==`: zeigen auf das gleiche Element?

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Iteratorkategorien
//
// - Output-Iterator (`*i = m`, `++i`, `i++`)
// - Input-Iterator (`!=`, `*i`, `i->m`, `++i`, `i++`)
// - Forward-Iterator (Multipass Input-Iterator)
// - Bidirektionaler-Iterator (Forward-Iterator, `--i`, `i--`)
// - Random-Access-Iterator (Bidirectional-Iterator, `i+n`, `i-n`, `i+=n`,
//   `i-=n`, `i[n]`, `i<i`, `i<=i`, `i>i`, `i>=i`)
// - Contiguous-Iterator (Iterator, der auf zusammenhängende Speicherbereiche
//   zeigt)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Erzeugung von Iteratoren
//
// - Iteratoren können mit dem `begin()`- und `end()`-Memberfunktionen eines
//   Containers erzeugt werden.
// - `begin()` liefert einen Iterator auf das erste Element des Containers.
// - `end()` liefert einen Iterator auf die Position hinter dem letzten Element
//   des Containers.
// - Die Varianten `cbegin()` und `cend()` liefern konstante Iteratoren, die
//   nicht zur Modifikation der Elemente verwendet werden können.
// - `std::begin()`, `std::cbegin()`, `std::end()` und `std::cend()` können auch
//   für primitive Arrays verwendet werden.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
int ia[]{1, 2};
const int* i{std::cbegin(ia)};
const int* end{std::cend(ia)};

// %% tags=["keep"]
std::cout << i << " " << end << " " << end - i << "\n";

// %% tags=["keep"]
(i == end)

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
