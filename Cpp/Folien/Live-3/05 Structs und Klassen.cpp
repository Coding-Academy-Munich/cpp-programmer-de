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
//  <b>Structs und Klassen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Structs und Klassen.cpp -->
// <!-- slides/module_150_classes/topic_150_structs_and_classes.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
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


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
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

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
MyStruct my_struct{};

// %% tags=["keep"]
my_struct.print();

// %% tags=["keep"]
my_struct.public_var

// %% tags=["keep"]
my_struct.public_var = 3;

// %% tags=["keep"]
// my_struct.private_var

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Invarianten
//
// - Invarianten sind Eigenschaften eines Objekts, die immer wahr sind.
// - Typischerweise wollen wir den Zustand eines Objekts von der Außenwelt
//   "verstecken", um sicherzustellen, dass seine Invarianten immer wahr sind.
// - Getter und Setter-Methoden sind eine Möglichkeit dies zu erreichen.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
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

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
MyStruct my_struct{};

// %% tags=["keep"]
my_struct.get_state()

// %% tags=["keep"]
my_struct.set_state(3);

// %% tags=["keep"]
my_struct.get_state()

// %% tags=["keep"]
my_struct.set_state(-1);

// %% tags=["keep"]
my_struct.get_state()


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `struct` vs. `class`
//
// - `struct` und `class` sind in C++ sehr ähnlich.
// - `struct` ist eine Klasse, bei der alle Member standardmäßig `public` sind.
// - `class` ist eine Klasse, bei der alle Member standardmäßig `private` sind.
// - Oft verwendet man `struct` für einfache Datenstrukturen und `class` für
//   Klassen mit Methoden.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
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

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
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

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
MyStruct my_struct{};

// %% tags=["keep"]
my_struct.print();

// %% tags=["keep"]
my_struct.default_var

// %% tags=["keep"]
my_struct.public_var

// %% tags=["keep"]
// my_struct.private_var


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
MyClass my_class{};

// %% tags=["keep"]
my_class.print();

// %% tags=["keep"]
// my_class.default_var

// %% tags=["keep"]
my_class.public_var

// %% tags=["keep"]
// my_class.private_var

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
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

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <cmath>

// %% tags=["subslide", "alt"] slideshow={"slide_type": "subslide"}
class MyComplex {
public:
    void set_re(double new_re) {
        re = new_re;
        update_abs();
    }

    void set_im(double new_im) {
        im = new_im;
        update_abs();
    }

    double get_re() const {
        return re;
    }

    double get_im() const {
        return im;
    }

    double get_abs() const {
        return abs;
    }
private:
    double re{};
    double im{};
    double abs{};

    void update_abs() {
        abs = std::sqrt(re * re + im * im);
    }
};

// %% tags=["subslide", "alt"] slideshow={"slide_type": "subslide"}
MyComplex c;

// %% tags=["alt"]
c.set_re(3);

// %% tags=["alt"]
c.set_im(4);

// %% tags=["alt"]
c.get_re()

// %% tags=["alt"]
c.get_im()

// %% tags=["alt"]
c.get_abs()
