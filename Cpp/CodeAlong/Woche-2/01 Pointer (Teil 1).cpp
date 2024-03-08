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
//  <b>Pointer (Teil 1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Pointer (Teil 1).cpp -->
// <!-- slides/module_130_pointers/topic_110_pointers.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Pointer
//
// - Ein Pointer repräsentiert die Adresse eines anderen Objekts.
// - Der Typ eines Pointers auf einen `int`-Wert wird als `int*` geschrieben.
// - Die Adresse eines Objekts erhalten wir mit dem Operator `&`.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `pi` ist ein Pointer auf einen `int`-Wert.
// - Der Wert von `pi` ist die Adresse von `i`.
// - Will man mit `pi` auf den Wert von `i` zugreifen, so schreibt man `*pi`.
// - Das nennen wir *Dereferenzieren* eines Pointers.

// %%

// %%

// %%

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/pointers-01.png" width="50%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/pointers-02.png" width="60%">

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können selbstverständlich auch Pointer für andere Typen haben.
// - Ein Pointer vom Typ `T*` muss auf ein Objekt vom Typ `T` zeigen.
//   - (Mit einigen Ausnahmen.)

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können `*pi` auch auf der linken Seite einer Zuweisung verwenden.
// - Damit wird der Wert von `i` geändert:

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Pointer sind selber Objekte.
// - Wir können also auch `pi` einen neuen Wert zuweisen.
// - Damit ändern wir das Objekt, auf das `pi` zeigt:

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown]
//
// <img src="../img/pointers-03.png" width="60%">

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown]
//
// <img src="../img/pointers-04.png" width="60%">

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Pointer
//
// Gegeben seien die folgenden Variablen:

// %% tags=["keep"]
unsigned int a{1};
bool b{true};

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Definieren Sie Pointer `pa` und `pb`, die auf `a` und `b` zeigen.
// - Geben Sie die Werte von `pa` und `pb` aus.
// - Geben Sie die Werte von `a` und `b` mittels `pa` und `pb` aus.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["keep"]
#include <iostream>

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Verwenden Sie `pa` um den Wert von `a` auf `2` zu ändern.
// - Verwenden Sie `pb` um den Wert von `b` auf `false` zu ändern.
// - Geben Sie die neuen Werte von `a` und `b` mittels `pa` und `pb` aus.

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Welche der folgenden Werte können Sie mit `pa` und `pb` ändern? Warum?

// %% tags=["keep"]
int c{1};
unsigned d{1};
long e{1};
unsigned long f{1};
bool g{true};

// %% [markdown] lang="de" tags=["answer"]
// *Antwort:* 

// %%

// %%

