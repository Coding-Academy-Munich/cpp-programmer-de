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
//  <b>C-Style Strings</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 C-Style Strings.cpp -->
// <!-- slides/module_140_collections/topic_180_c_strings.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - In C++ gibt es zwei Arten von Zeichenketten:
//   - C-Style Strings
//   - `std::string`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## C-Style Strings
//
// - C-Style Strings sind Zeichenketten, die als `char`-Arrays gespeichert werden
// - Sie werden auch als "Null-terminierte Zeichenketten" bezeichnet, da sie mit
//   einem Null-Byte (`'\0'`) terminiert werden
// - Sie werden in C++ nur noch selten verwendet, da `std::string` viele Vorteile
//   bietet
// - Allerdings sind String-Literale in C++ C-Style Strings: `"Hello, World!"`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Deklaration
//
// - C-Style Strings werden als `char`-Arrays deklariert
// - Die Größe des Arrays muss mindestens um 1 größer sein als die Länge der
//   Zeichenkette, da das Null-Byte gespeichert werden muss
// - Die Größe des Arrays kann entweder explizit angegeben werden oder implizit
//   durch die Initialisierung mit einem String-Literal

// %% tags=["keep"]
char str1[50];

// %% tags=["keep"]
char str2[]{"Hello, World!"};

// %% tags=["keep"]
char empty[]{};

// %% [markdown] lang="de"
//
// - Das Array `empty` hat die Größe 1, da es das Null-Byte enthält!

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Funktionen mit C-Style Strings
//
// - `std::strcpy`: Kopiert eine Zeichenkette

// %% tags=["keep"]
char dest[50];
char src[]{"Hello, World!"};

// %% tags=["keep"]
#include <cstring>

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `std::strcat`: Hängt Zeichenketten aneinander
// - Das erste Argument muss genug Platz für das Ergebnis haben

// %% tags=["keep"]
char str1[50]{"Hello"};
char str2[]{", World!"};

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `std::strlen`: Ermittelt die Länge einer Zeichenkette

// %% tags=["keep"]
char str[]{"Hello, World!"};

// %% tags=["keep"]
std::size_t length = std::strlen(str);

// %% tags=["keep"]
length

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `std::strcmp`: Vergleicht zwei Zeichenketten

// %% tags=["keep"]
char str1[]{"apple"};
char str2[]{"banana"};

// %% tags=["keep"]
std::strcmp(str1, str2)

// %% tags=["keep"]
std::strcmp(str2, str1)

// %% tags=["keep"]
std::strcmp(str1, str1)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `std::strncpy`: Kopiert eine bestimmte Anzahl von Zeichen von einer Zeichenkette
// - **Vorsicht:**
//   - Die Zielzeichenkette muss groß genug sein, um die kopierten Zeichen und
//     das Null-Byte zu speichern
//   - Wenn die Quellenzeichenkette kürzer ist als die angegebene Anzahl von
//     Zeichen, wird die Zielzeichenkette nicht mit einem Null-Byte terminiert

// %% tags=["keep"]
char dest[50];
char src[]{"Hello, World!"};

// %% tags=["keep"]
std::strncpy(dest, src, 5);
dest[5] = '\0';

// %%
