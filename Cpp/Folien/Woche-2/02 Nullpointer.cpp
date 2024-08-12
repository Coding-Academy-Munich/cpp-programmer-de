// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Nullpointer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Nullpointer.cpp -->
// <!-- slides/module_130_pointers/topic_120_nullptr.cpp -->

// %% [markdown]
//
// - Die meisten Pointer verweisen auf ein gültiges Objekt:

// %%
int i{1};
int* pi{&i};


// %% [markdown]
//
// ## `nullptr`
//
// - Manchmal möchte man ausdrücken, dass ein Pointer gerade nicht auf ein
//   gültiges Objekt verweist.
// - Dafür kann man in C++ den Nullpointer `nullptr` verwenden.
// - `nullptr` ist ein spezieller Pointer-Wert, der auf kein Objekt verweist.
// - Der Nullpointer darf nicht dereferenziert werden!

// %%
int *pi{nullptr};
long *pl{nullptr};

// %% [markdown]
//
// **Falsch!!!**

// %%
// *pi

// %% [markdown]
//
// [CG: ES.65: Don’t dereference an invalid
// pointer](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es65-dont-dereference-an-invalid-pointer)

// %% [markdown]
//
// - In älteren C++-Programmen wird oft das Literal `0` (oder der Macro `NULL`)
//   für den Nullpointer verwendet.
// - Das wird aber für modernen Code nicht mehr empfohlen.
// - [CG: ES.47: Use nullptr rather than `0` or
//   `NULL`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es47-use-nullptr-rather-than-0-or-null)

// %%
// Old style
int* pi2{0};
int* pi3{NULL};


// %% [markdown]
//
// - Pointer vom gleichen Typ können mit `==` und `!=` verglichen werden.
// - `a == b` ist genau dann wahr, wenn
//   - `a` und `b` beide `nullptr` sind, oder
//   - `a` und `b` beide auf das gleiche Objekt verweisen.

// %%
int i{1};
int j{1};

// %%
int* pi{&i};
int* pj{&j};
int* pn{nullptr};

// %%
#include <iostream>
#include <iomanip>

// %%
std::cout << std::boolalpha << (pi == pj);

// %%
std::cout << std::boolalpha << (pi == &i);

// %%
std::cout << std::boolalpha << (pi == pn);

// %%
std::cout << std::boolalpha << (pn == nullptr);

// %% [markdown]
//
// - In Booleschen Kontexten:
//   - Der Nullpointer ist falsch.
//   - Alle anderen Pointer-Werte sind wahr.

// %%
int i{1};
int* pi{&i};
int* my_nullptr{nullptr};

// %%
//
!pi

// %%
//
!my_nullptr

// %%
#include <iostream>

// %%
if (pi) {
    std::cout << "pi is not nullptr\n";
} else {
    std::cout << "pi is a nullptr\n";
}

// %% [markdown]
//
// [CG: ES.87: Don’t add redundant `==` or `!=` to
// conditions](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es87-dont-add-redundant--or--to-conditions)

// %% [markdown]
//
// ## Mini-Workshop: `nullptr`
//
// - Was ist der Wert von `result` nach Ausführung der folgenden Anweisung?
// - Wie können Sie das testen?

// %%
int* result{};

// %% [markdown]
// *Antwort:* 
// `result` ist `nullptr`.

// %%
#include <iostream>
#include <iomanip>

// %%
// Test
std::cout << std::boolalpha << (result == nullptr);

// %%
if (result) {
    std::cout << "result is not nullptr\n";
} else {
    std::cout << "result is a nullptr\n";
}

// %%
