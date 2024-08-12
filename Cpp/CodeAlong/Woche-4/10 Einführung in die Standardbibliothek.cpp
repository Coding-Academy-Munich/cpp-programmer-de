// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Einführung in die Standardbibliothek</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 10 Einführung in die Standardbibliothek.cpp -->
// <!-- slides/module_190_standard_library/topic_110_intro_standard_lib.cpp -->

// %% [markdown]
//
// # Bestandteile der Standardbibliothek
//
// - Low-Level-Unterstützung (Speicherverwaltung, Ausnahmen, RTTI, ...)
// - C-Standardbibliothek
// - Utilities (Smart Pointer, Funktionswrapper, Tupel, Optional, ...)
// - Metaprogrammierungs-Utilities (Type Traits, Type Manipulation, ...)
// - Numerik, komplexe Zahlen, Zufallszahlen
// - Strings, String-Views, reguläre Ausdrücke
// - I/O-Streams, Formatierung, Dateisystem
// - Container, Iteratoren, Algorithmen, Ranges (STL)
// - Konzepte
// - Nebenläufigkeit, Threads, Coroutinen

// %% [markdown]
//
// ## Organisation der Standardbibliothek
//
// - Header Dateien
//   - `#include <header>`
// - Namespace `std`
//   - Wenige Unter-Namespaces (z.B. `std::chrono`)

// %%

// %%

// %%

// %%


// %%

// %%

// %% [markdown]
//
// ## Workshop:Verwendung der Standardbibliothek
//
// - Schreiben Sie eine Funktion `int string_to_int(const std::string& str)`,
//   die eine Zeichenkette als Argument entgegennimmt und in eine `int`-Zahl
//   umwandelt, falls das möglich ist. Andernfalls soll die Funktion eine
//   geeignete Exception werfen.
// - Verwenden Sie den `std::pair`-Typ aus dem `utility`-Header, um eine
//   Funktion zu schreiben, die einen Vektor von `int`-Werten als Argument
//   entgegennimmt und das Minimum und das Maximum der Werte zurückgibt.
//
// ### Hinweise
//
// - Die Exceptions der Standardbibliothek sind in dem Header
//   [`stdexcept`](https://en.cppreference.com/w/cpp/header/stdexcept)
//   definiert.
// - Dokumentation zu
//   [`std::pair`](https://en.cppreference.com/w/cpp/utility/pair)

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%
