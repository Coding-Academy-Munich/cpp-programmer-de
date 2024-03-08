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
//  <b>Maps</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Maps.cpp -->
// <!-- slides/module_200_stl_collections/topic_140_maps.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Maps sind assoziative Container
// - Sie speichern Paare von Schlüsseln und Werten
// - Die Schlüssel sind eindeutig
// - Die Werte können mehrfach vorkommen

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - C++ bietet zwei Arten von Maps:
//   - `std::map` (sorted map)
//   - `std::unordered_map` (hash map)
// - Die Schlüssel müssen in `std::map` vergleichbar sein
// - Die Schlüssel müssen in `std::unordered_map` hashbar sein
// - Für die meisten Anwendungen ist `std::unordered_map` die bessere Wahl

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Map-Operationen
//
// - `map[key]` liefert eine Referenz auf den Wert, der zu `key` gehört, und
//   legt diesen gegebenenfalls an
// - `map.at(key)` liefert eine Referenz auf den Wert, der zu `key` gehört, und
//   wirft eine Exception, falls `key` nicht existiert
// - `map.insert({key, value})` fügt ein Paar aus Schlüssel und Wert ein
// - `map.erase(key)` löscht den Eintrag mit dem Schlüssel `key`
// - `map.find(key)` liefert einen Iterator auf den Eintrag mit dem Schlüssel `key`
// - `map.begin()` liefert einen Iterator auf den ersten Eintrag
// - `map.end()` liefert einen Iterator auf das Ende der Map

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Beispiel: Studenten
//
// - Wir speichern Studenten in einer Map um effizient mit der Matrikelnummer
//   auf den Studenten zugreifen zu können

// %% tags=["keep"]
#include <iostream>
#include <map>
#include <unordered_map>

// %% tags=["keep"]
std::unordered_map<int, std::string> students;
// std::map<int, std::string> students;

// %% tags=["keep"]
students[1] = "Alice";
students[2] = "Bob";
students[3] = "Charlie";

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
students[1]

// %%
students[4] = "Dean";

// %%
students.at(4)

// %%
students[4] = "Dora";

// %%
students[4]

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
// students.at(5)

// %%
students.insert({5, "Eric"});

// %%
students[5]

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
for (const std::pair<int, std::string>& student : students) {
    std::cout << "ID: " << student.first << ", Name: " << student.second << "\n";
}

// %%
for (const auto& [id, name] : students) {
    std::cout << "ID: " << id << ", Name: " << name << "\n";
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
students.erase(3)

// %% tags=["keep"]
for (const auto& [id, name] : students) {
    std::cout << "ID: " << id << ", Name: " << name << "\n";
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
auto it{students.find(1)};

// %%
it->first

// %%
it->second

// %%
(it == students.end())

// %%
auto it{students.find(123)};

// %%
(it == students.end())

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Zählen von Wörtern
//
// Schreiben Sie eine Funktion `count_words`, die für einen String die Anzahl
// der Vorkommnisse jedes Wortes zählt. Verwenden Sie dafür eine
// `std::unordered_map`.
//
// ### Hinweise:
//
// - Verwenden Sie `std::istringstream` um einen String wie einen Stream zu
//   lesen
// - Verwenden Sie `operator>>` um Wörter aus dem Stream zu lesen
// - `map[key]` liefert eine Referenz auf den Wert, der zu `key` gehört, und
//   legt diesen gegebenenfalls an

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <sstream>
#include <unordered_map>

// %%
std::unordered_map<std::string, int> count_words(const std::string& text) {
    std::unordered_map<std::string, int> result;
    std::istringstream in(text);
    std::string word;
    while (in >> word) {
        ++result[word];
    }
    return result;
}

// %% tags=["keep"]
std::string text = "I am a sick man. I am a spiteful man. Fyodor Dostoyevsky - Notes from the Underground";

// %%
auto word_count = count_words(text);

// %%
for (const auto& [word, count] : word_count) {
    std::cout << word << ": " << count << std::endl;
}
