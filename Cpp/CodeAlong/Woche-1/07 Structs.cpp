// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Structs</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Structs.cpp -->
// <!-- slides/module_120_basics/topic_170_structs.cpp -->

// %% [markdown]
//
// # Structs
//
// - Wir behandeln die `x` und `y` Koordinaten von Punkten als unabhängige Werte.
// - Es wäre besser sie zusammenzufassen.
// - Das können wir mit Structs (oder Klassen):

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Structs sind Datentypen, die aus mehreren Attributen bestehen.
// - Die Attribute können unterschiedliche Typen haben.
// - Structs können wie die eingebauten Datentypen verwendet werden:
//  - Wir können Variablen vom Typ `Point` deklarieren.
//  - Wir können `Point`-Objekte erzeugen.
//  - Wir können Structs als Parameter und Rückgabetypen von Funktionen verwenden.
// - Wir können auf die Attribute zugreifen.

// %% [markdown]
//
// ## `Point` als Funktionsparameter
//
// - Wir können Structs als Parameter von Funktionen verwenden:

// %%

// %%

// %% [markdown]
//
// - Damit können wir das Interface der `distance()`-Funktion verbessern:

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Verändern von Attributen
//
// - Wir können die Werte von Attributen durch Zuweisung verändern.
// - Um das Attribut `x` von `p` zu verändern schreiben wir `p.x` auf die linke
//   Seite einer Zuweisung:

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Structs als Argumente
//
// - Funktionsargumente werden als Werte übergeben (d.h., kopiert).
// - Änderungen in der Funktion habe keine Auswirkung auf den übergebenen Wert.
// - Wir werden später sehen, wie wir das ändern können.

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: Fläche eines Rechtecks
//
// In diesem Workshop wollen wir ein Programm schreiben, das die Fläche eines
// Rechtecks unter Verwendung von C++ Structs berechnet.
//
// Definieren Sie eine Struct `Rectangle`, die die Länge (`length`) und Breite
// (`width`) speichert.
//
// Implementieren Sie eine Funktion `area()`, die ein `Rectangle` als Parameter
// entgegennimmt und die Fläche des Rechtecks berechnet. Die Fläche eines
// Rechtecks wird mit der Formel `Fläche = Länge * Breite` berechnet.

// %% [markdown]
//
// Schreiben Sie ein Programm, das folgende Schritte ausführt:
//
// 1. Einlesen der Länge und Breite eines Rechtecks von der Konsole.
// 2. Speichern der eingelesenen Werte in einer Instanz des `Rectangle`-Structs.
// 3. Berechnen der Fläche des Rechtecks mit der Funktion `area()`.
// 4. Ausgeben der berechneten Fläche.

// %%

// %%

// %%

// %%
