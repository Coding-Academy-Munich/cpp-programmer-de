// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Vektor (Teil 1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 10 Vektor (Teil 1).cpp -->
// <!-- slides/module_140_collections/topic_150_vector_part1.cpp -->

// %% [markdown]
//
// - `std::vector` in der Standardbibliothek definiert.
// - Ein Vektor kann beliebig viele Elemente speichern.
// - Alle Elemente müssen den gleichen Typ haben.
// - Wir geben den Typ der Elemente in spitzen Klammern an.
// - Wir können zur Laufzeit Elemente hinzufügen und entfernen.

// %%
#include <vector>

// %%
std::vector<int> numbers;

// %%
numbers

// %% [markdown]
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

// %% [markdown]
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

// %% [markdown]
//
// - Zugriff auf das erste und letzte Element.

// %%
numbers.push_back(2);
numbers.push_back(3);
numbers

// %%
numbers.front()

// %%
numbers.back()

// %% [markdown]
//
// - Zugriff mit Index.
// - Index beginnt bei 0.
// - `at()` wirft eine Exception, wenn der Index ungültig ist.
// - `[]` hat undefiniertes Verhalten, wenn der Index ungültig ist.

// %%
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

// %% [markdown]
//
// - Entfernen des letzten Elements:

// %%
numbers

// %%
numbers.pop_back()

// %%
numbers

// %% [markdown]
//
// - Entfernen aller Elemente:

// %%
numbers

// %%
numbers.clear()

// %%
numbers

// %% [markdown]
//
// ## Initialisierung
//
// - Wir können einen Vektor mit einer Initialisierungsliste initialisieren:

// %%
std::vector<int> more_numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};

// %%
more_numbers

// %% [markdown]
//
// - Wir können einen Vektor auch mit einer bestimmten Anzahl von Elementen
//   initialisieren
// - Beachten Sie, dass wir dazu runde Klammern verwenden, nicht geschweifte:

// %%
std::vector<int> ten_numbers(10);

// %%
ten_numbers

// %% [markdown]
//
// - Wir können auch einen Vektor mit einer bestimmten Anzahl von Elementen und
//   einem bestimmten Wert initialisieren
// - Dazu verwenden wir wieder runde Klammern:


// %%
std::vector<int> ten_numbers_with_value(10, 42);

// %%
ten_numbers_with_value

// %% [markdown]
//
// ### Vorsicht!
//
// - `std::vector<int> ten_numbers(10, 42);` ist nicht das gleiche wie
//   `std::vector<int> ten_numbers{10, 42};`!

// %%
std::vector<int>(10)

// %%
std::vector<int>{10}

// %%
std::vector<int>(10, 42)

// %%
std::vector<int>{10, 42}

// %% [markdown]
//
// - Wir können einen Vektor `v` mit einem anderen Vektor `w` initialisieren:
// - Dabei werden die Elemente von `w` nach `v` kopiert:

// %%
std::vector<int> num_copy{more_numbers};

// %%
num_copy

// %%
more_numbers[0] = 42;
num_copy.push_back(20);

// %%
more_numbers

// %%
num_copy


// %% [markdown]
//
// ## Iteration
//
// - Wir können einen Vektor mit einer `for`-Schleife durchlaufen:


// %%
#include <iostream>

// %%
for (int i{0}; i < more_numbers.size(); ++i) {
    std::cout << more_numbers[i] << " ";
}

// %% [markdown]
//
// - Diese Schleife ist aber nicht sehr schön.
// - Besser ist, wenn wir eine Range-based `for`-Schleife verwenden:

// %%
for (int n : more_numbers) {
    std::cout << n << " ";
}
