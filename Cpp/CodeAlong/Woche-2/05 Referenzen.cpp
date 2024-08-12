// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Referenzen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Referenzen.cpp -->
// <!-- slides/module_130_pointers/topic_160_references.cpp -->

// %% [markdown]
//
// ## Referenzen
//
// - Eine **Referenz** (Lvalue-Referenz) ist ein Verweis auf ein anderes Objekt.
// - Syntax: `T&` für eine Referenz auf ein Objekt vom Typ `T`.
// - Anwendungsfälle ähnlich wie Pointer.
// - Referenzen sind keine Objekte.
//   - In manchen Fällen muss der Compiler keinen Speicher reservieren.
//   - Dennoch ist der erzeugte Maschinencode für Pointer und Referenzen meist
//     ähnlich.

// %%

// %%

// %%

// %%

// %%


// %% [markdown]
//
// ### Unterschiede zu Pointern:
//
// - Keine explizite Syntax zum Nehmen der Adresse und Dereferenzieren.
// - Kein "Reseating":
//   - Keine Möglichkeit zum Verändern des Objekts, auf das die Referenz
//     verweist.
//   - Jede Änderung an der Referenz ändert das referenzierte Objekt.
// - Muss gültigen Wert enthalten:
//   - Keine "Null-Referenz".
//   - Keine uninitialisierte Referenz.

// %%
int i{1};
int& ri{i};
int* pi;

// %%
#include <iostream>

// %%

// %%

// %%


// %% [markdown]
//
// ## Referenzen auf const
//
// - Syntax: `const T& cr{c}`.
// - `c` kann durch `cr` nicht verändert werden.
// - `c` muss nicht const sein.
// - Aber **über `cr`** kann `c` nicht verändert werden.
// - Referenzen auf const werden häufig für Funktionsparameter verwendet.

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ## Mini-Workshop: Reference auf Structs
//
// Gegeben seien die beiden Punkte `p1` und `p2`:

// %%
struct Point {
    double x;
    double y;
};

// %%
#include <iostream>

// %%
void print(Point p)
{
    std::cout << "Point{" << p.x << ", " << p.y << "}\n";
}

// %%
Point p1{1.0, 2.0};
Point p2{3.0, 4.0};

// %% [markdown]
//
// Definieren Sie eine Variable `rp1` vom Typ `Point&`, die `p1` referenziert.

// %%

// %% [markdown]
//
// Verwenden Sie `rp1` um die Werte von `p1.x` und `p1.y` auf dem Bildschirm
// auszugeben.

// %%

// %% [markdown]
//
// Verwenden Sie `rp1` um die Werte von `p1.x` und `p1.y` auf die Werte 10.0 und
// 20.0 zu setzen.

// %%

// %%
print(p1);
print(p2);

// %% [markdown]
//
// Können Sie `rp1` verwenden um `p2.x` und `p2.y` auf die Werte 30.0 und 40.0
// zu setzen? Warum (nicht)?

// %% [markdown]
// *Antwort:* 
