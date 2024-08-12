// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Ausnahme-Garantien</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Ausnahme-Garantien.cpp -->
// <!-- slides/module_180_error_handling/topic_150_exception_guarantees.cpp -->

// %% [markdown]
//
// In C++ gibt es verschiedene Zusicherungen, die Funktionen bezüglich
// Exception-Sicherheit machen:
// - Nothrow/nofail
// - Starke Ausnahme-Garantie
// - Grundlegende Ausnahme-Garantie

// %% [markdown]
//
// ## Nothrow/Nofail
//
// - Die Funktion löst nie eine Exception aus
// - Schlüsselwort `noexcept`
// - Nothrow:
//   - Fehler werden auf andere Art propagiert/unterdrückt
//   - Funktionen, die während des Stack-Unwindings aufgerufen werden
//     können, müssen Nothrow sein
//   - Insbesondere sind Destruktoren `noexcept`
//   - Beispiel: `std::vector::pop_back()` ist nothrow
// - Nofail:
//   - Die Funktion wird immer erfolgreich ausgeführt
//   - `swap()` und Move-Konstruktoren sind oft nofail


// %% [markdown]
//
// ## Starke Ausnahme-Garantie
//
// - Wenn die Funktion eine Exception auslöst, ist der Zustand des
//   Programms unverändert
// - Beispiel: `std::vector::push_back()`

// %% [markdown]
//
// ## Grundlegende Ausnahme-Garantie
//
// - Wenn die Funktion eine Exception auslöst, ist der Zustand des Programm gültig:
//   - Alle Invarianten sind erfüllt
//   - Es treten keine Resource-Leaks auf
// - Alle Standard-Bibliotheksfunktionen haben die Grundlegende
//   Ausnahme-Garantie

// %% [markdown]
//
// ## Keine Ausnahme-Garantie
//
// - Wenn die Funktion eine Exception auslöst, kann das Programm in einem
//   ungültigen Zustand sein
//   - Invarianten sind verletzt
//   - Resource-Leaks treten auf
//   - Der Speicher kann korrupt sein
