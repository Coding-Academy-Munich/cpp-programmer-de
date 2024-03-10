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
//  <b>String Views</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 16 String Views.cpp -->
// <!-- slides/module_190_standard_library/topic_130_string_views.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Zwei String-Typen:
//   - `std::string`
//   - `char*`, `char[]`
// - Probleme:
//   - Literale typischerweise `const char*`
//   - Wie sollen Strings an Funktionen übergeben werden?
//     - `std::string` als Wert?
//     - `std::string` als Referenz?
//     - `const char*`?

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## String Views
//
// - `std::string_view` ist ein Paar aus `const char*` und `size_t`
// - Kann (relativ) effizient für C-style strings und `std::string` verwendet
//   werden
// - Kann nicht modifiziert werden
// - Hat kein Eigentum an den Daten
// - Kann als Parameter für Funktionen verwendet werden
//   - `std::string_view` als Wert
// - Soll typischerweise **nicht** als Rückgabetyp verwendet werden

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <string>
#include <string_view>

// %% tags=["keep"]
std::string concat(std::string_view sv1, std::string_view sv2)
{
    std::string result{sv1};
    result += sv2;
    return result;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
using namespace std::literals;

std::string hello{"Hello, World!"};
const char* world{"Hello, World!"};

// %% tags=["keep"]
concat("Hello, ", "World!"s)

    // %% tags=["keep"]
    concat({&hello[0], 7}, world + 7)

    // %% tags=["keep"]
    concat({world, 7}, hello.substr(7))

    // %% tags=["keep"]
    concat("Hello, "sv, {world + 7, 6})

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Vorteile gegenüber anderen Parameter-Typen
//
// - Kann verschiedene Typen von Strings akzeptieren
// - Übergeben von Substrings ist leicht möglich
// - Muss für C-style Strings nicht kopieren
// - Kann mit range-based `for`-Schleifen verwendet werden

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Fallstricke
//
// - Kein Eigentum an den Daten
// - Daher ist es wichtig, dass die Daten während der Lebenszeit des
//   `std::string_view` gültig bleiben

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: String Views
//
// Schreiben Sie eine Funktion `to_lower()`, die eine String-View als Argument
// akzeptiert und einen `std::string` zurückgibt, der die Zeichen des String in
// Kleinbuchstaben enthält.

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Bonus-Aufgabe
//
// Schreiben Sie eine Funktion `rot13()`, die eine String-View als Argument
// akzeptiert und einen `std::string` zurückgibt, der die Zeichen des String
// nach ROT13 verschlüsselt enthält.
//
// - Konvertieren Sie nur Buchstaben, andere Zeichen sollen unverändert bleiben
// - ROT13 ersetzt jeden Buchstaben durch den 13. Buchstaben nach ihm im
//   Alphabet
//   - `A` wird zu `N`, `B` zu `O`, `C` zu `P`, usw.
//   - `N` wird zu `A`, `O` zu `B`, `P` zu `C`, usw.
//   - [Wikipedia Eintrag](https://de.wikipedia.org/wiki/ROT13)
//
// Testen Sie die Funktion, indem Sie den folgenden Text zweimal verschlüsseln:
//
// ```
// The "Magic Words" are Squeamish Ossifrage!?!
// ```


// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %%
