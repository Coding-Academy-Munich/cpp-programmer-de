// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Slicing</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Slicing.cpp -->
// <!-- slides/module_170_oop/topic_140_slicing.cpp -->

// %% [markdown]
//
// - Slicing tritt auf, wenn ein Objekt einer abgeleiteten Klasse in ein Objekt
//   der Basisklasse kopiert wird.
// - Nur die Attribute der Basisklasse werden kopiert.
// - Die Attribute der abgeleiteten Klasse gehen verloren.
// - Slicing kann auch auftreten, wenn ein Objekt einer abgeleiteten Klasse als
//   "by value" Argument an eine Funktion übergeben wird, die ein Objekt der
//   Basisklasse erwartet.

// %%
#include <iostream>

// %%
class BaseV1 {
public:
    int x;
    BaseV1(int x) : x{x} {}
    virtual ~BaseV1() = default;

    virtual void print() const {
        std::cout << "BaseV1::print(): x = " << x << "\n";
    }
};

// %%
class DerivedV1 : public BaseV1 {
public:
    int y;
    DerivedV1(int x, int y) : BaseV1{x}, y{y} {}

    void print() const override {
        std::cout << "DerivedV1::print(): x = " << x << ", y = " << y << "\n";
    }
};

// %%
BaseV1 b{1};
b.print();

// %%
DerivedV1 d{2, 3};
d.print();

// %%
BaseV1 b2 = d;
b2.print();

// %%
void print_base(BaseV1 b) {
    b.print();
}

// %%
print_base(d);

// %%
void print_base_ref(const BaseV1& b) {
    b.print();
}

// %%
print_base_ref(d);

// %% [markdown]
//
// - Slicing kann vermieden werden, indem ein Zeiger oder eine Referenz auf die
//   Basisklasse verwendet wird.
// - Um versehentliches Slicing zu vermeiden ist es empfehlenswert, die
//   Copy-Konstruktoren und Zuweisungsoperatoren der Klassen zu löschen.
// - Eine andere Möglichkeit ist, eine abstrakte Basisklasse zu definieren.

// %%
#include <iostream>

// %%
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

// %%
class DerivedV2 : public BaseV2 {
public:
    int y;
    DerivedV2(int x, int y) : BaseV2{x}, y{y} {}

    void print() const override {
        std::cout << "DerivedV2::print(): x = " << x << ", y = " << y << "\n";
    }
};

// %%
BaseV2 b{1};
b.print();

// %%
DerivedV2 d{2, 3};
d.print();

// %%
// BaseV2 b2 = d;

// %%
void print_base(BaseV2 b) {
    b.print();
}

// %%
// print_base(d);

// %%
void print_base_ref(const BaseV2& b) {
    b.print();
}

// %%
print_base_ref(d);

// %%
std::unique_ptr<BaseV2> pb{std::make_unique<DerivedV2>(1, 2)};

// %%
print_base_ref(*pb)

// %% [markdown]
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

// %% [markdown]
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

// %% [markdown]
//
// - Ergänzen Sie die Klassenhierarchie um die Klassen `Elephant`, `Zebra` und
//   `Lion`.
//   - Verwenden Sie dabei die Funktion `print_food_requirements` aus der
//     Basisklasse.
// - Die Ausgabe des Programms ist nicht korrekt. Warum?
// - Modifizieren Sie die Klasse `Animal` so, dass die fehlerhafte Anweisung zu
//   einem Compilezeit-Fehler führt.
// - Korrigieren Sie den Fehler.

// %%
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// %%
class Animal {
public:
    Animal(const std::string& name) : name{name} {}
    virtual ~Animal() = default;

    virtual void print_food_requirements() const
    {
        std::cout << name << " needs the following food: \n";
    }

protected:
    std::string name;
};

// %%

// %%

// %%

// %%

// %%
#include <vector>

// %%
using Animals = std::vector<Animal>;

// %%
Animals make_animals()
{
    std::vector<Animal> res{};
    res.push_back(Elephant{});
    res.push_back(Zebra{});
    res.push_back(Lion{});
    return res;
}

// %%
auto animals = make_animals();

// %%
for (const auto& animal : animals) {
    animal.print_food_requirements();
}
