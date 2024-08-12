// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Typen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Typen.cpp -->
// <!-- slides/module_120_basics/topic_110_types.cpp -->

// %% [markdown]
//
// # Quick-Start durch C++
//
// - Überblick über die wichtigsten Sprachkonstrukte
// - Im Allgemeinen wenig Details

// %% [markdown]
//
// ## Ziel: Berechnung von Pfadkosten
//
// Wir wollen folgendes Programm schreiben:
//
// - Gegeben: Liste von Koordinaten $(x, y, z)$ ($z$ ist Höhe).
// - Berechne die Kosten für eine Tour, die die Koordinaten der Reihe nach
//   besucht.
// - Die Kosten für ein Segment sind von der relativen Höhe des Start- und
//   Endpunkts sowie von den $(x, y)$-Koordinaten abhängig.
//
// Dabei gehen wir in kleinen Schritten vor und führen verschiedene
// Sprach-Features ein.

// %% [markdown]
//
// ## Abstand zwischen zwei Punkten
//
// Wir wollen den Abstand zwischen zwei Punkten in der Ebene berechnen, die
// durch ihre $x$ und $y$ Koordinaten gegeben sind, z.B. $p_1 = (1, 2)$ und $p_2
// = (4, 6)$.

// %%

// %% [markdown]
//
// # Kommentare
//
// - `//` bis zum Ende der Zeile
// - `/*` bis zum nächsten `*/`
// - `/* ... */` Kommentare können nicht verschachtelt werden!

// %%
/*
    Dies ist
    ein mehrzeiliger
    Kommentar
*/
123

// %%
// /* Dieser /* scheinbar verschachtelter Kommentar */ funktioniert nicht wie man denkt! */
123

// %% [markdown]
//
// # Variablen und Datentypen
//
// - Wir wollen die Differenz der Koordinaten von $p_1$ und $p_2$ nicht immer wieder angeben.
// - Daher führen wir Variablen ein:

// %%

// %%

// %% [markdown]
//
// - Mit Daten vom Typ `int` können wir nur ganzzahlige Koordinaten angeben.
// - Es wäre besser, Gleitkommazahlen zu verwenden:

// %%

// %%

// %% [markdown]
//
// ## Typen
//
// - In C++ hat jede Variable und jeder Ausdruck einen eindeutigen Typ.
// - Ein *Typ*
//     - hat eine Menge von möglichen Werten,
//     - definiert die Operationen, die auf diesen Werten möglich sind.

// %% [markdown]
//
// ### Einige Fundamentale Typen
//
// | Typ         | Beschreibung      | Größe   | Werte     | &nbsp;   | Literale Syntax   |
// | :---------- | :---------------- | ------: | :-------: | :------: | ----------------- |
// | `bool`      | Boolesche Werte   | N/A     | `false`   | `true`   | `true`            |
// | `char`      | Zeichen           | 8 Bit   | 0         | 127      | `'a'`             |
// | `int`       | Zahlen            | 16 Bit  | -32768    | 32767    | `123`, `0xF1`     |
// | `unsigned`  | positive Zahlen   | 16 Bit  | 0         | 65535    | `123u`            |
// | `long`      | große Zahlen      | 32 Bit  | -2^31     | 2^31 - 1 | `123L`            |
// | `long long` | sehr große Zahlen | 64 Bit  | -2^63     | 2^63 - 1 | `123LL`           |
// | `float`     | Gleitkommazahlen  | 6 SD    | 10.0^-38  | 10.0^38  | `1.0f`, `123e-2f` |
// | `double`    | Gleitkommazahlen  | 10 SD   | 10.0^-308 | 10.0^308 | `1.23`, `123e-2`  |
//
// - (SD = Significant Digits, Signifikante Stellen)
// - Typischerweise sind `int` und `unsigned` 32 Bit, aber das ist nicht vom Standard garantiert.

// %% [markdown]
//
// ### Integrale Typen (ganze Zahlen und verwandte Typen)

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Gleitkommazahlen

// %%

// %%

// %%

// %%

// %%


// %% [markdown]
//
// ## Mini-Workshop: Rechenoperationen
//
// In diesem sehr kurzen Workshop werden wir einige Literale in C++ auswerten.
// Der Hauptzweck ist, dass Sie im Umgang mit Notebooks vertraut werden.

// %% [markdown]
//
// Was ist der Wert der Hexadezimalzahl `cafe` in Dezimaldarstellung?

// %%

// %% [markdown]
//
// Was passiert, wenn Sie 1 zum unsigned Wert `4'294'967'295` addieren?

// %%

