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
//  <b>Ein- und Ausgabe</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Ein- und Ausgabe.cpp -->
// <!-- slides/module_120_basics/topic_150_io.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Ein- und Ausgabe von Werten
//
// - Wie können wir einen Wert auf dem Bildschirm ausgeben oder Daten vom
//   Benutzer einlesen?
// - C++ hat dafür keine eingebauten Funktionen.
// - Die Standardbibliothek bietet jedoch Möglichkeiten zum Ein- und Ausgeben
//   von Werten.
// - Um diese Funktionalität nutzen zu können, müssen wir den `iostream`-Header
//   inkludieren.
// - Ein und Ausgabe erfolgt über sogenannte *Streams*.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Ausgabe mit `std::cout`
//
// - Die Standardbibliothek bietet den `std::cout`-Stream an, über den wir
//   Werte ausgeben können.
// - Die Ausgabe erfolgt mit dem `<<`-Operator.
// - Text-Literale werden mit doppelten Anführungszeichen angegeben.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können mehrere Werte hintereinander ausgeben.
// - Das ist eine wiederholte Anwendung des `<<`-Operators.
// - Die Ausgabe erfolgt ohne Leerzeichen dazwischen.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Am Ende der Ausgabe wird von C++ *nicht* automatisch ein Zeilenumbruch
//   ausgegeben:

// %%

// %% [markdown] lang="de"
//
// - Wir haben mehrere Möglichkeiten, einen Zeilenumbruch auszugeben:
//    - `std::endl` gibt einen Zeilenumbruch aus und leert den Ausgabe-Puffer.
//    - `"\n"` gibt einen Zeilenumbruch aus, ohne den Ausgabe-Puffer zu leeren.

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Ein- und Ausgabe ist für viele Typen definiert.
// - Für eigene Typen können wir das Ausgabeformat definieren.

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können nicht nur Zeichenketten ausgeben, sondern auch andere Werte.
// - Später werden wir sehen, dass wir für eigene Typen das Ausgabeformat
//   definieren können.
// - Wir können die Ausgabe von verschiedenen Typen kombinieren.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Boolesche Werte werden als `1` bzw. `0` ausgegeben:

// %%

// %% [markdown] lang="de"
//
// - Wir können den `std::boolalpha`-Manipulator verwenden, um `true` bzw.
//   `false` auszugeben.
// - Dazu müssen wir den `iomanip`-Header inkludieren.
// - Dieser Header enthält auch andere nützliche Manipulatoren.
// - [Core Guidelines ES.24: Use `std::boolalpha` to output `true` and
//   `false`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-boolalpha)
// - Es ist möglich diese Ausgabe zu lokalisieren.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Einlesen mit `std::cin`
//
// - Der `std::cin`-Stream ermöglicht das Einlesen von Werten vom Benutzer.
// - Das Einlesen erfolgt mit dem `>>`-Operator.

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können mehrere Werte hintereinander einlesen.
// - Das ist eine wiederholte Anwendung des `>>`-Operators.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Beispiel: Umrechnung von Fahrenheit in Celsius
//
// - Wir wollen eine Temperatur in Fahrenheit einlesen und in Celsius ausgeben.
// - Die Umrechnung erfolgt mit der Formel
//   $$C = \frac{5}{9} \cdot (F - 32)$$

// %% lang="de"

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Umrechnung von Meilen in Kilometer
//
// - Schreiben Sie ein Programm, das eine Distanz in Meilen einliest und in
//   Kilometern ausgibt.
// - Die Umrechnung erfolgt mit der Formel
//   $$K = 1.609 \cdot M$$
// - Verwenden Sie `std::cout` und `std::cin` für die Ausgabe und das Einlesen.
// - Speichern Sie die Zwischenergebnisse in Variablen.

// %% lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
