// -*- coding: utf-8 -*-
// %% [markdown]
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

// %% [markdown]
//
// - In den meisten Fällen meinen wir einen *Pointer auf Const*, wenn wir von
//   einem *konstanten Pointer* sprechen.
// - Es gibt aber auch wirklich *konstante Pointer*.

// %% [markdown]
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

// %% [markdown]
//
// Konstanter `int`-Wert:

// %%

// %% [markdown]
//
// Pointer auf int:

// %%

// %% [markdown]
//
// Pointer auf konstanten `int`-Wert:

// %%

// %% [markdown]
//
// Konstanter Pointer auf `int`-Wert:

// %%

// %% [markdown]
//
// Konstanter Pointer auf konstanten `int`-Wert:

// %%

// %% [markdown]
//
// - Bei einem Pointer auf Const kann man
//   - den Pointer selbst verändern, aber
//   - das referenzierte Objekt nicht verändern.
// - Man spricht auch von einem **low-level `const`**.

// %%

// %%

// %%

// %% [markdown]
//
// - Bei einem konstanten Pointer kann man
//   - den Pointer selbst nicht verändern, aber
//   - das referenzierte Objekt verändern.
// - Man spricht auch von einem **top-level `const`**.

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Bei einem konstanten Pointer auf Const kann man
//   - den Pointer selbst nicht verändern, und
//   - das referenzierte Objekt nicht verändern.
// - Hier haben wir sowohl low-level als auch top-level `const`.

// %%

// %%

// %%

// %% [markdown]
//
// ## `constexpr` Pointer
//
// - Pointer können auch `constexpr` sein.
// - Das bedeutet, dass der Pointer zur Compile-Zeit bekannt sein muss.
//   - Das ist z.B. für Variablen mit statischer Speicherdauer der Fall.
// - Der Wert des Pointers kann sich zur Laufzeit ändern.
// - D.h. `constexpr` Pointer sind *immer* top-level `const`.

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Auch `constexpr` Pointer auf `const` sind möglich.
// - Ein derartiger Pointer ist sowohl low-level als auch top-level `const`.

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Bei fundamentalen Typen ist es nicht notwendig, `constexpr` zusammen mit
//   `const` zu verwenden.

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: `const` Pointer
//
// Gegeben seien die folgenden Variablendefinitionen:

// %%
int i{};
const int ci{};
int* pi{};
const int* pci{};
int* const cpi{};
const int* const cpci{};

// %% [markdown]
//
// Welche der folgenden Zuweisungen sind gültig? Warum (nicht)?

// %%
// i = 1;

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%
