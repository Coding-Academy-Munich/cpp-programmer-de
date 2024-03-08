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
//  <b>Destruktoren und Vererbung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Destruktoren und Vererbung.cpp -->
// <!-- slides/module_170_oop/topic_130_destruction.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Der Destruktor wird wie andere Funktionen behandelt:
//   - Wenn er nicht virtuell ist, bestimmt der statische Typ, welcher Destruktor
//     aufgerufen wird.
//   - Das ist fast immer falsch wenn Vererbung im Spiel ist!
//   - Wenn die Unterklasse Ressourcen allokiert, werden diese nicht freigegeben.
// - Wir müssen den Destruktor als virtuell deklarieren, damit er korrekt
//   aufgerufen wird.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class BaseV1 {
public:
    ~BaseV1() {
        std::cout << "BaseV1::~BaseV1()\n";
    }
}

// %% tags=["keep"]
class DerivedV1 : public BaseV1 {
public:
    ~DerivedV1() {
        std::cout << "DerivedV1::~DerivedV1()\n";
    }
}

// %% tags=["keep"]
BaseV1* pb = new DerivedV1{};
delete pb;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <memory>

// %% tags=["keep"]
{
    std::unique_ptr<BaseV1> pb = std::make_unique<DerivedV1>();
}


// %% [markdown] lang="de"
//
// - Der Destruktor von `DerivedV1` wird nicht aufgerufen!
// - Wir müssen den Destruktor als virtuell deklarieren, damit er korrekt
//   aufgerufen wird, wenn wir Klassen über Zeiger zerstören wollen.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class Base {
public:
    virtual ~Base() {
        std::cout << "Base::~Base()\n";
    }
};

// %% tags=["keep"]
class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived::~Derived()\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Base* pb = new Derived{};
delete pb;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <memory>

// %% tags=["keep"]
{
    std::unique_ptr<Base> pb = std::make_unique<Derived>();
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Eine häufige Faustregel ist, dass ein Destruktor für eine Basisklasse
//   entweder
//   - public und virtuell oder
//   - protected und nicht virtuell sein muss.
// - Die zweite Form wird oft im [nicht-virtuellen
//   Interface](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface)
//   Pattern eingesetzt.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Destruktoren
//
// Gegeben seien die im folgenden definierten Klassen `Shape`, `Circle` und
// `Rectangle`.
//
// - Schreiben Sie eine Funktion `total_area()`, die die Summe der Flächen aller
//   Objekte für einen Vektor von `std::unique_ptr<Shape>` berechnet.
// - Definieren Sie einen Vektor `shapes`, der Unique Pointer auf Shapes speichert.
// - Speichern Sie in diesem Vektor folgende Objekte:
//   - Ein `Circle` mit Radius 2.0
//   - Ein `Rectangle` mit Breite 3.0 und Höhe 4.0
// - Rufen Sie diese Funktion auf. Was passiert?
// - Entfernen Sie alle Elemente aus `shapes`. Was passiert?
// - Was müssen Sie tun, um den Fehler zu beheben?

// %% tags=["alt", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

class Shape {
public:
    Shape() {
        std::cout << "Shape::Shape()\n";
    }
    virtual ~Shape() {
        std::cout << "Shape::~Shape()\n";
    }
    virtual double area() const = 0;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
constexpr double pi{3.14159265358979323846};
class Circle : public Shape {
public:
    Circle(double radius) : radius_{radius} {
        std::cout << "Circle::Circle()\n";
    }
    ~Circle() {
        std::cout << "Circle::~Circle()\n";
    }
    double area() const override {
        return radius_ * radius_ * pi;
    }
private:
    double radius_;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_{width}, height_{height} {
        std::cout << "Rectangle::Rectangle()\n";
    }
    ~Rectangle() {
        std::cout << "Rectangle::~Rectangle()\n";
    }
    double area() const override {
        return width_ * height_;
    }
private:
    double width_;
    double height_;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <vector>

// %%
double total_area(const std::vector<std::unique_ptr<Shape>>& shapes)
{
    double total{};
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::vector<std::unique_ptr<Shape>> shapes;

// %%
shapes.push_back(std::make_unique<Circle>(2.0));

// %%
shapes.push_back(std::make_unique<Rectangle>(3.0, 4.0));

// %%
total_area(shapes);

// %%
shapes.clear();

// %%
