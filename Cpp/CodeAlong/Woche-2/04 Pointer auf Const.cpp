// -*- coding: utf-8 -*-
// %% [markdown]
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

// %% [markdown]
//
// Wir können Objekte, auf die ein Pointer zeigt verändern:

// %%

// %%

// %%

// %% [markdown]
//
// Wenn wir das verhindern wollen, können wir einen Pointer auf `const`
// erzeugen:

// %%

// %%

// %%

// %% [markdown]
//
// - Wir können auch einen `const T*` Pointer auf ein Objekt erzeugen, das nicht
//   konstant ist.
// - Das ist eine Ausnahme von der Regl, dass ein Pointer `T*` auf ein Objekt
//   vom Typ `T` zeigen muss.

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Ein Pointer vom Typ `T*` kann nicht auf ein Objekt vom Typ `const T`
//   zeigen:

// %%

// %%

// %%

// %%


// %% [markdown]
//
// - Ein Pointer auf Const ist selber *nicht* `const`.
// - Er kann modifiziert werden, so dass er auf ein anderes Objekt zeigt.
// - Man sagt, das `const` ist **low-level**.

// %%

// %% [markdown]
//
// ## Mini-Workshop: Pointer auf Const
//
// Gegeben seien die folgenden Variablen:

// %%
int i{1};
const int ci{2};

// %%
int* pi{};
const int* pci{};

// %% [markdown]
//
// Welche der folgenden Ausdrücke sind gültig? Warum?

// %%
// pi = &i;

// %%
// pi = &ci;

// %%
// pci = &i;

// %%
// pci = &ci;

// %%
// *pi = 3;

// %%
// *pci = 4;

// %% [markdown]
//
// Hängt die Korrektheit des letzten Ausdrucks davon ab, ob `pci` auf ein Objekt
// vom Typ `const int` zeigt?

// %% [markdown]
// *Antwort:* 
