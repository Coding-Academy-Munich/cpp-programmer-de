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
//  <b>Blockstruktur</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Blockstruktur.cpp -->
// <!-- slides/module_120_basics/topic_176_block_structure.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Blockstruktur, Scopes und Lifetimes
//
// - Wichtige Konzepte im Zusammenhang mit der Verwendung und Organisation von
//   Variablen in C++:
// - Block: Folge von Anweisungen.
// - Scope: Bereich des Quelltexts, in dem eine Variable sichtbar ist.
// - Lifetime: Zeitraum, bei der Programm-Ausführung in dem eine Variable
//   existiert.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Blockstruktur
//
// - Ein Block ist eine Sequenz von Anweisungen, die in geschweiften Klammern
//   (`{}`) eingeschlossen sind.
// - Definiert einen lokalen Scope;
//   - Variablen, die in einem Block definiert werden sind nur in diesem Block sichtbar.
//   - Ihre Lebensdauer endet, wenn der Kontrollfluss den Block verlässt.
// - Kann in anderen Blöcken verschachtelt werden.

// %% tags=["keep"]
#include <iostream>

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Variablen in einem inneren Block können Variablen aus äußeren Blöcken
//   verschatten.

// %% tags=["keep"]
#include <iostream>

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Blockstruktur
//
// - Welche Ausgabe erzeugt der folgende Code? Warum?
// - Benennen Sie die Variablen so um, dass kein Shadowing mehr auftritt.

// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
void workshop_block_structure() {
    int var{1};
    std::cout << "1. var: " << ++var << "\n";
    {
        int var{10};
        std::cout << "2. var: " << ++var << "\n";
        {
            int var{20};
            std::cout << "3. var: " << ++var << "\n";
        }
        std::cout << "4. var: " << ++var << "\n";
        {
            int var{100};
            std::cout << "5. var: " << ++var << "\n";
        }
        std::cout << "6. var: " << ++var << "\n";
        {
            std::cout << "7. var: " << ++var << "\n";
        }
        std::cout << "8. var: " << ++var << "\n";
    }
    std::cout << "9. var: " << ++var << "\n";
}

// %%
