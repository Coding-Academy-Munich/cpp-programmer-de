// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Konstruktion und Methoden</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Konstruktion und Methoden.cpp -->
// <!-- slides/module_170_oop/topic_150_construction.cpp -->

// %% [markdown]
//
// - Was passiert, wenn im Konstruktor eine virtuelle Methode aufgerufen wird?

// %%
#include <iostream>

// %%
class Base {
public:
    Base() {
        std::cout << "Base::Base()\n";
        print();
    }

    virtual ~Base() = default;

    virtual void print() const {
        std::cout << "Base::print()\n";
    }
};

// %%
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived::Derived()\n";
    }

    void print() const override {
        std::cout << "Derived::print()\n";
    }
};

// %%
Derived d;

// %%
Base* b = new Derived();

// %%
b->print();

// %%
delete b;

// %% [markdown]
//
// - Im Konstruktor der Basisklasse hat das Objekt noch nicht seine endgültige
//   Form
// - Daher wird die Methode der Basisklasse aufgerufen!
