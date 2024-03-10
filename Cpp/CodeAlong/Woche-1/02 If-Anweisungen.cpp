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
//  <b>If-Anweisungen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 If-Anweisungen.cpp -->
// <!-- slides/module_120_basics/topic_162_if.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Die `if`-Anweisung
//
// - Kontrollfluss wird anhand einer Bedingung gesteuert.
// - Schlüsselwort `if`.
// - Die Bedingung *muss* in Klammern eingeschlossen werden.
// - `else`-Zweig wird genommen, wenn die Bedingung falsch ist.

// %% tags=["keep"]
#include <iostream>

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wenn ein Zweig mehrere Anweisungen enthält, müssen diese in geschweifte
//   Klammern eingeschlossen werden:

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die `else`-Klausel ist optional.
// - Es können beliebig viele `else if`-Klauseln verwendet werden.

// %%

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int value{4};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Das letzte Beispiel könnte auch so geschrieben werden:
// - Natürlich macht man das nicht, aber es ist hilfreich um in den Nächsten
//   Beispielen den Scope der Variablen zu verstehen.

// %% tags=["keep"]
if (value == 1) {
    std::cout << "Value is 1.\n";
}
else {
    if (value == 2) {
        std::cout << "Value is 2.\n";
    }
    else {
        std::cout << "Value is neither 1 nor 2.\n";
    }
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Vorsicht auf das `dangling else`-Problem:

// %% tags=["keep"]
void dangling_else(int value) {
    if (value >= 1)
        if (value <= 10)
            std::cout << "Value is between 1 and 10.\n";
    else
        std::cout << "Value is NOT between 1 and 10.\n";
}

// %%

// %%

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die Bedingung kann einen beliebigen Typ haben, der implizit in `bool`
//   konvertiert werden kann:

// %% tags=["keep"]
int condition{1};

// %%

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
int value{0};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - In der Bedingung können Variablen definiert werden.
// - Der Scope dieser Variablen ist die komplette `if`-Anweisung:
//   - sie sind nur innerhalb der `if`-Anweisung gültig,
//   - sie können auch in den `else`- oder `else if`-Zweigen verwendet werden.

// %% tags=["keep"]
int value{10};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Wenn
//
// - nur eine Variable definiert wird und
// - nach der Definition kein Test angegeben wird
//
// so wird der Wert der Variablen nach `bool` konvertiert.

// %% tags=["keep"]
int value{12};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wenn mehrere Variablen definiert werden muss ein expliziter Test angegeben
//   werden:

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Amerikanische Schulnoten
//
// In diesem Workshop soll zunächst die Note eines Schülers im amerikanischen
// Notensystem bestimmt werden.
//
// - Schreiben Sie ein Programm, das den Benutzer nach einer Punktzahl (einem
//   ganzzahligen Wert) fragt.
// - Verwenden Sie eine `if`-Anweisung um die entsprechende Note anhand der
//   folgenden Skala zu bestimmen:
//   - `A` für Punktzahlen von 90 oder höher
//   - `B` für Punktzahlen zwischen 80 und 89
//   - `C` für Punktzahlen zwischen 70 und 79
//   - `D` für Punktzahlen zwischen 60 und 69
//   - `F` für Punktzahlen unter 60
// - Geben Sie die Note auf dem Bildschirm aus.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Im zweiten Teil der Aufgabe sollen Sie eine Note im amerikanischen
// Notensystem in einen der zugehörigen numerischen Werte konvertieren:
//
// - Schreiben Sie ein Programm, das den Benutzer nach einer Note (ein Zeichen
//   vom Typ `char`) fragt.
// - Verwenden Sie eine `if`-Anweisung, um die Note in einen der zugehörigen
//   numerischen Werte umzuwandeln. Verwenden Sie den niedrigsten möglichen Wert
//   für jede Note.
// - Geben Sie den numerischen Wert auf dem Bildschirm aus.


// %% tags=["subslide"] slideshow={"slide_type": "subslide"}


// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%
