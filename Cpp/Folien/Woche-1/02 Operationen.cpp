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
1 == 2

// %%
1 == 1

// %%
1 != 2

// %%
1 != 1

// %% [markdown]
//
// #### Ungleichheit

// %%
1 < 2

// %%
1 < 1

// %%
1 <= 1

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
// Verhindere, dass das Notebook `!` am Anfang einer Zelle als Shell-Escape interpretiert
!true

// %%
//
!false

// %% [markdown]
//
// #### Logisches Und

// %%
true && true

// %%
true && false

// %%
false && true

// %%
false && false

// %% [markdown]
//
// #### Logisches Oder

// %%
true || true

// %%
true || false

// %%
false || true

// %%
false || false

// %% [markdown]
//
// - Die Booleschen Operatoren können auch mit Werten verwendet werden, die
//   nicht den Typ `bool` haben.
// - Bei integralen Werten gilt `0` als falsch und jeder andere Wert als wahr.

// %%
1 || true

// %%
true || 2

// %%
true && 0

// %%
//
!-1

// %%
//
!0

// %% [markdown]
//
// Die Operatoren `&&` und `||` werden nicht-strikt ausgewertet, d.h., wenn nach
// der Auswertung von `x` das Ergebnis schon klar ist wird `y` nicht mehr
// ausgewertet.

// %%
// 1 / 0

// %%
false && (1 / 0)

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
1 + 2 * 3

// %%
(1 + 2) * 3

// %%
1 / 2

// %%
1.0 / 2.0

// %%
1 % 2

// %%
// 1.0 % 2.0

// %% [markdown]
//
// ### Gleitkommazahlen
//
// - Gleitkommazahlen können viele Werte nicht exakt darstellen
// - Das führt zu Rundungsfehlern!

// %%
0.1

// %%
0.1 * 0.1

// %%
0.1 * 0.1 == 0.01

// %%
0.1 * 0.1 - 0.01

// %% [markdown]
//
// ### Typkonversionen
//
// - C++ führt oft automatische Typkonversionen durch.
// - Dabei wird versucht in den Typ zu konvertieren, der die meisten Werte
//   darstellen kann.
// - Das führt manchmal zu unerwarteten Ergebnissen!

// %%
10 + 2.0

// %%
10 + 1.f

// %%
2'000'000'000 + 1 - 2'000'000'000

// %%
2'000'000'000 + 1.f - 2'000'000'000

// %%
2'000'000'000 + 1.0 - 2'000'000'000

// %% [markdown]
//
// Vorsicht bei Arithmetik zwischen `signed` und `unsigned` Typen:

// %%
2u - 1

// %%
1u - 2

// %%
1 - 2u

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
'c' / 'a'

// %%
'c' % 'a'

// %% [markdown]
//
// Bei den Booleschen Werten entspricht
// - `true` der Zahl 1 und
// - `false` der Zahl 0.

// %%
true + true

// %%
true + false

// %%
10 + true

// %%
'a' + 1

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
7 / 2

// %% [markdown]
//
// Welche Möglichkeiten gibt es, um das Ergebnis als Gleitkommazahl zu erhalten?

// %%
7 / 2.0

// %%
7.0 / 2

// %%
7.0 / 2.0

// %% [markdown]
//
// Was ist der Rest von `7 / 2`?

// %%
7 % 2

// %% [markdown]
//
// Wie können Sie in C++ testen, ob gleichzeitig die Bedingungen `0 < 1` und
// `1 < 10` erfüllt sind?

// %%
0 < 1 && 1 < 10

// %% [markdown]
//
// **Hinweis:** Sie können diese Operationen nicht in einen Ausdruck der Form `0
// < 1 < 10` schreiben. Dieser Ausdruck ist in C++ zwar syntaktisch erlaubt, hat
// aber eine andere Bedeutung.

// %%
0 < 1 < 10

// %% [markdown]
//
// Dieser Ausdruck wird wie folgt ausgewertet:
// - `0 < 1` ist wahr, hat also den Wert `true`.
// - `true < 10` wird als `1 < 10` ausgewertet, ergibt also ebenfalls `true`.
//
// In diesem Fall ist das das selbe Ergebnis wie `0 < 1 && 1 < 10`.
//
// Wir sehen den Unterschied, wenn wir zwei andere Bedingungen verwenden:

// %%
10 > 5 && 5 > 2

// %%
10 > 5 > 2
