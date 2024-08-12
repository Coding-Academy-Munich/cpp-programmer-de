// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Ein- und Ausgabe</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Ein- und Ausgabe.cpp -->
// <!-- slides/module_120_basics/topic_150_io.cpp -->

// %% [markdown]
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
#include <iostream>

// %% [markdown]
//
// ## Ausgabe mit `std::cout`
//
// - Die Standardbibliothek bietet den `std::cout`-Stream an, über den wir
//   Werte ausgeben können.
// - Die Ausgabe erfolgt mit dem `<<`-Operator.
// - Text-Literale werden mit doppelten Anführungszeichen angegeben.

// %%
std::cout << "Hello, world!";

// %% [markdown]
//
// - Wir können mehrere Werte hintereinander ausgeben.
// - Das ist eine wiederholte Anwendung des `<<`-Operators.
// - Die Ausgabe erfolgt ohne Leerzeichen dazwischen.

// %%
std::cout << "Hello, "
          << "world!";

// %% [markdown]
//
// - Am Ende der Ausgabe wird von C++ *nicht* automatisch ein Zeilenumbruch
//   ausgegeben:

// %%
std::cout << "Hello, ";
std::cout << "world!";

// %% [markdown]
//
// - Wir haben mehrere Möglichkeiten, einen Zeilenumbruch auszugeben:
//    - `std::endl` gibt einen Zeilenumbruch aus und leert den Ausgabe-Puffer.
//    - `"\n"` gibt einen Zeilenumbruch aus, ohne den Ausgabe-Puffer zu leeren.

// %%
std::cout << "Hello, world!" << std::endl;

// %%
std::cout << "Hello, world!\n";

// %% [markdown]
//
// - Ein- und Ausgabe ist für viele Typen definiert.
// - Für eigene Typen können wir das Ausgabeformat definieren.

// %%
std::cout << "An int: " << 17 + 4 << ", a double: " << 1.0;

// %%
std::cout << 0.1 * 10 + 101.0 / 10;

// %% [markdown]
//
// - Wir können nicht nur Zeichenketten ausgeben, sondern auch andere Werte.
// - Später werden wir sehen, dass wir für eigene Typen das Ausgabeformat
//   definieren können.
// - Wir können die Ausgabe von verschiedenen Typen kombinieren.

// %% [markdown]
//
// - Boolesche Werte werden als `1` bzw. `0` ausgegeben:

// %%
std::cout << true;

// %% [markdown]
//
// - Wir können den `std::boolalpha`-Manipulator verwenden, um `true` bzw.
//   `false` auszugeben.
// - Dazu müssen wir den `iomanip`-Header inkludieren.
// - Dieser Header enthält auch andere nützliche Manipulatoren.
// - [Core Guidelines ES.24: Use `std::boolalpha` to output `true` and
//   `false`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-boolalpha)
// - Es ist möglich diese Ausgabe zu lokalisieren.

// %%
#include <iomanip>
std::cout << std::boolalpha << true;

// %% [markdown]
//
// ## Einlesen mit `std::cin`
//
// - Der `std::cin`-Stream ermöglicht das Einlesen von Werten vom Benutzer.
// - Das Einlesen erfolgt mit dem `>>`-Operator.

// %%
#include <iostream>
int i{};
// std::cin >> i;

// %%
std::cout << i << "\n";

// %% [markdown]
//
// - Wir können mehrere Werte hintereinander einlesen.
// - Das ist eine wiederholte Anwendung des `>>`-Operators.

// %%
int i{}, j{};
// std::cin >> i >> j;
std::cout << "i = " << i << ", j = " << j;

// %% [markdown]
//
// ## Beispiel: Umrechnung von Fahrenheit in Celsius
//
// - Wir wollen eine Temperatur in Fahrenheit einlesen und in Celsius ausgeben.
// - Die Umrechnung erfolgt mit der Formel
//   $$C = \frac{5}{9} \cdot (F - 32)$$

// %%
#include <iostream>
double fahrenheit{};

std::cout << "Bitte geben Sie die Temperatur in Fahrenheit ein: ";
std::cin >> fahrenheit;

double celsius{5.0 / 9.0 * (fahrenheit - 32.0)};
std::cout << "Das sind " << celsius << " Grad Celsius.\n";

// %% [markdown]
//
// ## Mini-Workshop: Umrechnung von Meilen in Kilometer
//
// - Schreiben Sie ein Programm, das eine Distanz in Meilen einliest und in
//   Kilometern ausgibt.
// - Die Umrechnung erfolgt mit der Formel
//   $$K = 1.609 \cdot M$$
// - Verwenden Sie `std::cout` und `std::cin` für die Ausgabe und das Einlesen.
// - Speichern Sie die Zwischenergebnisse in Variablen.

// %%
#include <iostream>
double miles{};

std::cout << "Bitte geben Sie die Distanz in Meilen ein: ";
std::cin >> miles;

double kilometers{1.609 * miles};
std::cout << "Das sind " << kilometers << " Kilometer.\n";
