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
int* a1{new int[10]};

// %%
a1[0]

// %%
*(a1 + 9)

// %%
delete[] a1;

// %% [markdown]
//
// ### Initialisierung mit `{}`:

// %%
int* a2{new int[10]{}};

// %%
a2[0]

// %%
a2[9]

// %%
delete[] a2;

// %% [markdown]
//
// ### Initialisierung mit Werten:

// %%
int* a3{new int[10]{1, 2, 3, 4, 5}};

// %%
a3[0]

// %%
a3[4]

// %%
a3[5]

// %%
delete[] a3;


// %% [markdown]
//
// ## Dynamische Arrays
//
// - In `new[size]` muss `size` keine Konstante sein.
// - Arrays, deren Größe zur Laufzeit bestimmt wird, heißen dynamische Arrays.

// %%
#include <iostream>

// %%
int size{5};

// %%
// std::cin >> size;

// %%
int* da{new int[size]{}};

// %%
da[4]

// %%
da[10]

// %% [markdown]
//
// ## Arrays als Rückgabewerte von Funktionen
//
// - Arrays können nicht als Rückgabewerte von Funktionen verwendet werden.
// - Wir können aber einen Zeiger auf ein Array als Rückgabewert verwenden.
// - Oft ist das ein heap-alloziertes Array.
// - Besser ist es einen Typ wie `std::vector` zu verwenden.

// %%
int* create_array(int size, int value) {
    int* result{new int[size]};
    for (int i{0}; i < size; ++i) {
        result[i] = value;
    }
    return result;
}

// %%
int* a{create_array(10, 42)};

// %%
a[0]

// %%
a[9]

// %%
delete[] a;

// %% [markdown]
//
// ## Mini-Workshop: Dynamische Arrays
//
// - Definieren Sie eine Funktion `int* iota(int size, int start_value)`, die
//   ein Array der Größe `size` mit den Werten `start_value`, `start_value + 1`,
//   ..., `start_value + size - 1` erzeugt.

// %%
int* iota(int size, int start_value)
{
    int* result{new int[size]};
    for (int i{0}; i < size; ++i) {
        result[i] = start_value + i;
    }
    return result;
}

// %%
int* a{iota(10, 42)};

// %%
#include <iostream>

// %%
for (int i{0}; i < 10; ++i) {
    std::cout << a[i] << " ";
}

// %%
delete[] a;

// %% [markdown]
//
// - Definieren Sie eine Funktion `int* resize(int* array, int old_size, int
//   new_size)`, die ein neues Array der Größe `new_size` erzeugt, die ersten
//   `old_size` Elemente von `array` in das neue Array kopiert, die restlichen
//   Elemente mit `0` initialisiert und das alte Array löscht.
// - Was passiert, wenn `new_size < old_size`?

// %%
int* resize(int* array, int old_size, int new_size)
{
    int* result{new int[new_size]{}};
    for (int i{0}; i < old_size; ++i) {
        result[i] = array[i];
    }
    delete[] array;
    return result;
}

// %%
int* a{iota(10, 42)};
int* b{resize(a, 10, 20)};

// %%
for (int i{0}; i < 20; ++i) {
    std::cout << b[i] << " ";
}

// %%
delete[] b;

// %% [markdown]
// *Antwort:* 
// - Wenn `new_size < old_size` versucht die Funktion auf den Speicher hinter
//   dem Array zuzugreifen, der nicht reserviert ist.
// - Die Funktion `resize()` kann also in der aktuellen Form **nicht** verwendet
//   werden, um ein Array zu verkleinern.

// %%
#include <cmath>

// %%
int* resize(int* array, int old_size, int new_size)
{
    int* result{new int[new_size]{}};
    for (int i{0}; i < std::min(old_size, new_size); ++i) {
        result[i] = array[i];
    }
    delete[] array;
    return result;
}

// %%
int* a{iota(20, 42)};
int* b{resize(a, 20, 10)};

// %%
for (int i{0}; i < 10; ++i) {
    std::cout << b[i] << " ";
}
