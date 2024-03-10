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
//  <b>Einführung in die Standardbibliothek</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 15 Einführung in die Standardbibliothek.cpp -->
// <!-- slides/module_190_standard_library/topic_110_intro_standard_lib.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Bestandteile der Standardbibliothek
//
// - Low-Level-Unterstützung (Speicherverwaltung, Ausnahmen, RTTI, ...)
// - Metaprogrammierungs-Utilities (Type Traits, Type Manipulation, ...)
// - Numerik, komplexe Zahlen, Zufallszahlen
// - C-Standardbibliothek
// - Strings, String-Views, reguläre Ausdrücke
// - I/O-Streams, Formatierung, Dateisystem
// - Container, Iteratoren, Algorithmen, Ranges (STL)
// - Konzepte
// - Nebenläufigkeit, Threads, Coroutinen
// - Utilities (Smart Pointer, Funktionswrapper, Tupel, Optional, ...)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Organisation der Standardbibliothek
//
// - Header Dateien
//   - `#include <header>`
// - Namespace `std`
//   - Wenige Unter-Namespaces (z.B. `std::chrono`)
