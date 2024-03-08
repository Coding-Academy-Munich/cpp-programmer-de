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
//  <b>Unique Pointer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Unique Pointer.cpp -->
// <!-- slides/module_160_raii/topic_130_unique_ptr.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `std::unique_ptr`
//
// - Smart Pointer
// - Alleiniges Eigentum an einem Objekt
// - Löscht das Objekt mit `delete`
// - Kann **nicht** kopiert werden
// - Kann verschoben werden, z.B. mit `std::move()`
// - Erzeugen mit `std::make_unique<T>()`

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <memory>
#include <iostream>
#include "lifetime_observer.hpp"
#include "print_info.hpp"

// %% [markdown] lang="de"
//
// Wir verwenden die Klasse `Obs` zum Beobachten des Lebenszyklus

// %% tags=["keep"]
{
    Obs obs{42};
    Obs obs2 = obs;
    Obs obs3{std::move(obs)};
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Erzeugung als "Nullpointer":

// %% tags=["keep"]
std::unique_ptr<Obs> obs{};

// %%
(obs == nullptr)

// %%
print_bool(obs);

// %%
print_null(obs);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::unique_ptr<Obs> obs{nullptr};

// %%
print_null(obs)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Erzeugung aus Pointer:

// %% tags=["keep"]
{
    std::unique_ptr<Obs> obs{new Obs{42}};
    print_null(obs);
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Besser: Erzeugung mit `std::make_unique()`:

// %% tags=["keep"]
{
    std::unique_ptr<Obs> obs{std::make_unique<Obs>(42)};
    print_null(obs);
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Da der Typ relativ lang ist und sich aus dem Template-Argument von
//   `std::make_unique()` ergibt, verwendet man oft `auto`.
// - `auto` deklariert die Variable mit dem Typ des Initialisierers.
//   - `auto` ist kein Typ!
//   - Entfernt Pointer, Referenz, const, volatile, ...
//   - `const`, `*`, `&` können mit `auto` kombiniert werden.

// %% tags=["keep"]
{
    auto obs{std::make_unique<Obs>(42)};
    print_null(obs);
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zugriff auf das Objekt mit dem Dereferenzierungsoperator `*`:
// - `*i` liefert eine Referenz auf das Objekt.

// %% tags=["keep"]
std::unique_ptr<Obs> obs{std::make_unique<Obs>(42)};

// %%
*obs

// %%
*obs = 23;

// %%
*obs


// %% tags=["keep"]
obs = nullptr;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wie bei Zeigern kann man mit `->` auf Member zugreifen:

// %% tags=["keep"]
std::unique_ptr<Obs> obs{std::make_unique<Obs>()};

// %%
obs->value

// %%
obs->value = 10

// %%
obs->value

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Mit `std::move()` kann man das Eigentum an einen anderen Unique-Pointer
//   übergeben:

// %% tags=["keep"]
auto obs{std::make_unique<Obs>(3)};

// %% tags=["alt"]
auto obs2{std::move(obs)};

// %% tags=["keep"]
print_null(obs);
print_null(obs2);

// %%
*obs2

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Nach dem Verschieben ist der ursprüngliche `unique_ptr` ungültig.
//   - `obs` enthält jetzt den Wert `nullptr`.
//   - An `obs` kann ein neuer Wert zugewiesen werden.

// %% tags=["keep"]
print_null(obs);

// %% tags=["keep"]
obs = std::make_unique<Obs>();

// %% tags=["keep"]
print_null(obs);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Unique Pointer und Funktionen
//
// - Funktionen können `unique_ptr`-Parameter haben.
// - Das sollten sie aber nur in Ausnahmefällen.
// - Die meisten Funktionen haben Referenzen oder Pointer als Argumente.
// - Nur Funktionen, die Eigentum an Objekten übernehmen, sollten `unique_ptr`
//   als Parameter haben.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <memory>

// %% tags=["keep"]
void describe(const Obs& obs)
{
    std::cout << "describe(Obs&): " << obs << "\n";
}

// %% tags=["keep"]
void describe(const Obs* obs)
{
    std::cout << "describe(Obs*): " << obs << "\n";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
auto obs{std::make_unique<Obs>()};

// %%
describe(*obs);

// %%
describe(obs.get());

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void take_ownership(std::unique_ptr<Obs> obs)
{
    std::cout << "take_ownership(unique_ptr<Obs>): ";
    if (obs) {
        std::cout << *obs << "\n";
    } else {
        std::cout << "nullptr\n";
    }
}

// %% tags=["keep"]
take_ownership(std::move(obs));

// %% tags=["keep"]
print_null(obs)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## C++ Core Guidelines für Unique Pointer
//
// - [R.30: Take smart pointers as parameters only to explicitly express
//   lifetime
//   semantics](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r30-take-smart-pointers-as-parameters-only-to-explicitly-express-lifetime-semantics)
// - [F.7: For general use, take `T*` or `T&` arguments rather than smart
//   pointers](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f7-for-general-use-take-t-or-t-arguments-rather-than-smart-pointers)
// - [R.32: Take a `unique_ptr<widget>` parameter to express that a function
//   assumes ownership of a
//   `widget`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r32-take-a-unique_ptrwidget-parameter-to-express-that-a-function-assumes-ownership-of-a-widget)
// - [R.33: Take a `unique_ptr<widget>&` parameter to express that a function
//   reseats the
//   `widget`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r33-take-a-unique_ptrwidget-parameter-to-express-that-a-function-reseats-the-widget)
// - [R.37: Do not pass a pointer or reference obtained from an aliased smart
//   pointer](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r37-do-not-pass-a-pointer-or-reference-obtained-from-an-aliased-smart-pointer)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Zugriff
//
// - `*` zum Zugriff auf das Objekt
// - `->` zum Zugriff auf Member
// - `get()` zum Zugriff auf den Pointer
// - `reset()` zum Löschen des Objekts
// - `release()` zum Freigeben des Eigentums

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <memory>

// %% tags=["keep"]
auto obs{std::make_unique<Obs>(1)};
std::cout << *obs << "\n";

// %% tags=["keep"]
describe(*obs);

// %% tags=["keep"]
obs->value

// %% tags=["keep"]
describe(obs.get());

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
obs.reset();

// %% tags=["keep"]
std::cout << obs.get();

// %% tags=["keep"]
obs.reset(new Obs{4});

// %% tags=["keep"]
obs->value

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
auto obs{std::make_unique<Obs>(10)};

// %% tags=["keep"]
Obs* obs_ptr{obs.release()};

// %% tags=["keep"]
print_null(obs);

// %% tags=["keep"]
*obs_ptr

// %% tags=["keep"]
delete obs_ptr;

// %% [markdown] lang="de"
//
// **Vorsicht:** Verwenden Sie `get()` oder `*` für Argumente, nicht `release()`!

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Vektoren von Unique Pointern
//
// - Vektoren von Unique Pointern sind möglich.
// - Listen-Initialisierung ist nicht möglich, da die Elemente nicht kopiert
//   werden können.
// - Die Elemente werden beim Löschen des Vektors automatisch gelöscht.
// - Der Vektor kann nicht kopiert werden.
// - Er kann aber verschoben werden.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <vector>
#include <memory>

// %% [markdown] lang="de"
//
// - Wir definieren einen Typ-Alias für einen Vektor von Unique Pointern.
// - Das erspart uns das Schreiben von `std::vector<std::unique_ptr<Obs>>`.
// - Außerdem kommt der Xeus-Cling-Kernel nicht mit dem langen Typ-Namen klar.

// %% tags=["keep"]
using ObsVec = std::vector<std::unique_ptr<Obs>>;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
ObsVec make_vec(int n = 3)
{
    ObsVec vec{};
    for (int i{1}; i <= n; ++i) {
        vec.push_back(std::make_unique<Obs>(i));
    }
    return vec;
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
ObsVec my_vec{make_vec(5)};

// %%
my_vec.clear();

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
{
    ObsVec your_vec{make_vec(4)};
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
try {
    ObsVec our_vec{make_vec(2)};
    throw std::runtime_error{"oops"};
}
catch (const std::exception& e) {
    std::cout << e.what() << "\n";
}


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Workshop: Inventarverwaltung
//
// Entwickeln Sie ein System, in dem eine Klasse `Inventory` einen Vektor von
// `Item`-Objekten verwaltet. Es gibt verschiedene `Item`-Unterklassen (wie
// `FoodItem`, `ElectronicItem`, etc.) und die `Item`-Klasse muss polymorph
// verwendet werden können.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Implementieren Sie eine `Item`-Klasse, die polymorph verwendet werden kann.
//   Sie soll eine eindeutige Identifikationsnummer und einen Namen speichern.
//   Sie soll außerdem eine virtuelle Methode `std::string Describe() const`
//   bereitstellen.
// - Implementieren Sie eine `FoodItem`-Klasse, die von `Item` erbt. Sie soll
//   ein Verfallsdatum speichern. Die Implementierung von `Describe()` soll das
//   Verfallsdatum enthalten.
// - Implementieren Sie eine `ElectronicItem`-Klasse, die von `Item` erbt. Sie
//   soll eine Garantie-Periode speichern. Die Implementierung von `Describe()`
//   soll die Garantie-Periode enthalten.
// - Implementieren Sie eine `Inventory`-Klasse, die einen Vektor von `Item`
//   Objekten halten kann. Sie soll Methoden bereitstellen, um Items dem
//   Inventar hinzuzufügen und aus dem Inventar zu entfernen. Sie soll außerdem
//   eine Methode bereitstellen, um alle Items im Inventar auszugeben (unter
//   Verwendung ihrer `Describe()`-Methode).
//   - Die `Inventory`-Klasse soll der alleinige Eigentümer ihrer Items sein.
//   - Wie können Sie die Items im Inventar speichern?
//   - Was passiert, wenn die Lebensdauer eines `Inventory`-Objekts endet?
// - Modifizieren Sie Ihre `Item`-Klasse, um zu verifizieren, dass alle Items
//   korrekt gelöscht werden, wenn die Lebensdauer eines `Inventory`-Objekts
//   endet (z.B. indem Sie eine Ausgabe auf `std::cout` schreiben, wenn ein
//   `Item`-Objekt zerstört wird).
// - Erzeugen Sie ein `Inventory`-Objekt in einem lokalen Scope und fügen Sie
//   einige Items hinzu. Beobachten Sie, wie die Items gelöscht werden, wenn das
//   `Inventory`-Objekt den Scope verlässt.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
class Item {
public:
    Item(int id, std::string name) : id_{id}, name_{name} {}
    Item(const Item&) = delete;
    Item& operator=(const Item&) = delete;
    Item(Item&&) = delete;
    Item& operator=(Item&&) = delete;
    virtual ~Item() { std::cout << "Destroying Item " << id_ << "\n"; }

    int GetId() const { return id_; }
    std::string GetName() const { return name_; }

    virtual std::string Describe() const {
        return "Item " + std::to_string(id_) + ": " + name_;
    };

private:
    int id_;
    std::string name_;
};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
class FoodItem : public Item {
public:
    FoodItem(int id, std::string name, std::string bestBefore)
        : Item{id, name}, bestBefore_{bestBefore} {}
    ~FoodItem() { std::cout << "Destroying FoodItem " << Describe() << "\n"; }

    std::string BestBefore() const { return bestBefore_; }

    std::string Describe() const override {
        return Item::Describe() + " (best before " + bestBefore_ + ")";
    }

private:
    std::string bestBefore_;
};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
class ElectronicItem : public Item {
public:
    ElectronicItem(int id, std::string name, std::string warranty)
        : Item{id, name}, warranty_{warranty} {}
    ~ElectronicItem() {
        std::cout << "Destroying ElectronicItem " << Describe() << "\n";
    }

    std::string Warranty() const { return warranty_; }

    std::string Describe() const override {
        return Item::Describe() + " (warranty " + warranty_ + ")";
    }

private:
    std::string warranty_;
};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
class Inventory {
public:
    Inventory() = default;
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;
    Inventory(Inventory&&) = default;
    Inventory& operator=(Inventory&&) = default;
    ~Inventory() {
        std::cout << "Destroying Inventory with " << items_.size() << " items\n";
    }

    void AddItem(std::unique_ptr<Item> item) { items_.push_back(std::move(item)); }

    void PrintItems() const {
        for (const auto& item : items_) {
            std::cout << item->Describe() << "\n";
        }
    }

private:
    std::vector<std::unique_ptr<Item>> items_;
};


// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
{
    Inventory inventory;
    inventory.AddItem(std::make_unique<FoodItem>(1, "Apple", "2021-01-01"));
    inventory.AddItem(std::make_unique<ElectronicItem>(2, "Laptop", "2023-01-01"));
    inventory.PrintItems();
}
