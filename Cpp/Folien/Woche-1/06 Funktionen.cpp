// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Funktionen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Funktionen.cpp -->
// <!-- slides/module_120_basics/topic_160_functions.cpp -->

// %% [markdown]
//
// ## Funktionen
//
// Wir hatten den Abstand zweier Punkte folgendermaßen berechnet:

// %%
double dx{4.0 - 1.0};
double dy{6.0 - 2.0};

// %%
#include <iostream>

// %%
std::cout << sqrt(dx * dx + dy * dy);

// %% [markdown]
//
// - Das ist unpraktisch, wenn wir die Distanz öfters ausrechnen müssen.
// - Wir wollen nun von den Details der Berechnung abstrahieren.
// - Das können wir durch die Definition einer Funktion erreichen:

// %%
double distance(double p1x, double p1y, double p2x, double p2y)
{
    double dx{p2x - p1x};
    double dy{p2y - p1y};
    return sqrt(dx * dx + dy * dy);
}

// %%
std::cout << distance(1.0, 2.0, 4.0, 6.0);

// %% [markdown]
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

// %% [markdown]
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
int add(int x, int y)
{
    return x + y;
    std::cout << "This is not executed.\n";
}

// %% [markdown]
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

// %% [markdown]
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

// %%
#include <iostream>

void print_distance(double p1x, double p1y, double p2x, double p2y)
{
    std::cout << "The distance is " << distance(p1x, p1y, p2x, p2y) << ".\n";
}

// %%
print_distance(1, 2, 4, 6);

// %%
print_distance(1.0, 2.0, 4.0, 6.0);

// %% [markdown]
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

// %%
int greetings(int n) { return n * (n - 1); }

// %%
void print_greetings(int n)
{
    std::cout << "Auf einer Party mit " << n << " Gästen werden " << greetings(n)
              << " Begrüßungen ausgetauscht.\n";
}

// %%
std::cout << greetings(12) << "\n";

// %%
print_greetings(12);
