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
//  <b>Arbeiten mit Notebooks</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Arbeiten mit Notebooks.cpp -->
// <!-- slides/module_110_introduction/topic_180_working_with_notebooks.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Starten des Docker Containers
//
// ```bash
// docker ps --all  # Anzeigen der Container
// docker start <container-name>
// ```

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Notebooks
//
// - Notebooks erlauben interaktives Arbeiten mit Code und Text
// - Diese Art zu Arbeiten ist bei C++ nicht so verbreitet
// - Für Schulungen ist sie aber hervorragend geeignet

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Arbeiten mit Notebooks
//
// - Der Notebook-Server zeigt uns eine Liste der Dateien im aktuellen
//   Verzeichnis
// - Durch Anklicken einer Notebook-Datei können wir sie öffnen
// - Notebooks sind in Zellen aufgeteilt
// - Zellen können entweder Text oder C++ Code enthalten
// - Im Gegensatz zu C++ Programmen, können Zellen auch Ausdrücke enthalten
// - Wenn die Zelle ausgeführt wird, werden die Ausdrücke ausgewertet und das
//   Ergebnis angezeigt

// %%
123

// %%
17 + 4

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zellen können auch Anweisungen enthalten, z.B. Funktionsdefinitionen
// - Beim Ausführen einer Zelle, in der eine Funktion definiert wird, wird die
//   Funktion für den Rest des Notebooks verfügbar gemacht

// %% tags=["keep"]
#include <iostream>

void say_hello(const std::string& name) {
    std::cout << "Hello " << name << "!\n";
}

// %%
say_hello("World")

// %%
say_hello("you")

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Das gleiche gilt für Structs und Klassen:

// %% tags=["keep"]
struct Point {
    int x;
    int y;
};

// %%
Point p{1, 2};

// %%
p.x

// %%
p.y

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Es gibt zwei Modi: Kommando- und Edit-Modus (`Esc` / `Enter`)
// - Einige Tastaturkürzel:
//   - `Strg`-`Enter`
//   - `Shift`-`Enter`
//   - (`Tab`)
//   - (`Shift-Tab`)

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
123

// %%
17 + 4

// %%
int answer{42}

// %%
answer

// %%
answer;
