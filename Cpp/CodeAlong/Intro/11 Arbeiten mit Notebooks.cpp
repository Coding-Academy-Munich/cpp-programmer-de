// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Arbeiten mit Notebooks</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 11 Arbeiten mit Notebooks.cpp -->
// <!-- slides/module_110_introduction/topic_180_working_with_notebooks.cpp -->

// %% [markdown]
//
// # Starten des Docker Containers
//
// ```bash
// docker ps --all  # Anzeigen der Container
// docker start <container-name>
// ```

// %% [markdown]
//
// # Notebooks
//
// - Notebooks erlauben interaktives Arbeiten mit Code und Text
// - Diese Art zu Arbeiten ist bei C++ nicht so verbreitet
// - Für Schulungen ist sie aber hervorragend geeignet

// %% [markdown]
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

// %%

// %% [markdown]
//
// - Zellen können auch Anweisungen enthalten, z.B. Funktionsdefinitionen
// - Beim Ausführen einer Zelle, in der eine Funktion definiert wird, wird die
//   Funktion für den Rest des Notebooks verfügbar gemacht

// %%
#include <iostream>

void say_hello(const std::string& name) {
    std::cout << "Hello " << name << "!\n";
}

// %%

// %%

// %% [markdown]
//
// - Das gleiche gilt für Structs und Klassen:

// %%
struct Point {
    int x;
    int y;
};

// %%

// %%

// %%

// %% [markdown]
//
// - Es gibt zwei Modi: Kommando- und Edit-Modus (`Esc` / `Enter`)
// - Einige Tastaturkürzel:
//   - `Strg`-`Enter`
//   - `Shift`-`Enter`
//   - (`Tab`)
//   - (`Shift-Tab`)

// %%

// %%

// %%

// %%

// %%
