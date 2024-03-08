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
//  <b>Strings</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Strings.cpp -->
// <!-- slides/module_140_collections/topic_190_strings.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## C++ Strings: `std::string`
//
// In den meisten Fällen ist es besser `std::string` anstelle von C-Strings zu
// verwenden.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `empty`: Prüfen, ob String leer ist

// %% tags=["keep"]
std::string str1{"Hello, World!"};

// %% tags=["keep"]
str1.empty()

// %% tags=["keep"]
std::string str2{};

// %% tags=["keep"]
str2.empty()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `length` oder `size`: Länge eines Strings ermitteln

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
std::string::size_type length{str.length()};

// %% tags=["keep"]
length

// %% tags=["keep"]
str.size()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `operator[]`: Zugriff auf einzelne Zeichen

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str[0]

// %% tags=["keep"]
str[1]

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `at`: Zugriff auf einzelne Zeichen

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.at(0)

// %% tags=["keep"]
str.at(1)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `clear`: Löschen des Strings

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.clear();

// %% tags=["keep"]
str

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `substr`: Extrahieren eines Teilstrings

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.substr(0, 5)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `find`: Ermitteln der Position eines Teilstrings

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
std::string::size_type pos{str.find("World")};

// %% tags=["keep"]
pos

// %% tags=["keep"]
std::string::size_type pos{str.find("Universe")};

// %% tags=["keep"]
pos

// %% tags=["keep"]
pos == std::string::npos

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `append`: Verketten von Strings

// %% tags=["keep"]
std::string str1{"Hello"};
std::string str2{", World!"};

// %% tags=["keep"]
str1.append(str2)

// %% tags=["keep"]
str1

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Vergleichen von Strings
//
// - `<`, `<=`, `>`, `>=`
// - `compare`

// %% tags=["keep"]
std::string str1{"apple"};
std::string str2{"banana"};

// %% tags=["keep"]
str1 < str2

// %% tags=["keep"]
str1 <= str2

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
str1.compare(str2)

// %% tags=["keep"]
str2.compare(str1)

// %% tags=["keep"]
str1.compare(str1)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Modifizieren von Strings
//
// - `replace`: Ersetzen von Teilstrings

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.replace(0, 5, "Goodbye")

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `insert`: Einfügen von Teilstrings

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.insert(5, "Goodbye, ")


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `erase`: Löschen von Teilstrings

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.erase(5, 7)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `push_back`: Anhängen eines Zeichens

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.push_back('!');

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `pop_back`: Entfernen des letzten Zeichens

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.pop_back();

// %% tags=["keep"]
str

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `c_str`: Zugriff auf C-String

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.c_str()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `data`: Zugriff auf Daten
// - Muss für Versionen vor C++11 nicht mit `'\0'` enden
// - Seit C++11 die gleiche Funktion wie `c_str()`

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.data()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `resize`: Ändern der Länge des Strings
//   - Zweites Argument: Zeichen, mit dem aufgefüllt wird
//   - Ohne zweites Argument: `'0'`

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.resize(5);

// %% tags=["keep"]
str

// %% tags=["keep"]
str.resize(20, '!');

// %% tags=["keep"]
str

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `reserve`: Reservieren von Speicherplatz

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
str.reserve(100);

// %% tags=["keep"]
str

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `shrink_to_fit`: Freigeben von nicht benötigtem Speicherplatz

// %% tags=["keep"]
std::string str{"Hello, World!"};
str.reserve(100);

// %% tags=["keep"]
str.capacity()

// %% tags=["keep"]
str.shrink_to_fit();

// %% tags=["keep"]
str.capacity()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Iteration über Strings
//
// - Range-based `for`-Schleife
// - (Iteratoren)

// %% tags=["keep"]
std::string str{"Hello, World!"};

// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
for (char c : str) {
    std::cout << c << '\n';
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## C++-String-Literale
//
// - In C++ gibt es benutzerdefinierte Literale
// - Die Standardbibliothek definiert ein Literal für `std::string`
// - Benötigt `<string>` Header und `using namespace std::string_literals;`
// - Syntax: String-Literal gefolgt von `s`

// %% tags=["keep"]
#include <string>
using namespace std::string_literals;

// %% tags=["keep"]
auto str{"Hello, World!"s};

// %% tags=["keep"]
str

// %% tags=["keep"]
str.size()


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Strings
//
// - Schreiben Sie ein Programm, das einen String vom Benutzer einliest und alle
//   Vorkommen `Dollar` durch `Euro` ersetzt.
// - *Hinweise:*
//   - Zum Einlesen eines Strings mit Leerzeichen ist es zweckmäßig, die
//     Funktion `std::getline(std::cin, str)` zu verwenden.
//   - Es genügt, wenn Sie eine Zeile einlesen.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <string>

using namespace std::string_literals;

// %%

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::string text{"I'm on the grind, chasing a Dollar and a dream. But mostly a Dollar."};
std::string text2{"Dollar and Dollar"};

// %%


// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Schreiben Sie ein Programm, das einen String vom Benutzer einliest und
//   ausgibt, wie viele Vokale (`a`, `e`, `i`, `o`, `u`) der String enthält.
//   Verwenden Sie für diese Aufgabe `std::string`.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <string>

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%
