// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Member Functions</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Member Functions.cpp -->
// <!-- slides/module_150_classes/topic_110_member_functions.cpp -->

// %% [markdown]
//
// # Member Functions
//
// - Wir können Funktionen in Structs (und Klassen) definieren.
// - Diese Funktionen heißen *Member Functions*.
// - Member Functions werden mit dem `.`-Operator aufgerufen.
// - Im Rumpf einer Member Function können wir auf die anderen Member des
//   Objekts zugreifen.

// %%
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

// %%
Point p1{1.0, 2.0};
Point p2{4.0, 6.0};

// %%
p1.distance(p2)

// %%
p2.move(2.0, 1.0);

// %%
p2.x

// %%
p2.y

// %%
p1.distance(p2)

// %% [markdown]
//
// - Wir können Member Functions auch außerhalb des Structs **definieren**.
// - Im Struct **deklarieren** wir die Member Function nur.
// - Oft werden Structs in Header-Dateien deklariert und ihre Member Functions
//   in einer Quelldatei definiert.
// - Bei der Definition der Funktion schreiben wir den Namen des Structs vor den
//   Funktionsnamen, mit dem `Scope`-Operator `::` als Trennzeichen: `Point::move()`

// %%
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other);
    void move(double dx, double dy);
    void move(const Point& other);
};

// %%
#include <cmath>

// %%
double Point::distance(const Point& other)
{
    double dx{x - other.x};
    double dy{y - other.y};
    return std::sqrt(dx * dx + dy * dy);
}

// %%
void Point::move(double dx, double dy)
{
    x += dx;
    y += dy;
}

// %%
void Point::move(const Point& other)
{
    move(other.x, other.y);
}

// %% [markdown]
//
// - Die Verwendung ist identisch zu der Member Function, die im Struct
//   definiert wurde.

// %%
Point p{1.0, 2.0};

// %%
p.distance(Point{3.0, 4.0})

// %%
p.move(1.0, 1.0)

// %%
p.x

// %% [markdown]
//
// ## `this`-Pointer
//
// - Das Schlüsselwort `this` ist ein Pointer auf das Objekt, auf dem die Member
//   Function aufgerufen wurde.
// - Statt direkt auf Member zuzugreifen, können wir auch `this->` verwenden:

// %%
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other);
    void move(double dx, double dy);
    void move(const Point& other);
};

// %%
double Point::distance(const Point& other)
{
    double dx{this->x - other.x};
    double dy{this->y - other.y};
    return std::sqrt(dx * dx + dy * dy);
}

// %%
void Point::move(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}

// %%
void Point::move(const Point& other)
{
    this->move(other.x, other.y);
}

// %%
Point p1{1.0, 2.0};
Point p2{4.0, 6.0};

// %%
p1.distance(p2)

// %%
p2.move(2.0, 1.0);

// %%
p1.distance(p2)

// %% [markdown]
//
// ## Member-Funktionen und `const`
//
// - Nachdem wir mit dem `this`-Pointer das Objekt modifizieren können, können
//   wir Member-Funktionen nicht auf `const Point`-Objekten aufrufen:

// %%
const Point cp1{1.0, 2.0};
const Point cp2{4.0, 6.0};

// %%
// cp1.move(1.0, 2.0);

// %% [markdown]
//
// - Für Funktionen, wie `distance()` ist das unnötig, da sie das Objekt nicht
//   verändern.

// %%
// cp1.distance(cp2)

// %%
p1.distance(cp2)

// %% [markdown]
//
// ## `const`-qualifizierte Member-Funktionen
//
// - Eine Member-Funktion kann mit `const` qualifiziert werden
// - Dann ist `this` ein Zeiger auf ein `const Point`-Objekt
// - Der `const`-Qualifier steht hinter der Parameterliste:

// %%
struct Point {
    double x{0.0};
    double y{0.0};

    double distance(const Point& other) const;
};

// %%
double Point::distance(const Point& other) const
{
    double dx{x - other.x};
    double dy{y - other.y};
    return std::sqrt(dx * dx + dy * dy);
}

// %%
const Point cp1{1.0, 2.0};
const Point cp2{4.0, 6.0};

// %%
cp1.distance(cp2)

// %% [markdown]
//
// - Auch in `const`-qualifizierten Member-Funktionen können wir
//   den `this`-Pointer explizit verwenden:

// %%
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

// %%
const Point cp1{1.0, 2.0};
const Point cp2{4.0, 6.0};

// %%
cp1.distance(cp2)

// %% [markdown]
//
// ## Überladen von Const-Qualifizierung
//
// - Eine Member-Funktion kann in zwei Varianten existieren:
//   - `const`-qualifiziert
//   - nicht `const`-qualifiziert

// %%
#include <iostream>

// %%
struct Point {
    double x_;
    double y_;

    double x() const;
    double& x();

    double y() const { return y_; }
    // double& y() { return y_; }
};

// %%
double Point::x() const
{
    std::cout << "x() const\n";
    return x_;
}

// %%
double& Point::x()
{
    std::cout << "x()\n";
    return x_;
}

// %%
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

// %%
const Point cp{1.0, 2.0};

// %%
cp.x()

// %%
// cp.x() = 3.0;


// %% [markdown]
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

// %%
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

// %%
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
