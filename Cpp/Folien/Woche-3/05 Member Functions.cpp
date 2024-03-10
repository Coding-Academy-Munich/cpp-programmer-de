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
//  <b>Member Functions</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Member Functions.cpp -->
// <!-- slides/module_150_classes/topic_110_member_functions.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Member Functions
//
// - Wir können Funktionen in Structs (und Klassen) definieren.
// - Diese Funktionen heißen *Member Functions*.
// - Member Functions werden mit dem `.`-Operator aufgerufen.
// - Im Rumpf einer Member Function können wir auf die anderen Member des
//   Objekts zugreifen.

// %% tags=["subslide", "alt"] slideshow={"slide_type": "subslide"}
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other)
    {
        double dx{x - other.x};
        double dy{y - other.y};
        return sqrt(dx * dx + dy * dy);
    }

    void move(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    void move(const Point& other)
    {
        move(other.x, other.y);
    }
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
Point p1{1.0, 2.0};
Point p2{4.0, 6.0};

// %%
p1.distance(p2)

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
p2.move(2.0, 1.0);

// %%
p2.x

// %%
p2.y

// %%
p1.distance(p2)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können Member Functions auch außerhalb des Structs **definieren**.
// - Im Struct **deklarieren** wir die Member Function nur.
// - Oft werden Structs in Header-Dateien deklariert und ihre Member Functions
//   in einer Quelldatei definiert.
// - Bei der Definition der Funktion schreiben wir den Namen des Structs vor den
//   Funktionsnamen, mit dem `Scope`-Operator `::` als Trennzeichen: `Point::move()`

// %% tags=["subslide", "alt"] slideshow={"slide_type": "subslide"}
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other);
    void move(double dx, double dy);
    void move(const Point& other);
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <cmath>

// %% tags=["keep"]
double Point::distance(const Point& other)
{
    double dx{x - other.x};
    double dy{y - other.y};
    return std::sqrt(dx * dx + dy * dy);
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
void Point::move(double dx, double dy)
{
    x += dx;
    y += dy;
}

// %% tags=["keep"]
void Point::move(const Point& other)
{
    move(other.x, other.y);
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die Verwendung ist identisch zu der Member Function, die im Struct
//   definiert wurde.

// %% tags=["keep"]
Point p{1.0, 2.0};

// %% tags=["keep"]
p.distance(Point{3.0, 4.0})

// %% tags=["keep"]
p.move(1.0, 1.0)

// %% tags=["keep"]
p.x

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `this`-Pointer
//
// - Das Schlüsselwort `this` ist ein Pointer auf das Objekt, auf dem die Member
//   Function aufgerufen wurde.
// - Statt direkt auf Member zuzugreifen, können wir auch `this->` verwenden:

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other);
    void move(double dx, double dy);
    void move(const Point& other);
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
double Point::distance(const Point& other)
{
    double dx{this->x - other.x};
    double dy{this->y - other.y};
    return std::sqrt(dx * dx + dy * dy);
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
void Point::move(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}

// %% tags=["keep"]
void Point::move(const Point& other)
{
    this->move(other.x, other.y);
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
Point p1{1.0, 2.0};
Point p2{4.0, 6.0};

// %% tags=["keep"]
p1.distance(p2)

// %% tags=["keep"]
p2.move(2.0, 1.0);

// %% tags=["keep"]
p1.distance(p2)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Member-Funktionen und `const`
//
// - Nachdem wir mit dem `this`-Pointer das Objekt modifizieren können, können
//   wir Member-Funktionen nicht auf `const Point`-Objekten aufrufen:

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
const Point cp1{1.0, 2.0};
const Point cp2{4.0, 6.0};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
// cp1.move(1.0, 2.0);

// %% [markdown] lang="de"
//
// - Für Funktionen, wie `distance()` ist das unnötig, da sie das Objekt nicht
//   verändern.

// %% tags=["keep"]
// cp1.distance(cp2)

// %% tags=["keep"]
p1.distance(cp2)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `const`-qualifizierte Member-Funktionen
//
// - Eine Member-Funktion kann mit `const` qualifiziert werden
// - Dann ist `this` ein Zeiger auf ein `const Point`-Objekt
// - Der `const`-Qualifier steht hinter der Parameterliste:

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other) const;
};

// %% tags=["keep"]
double Point::distance(const Point& other) const
{
    double dx{x - other.x};
    double dy{y - other.y};
    return std::sqrt(dx * dx + dy * dy);
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
const Point cp1{1.0, 2.0};
const Point cp2{4.0, 6.0};

// %% tags=["keep"]
cp1.distance(cp2)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Auch in `const`-qualifizierten Member-Funktionen können wir
//   den `this`-Pointer explizit verwenden:

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other) const
    {
        double dx{this->x - other.x};
        double dy{this->y - other.y};
        return sqrt(dx * dx + dy * dy);
    }
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
const Point cp1{1.0, 2.0};
const Point cp2{4.0, 6.0};

// %% tags=["keep"]
cp1.distance(cp2)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Überladen von Const-Qualifizierung
//
// - Eine Member-Funktion kann in zwei Varianten existieren:
//   - `const`-qualifiziert
//   - nicht `const`-qualifiziert

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
struct Point {
    double x_;
    double y_;

    double x() const;
    double& x();

    double y() const { return y_; }
    // double& y() { return y_; }
};

// %% tags=["keep"]
double Point::x() const
{
    std::cout << "x() const\n";
    return x_;
}

// %% tags=["keep"]
double& Point::x()
{
    std::cout << "x()\n";
    return x_;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Point p{1.0, 2.0};

// %%
p.x()

// %%
p.y()

// %%
p.x() = 3.0;

// %%
p.x()

// %%
// p.y() = 4.0;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
const Point cp{1.0, 2.0};

// %%
cp.x()

// %%
// cp.x() = 3.0;


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Counter
//
// In diesem Workshop implementieren wir eine Struct `Counter`, die einen Zähler
// darstellt.
//
// - Der Zähler soll einen Wert haben, der mit `0` initialisiert wird.
// - Die Klasse soll folgende Member-Funktionen haben:
//   - `increment()`: Erhöht den Zähler um `1`.
//   - `decrement()`: Verringert den Zähler um `1`.
//   - `value()`: Gibt den aktuellen Wert des Zählers zurück.
//     - Diese Funktion soll so überladen sein, dass damit für Zähler, die nicht
//       `const` sind, der Wert geändert werden kann.
//
// - Implementieren Sie die Klasse `Counter` und testen Sie die
//   Member-Funktionen.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
struct Counter {
    int value_{0};

    void increment()
    {
        ++value_;
    }

    void decrement()
    {
        --value_;
    }

    int value() const
    {
        return value_;
    }

    int& value()
    {
        return value_;
    }
};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
Counter c{};

// %%
c.value()

// %%
c.increment();

// %%
c.value()

// %%
c.decrement();

// %%
c.value()

// %%
c.value() = 42;

// %%
c.value()

// %%
