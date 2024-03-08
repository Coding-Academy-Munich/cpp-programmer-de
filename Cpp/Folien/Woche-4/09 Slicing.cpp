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
//  <b>Slicing</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Slicing.cpp -->
// <!-- slides/module_170_oop/topic_140_slicing.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Slicing tritt auf, wenn ein Objekt einer abgeleiteten Klasse in ein Objekt
//   der Basisklasse kopiert wird.
// - Nur die Attribute der Basisklasse werden kopiert.
// - Die Attribute der abgeleiteten Klasse gehen verloren.
// - Slicing kann auch auftreten, wenn ein Objekt einer abgeleiteten Klasse als
//   "by value" Argument an eine Funktion übergeben wird, die ein Objekt der
//   Basisklasse erwartet.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class BaseV1 {
public:
    int x;
    BaseV1(int x) : x{x} {}
    virtual ~BaseV1() = default;

    virtual void print() const {
        std::cout << "BaseV1::print(): x = " << x << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class DerivedV1 : public BaseV1 {
public:
    int y;
    DerivedV1(int x, int y) : BaseV1{x}, y{y} {}

    void print() const override {
        std::cout << "DerivedV1::print(): x = " << x << ", y = " << y << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
BaseV1 b{1};
b.print();

// %% tags=["keep"]
DerivedV1 d{2, 3};
d.print();

// %% tags=["keep"]
BaseV1 b2 = d;
b2.print();

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void print_base(BaseV1 b) {
    b.print();
}

// %% tags=["keep"]
print_base(d);

// %% tags=["keep"]
void print_base_ref(const BaseV1& b) {
    b.print();
}

// %% tags=["keep"]
print_base_ref(d);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Slicing kann vermieden werden, indem ein Zeiger oder eine Referenz auf die
//   Basisklasse verwendet wird.
// - Um versehentliches Slicing zu vermeiden ist es empfehlenswert, die
//   Copy-Konstruktoren und Zuweisungsoperatoren der Klassen zu löschen.
// - Eine andere Möglichkeit ist, eine abstrakte Basisklasse zu definieren.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class BaseV2 {
public:
    int x;
    BaseV2(int x) : x{x} {}
    virtual ~BaseV2() = default;
    BaseV2(const BaseV2&) = delete;
    BaseV2& operator=(const BaseV2&) = delete;
    BaseV2(BaseV2&&) = delete;
    BaseV2& operator=(BaseV2&&) = delete;

    virtual void print() const {
        std::cout << "BaseV2::print(): x = " << x << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class DerivedV2 : public BaseV2 {
public:
    int y;
    DerivedV2(int x, int y) : BaseV2{x}, y{y} {}

    void print() const override {
        std::cout << "DerivedV2::print(): x = " << x << ", y = " << y << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
BaseV2 b{1};
b.print();

// %% tags=["keep"]
DerivedV2 d{2, 3};
d.print();

// %% tags=["keep"]
// BaseV2 b2 = d;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void print_base(BaseV2 b) {
    b.print();
}

// %% tags=["keep"]
// print_base(d);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void print_base_ref(const BaseV2& b) {
    b.print();
}

// %% tags=["keep"]
print_base_ref(d);

// %% tags=["keep"]
std::unique_ptr<BaseV2> pb{std::make_unique<DerivedV2>(1, 2)};

// %% tags=["keep"]
print_base_ref(*pb)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Zoo
//
// In diesem Workshop wollen wir ein System zur Verwaltung eines Zoos
// implementieren. Dazu definieren wir eine Klassenhierarchie für Tiere im Zoo.
//
// In dieser Aufgabe konzentrieren wir uns auf die Funktion
// `print_food_requirements()`, die ausgibt, welches Futter wir für ein Tier
// brauchen.
//
// Einer Ihrer Kollegen hat das im Folgenden angegebene Programmgerüst
// entwickelt.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Die gewünschte Ausgabe des Programms ist:
//
// ```
// Elephant needs the following food:
//   hay
//   fruit
//   vegetables
// Zebra needs the following food:
//   hay
//   grass
// Lion needs the following food:
//   meat
// ```

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Ergänzen Sie die Klassenhierarchie um die Klassen `Elephant`, `Zebra` und
//   `Lion`.
//   - Verwenden Sie dabei die Funktion `print_food_requirements` aus der
//     Basisklasse.
// - Die Ausgabe des Programms ist nicht korrekt. Warum?
// - Modifizieren Sie die Klasse `Animal` so, dass die fehlerhafte Anweisung zu
//   einem Compilezeit-Fehler führt.
// - Korrigieren Sie den Fehler.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
class Animal {
public:
    Animal(const std::string& name) : name{name} {}
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;
    Animal(Animal&&) = delete;
    Animal& operator=(Animal&&) = delete;
    virtual ~Animal() = default;

    virtual void print_food_requirements() const
    {
        std::cout << name << " needs the following food: \n";
    }

protected:
    std::string name;
};

// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
class Elephant : public Animal {
public:
    Elephant() : Animal{"Elephant"} {}

    void print_food_requirements() const override
    {
        Animal::print_food_requirements();
        std::cout << "  hay\n";
        std::cout << "  fruit\n";
        std::cout << "  vegetables\n";
    }
};

// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
class Zebra : public Animal {
public:
    Zebra() : Animal{"Zebra"} {}

    void print_food_requirements() const override
    {
        Animal::print_food_requirements();
        std::cout << "  hay\n";
        std::cout << "  grass\n";
    }
};

// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
class Lion : public Animal {
public:
    Lion() : Animal{"Lion"} {}

    void print_food_requirements() const override
    {
        Animal::print_food_requirements();
        std::cout << "  meat\n";
    }
};


// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
using Animals = std::vector<std::shared_ptr<Animal>>;

// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
Animals make_animals()
{
    std::vector<std::shared_ptr<Animal>> res{};
    res.push_back(std::make_shared<Elephant>());
    res.push_back(std::make_shared<Zebra>());
    res.push_back(std::make_shared<Lion>());
    return res;
}

// %% tags=["alt"]
auto animals = make_animals();

// %% tags=["alt"]
for (const auto& animal : animals) {
    animal->print_food_requirements();
}

// %%
