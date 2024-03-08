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
//  <b>Pointer auf Const</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Pointer auf Const.cpp -->
// <!-- slides/module_130_pointers/topic_140_pointer_to_const.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Wir können Objekte, auf die ein Pointer zeigt verändern:

// %%
int i{1};
int* pi{&i};

// %%
*pi = 10;

// %%
i

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Wenn wir das verhindern wollen, können wir einen Pointer auf `const`
// erzeugen:

// %%
const int i{1};
const int* pci{&i};

// %%
*pci

// %%
// *pi = 10;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können auch einen `const T*` Pointer auf ein Objekt erzeugen, das nicht
//   konstant ist.
// - Das ist eine Ausnahme von der Regl, dass ein Pointer `T*` auf ein Objekt
//   vom Typ `T` zeigen muss.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
int i{1};
const int* pci{&i};

// %%
*pci

// %%
i = 2;

// %%
*pci

// %%
// *pci = 3;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Ein Pointer vom Typ `T*` kann nicht auf ein Objekt vom Typ `const T`
//   zeigen:

// %%
const int i{1};

// %%
// int* pi{&i};

// %%
const int* pci{&i};

// %%
*pci


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Ein Pointer auf Const ist selber *nicht* `const`.
// - Er kann modifiziert werden, so dass er auf ein anderes Objekt zeigt.
// - Man sagt, das `const` ist **low-level**.

// %% tss=["subslide"]
int j{10};
pci = &j;
*pci

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Pointer auf Const
//
// Gegeben seien die folgenden Variablen:

// %% tags=["keep"]
int i{1};
const int ci{2};

// %% tags=["keep"]
int* pi{};
const int* pci{};

// %% [markdown] lang="de"
//
// Welche der folgenden Ausdrücke sind gültig? Warum?

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
// pi = &i;

// %% tags=["keep"]
// pi = &ci;

// %% tags=["keep"]
// pci = &i;

// %% tags=["keep"]
// pci = &ci;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
// *pi = 3;

// %% tags=["keep"]
// *pci = 4;

// %% [markdown] lang="de"
//
// Hängt die Korrektheit des letzten Ausdrucks davon ab, ob `pci` auf ein Objekt
// vom Typ `const int` zeigt?

// %% [markdown] lang="de" tags=["answer"]
// *Antwort:* 
// Nein, Modifikationen über einen Pointer auf const sind immer ungültig.
