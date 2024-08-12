// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Konstruktoren</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Konstruktoren.cpp -->
// <!-- slides/module_150_classes/topic_160_constructors.cpp -->

// %% [markdown]
//
// ## Konstruktoren
//
// - Unsere `MyVector`-Implementierung kann im Moment nur als leerer Vektor
//   konstruiert werden.
// - Wir würden gerne auch einen Vektor mit vorgegebener Größe oder
//   Initialwerten konstruieren können.
// - Dafür können wir einen *Konstruktor* definieren.

// %% [markdown]
//
// - Ein Konstruktor ist eine spezielle Funktion, die automatisch aufgerufen wird,
//   wenn ein Objekt erzeugt wird.
// - Der Name des Konstruktors ist immer der Name der Klasse.
// - Ein Konstruktor hat keinen Rückgabetyp, nicht einmal `void`.
// - Ein Konstruktor kann überladen werden.

// %% [markdown]
//
// ### Default-Konstruktor
//
// - Ein Konstruktor ohne Parameter wird *Default-Konstruktor* genannt.
// - Wenn wir keinen Konstruktor definieren, wird automatisch ein
//   Default-Konstruktor erzeugt.
// - Der Default-Konstruktor default-initialisiert alle Member-Variablen
//   - Wenn wir Default-Member-Initializer angeben, werden diese verwendet.
// - Der Default-Konstruktor wird *nur* erzeugt, wenn wir *keinen* Konstruktor
//   definieren.
// - Wir können die Default-Implementierung explizit mit `= default;` erzeugen.
// - Wir können mit `= delete;` verhindern, dass ein Default-Konstruktor
//   erzeugt wird.

// %%
class MyVector
{
public:
    // Synthetisierter Default-Konstruktor
    MyVector() = default;
    MyVector(std::size_t size);
    // Delegierender Konstruktor (siehe Implementierung)
    MyVector(std::size_t size, int value);
    MyVector(std::initializer_list<int> init);

    void print();

private:
    std::size_t size_{0};     // Beide Member haben Default-Member-Initializer
    int* data_{nullptr};
};

// %% [markdown]
//
// ## Member-Initialisierungsliste
//
// - Ein Konstruktor kann eine Member-Initialisierungsliste haben.
// - In der Member-Initialisierungsliste werden die Member-Variablen
//   initialisiert.
// - Die Member-Variablen werden in der Reihenfolge initialisiert, in der sie
//   **in der Klasse** deklariert wurden.
// - Die Member-Initialisierungsliste wird durch einen Doppelpunkt `:` vom
//   Konstruktor-Rumpf getrennt.
// - Viele Konstruktoren haben eine Member-Initialisierungsliste, gefolgt von
//   einem leeren Rumpf.

// %%
MyVector::MyVector(std::size_t size) : size_(size), data_(new int[size_]) { }

// %% [markdown]
//
// ### Delegierender Konstruktor
//
// - Ein Konstruktor kann einen anderen Konstruktor aufrufen.
// - Dieser Konstruktor wird *delegierender Konstruktor* genannt.
// - Der delegierende Konstruktor muss den anderen Konstruktor in der
//   Member-Initialisierungsliste aufrufen.
// - Es dürfen dann keine weiteren Member-Initializer angegeben werden.

// %%
MyVector::MyVector(std::size_t size, int value) : MyVector(size)
{
    for (std::size_t i{0}; i != size_; ++i) {
        data_[i] = value;
    }
}

// %% [markdown]
//
// - Dieser Overload ermöglicht es, einen `MyVector` mit einer
//   Initialisierungsliste von Werten zu initialisieren.
// - Wenn ein Konstruktor für den Typ `initializer_list<T>` definiert wird,
//   dann wird er für Initialisierungslisten vom Typ `T` verwendet.
// - Initialisierungslisten mit anderen Typen werden wie üblich behandelt.

// %%
MyVector::MyVector(std::initializer_list<int> init)
    : size_(init.size()), data_(new int[size_])
{
    std::copy(init.begin(), init.end(), data_);
}


// %%
#include <iostream>

// %%
void MyVector::print()
{
    std::cout << "size: " << size_ << "\n";
    std::cout << "data: ";
    for (int i = 0; i != size_; ++i) {
        std::cout << data_[i] << " ";
    }
    std::cout << "\n";
}

// %%
MyVector v1{};

// %%
v1.print();

// %%
MyVector v2(5);

// %%
v2.print();

// %%
MyVector v3(5, 42);

// %%
v3.print();

// %%
MyVector v4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// %%
v4.print();

// %% [markdown]
//
// ## Konvertierende Konstruktoren
//
// - Aus Gründen, die wir später sehen werden, heißen die Konstruktoren, die
//   wir in diesem Abschnitt gesehen haben, *konvertierende Konstruktoren*.

// %% [markdown]
//
// ## Mini-Workshop: Todo-Liste
//
// In dieser Aufgabe sollen Sie eine einfache Todo-Liste implementieren.
//
// - Jede Aufgabe in der Todo-Liste hat einen Titel und einen Booleschen Status
//   (`done`).
// - Implementieren Sie eine Struct `Item` zur Repräsentation einer Aufgabe.
//   - Implementieren Sie einen Konstruktor für `Item`, der einen Titel
//     akzeptiert und den Status auf `false` setzt.
//   - Implementieren Sie einen Konstruktor für `Item`, der einen Titel und
//     einen Status akzeptiert.
//   - Können Sie diese beiden Konstruktoren kombinieren?
//   - Können Sie `Item`-Instanzen ohne Argumente erzeugen, nachdem Sie diese
//     Konstruktoren definiert haben?
//   - Was passiert, wenn Sie keinen expliziten Konstruktor für `Item`
//     definieren?

// %% [markdown]
//
// - Implementieren Sie eine Klasse `TodoList` zur Verwaltung einer Liste von
//   Aufgaben.
//   - Implementieren Sie einen Konstruktor für `TodoList`, der eine
//     Initialisierungsliste von `Item`s akzeptiert.
//   - Implementieren Sie eine Member-Funktion `print()`, die die Liste der
//     Aufgaben ausgibt.
//   - Welche Datenstruktur ist zur Speicherung der Aufgaben sinnvoll?
// - Konstruieren Sie eine `TodoList` mit einigen Aufgaben und geben Sie diese
//   aus.

// %%
struct Item
{
    std::string title;
    bool done;

    Item(const std::string& title, bool done = false) : title(title), done(done) {}
};

// %%
#include <iostream>
#include <iomanip>

void print_item(const Item& item)
{
    std::cout << "Item: '" << item.title << "', " << std::boolalpha << item.done;
}

// %%
print_item(Item{"Task 1"});

// %%
print_item(Item{"Task 2", true});

// %%
// print_item(Item{});

// %%
#include <iostream>

// %%
class TodoList
{
public:
    TodoList(std::initializer_list<Item> init) : items_(init) {}

    void print()
    {
        for (const auto& item : items_) {
            std::cout << (item.done ? "[x] " : "[ ] ") << item.title << "\n";
        }
    }

private:
    std::vector<Item> items_;
};

// %%
// Written in this way to work around a bug in jupytext when processing the file.
Item item1{"Task 1"}, item2{"Task 2", true}, item3{"Task 3", false};
TodoList todo_list{item1, item2, item3};

// %%
todo_list.print();
