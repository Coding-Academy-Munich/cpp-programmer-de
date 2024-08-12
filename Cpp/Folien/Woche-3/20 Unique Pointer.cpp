// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Unique Pointer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 20 Unique Pointer.cpp -->
// <!-- slides/module_160_raii/topic_130_unique_ptr.cpp -->

// %% [markdown]
//
// ## `std::unique_ptr`
//
// - Smart Pointer
// - Alleiniges Eigentum an einem Objekt
// - Löscht das Objekt mit `delete`
// - Kann **nicht** kopiert werden
// - Kann verschoben werden, z.B. mit `std::move()`
// - Erzeugen mit `std::make_unique<T>()`

// %%
#include <memory>
#include <iostream>
#include "lifetime_observer.hpp"
#include "print_info.hpp"

// %% [markdown]
//
// Wir verwenden die Klasse `Obs` zum Beobachten des Lebenszyklus

// %%
{
    Obs obs{42};
    Obs obs2 = obs;
    Obs obs3{std::move(obs)};
}

// %% [markdown]
//
// - Erzeugung als "Nullpointer":

// %%
std::unique_ptr<Obs> obs{};

// %%
(obs == nullptr)

// %%
print_bool(obs);

// %%
print_null(obs);

// %%
std::unique_ptr<Obs> obs{nullptr};

// %%
print_null(obs)

// %% [markdown]
//
// - Erzeugung aus Pointer:

// %%
{
    std::unique_ptr<Obs> obs{new Obs{42}};
    print_null(obs);
}

// %% [markdown]
//
// Besser: Erzeugung mit `std::make_unique()`:

// %%
{
    std::unique_ptr<Obs> obs{std::make_unique<Obs>(42)};
    print_null(obs);
}

// %% [markdown]
//
// - Da der Typ relativ lang ist und sich aus dem Template-Argument von
//   `std::make_unique()` ergibt, verwendet man oft `auto`.
// - `auto` deklariert die Variable mit dem Typ des Initialisierers.
//   - `auto` ist kein Typ!
//   - Entfernt Pointer, Referenz, const, volatile, ...
//   - `const`, `*`, `&` können mit `auto` kombiniert werden.

// %%
{
    auto obs{std::make_unique<Obs>(42)};
    print_null(obs);
}

// %% [markdown]
//
// - Zugriff auf das Objekt mit dem Dereferenzierungsoperator `*`:
// - `*i` liefert eine Referenz auf das Objekt.

// %%
std::unique_ptr<Obs> obs{std::make_unique<Obs>(42)};

// %%
*obs

// %%
*obs = 23;

// %%
*obs


// %%
obs = nullptr;

// %% [markdown]
//
// - Wie bei Zeigern kann man mit `->` auf Member zugreifen:

// %%
std::unique_ptr<Obs> obs{std::make_unique<Obs>()};

// %%
obs->value

// %%
obs->value = 10

// %%
obs->value

// %% [markdown]
//
// - Mit `std::move()` kann man das Eigentum an einen anderen Unique-Pointer
//   übergeben:

// %%
auto obs{std::make_unique<Obs>(3)};

// %%
auto obs2{std::move(obs)};

// %%
print_null(obs);
print_null(obs2);

// %%
*obs2

// %% [markdown]
//
// - Nach dem Verschieben ist der ursprüngliche `unique_ptr` ungültig.
//   - `obs` enthält jetzt den Wert `nullptr`.
//   - An `obs` kann ein neuer Wert zugewiesen werden.

// %%
print_null(obs);

// %%
obs = std::make_unique<Obs>();

// %%
print_null(obs);

// %% [markdown]
//
// ## Unique Pointer und Funktionen
//
// - Funktionen können `unique_ptr`-Parameter haben.
// - Das sollten sie aber nur in Ausnahmefällen.
// - Die meisten Funktionen haben Referenzen oder Pointer als Argumente.
// - Nur Funktionen, die Eigentum an Objekten übernehmen, sollten `unique_ptr`
//   als Parameter haben.

