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
//  <b>Konstruktion und Methoden</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Konstruktion und Methoden.cpp -->
// <!-- slides/module_170_oop/topic_150_construction.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Was passiert, wenn im Konstruktor eine virtuelle Methode aufgerufen wird?

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
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

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived::Derived()\n";
    }

    void print() const override {
        std::cout << "Derived::print()\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Derived d;

// %% tags=["keep"]
Base* b = new Derived();

// %%
b->print();

// %% tags=["keep"]
delete b;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Im Konstruktor der Basisklasse hat das Objekt noch nicht seine endgültige
//   Form
// - Daher wird die Methode der Basisklasse aufgerufen!
