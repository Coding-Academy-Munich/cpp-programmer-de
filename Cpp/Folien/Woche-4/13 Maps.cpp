// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Maps</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 13 Maps.cpp -->
// <!-- slides/module_200_stl_collections/topic_140_maps.cpp -->

// %% [markdown]
//
// - Maps sind assoziative Container
// - Sie speichern Paare von Schlüsseln und Werten
// - Die Schlüssel sind eindeutig
// - Die Werte können mehrfach vorkommen

// %% [markdown]
//
// - C++ bietet zwei Arten von Maps:
//   - `std::map` (sorted map)
//   - `std::unordered_map` (hash map)
// - Die Schlüssel müssen in `std::map` vergleichbar sein
// - Die Schlüssel müssen in `std::unordered_map` hashbar sein
// - Für die meisten Anwendungen ist `std::unordered_map` die bessere Wahl

// %% [markdown]
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

// %% [markdown]
//
// ### Beispiel: Studenten
//
// - Wir speichern Studenten in einer Map um effizient mit der Matrikelnummer
//   auf den Studenten zugreifen zu können

// %%
#include <iostream>
#include <map>
#include <unordered_map>

// %%
std::unordered_map<int, std::string> students;
// std::map<int, std::string> students;

// %%
students[1] = "Alice";
students[2] = "Bob";
students[3] = "Charlie";

// %%
students[1]

// %%
students[4] = "Dean";

// %%
students.at(4)

// %%
students[4] = "Dora";

// %%
students[4]

// %%
// students.at(5)

// %%
students.insert({5, "Eric"});

// %%
students[5]

// %%
for (const std::pair<int, std::string>& student : students) {
    std::cout << "ID: " << student.first << ", Name: " << student.second << "\n";
}

// %%
for (const auto& [id, name] : students) {
    std::cout << "ID: " << id << ", Name: " << name << "\n";
}

// %%
students.erase(3)

// %%
for (const auto& [id, name] : students) {
    std::cout << "ID: " << id << ", Name: " << name << "\n";
}

// %%
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

// %% [markdown]
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

// %%
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

// %%
std::string text = "I am a sick man. I am a spiteful man. Fyodor Dostoyevsky - Notes from the Underground";

// %%
auto word_count = count_words(text);

// %%
for (const auto& [word, count] : word_count) {
    std::cout << word << ": " << count << std::endl;
}