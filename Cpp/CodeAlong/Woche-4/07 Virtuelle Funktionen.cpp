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
//  <b>Virtuelle Funktionen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Virtuelle Funktionen.cpp -->
// <!-- slides/module_170_oop/topic_120_virtual_functions.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Statischer vs. Dynamischer Typ
//
// - *Statischer Typ* eines Objekts
//   - Typ des Objekts zur Compile-Zeit
// - *Dynamischer Typ* eines Objekts
//   - Typ des Objekts zur Laufzeit

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <vector>

// %% tags=["start"]
int i{0};

// %% tags=["start"]
std::vector<int> v{};

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zeiger und Referenzen können auf Subtyp-Instanzen verweisen
//   - statischer Typ oft nicht dynamischer Typ
//   - statischer Typ immer ein Supertyp des dynamischen Typs
// - Das ist möglich bei
//   - Zeigern und Referenzen (z.B. `BaseV1*`, `BaseV1&`)
//   - Typen, die diese Semantik implementieren (z.B. `std::unique_ptr`)
// - Das ist **nicht** möglich bei **Werten** (z.B. `int`, `std::vector`)

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class BaseV1
{
public:
    int x;
    BaseV1(int x) : x{x} {}

    void print() const { std::cout << "BaseV1::print(): x = " << x << "\n"; }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class DerivedV1 : public BaseV1
{
public:
    int y;
    DerivedV1(int x, int y) : BaseV1{x}, y{y} {}

    void print() const
    {
        std::cout << "DerivedV1::print(): x = " << x << ", y = " << y << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
BaseV1 b{1};
DerivedV1 d{2, 3};

// %% tags=["keep"]
BaseV1* pb = &b;    // Statischer Typ: `BaseV1*`, dynamischer Typ: `BaseV1*`
pb->print();

// %% tags=["keep"]
pb = &d;            // Statischer Typ: `BaseV1*`, dynamischer Typ: `DerivedV1*`
pb->print();

// %% tags=["keep"]
DerivedV1* pd = &d; // Statischer Typ: `DerivedV1*`, dynamischer Typ: `DerivedV1*`
pd->print();

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `print()` ist in beiden Klassen definiert
// - Der statische Typ bestimmt, welche Funktion aufgerufen wird:
//
// | Statischer Typ | Aufgerufene Funktion |
// | -------------- | -------------------- |
// | `BaseV1`       | `BaseV1::print()`    |
// | `DerivedV1`    | `DerivedV1::print()` |
//
// - Das ist normalerweise nicht das, was wir wollen!

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Virtuelle Funktionen
//
// - Virtuelle Funktion:
//   - Member-Funktion
//   - In einer Basisklasse deklariert
//   - Kann in einer abgeleiteten Klasse überschrieben werden
// - Syntax:
//   - `virtual` in der Basisklasse
//   - `override` in der abgeleiteten Klasse (optional aber empfohlen)

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class BaseV2 {
public:
    int x;
    BaseV2(int x) : x{x} {}

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

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Aufruf virtueller Funktionen
//
// - `print()` ist eine virtuelle Funktion
// - Der **dynamische Typ** bestimmt, welche Funktion aufgerufen wird:
//
// | Dynamischer Typ | Aufgerufene Funktion |
// | --------------- | -------------------- |
// | `BaseV2`        | `BaseV2::print()`    |
// | `DerivedV2`     | `DerivedV2::print()` |

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
BaseV2 b{1};       // Statischer Typ: `BaseV2`, dynamischer Typ: `BaseV2`
b.print();

// %% tags=["keep"]
DerivedV2 d{2, 3}; // Statischer Typ: `DerivedV2`, dynamischer Typ: `DerivedV2`
d.print();

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
BaseV2* pb = &b; // Statischer Typ: `BaseV2*`, dynamischer Typ: `BaseV2*`
pb->print();
pb = &d;         // Statischer Typ: `BaseV2*`, dynamischer Typ: `DerivedV2*`
pb->print();

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
DerivedV2* pd = &d; // Statischer Typ: `DerivedV2*`, dynamischer Typ: `DerivedV2*`
pd->print();

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Methoden der Basisklasse aufrufen
//
// - Wir können die Methoden der Basisklasse explizit aufrufen:

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <string_view>

// %% tags=["keep"]
class SimpleGreeting {
public:
    virtual void print(std::string_view name) const {
        std::cout << "Hello, " << name << "!\n";
    }
};

// %% tags=["keep"]
class ElaborateGreeting : public SimpleGreeting {
public:
    virtual void print(std::string_view name) const override {
        SimpleGreeting::print(name);
        std::cout << "How are you?\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::unique_ptr<SimpleGreeting> g{std::make_unique<ElaborateGreeting>()};

// %% tags=["keep"]
g->print("World");

// %% tags=["keep"]
g = std::make_unique<SimpleGreeting>();

// %% tags=["keep"]
g->print("World");



// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Rein virtuelle Funktionen
//
// - In vielen Fällen können virtuelle Funktionen in der Basisklasse nicht
//   sinnvoll implementiert werden
// - In diesen Fällen können wir die Funktion als **rein virtuell** deklarieren
// - Syntax:
//   - `= 0` nach dem Funktions-Kopf in der Basisklasse
// - Die Funktion muss in einer abgeleiteten Klasse überschrieben werden

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Konsequenzen
//
// - Eine Klasse mit mindestens einer rein virtuellen Funktion ist eine
//   **abstrakte Klasse**
// - Abstrakte Klassen können nicht instanziiert werden
// - Abstrakte Klassen können als Basisklassen verwendet werden

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class BaseV3 {
public:
    virtual void print() const = 0;
};

// %% tags=["keep"]
class DerivedV3a : public BaseV3 {
public:
    void print() const override {
        std::cout << "DerivedV3a::print()\n";
    }
};

// %% tags=["keep"]
class DerivedV3b : public BaseV3 {
public:
    void print() const override {
        std::cout << "DerivedV3b::print()\n";
    }
};

// %% tags=["keep", "subslide"] lang="de" slideshow={"slide_type": "subslide"}
// BaseV3 b3; // Fehler: Kann nicht instanziiert werden

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
DerivedV3a d3a;
DerivedV3b d3b;

// %% tags=["keep"]
BaseV3* pb3{&d3a};

// %% tags=["keep"]
pb3->print();

// %% tags=["keep"]
pb3 = &d3b;

// %% tags=["keep"]
pb3->print();


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Mitarbeiter
//
// In dieser Aufgabe werden wir eine kleine Klassenhierarchie für die
// Repräsentation von Mitarbeitern einer Firma erstellen. Jeder Mitarbeiter hat
// einen Namen und ein Gehalt. Es gibt zwei Arten von Mitarbeitern: Ingenieure
// und Manager, deren Gehalt unterschiedlich berechnet wird. Gehen Sie dabei
// folgendermaßen vor:


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// 1. Erstellen Sie eine Basisklasse namens "Employee" mit den folgenden
//    Membern:
//    - Eine protected Member-Variable `name` vom Typ `std::string` zur
//      Speicherung des Namens des Mitarbeiters.
//    - Eine protected Member-Variablen `base_salary` vom Typ `double` zur
//      Speicherung des Grundgehalts des Mitarbeiters.
//    - Einen öffentlichen Konstruktor, der `name` und `base_salary` als
//      Parameter entgegennimmt und die Member-Variablen initialisiert.
//    - Eine Funktion `get_name()`, die einen `std::string` mit dem Namen des
//      Mitarbeiters zurückgibt.
//    - Eine rein virtuelle Funktion `get_salary()`, die einen `double`-Wert
//      zurückgibt. Diese Funktion soll in abgeleiteten Klassen überschrieben
//      werden.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// 2. Leiten Sie zwei Klassen von der Basisklasse `Employee` ab:
//    - Erstellen Sie eine Klasse namens "Manager" mit den folgenden Membern:
//      - Eine private Member-Variable `bonus` vom Typ `double` zur Speicherung
//        des Bonus.
//      - Einen öffentlichen Konstruktor, der `name`, `base_salary` und `bonus`
//        als Parameter entgegennimmt und die Member-Variablen initialisiert.
//      - Überschreiben Sie die Funktion `get_name()`, so dass sie den Namen des
//        Mitarbeiters gefolgt von ", Manager" zurückgibt. Verwenden Sie dabei
//        `get_name()` aus der Basisklasse.
//      - Überschreiben Sie die Funktion `get_salary()`, um das Gesamtgehalt zu
//        berechnen und zurückzugeben, das die Summe aus Grundgehalt und Bonus
//        ist.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//   - Erstellen Sie eine Klasse namens "Engineer" mit den folgenden Membern:
//     - Eine private Member-Variable `years_of_experience` vom Typ `int` zur
//       Speicherung der Berufserfahrung.
//     - Einen öffentlichen Konstruktor, der `name`, `base_salary` und
//       `years_of_experience` als Parameter entgegennimmt und die
//       Member-Variablen initialisiert.
//     - Überschreiben Sie die Funktion `get_salary()`, um das Gesamtgehalt zu
//       berechnen und zurückzugeben. Das Gesamtgehalt besteht aus dem
//       Grundgehalt plus zusätzlich 1000 Euro für jedes Jahr Berufserfahrung.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Erstellen sie ein Objekt der Klasse `Manager` mit dem Namen "John Doe",
//   einem Grundgehalt von 5000 Euro und einem Bonus von 1000 Euro.
// - Erstellen sie ein Objekt der Klasse `Engineer` mit dem Namen "Jane Smith",
//   einem Grundgehalt von 4000 Euro und 3 Jahren Berufserfahrung.
// - Rufen Sie die Funktionen `get_name()` und `get_salary()` für jedes Objekt
//   sowohl direkt, als auch über einen Zeiger auf `Employee` auf.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%
