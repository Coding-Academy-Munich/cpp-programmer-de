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
//  <b>Einschub: Konstante Pointer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Einschub Konstante Pointer.cpp -->
// <!-- slides/module_130_pointers/topic_300_const_pointer.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - In den meisten Fällen meinen wir einen *Pointer auf Const*, wenn wir von
//   einem *konstanten Pointer* sprechen.
// - Es gibt aber auch wirklich *konstante Pointer*.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Um die Syntax zu verstehen, sehen wir uns die Stellung des Schlüsselworts
//   `const` an.
// - In C++ werden Typen von rechts nach links gelesen.
// - Allerdings kann `const` sowolh links als auch rechts vom Typ stehen.
// - `const int` und `int const` sind also äquivalent.
// - Um Pointer zu verstehen ist die zweite Schreibweise hilfreich.

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Konstanter `int`-Wert:

// %%

// %% [markdown] lang="de"
//
// Pointer auf int:

// %%

// %% [markdown] lang="de" tss=["subslide"]
//
// Pointer auf konstanten `int`-Wert:

// %%

// %% [markdown] lang="de"
//
// Konstanter Pointer auf `int`-Wert:

// %%

// %% [markdown] lang="de"
//
// Konstanter Pointer auf konstanten `int`-Wert:

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Bei einem Pointer auf Const kann man
//   - den Pointer selbst verändern, aber
//   - das referenzierte Objekt nicht verändern.
// - Man spricht auch von einem **low-level `const`**.

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Bei einem konstanten Pointer kann man
//   - den Pointer selbst nicht verändern, aber
//   - das referenzierte Objekt verändern.
// - Man spricht auch von einem **top-level `const`**.

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Bei einem konstanten Pointer auf Const kann man
//   - den Pointer selbst nicht verändern, und
//   - das referenzierte Objekt nicht verändern.
// - Hier haben wir sowohl low-level als auch top-level `const`.

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `constexpr` Pointer
//
// - Pointer können auch `constexpr` sein.
// - Das bedeutet, dass der Pointer zur Compile-Zeit bekannt sein muss.
//   - Das ist z.B. für Variablen mit statischer Speicherdauer der Fall.
// - Der Wert des Pointers kann sich zur Laufzeit ändern.
// - D.h. `constexpr` Pointer sind *immer* top-level `const`.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Auch `constexpr` Pointer auf `const` sind möglich.
// - Ein derartiger Pointer ist sowohl low-level als auch top-level `const`.

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Bei fundamentalen Typen ist es nicht notwendig, `constexpr` zusammen mit
//   `const` zu verwenden.

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: `const` Pointer
//
// Gegeben seien die folgenden Variablendefinitionen:

// %% tags=["keep"]
int i{};
const int ci{};
int* pi{};
const int* pci{};
int* const cpi{};
const int* const cpci{};

// %% [markdown] lang="de"
//
// Welche der folgenden Zuweisungen sind gültig? Warum (nicht)?

// %% tags=["keep"]
// i = 1;

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%
