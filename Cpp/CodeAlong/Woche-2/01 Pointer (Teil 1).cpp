// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Pointer (Teil 1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Pointer (Teil 1).cpp -->
// <!-- slides/module_130_pointers/topic_110_pointers.cpp -->

// %% [markdown]
//
// # Pointer
//
// - Ein Pointer repräsentiert die Adresse eines anderen Objekts.
// - Der Typ eines Pointers auf einen `int`-Wert wird als `int*` geschrieben.
// - Die Adresse eines Objekts erhalten wir mit dem Operator `&`.

// %%

// %% [markdown]
//
// - `pi` ist ein Pointer auf einen `int`-Wert.
// - Der Wert von `pi` ist die Adresse von `i`.
// - Will man mit `pi` auf den Wert von `i` zugreifen, so schreibt man `*pi`.
// - Das nennen wir *Dereferenzieren* eines Pointers.

// %%

// %%

// %%

// %% [markdown]
//
// <img src="../img/pointers-01.png" width="50%">

// %% [markdown]
//
// <img src="../img/pointers-02.png" width="60%">

// %% [markdown]
//
// - Wir können selbstverständlich auch Pointer für andere Typen haben.
// - Ein Pointer vom Typ `T*` muss auf ein Objekt vom Typ `T` zeigen.
//   - (Mit einigen Ausnahmen.)

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Wir können `*pi` auch auf der linken Seite einer Zuweisung verwenden.
// - Damit wird der Wert von `i` geändert:

// %%

// %%

// %%

// %% [markdown]
//
// - Pointer sind selber Objekte.
// - Wir können also auch `pi` einen neuen Wert zuweisen.
// - Damit ändern wir das Objekt, auf das `pi` zeigt:

// %%

// %% [markdown]
//
// <img src="../img/pointers-03.png" width="60%">

// %%

// %% [markdown]
//
// <img src="../img/pointers-04.png" width="60%">

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: Pointer
//
// Gegeben seien die folgenden Variablen:

// %%
unsigned int a{1};
bool b{true};

// %% [markdown]
//
// - Definieren Sie Pointer `pa` und `pb`, die auf `a` und `b` zeigen.
// - Geben Sie die Werte von `pa` und `pb` aus.
// - Geben Sie die Werte von `a` und `b` mittels `pa` und `pb` aus.

// %%

// %%
#include <iostream>

// %%

// %%

// %% [markdown]
//
// - Verwenden Sie `pa` um den Wert von `a` auf `2` zu ändern.
// - Verwenden Sie `pb` um den Wert von `b` auf `false` zu ändern.
// - Geben Sie die neuen Werte von `a` und `b` mittels `pa` und `pb` aus.

// %%

// %%

// %% [markdown]
//
// - Welche der folgenden Werte können Sie mit `pa` und `pb` ändern? Warum?

// %%
int c{1};
unsigned d{1};
long e{1};
unsigned long f{1};
bool g{true};

// %% [markdown]
// *Antwort:* 

// %%

// %%

