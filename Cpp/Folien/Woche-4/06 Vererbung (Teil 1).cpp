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
//  <b>Vererbung (Teil 1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Vererbung (Teil 1).cpp -->
// <!-- slides/module_170_oop/topic_110_inheritance_part1.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Eine Klasse kann von einer anderen Klasse erben.
// - Die abgeleitete Klasse erbt alle Attribute und Methoden der Basisklasse.
// - Zeiger und Referenzen auf die Basisklasse können auf Objekte der
//   abgeleiteten Klasse zeigen.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class Base
{
public:
    int x;
    Base(int x) : x{x} { std::cout << "Base::Base(int): x = " << x << "\n"; }

    void print_base() const { std::cout << "Base::print_base(): x = " << x << "\n"; }
};

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die abgeleitete Klasse kann zusätzliche Attribute und Methoden haben.
// - Der Konstruktor der abgeleiteten Klasse muss den Konstruktor der
//   Basisklasse aufrufen.
//   - Das geschieht automatisch, wenn die Basisklasse einen Standardkonstruktor
//     hat.
//   - Ansonsten muss der Konstruktor der abgeleiteten Klasse den Konstruktor
//     der Basisklasse explizit aufrufen.
// - Der Konstruktor der Basisklasse wird vor der Initialisierung der Member
//   aufgerufen.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class Derived : public Base
{
public:
    int y;
    Derived(int x, int y) : Base{x}, y{y}
    {
        std::cout << "Derived::Derived(int, int): x = " << x << ", y = " << y
                  << "\n";
    }

    void print_derived() const
    {
        std::cout << "Derived::print_derived(): x = " << x << ", y = " << y << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Base b{1};

// %% tags=["keep"]
b.x

// %% tags=["keep"]
b.print_base();

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Derived d{2, 3};

// %% tags=["keep"]
d.x

// %% tags=["keep"]
d.y

// %% tags=["keep"]
d.print_base();

// %% tags=["keep"]
d.print_derived();

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Base* pb = &b;

// %% tags=["keep"]
pb->x

// %% tags=["keep"]
pb->print_base();

// %% tags=["keep"]
pb = &d;

// %% tags=["keep"]
pb->print_base();

// %% tags=["keep"]
// pb->print_derived();

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Derived* pd = &d;

// %% tags=["keep"]
pd->x

// %% tags=["keep"]
pd->y

// %% tags=["keep"]
pd->print_base();

// %% tags=["keep"]
pd->print_derived();

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
// pd = &b;

// %% tags=["keep"]
// pd = pb;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Über den Zeiger auf die Basisklasse kann man nicht auf die Methoden der
//   abgeleiteten Klasse zugreifen.
// - Wir hätten gerne eine `print()`-Methode, die sowohl für `Base` als auch
//   für `Derived` funktioniert.
// - Das geht mit virtuellen Methoden.
