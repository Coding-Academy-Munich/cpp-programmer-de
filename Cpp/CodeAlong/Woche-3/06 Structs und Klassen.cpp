// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Structs und Klassen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Structs und Klassen.cpp -->
// <!-- slides/module_150_classes/topic_150_structs_and_classes.cpp -->

// %% [markdown]
//
// ## Sichtbarkeit von Membern
//
// - Member von `struct` und `class` können `public`, `protected` oder `private`
//   sein.
// - `public`-Member sind von außen sichtbar.
// - `private`-Member sind nur von Member-Funktionen der Klasse sichtbar.
// - `protected`-Member sind nur von Member-Funktionen der Klasse und von
//   abgeleiteten Klassen sichtbar.
// - Sichtbarkeit ist eine Eigenschaft der Klasse, nicht des Objekts.


// %%
#include <iostream>

struct MyStruct {
public:
    void print() {
        std::cout << public_var << ", " << private_var << "\n";
    }

    int public_var{1};
private:
    int private_var{2};
}

// %%
MyStruct my_struct{};

// %%
my_struct.print();

// %%
my_struct.public_var

// %%
my_struct.public_var = 3;

// %%
// my_struct.private_var

// %% [markdown]
//
// ## Invarianten
//
// - Invarianten sind Eigenschaften eines Objekts, die immer wahr sind.
// - Typischerweise wollen wir den Zustand eines Objekts von der Außenwelt
//   "verstecken", um sicherzustellen, dass seine Invarianten immer wahr sind.
// - Getter und Setter-Methoden sind eine Möglichkeit dies zu erreichen.

// %%
struct MyStruct {
public:
    int get_state() { return state; }
    void set_state(int new_state)
    {
         state = new_state;
         if (state < 0) state = 0;
    }

private:
    int state{1};
}

// %%
MyStruct my_struct{};

// %%
my_struct.get_state()

// %%
my_struct.set_state(3);

// %%
my_struct.get_state()

// %%
my_struct.set_state(-1);

// %%
my_struct.get_state()


// %% [markdown]
//
// ## `struct` vs. `class`
//
// - `struct` und `class` sind in C++ sehr ähnlich.
// - `struct` ist eine Klasse, bei der alle Member standardmäßig `public` sind.
// - `class` ist eine Klasse, bei der alle Member standardmäßig `private` sind.
// - Oft verwendet man `struct` für einfache Datenstrukturen und `class` für
//   Klassen mit Methoden.

// %%
struct MyStruct {
    int default_var{0};
public:
    int public_var{1};
private:
    int private_var{2};
public:
    void print() {
        std::cout << default_var << " " << public_var << " " << private_var << "\n";
    }
};

// %%
class MyClass {
    int default_var{0};
public:
    int public_var{1};
private:
    int private_var{2};
public:
    void print() {
        std::cout << default_var << " " << public_var << " " << private_var << "\n";
    }
};

// %%
MyStruct my_struct{};

// %%
my_struct.print();

// %%
my_struct.default_var

// %%
my_struct.public_var

// %%
// my_struct.private_var


// %%
MyClass my_class{};

// %%
my_class.print();

// %%
// my_class.default_var

// %%
my_class.public_var

// %%
// my_class.private_var

// %% [markdown]
//
// ## Mini-Workshop: Garantieren von Invarianten
//
// Die Struct `MyComplex` soll folgende Invariante haben:
// - `abs` ist immer der Abstand vom Punkt `(0, 0)`
//
// Wie können Sie diese Invariante sicherstellen?
//
// - Sie können das Interface der Struct anpassen um das zu ermöglichen.
// - Möglicherweise empfiehlt es sich dabei, `MyComplex` in eine Klasse
//   umzuwandeln.
// - Benutzer der Struct/Klasse sollten `update_abs` nicht selbst aufrufen müssen.

// %%
#include <cmath>

// %%
struct MyComplex {
    double re{};
    double im{};
    double abs{};

    void update_abs() {
        abs = std::sqrt(re * re + im * im);
    }
};

// %%
MyComplex c;

// %%
c.re = 3;

// %%
c.im = 4;

// %%
c.re

// %%
c.im

// %%
c.abs

// %%
c.update_abs();

// %%
c.abs
