// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Pointer als Parameter</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Pointer als Parameter.cpp -->
// <!-- slides/module_130_pointers/topic_220_pointer_args.cpp -->

// %% [markdown]
//
// ## Pointer als Funktionsparameter
//
// - Pointer können als Funktionsparameter übergeben werden.
// - Damit sparen wir uns das Kopieren des Objekts.
// - Das ist eine Alternative zu Referenzen.

// %%
#include <iostream>

// %%

// %%
int i{1};

// %%

// %% [markdown]
//
// - Wenn eine Funktion ein Pointer-Argument bekommt empfiehlt es sich
//   typischerweise, zu überprüfen, ob der Pointer `nullptr` ist.
// - Wenn der Pointer nicht `nullptr` sein kann ist es besser den Parameter als
//   Referenz zu übergeben.

// %%

// %%
int i{1};

// %%

// %%

// %% [markdown]
//
// - [CG: F.16: For "in" parameters, pass cheaply-copied types by value and
//   others by reference to
//   `const`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f16-for-in-parameters-pass-cheaply-copied-types-by-value-and-others-by-reference-to-const)
// - [CG: F.60: Prefer `T*` over `T&` when "no argument" is a valid
//   option](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f60-prefer-t-over-t-when-no-argument-is-a-valid-option)
// - [CG: F.23: Use a `not_null<T>` to indicate that "null" is not a valid
//   value](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value)

// %% [markdown]
//
// - Wenn wir einen (nicht-konstanten Pointer verwenden), können wir das
//   referenzierte Objekt verändern:

// %%

// %%

// %%

// %% [markdown]
//
// <img src="../img/call-21.png" width="30%">

// %% [markdown]
//
// <img src="../img/call-22.png" width="80%">

// %% [markdown]
//
// <img src="../img/call-23.png" width="80%">

// %% [markdown]
//
// - Pointer-Argumente werden häufig für Structs verwendet.
// - Dadurch können wir das Kopieren der Structs vermeiden.
// - Beim Zugriff auf Felder müssen wir den Pointer dereferenzieren.

// %%
#include <iostream>

// %%
struct Point {
    double x;
    double y;
};

// %%
Point my_point{1.0, 2.0};

// %%

// %%

// %% [markdown]
//
// - Wenn wir Structs per Pointer übergeben, können wir ihre Felder verändern:

// %%

// %%

// %%

// %%

// %% [markdown]
//
// <img src="../img/call-31.png" width="40%">

// %% [markdown]
//
// <img src="../img/call-32.png" width="60%">

// %% [markdown]
//
// <img src="../img/call-33.png" width="60%">

// %% [markdown]
//
// ## Mini-Workshop: Addition mit Pointern
//
// - Schreiben Sie eine Funktion `int add(const int* a, const int* b)` die die
//   von `a` und `b` referenzierten Objekte addiert und das Ergebnis zurückgibt.
// - Wenn einer der Pointer `nullptr` ist, soll die Funktion den anderen Wert
//   zurückgeben.
// - Wenn beide Pointer `nullptr` sind, soll die Funktion `0` zurückgeben.

// %%

// %%

// %%

// %%

// %%

// %%
