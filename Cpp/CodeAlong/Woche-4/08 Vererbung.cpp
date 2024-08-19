// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Vererbung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Vererbung.cpp -->
// <!-- slides/module_170_oop/topic_110_inheritance_part1.cpp -->

// %% [markdown]
//
// - Eine Klasse kann von einer anderen Klasse erben.
// - Die abgeleitete Klasse erbt alle Attribute und Methoden der Basisklasse.
// - Zeiger und Referenzen auf die Basisklasse können auf Objekte der
//   abgeleiteten Klasse zeigen.

// %%
#include <iostream>

// %%
class Base
{
public:
    int x;
    Base(int x) : x{x} { std::cout << "Base::Base(int): x = " << x << "\n"; }

    void print_base() const { std::cout << "Base::print_base(): x = " << x << "\n"; }
};

// %% [markdown]
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

// %%
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

// %%
Base b{1};

// %%
b.x

// %%
b.print_base();

// %%
Derived d{2, 3};

// %%
d.x

// %%
d.y

// %%
d.print_base();

// %%
d.print_derived();

// %%
Base* pb = &b;

// %%
pb->x

// %%
pb->print_base();

// %%
pb = &d;

// %%
pb->print_base();

// %%
// pb->print_derived();

// %%
Derived* pd = &d;

// %%
pd->x

// %%
pd->y

// %%
pd->print_base();

// %%
pd->print_derived();

// %%
// pd = &b;

// %%
// pd = pb;

// %% [markdown]
//
// - Über den Zeiger auf die Basisklasse kann man nicht auf die Methoden der
//   abgeleiteten Klasse zugreifen.
// - Wir hätten gerne eine `print()`-Methode, die sowohl für `Base` als auch
//   für `Derived` funktioniert.
// - Das geht mit virtuellen Methoden.
