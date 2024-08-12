// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Dynamische Arrays</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 14 Dynamische Arrays.cpp -->
// <!-- slides/module_140_collections/topic_130_dynamic_arrays.cpp -->

// %% [markdown]
//
// ## Heap-allozierte Arrays
//
// - Wir können ein Heap-alloziertes Array mit `new[size]` erzeugen:
//   - `new int[10]` erzeugt ein Array mit 10 Elementen.
//   - `new int[10]{}` erzeugt ein Array mit 10 Elementen, die mit 0
//     initialisiert sind.
// - Ein Heap-alloziertes Array wird mit `delete[]` gelöscht.

// %% [markdown]
//
// ### Erzeugen eines uninitialierten Arrays:

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Initialisierung mit `{}`:

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Initialisierung mit Werten:

// %%

// %%

// %%

// %%

// %%


// %% [markdown]
//
// ## Dynamische Arrays
//
// - In `new[size]` muss `size` keine Konstante sein.
// - Arrays, deren Größe zur Laufzeit bestimmt wird, heißen dynamische Arrays.

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Arrays als Rückgabewerte von Funktionen
//
// - Arrays können nicht als Rückgabewerte von Funktionen verwendet werden.
// - Wir können aber einen Zeiger auf ein Array als Rückgabewert verwenden.
// - Oft ist das ein heap-alloziertes Array.
// - Besser ist es einen Typ wie `std::vector` zu verwenden.

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: Dynamische Arrays
//
// - Definieren Sie eine Funktion `int* iota(int size, int start_value)`, die
//   ein Array der Größe `size` mit den Werten `start_value`, `start_value + 1`,
//   ..., `start_value + size - 1` erzeugt.

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Definieren Sie eine Funktion `int* resize(int* array, int old_size, int
//   new_size)`, die ein neues Array der Größe `new_size` erzeugt, die ersten
//   `old_size` Elemente von `array` in das neue Array kopiert, die restlichen
//   Elemente mit `0` initialisiert und das alte Array löscht.
// - Was passiert, wenn `new_size < old_size`?

// %%

// %%

// %%

// %%

// %% [markdown]
// *Antwort:* 

// %%

// %%

// %%

// %%
