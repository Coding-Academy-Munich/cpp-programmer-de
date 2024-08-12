// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>C-Style Strings</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 13 C-Style Strings.cpp -->
// <!-- slides/module_140_collections/topic_180_c_strings.cpp -->

// %% [markdown]
//
// - In C++ gibt es zwei Arten von Zeichenketten:
//   - C-Style Strings
//   - `std::string`

// %% [markdown]
//
// ## C-Style Strings
//
// - C-Style Strings sind Zeichenketten, die als `char`-Arrays gespeichert werden
// - Sie werden auch als "Null-terminierte Zeichenketten" bezeichnet, da sie mit
//   einem Null-Byte (`'\0'`) terminiert werden
// - Sie werden in C++ nur noch selten verwendet, da `std::string` viele Vorteile
//   bietet
// - Allerdings sind String-Literale in C++ C-Style Strings: `"Hello, World!"`

// %% [markdown]
//
// ### Deklaration
//
// - C-Style Strings werden als `char`-Arrays deklariert
// - Die Größe des Arrays muss mindestens um 1 größer sein als die Länge der
//   Zeichenkette, da das Null-Byte gespeichert werden muss
// - Die Größe des Arrays kann entweder explizit angegeben werden oder implizit
//   durch die Initialisierung mit einem String-Literal

// %%
char str1[50];

// %%
char str2[]{"Hello, World!"};

// %%
char empty[]{};

// %% [markdown]
//
// - Das Array `empty` hat die Größe 1, da es das Null-Byte enthält!

// %% [markdown]
//
// ## Funktionen mit C-Style Strings
//
// - `std::strcpy`: Kopiert eine Zeichenkette

// %%
char dest[50];
char src[]{"Hello, World!"};

// %%
#include <cstring>

// %%

// %%

// %% [markdown]
//
// - `std::strcat`: Hängt Zeichenketten aneinander
// - Das erste Argument muss genug Platz für das Ergebnis haben

// %%
char str1[50]{"Hello"};
char str2[]{", World!"};

// %%

// %%

// %%

// %% [markdown]
//
// - `std::strlen`: Ermittelt die Länge einer Zeichenkette

// %%
char str[]{"Hello, World!"};

// %%
std::size_t length = std::strlen(str);

// %%
length

// %% [markdown]
//
// - `std::strcmp`: Vergleicht zwei Zeichenketten

// %%
char str1[]{"apple"};
char str2[]{"banana"};

// %%
std::strcmp(str1, str2)

// %%
std::strcmp(str2, str1)

// %%
std::strcmp(str1, str1)

// %% [markdown]
//
// - `std::strncpy`: Kopiert eine bestimmte Anzahl von Zeichen von einer Zeichenkette
// - **Vorsicht:**
//   - Die Zielzeichenkette muss groß genug sein, um die kopierten Zeichen und
//     das Null-Byte zu speichern
//   - Wenn die Quellenzeichenkette kürzer ist als die angegebene Anzahl von
//     Zeichen, wird die Zielzeichenkette nicht mit einem Null-Byte terminiert

// %%
char dest[50];
char src[]{"Hello, World!"};

// %%
std::strncpy(dest, src, 5);
dest[5] = '\0';

// %%
