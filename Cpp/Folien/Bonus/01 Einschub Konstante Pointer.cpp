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
int const i{};

// %%
i

// %%
const int j{};

// %%
j

// %% [markdown]
//
// Konstanter `int`-Wert:

// %%
int const i{};

// %% [markdown]
//
// Pointer auf int:

// %%
int* pi{};

// %% [markdown]
//
// Pointer auf konstanten `int`-Wert:

// %%
int const* pci{};

// %% [markdown]
//
// Konstanter Pointer auf `int`-Wert:

// %%
int* const cpi{};

// %% [markdown]
//
// Konstanter Pointer auf konstanten `int`-Wert:

// %%
int const* const cpci{};

// %% [markdown]
//
// - Bei einem Pointer auf Const kann man
//   - den Pointer selbst verändern, aber
//   - das referenzierte Objekt nicht verändern.
// - Man spricht auch von einem **low-level `const`**.

// %%
int i{1};
int j{2};
const int* pci{&i};

// %%
pci = &j;

// %%
// *pi = 10;

// %% [markdown]
//
// - Bei einem konstanten Pointer kann man
//   - den Pointer selbst nicht verändern, aber
//   - das referenzierte Objekt verändern.
// - Man spricht auch von einem **top-level `const`**.

// %%
int i{1};
int j{2};
int* const cpi{&i};

// %%
// cpi = &j;

// %%
*cpi = 10;

// %%
i

// %% [markdown]
//
// - Bei einem konstanten Pointer auf Const kann man
//   - den Pointer selbst nicht verändern, und
//   - das referenzierte Objekt nicht verändern.
// - Hier haben wir sowohl low-level als auch top-level `const`.

// %%
int i{1};
int j{2};
const int* const cpci{&i};

// %%
// cpci = &j;

// %%
// *cpci = 10;

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
static int i{};
static int j{1};
constexpr int* cpi{&i}

// %%
*cpi

// %%
// cpi = &j;

// %%
*cpi = 10;

// %%
*cpi

// %%
i

// %% [markdown]
//
// - Auch `constexpr` Pointer auf `const` sind möglich.
// - Ein derartiger Pointer ist sowohl low-level als auch top-level `const`.

// %%
constexpr const int* cpci{&i}

// %%
*cpci

// %%
// cpci = &j;

// %%
// *cpci = 10;

// %% [markdown]
//
// - Bei fundamentalen Typen ist es nicht notwendig, `constexpr` zusammen mit
//   `const` zu verwenden.

// %%
constexpr int i{1};
constexpr const int j{2};

// %%
// i = 10;

// %%
// j = 20;

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
// ci = 2;

// %%
// pi = &i;

// %%
// pi = &ci;

// %%
// pci = &i;

// %%
// pci = &ci;

// %%
// cpi = &i;

// %%
// cpi = &ci;

// %%
// cpci = &i;

// %%
// cpci = &ci;

// %%
// *pi = 1;

// %%
// *pci = 2;

// %%
// *cpi = 3;

// %%
// *cpci = 4;

// %%
// i = *pi;

// %%
// i = *pci;

// %%
// i = *cpi;

// %%
// i = *cpci;
