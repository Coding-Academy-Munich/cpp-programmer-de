// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Pointer als Parameter</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Pointer als Parameter.cpp -->
// <!-- slides/module_130_pointers/topic_220_pointer_args.cpp -->

// %% [markdown]
//
// ## Pointer als Funktionsparameter
//
// - Pointer können als Funktionsparameter übergeben werden.
// - Damit sparen wir uns das Kopieren des Objekts.
// - Das ist eine Alternative zu Referenzen.

// %%
#include <iostream>

// %%
void pass_by_pointer_1(const int* pi)
{
    std::cout << *pi << "\n";
}

// %%
int i{1};

// %%
pass_by_pointer_1(&i);

// %% [markdown]
//
// - Wenn eine Funktion ein Pointer-Argument bekommt empfiehlt es sich
//   typischerweise, zu überprüfen, ob der Pointer `nullptr` ist.
// - Wenn der Pointer nicht `nullptr` sein kann ist es besser den Parameter als
//   Referenz zu übergeben.

// %%
void pass_by_pointer_2(const int* pi)
{
    if (pi) {
        std::cout << *pi << "\n";
    } else {
        std::cout << "Oops, got a null pointer!\n";
    }
}

// %%
int i{1};

// %%
pass_by_pointer_2(&i);

// %%
pass_by_pointer_2(nullptr);

// %% [markdown]
//
// - [CG: F.16: For "in" parameters, pass cheaply-copied types by value and
//   others by reference to
//   `const`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f16-for-in-parameters-pass-cheaply-copied-types-by-value-and-others-by-reference-to-const)
// - [CG: F.60: Prefer `T*` over `T&` when "no argument" is a valid
//   option](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f60-prefer-t-over-t-when-no-argument-is-a-valid-option)
// - [CG: F.23: Use a `not_null<T>` to indicate that "null" is not a valid
//   value](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value)

// %% [markdown]
//
// - Wenn wir einen (nicht-konstanten Pointer verwenden), können wir das
//   referenzierte Objekt verändern:

// %%
void pass_by_pointer(int* pi)
{
    ++(*pi);
    std::cout << *pi << "\n";
}

// %%
pass_by_pointer(&i);

// %%
i

// %% [markdown]
//
// <img src="../img/call-21.png" width="30%">

// %% [markdown]
//
// <img src="../img/call-22.png" width="80%">

// %% [markdown]
//
// <img src="../img/call-23.png" width="80%">

// %% [markdown]
//
// - Pointer-Argumente werden häufig für Structs verwendet.
// - Dadurch können wir das Kopieren der Structs vermeiden.
// - Beim Zugriff auf Felder müssen wir den Pointer dereferenzieren.

// %%
#include <iostream>

// %%
struct Point {
    double x;
    double y;
};

// %%
Point my_point{1.0, 2.0};

// %%
void print(const Point* p)
{
    if (p) {
        std::cout << "Point{" << p->x << ", " << p->y << "}";
    } else {
        std::cout << "Cannot print a null pointer!";
    }
}

// %%
print(&my_point);

// %% [markdown]
//
// - Wenn wir Structs per Pointer übergeben, können wir ihre Felder verändern:

// %%
void pass_by_pointer(Point* p)
{
    p->x += 1.0;
    p->y += 2.0;
    print(p);
}

// %%
print(&my_point);

// %%
pass_by_pointer(&my_point);

// %%
print(&my_point);

// %% [markdown]
//
// <img src="../img/call-31.png" width="40%">

// %% [markdown]
//
// <img src="../img/call-32.png" width="60%">

// %% [markdown]
//
// <img src="../img/call-33.png" width="60%">

// %% [markdown]
//
// ## Mini-Workshop: Addition mit Pointern
//
// - Schreiben Sie eine Funktion `int add(const int* a, const int* b)` die die
//   von `a` und `b` referenzierten Objekte addiert und das Ergebnis zurückgibt.
// - Wenn einer der Pointer `nullptr` ist, soll die Funktion den anderen Wert
//   zurückgeben.
// - Wenn beide Pointer `nullptr` sind, soll die Funktion `0` zurückgeben.

// %%
int add(const int* a, const int* b)
{
    int a_value{a ? *a : 0};
    int b_value{b ? *b : 0};
    return a_value + b_value;
}

// %%
int add_1(const int* a, const int* b)
{
    if (a) {
        if (b) {
            return *a + *b;
        } else {
            return *a;
        }
    }
    else {
        if (b) {
            return *b;
        } else {
            return 0;
        }
    }
}

// %%
int a{1};
int b{2};

// %%
add(&a, &b)

// %%
add(&a, nullptr)

// %%
add(nullptr, &b)

// %%
add(nullptr, nullptr)