// %%
#include <iostream>
#include <memory>

// %%
void describe(const Obs& obs)
{
    std::cout << "describe(Obs&): " << obs << "\n";
}

// %%
void describe(const Obs* obs)
{
    std::cout << "describe(Obs*): " << obs << "\n";
}

// %%
auto obs{std::make_unique<Obs>()};

// %%
describe(*obs);

// %%
describe(obs.get());

// %%
void take_ownership(std::unique_ptr<Obs> obs)
{
    std::cout << "take_ownership(unique_ptr<Obs>): ";
    if (obs) {
        std::cout << *obs << "\n";
    } else {
        std::cout << "nullptr\n";
    }
}

// %%
take_ownership(std::move(obs));

// %%
print_null(obs)

// %% [markdown]
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

// %% [markdown]
//
// ## Zugriff
//
// - `*` zum Zugriff auf das Objekt
// - `->` zum Zugriff auf Member
// - `get()` zum Zugriff auf den Pointer
// - `reset()` zum Löschen des Objekts
// - `release()` zum Freigeben des Eigentums

// %%
#include <iostream>
#include <memory>

// %%
auto obs{std::make_unique<Obs>(1)};
std::cout << *obs << "\n";

// %%
describe(*obs);

// %%
obs->value

// %%
describe(obs.get());

// %%
obs.reset();

// %%
std::cout << obs.get();

// %%
obs.reset(new Obs{4});

// %%
obs->value

// %%
auto obs{std::make_unique<Obs>(10)};

// %%
Obs* obs_ptr{obs.release()};

// %%
print_null(obs);

// %%
*obs_ptr

// %%
delete obs_ptr;

// %% [markdown]
//
// **Vorsicht:** Verwenden Sie `get()` oder `*` für Argumente, nicht `release()`!

// %% [markdown]
//
// ## Vektoren von Unique Pointern
//
// - Vektoren von Unique Pointern sind möglich.
// - Listen-Initialisierung ist nicht möglich, da die Elemente nicht kopiert
//   werden können.
// - Die Elemente werden beim Löschen des Vektors automatisch gelöscht.
// - Der Vektor kann nicht kopiert werden.
// - Er kann aber verschoben werden.

// %%
#include <vector>
#include <memory>

// %% [markdown]
//
// - Wir definieren einen Typ-Alias für einen Vektor von Unique Pointern.
// - Das erspart uns das Schreiben von `std::vector<std::unique_ptr<Obs>>`.
// - Außerdem kommt der Xeus-Cling-Kernel nicht mit dem langen Typ-Namen klar.

// %%
using ObsVec = std::vector<std::unique_ptr<Obs>>;

// %%
ObsVec make_vec(int n = 3)
{
    ObsVec vec{};
    for (int i{1}; i <= n; ++i) {
        vec.push_back(std::make_unique<Obs>(i));
    }
    return vec;
}

// %%
ObsVec my_vec{make_vec(5)};

// %%
my_vec.clear();

// %%
{
    ObsVec your_vec{make_vec(4)};
}

// %%
try {
    ObsVec our_vec{make_vec(2)};
    throw std::runtime_error{"oops"};
}
catch (const std::exception& e) {
    std::cout << e.what() << "\n";
}


// %% [markdown]
//
// ## Workshop: Inventarverwaltung
//
// Entwickeln Sie ein System, in dem eine Klasse `Inventory` einen Vektor von
// `Item`-Objekten verwaltet. Es gibt verschiedene `Item`-Unterklassen (wie
// `FoodItem`, `ElectronicItem`, etc.) und die `Item`-Klasse muss polymorph
// verwendet werden können.

// %% [markdown]
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

// %%
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// %%
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

// %%
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

// %%
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

// %%
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


// %%
{
    Inventory inventory;
    inventory.AddItem(std::make_unique<FoodItem>(1, "Apple", "2021-01-01"));
    inventory.AddItem(std::make_unique<ElectronicItem>(2, "Laptop", "2023-01-01"));
    inventory.PrintItems();
}
