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
//  <b>Vektor (Teil 1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Vektor (Teil 1).cpp -->
// <!-- slides/module_140_collections/topic_150_vector_part1.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `std::vector` in der Standardbibliothek definiert.
// - Ein Vektor kann beliebig viele Elemente speichern.
// - Alle Elemente müssen den gleichen Typ haben.
// - Wir geben den Typ der Elemente in spitzen Klammern an.
// - Wir können zur Laufzeit Elemente hinzufügen und entfernen.

// %% tags=["keep"]
#include <vector>

// %%
std::vector<int> numbers;

// %%
numbers

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Member-Funktionen
//
// - Wir können
//   - mit `empty()` prüfen, ob ein Vektor leer ist,
//   - mit `size()` die Größe abfragen,
//   - mit `push_back()` ein Element hinzufügen,
//   - mit `front()` und `back()` das erste bzw. letzte Element abfragen,
//   - mit `[]` oder `at()` ein Element an einer bestimmten Position abfragen,
//   - mit `pop_back()` das letzte Element entfernen,
//   - mit `clear()` alle Elemente entfernen.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Prüfen, ob ein Vektor leer ist.
// - Abfragen der Größe.
// - Hinzufügen eines Elements.

// %%
numbers.empty()

// %%
numbers.size()

// %%
numbers.push_back(1);

// %%
numbers.empty()

// %%
numbers.size()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zugriff auf das erste und letzte Element.

// %% tags=["keep"]
numbers.push_back(2);
numbers.push_back(3);
numbers

// %%
numbers.front()

// %%
numbers.back()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zugriff mit Index.
// - Index beginnt bei 0.
// - `at()` wirft eine Exception, wenn der Index ungültig ist.
// - `[]` hat undefiniertes Verhalten, wenn der Index ungültig ist.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
numbers

// %%
numbers[0]

// %%
numbers[2]

// %%
numbers.at(0)

// %%
numbers.at(2)

// %%
// numbers[5]

// %%
// numbers.at(5)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Entfernen des letzten Elements:

// %% tags=["keep"]
numbers

// %%
numbers.pop_back()

// %%
numbers

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Entfernen aller Elemente:

// %% tags=["keep"]
numbers

// %%
numbers.clear()

// %%
numbers

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Initialisierung
//
// - Wir können einen Vektor mit einer Initialisierungsliste initialisieren:

// %% tags=["keep"]
std::vector<int> more_numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};

// %%
more_numbers

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können einen Vektor auch mit einer bestimmten Anzahl von Elementen
//   initialisieren
// - Beachten Sie, dass wir dazu runde Klammern verwenden, nicht geschweifte:

// %% tags=["keep"]
std::vector<int> ten_numbers(10);

// %% tags=["keep"]
ten_numbers

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können auch einen Vektor mit einer bestimmten Anzahl von Elementen und
//   einem bestimmten Wert initialisieren
// - Dazu verwenden wir wieder runde Klammern:


// %% tags=["keep"]
std::vector<int> ten_numbers_with_value(10, 42);

// %% tags=["keep"]
ten_numbers_with_value

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Vorsicht!
//
// - `std::vector<int> ten_numbers(10, 42);` ist nicht das gleiche wie
//   `std::vector<int> ten_numbers{10, 42};`!

// %% tags=["keep"]
std::vector<int>(10)

// %% tags=["keep"]
std::vector<int>{10}

// %% tags=["keep"]
std::vector<int>(10, 42)

// %% tags=["keep"]
std::vector<int>{10, 42}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können einen Vektor `v` mit einem anderen Vektor `w` initialisieren:
// - Dabei werden die Elemente von `w` nach `v` kopiert:

// %% tags=["keep"]
std::vector<int> num_copy{more_numbers};

// %% tags=["keep"]
num_copy

// %% tags=["keep"]
more_numbers[0] = 42;
num_copy.push_back(20);

// %% tags=["keep"]
more_numbers

// %% tags=["keep"]
num_copy


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Iteration
//
// - Wir können einen Vektor mit einer `for`-Schleife durchlaufen:


// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
for (int i{0}; i < more_numbers.size(); ++i) {
    std::cout << more_numbers[i] << " ";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Diese Schleife ist aber nicht sehr schön.
// - Besser ist, wenn wir eine Range-based `for`-Schleife verwenden:

// %%
for (int n : more_numbers) {
    std::cout << n << " ";
}
