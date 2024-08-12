// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Operationen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Operationen.cpp -->
// <!-- slides/module_120_basics/topic_120_operations.cpp -->

// %% [markdown]
//
// ## Operationen
//
// C++ bietet die üblichen Operationen an:
// - Vergleichsoperationen
// - Boolesche Operationen (und, oder, nicht)
// - Arithmetik
// - ...

// %% [markdown]
//
// ### Vergleichsoperationen
//
// | Operation | Bedeutung      |
// | :-------: | :------------- |
// | `x == y`  | Gleichheit     |
// | `x != y`  | Ungleichheit   |
// | `x < y`   | Kleiner        |
// | `x <= y`  | Kleiner oder gleich |
// | `x > y`   | Größer         |
// | `x >= y`  | Größer oder gleich |

// %% [markdown]
//
// #### Gleichheit

// %%

// %%

// %%

// %%

// %% [markdown]
//
// #### Ungleichheit

// %%

// %%

// %%

// %% [markdown]
//
// ### Boolesche Operationen
//
// | Operation   | Bedeutung          |
// | :---------: | :----------------- |
// | `x && y`    | Logisches Und      |
// | `x \|\| y`  | Logisches Oder     |
// | `!x`        | Negation           |

// %% [markdown]
//
// #### Negation

// %%

// %%

// %% [markdown]
//
// #### Logisches Und

// %%

// %%

// %%

// %%

// %% [markdown]
//
// #### Logisches Oder

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Die Booleschen Operatoren können auch mit Werten verwendet werden, die
//   nicht den Typ `bool` haben.
// - Bei integralen Werten gilt `0` als falsch und jeder andere Wert als wahr.

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// Die Operatoren `&&` und `||` werden nicht-strikt ausgewertet, d.h., wenn nach
// der Auswertung von `x` das Ergebnis schon klar ist wird `y` nicht mehr
// ausgewertet.

// %%

// %%

// %% [markdown]
//
// ### Arithmetik
//
// | Operation | Bedeutung          |
// | :-------: | :----------------- |
// | `-x`      | Negation           |
// | `x + y`   | Addition           |
// | `x - y`   | Subtraktion        |
// | `x * y`   | Multiplikation     |
// | `x / y`   | Division           |
// | `x % y`   | Rest (Modulus)     |
//
// - Arithmetische Operatoren folgen den übliche Punkt vor Strich Regeln.
// - Mit Klammern kann die Präzedenz verändert werden.

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Gleitkommazahlen
//
// - Gleitkommazahlen können viele Werte nicht exakt darstellen
// - Das führt zu Rundungsfehlern!

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Typkonversionen
//
// - C++ führt oft automatische Typkonversionen durch.
// - Dabei wird versucht in den Typ zu konvertieren, der die meisten Werte
//   darstellen kann.
// - Das führt manchmal zu unerwarteten Ergebnissen!

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// Vorsicht bei Arithmetik zwischen `signed` und `unsigned` Typen:

// %%

// %%

// %%

// %% [markdown]
//
// ### Zeichen und Boolesche Werte
//
// - Zeichen (`char`) und Boolesche Werte sind integrale Typen.
// - Sie können mit den üblichen arithmetischen Operatoren verwendet werden.
// - Zeichen werden dabei als ihre Werte im Zeichensatz des Computers
//   interpretiert.
// - Typischerweise ist das der ASCII-Zeichensatz.


// %%

// %%

// %% [markdown]
//
// Bei den Booleschen Werten entspricht
// - `true` der Zahl 1 und
// - `false` der Zahl 0.

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: Rechenoperationen
//
// In diesem sehr kurzen Workshop werden wir einige Rechenoperationen in C++
// ausprobieren. Der Hauptzweck ist wieder, dass Sie im Umgang mit Notebooks
// vertraut werden.

// %% [markdown]
//
// Was ist das Ergebnis von `7 / 2`?

// %%

// %% [markdown]
//
// Welche Möglichkeiten gibt es, um das Ergebnis als Gleitkommazahl zu erhalten?

// %%

// %%

// %%

// %% [markdown]
//
// Was ist der Rest von `7 / 2`?

// %%

// %% [markdown]
//
// Wie können Sie in C++ testen, ob gleichzeitig die Bedingungen `0 < 1` und
// `1 < 10` erfüllt sind?

// %%
