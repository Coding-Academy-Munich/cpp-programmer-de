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
//  <b>Funktionen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Funktionen.cpp -->
// <!-- slides/module_120_basics/topic_160_functions.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Funktionen
//
// Wir hatten den Abstand zweier Punkte folgendermaßen berechnet:

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Das ist unpraktisch, wenn wir die Distanz öfters ausrechnen müssen.
// - Wir wollen nun von den Details der Berechnung abstrahieren.
// - Das können wir durch die Definition einer Funktion erreichen:

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Funktionsdefinition
//
// - Eine Funktion wird durch einen Funktionskopf und einen Funktionsrumpf
//   definiert.
// - Der Funktionskopf besteht aus dem Rückgabetyp, dem Funktionsnamen und der
//   Parameterliste.
// - Die Parameterliste besteht aus Parametern, die durch Kommata getrennt sind.
// - Die Parameterliste kann leer sein.
// - Ein Parameter besteht aus einem Typ und (optional) einem Namen.
// - ```cpp
//   double distance(double p1x, double p1y, double p2x, double p2y)
//   ```
// - Der Funktionskopf, gefolgt von einem Semikolon, ist die Funktionsdeklaration.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Der Funktionsrumpf besteht aus einer oder mehreren Anweisungen, die in
//   geschweifte Klammern eingeschlossen sind.
// - Mit dem Schlüsselwort `return` kann ein Wert zurückgegeben werden.
// - ```cpp
//   return sqrt(dx * dx + dy * dy);
//   ```
// - Der Typ des Rückgabewerts muss mit dem Rückgabetyp der Funktion
//   übereinstimmen.
// - Die `return` Anweisung beendet die Funktion. Code der danach kommt wird
//   nicht mehr ausgeführt.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Funktionsaufruf
//
// - Eine Funktion wird durch ihren Funktionsnamen und die Argumente aufgerufen.
// - Die Argumente werden in der Reihenfolge der Parameter in der Parameterliste
//   übergeben.
// - Die Anzahl der Argumente muss mit der Anzahl der Parameter übereinstimmen.
// - Die Argumente werden durch Kommata getrennt.
// - ```cpp
//   distance(1.0, 2.0, 4.0, 6.0)
//   ```

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Funktionen ohne Rückgabewert
//
// - Mit der `distance()`-Funktion können wir eine Funktion schreiben, die die
//   Distanz zwischen zwei Punkten ausgibt.
// - Diese Funktion gibt keinen (sinnvollen) Wert zurück.
// - Der Rückgabetyp einer derartigen Funktion ist `void`.
// - Funktionen, die `void` zurückgeben, brauchen keinen `return`-Ausdruck.
// - Wenn ein `return`-Ausdruck verwendet wird, darf er keinen Wert zurückgeben:
//   ```cpp
//   return;
//   ```

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Party-Gäste
//
// Wenn auf einer Party mit `n` Gästen jeder Gast jeden anderen Gast begrüßt, so
// werden
// ```
// n * (n - 1)
// ```
// Begrüßungen ausgetauscht.
//
// - Schreiben Sie eine Funktion `int greetings(int n)`, die die Anzahl der
//   Begrüßungen für eine Party mit `n` Gästen berechnet.
//   - `greetings(12)` soll also den Wert `132` zurückgeben.
// - Schreiben Sie eine Funktion `void print_greetings(int n)`, die die Anzahl
//   der Begrüßungen für eine Party mit `n` Gästen ausgibt.
//   - `print_greetings(12)` soll den Text
//     ```
//     Auf einer Party mit 12 Gästen werden 132 Begrüßungen ausgetauscht.
//     ```
//     ausgeben.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%
