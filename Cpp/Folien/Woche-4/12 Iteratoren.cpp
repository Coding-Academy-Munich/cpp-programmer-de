// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Iteratoren</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 Iteratoren.cpp -->
// <!-- slides/module_200_stl_collections/topic_120_iterators.cpp -->

// %% [markdown]
//
// ## Iteratoren
//
// - STL: Algorithmen, die auf verschiedenen Containern arbeiten
// - Algorithmen von Details der Container unabhängig
// - Erreicht durch konsequente Verwendung von Iteratoren

// %% [markdown]
//
// ## Iterator-Konzept
//
// - Iterator: Objekt, das auf ein Element in einem Container zeigt.
//   - Dereferenzierungsoperator `*`: Zugriff auf Element
//   - Inkrementoperator `++`: nächstes Element im Container
//   - Vergleichsoperator `==`: zeigen auf das gleiche Element?

// %% [markdown]
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

// %% [markdown]
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

// %%
#include <iostream>

// %%
int ia[]{1, 2};
const int* i{std::cbegin(ia)};
const int* end{std::cend(ia)};

// %%
std::cout << i << " " << end << " " << end - i << "\n";

// %%
(i == end)

// %%
*i++

// %%
(i == end)

// %%
*i++

// %%
(i == end)

// %%
#include <iostream>

// %%
int ia[]{1, 2, 3, 4, 5 };

// %%
for (const int *i{std::cbegin(ia)}; i != std::cend(ia); ++i) {
    std::cout << *i << " ";
}

// %%
for (const auto* i{std::cbegin(ia)}; i != std::cend(ia); ++i) {
    std::cout << *i << " ";
}

// %%
#include <vector>

// %%
std::vector<int> v{1, 2, 3, 4, 5};

// %%
for (std::vector<int>::const_iterator i{v.cbegin()}; i != v.cend(); ++i) {
    std::cout << *i << " ";
}

// %%
for (auto i{std::cbegin(v)}; i != std::cend(v); ++i) {
    std::cout << *i << " ";
}

// %%
#include <array>

// %%
std::array<int, 5> a{1, 2, 3, 4, 5};

// %%
for (std::array<int, 5>::const_iterator i{a.cbegin()}; i != a.cend(); ++i) {
    std::cout << *i << " ";
}

// %%
for (auto i{std::cbegin(ia)}; i != std::cend(ia); ++i) {
    std::cout << *i << " ";
}

// %%
#include <set>

// %%
std::set<int> s{1, 2, 3, 4, 5};

// %%
// s[0]

// %%
for (std::set<int>::const_iterator i{s.cbegin()}; i != s.cend(); ++i) {
    std::cout << *i << " ";
}

// %%
for (auto i{std::cbegin(s)}; i != std::cend(s); ++i) {
    std::cout << *i << " ";
}
