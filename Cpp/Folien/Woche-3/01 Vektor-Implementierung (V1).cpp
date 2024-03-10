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
//  <b>Vektor-Implementierung (V1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Vektor-Implementierung (V1).cpp -->
// <!-- slides/module_140_collections/topic_160_my_vector_v1.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `MyVector`-Klasse
//
// - Die `std::vector`-Klasse verwendet viele Features und Techniken, die in C++
//   häufig eingesetzt werden.
// - Wir wollen versuchen eine eigene, einfache Version von `std::vector` zu
//   implementieren.
// - Dabei sehen wir, welche Sprachfeatures und Techniken wir dafür benötigen.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Sehr naive Implementierung
//
// - Wir beginnen mit einer sehr naiven Implementierung.
//   - Nur für `int`-Werte.
//   - Wesentlich weniger benutzerfreundlich.
//   - Sehr viel fehleranfälliger.

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-01.png" width="75%">


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-02.png" width="75%">


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-03.png" width="100%">


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-04.png" width="100%">


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-05.png" width="90%">


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct MyVector {
    int* data;
    std::size_t size;
    std::size_t capacity;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void init(MyVector& vec) {
    vec.data = nullptr;
    vec.size = 0;
    vec.capacity = 0;
}

// %% tags=["keep"]
void destroy(MyVector& vec) {
    delete[] vec.data;
    vec.data = nullptr;
    vec.size = 0;
    vec.capacity = 0;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void push_back(MyVector& vec, int value) {
    if (vec.size == vec.capacity) {
        std::size_t new_capacity = vec.capacity == 0 ? 1 : vec.capacity * 2;
        int* new_data = new int[new_capacity];
        for (std::size_t i = 0; i < vec.size; ++i) {
            new_data[i] = vec.data[i];
        }
        delete[] vec.data;
        vec.data = new_data;
        vec.capacity = new_capacity;
    }
    vec.data[vec.size] = value;
    ++vec.size;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int at(MyVector& vec, std::size_t index) {
    // The `at()` method should do bounds checking...
    return vec.data[index];
}

// %% tags=["keep"]
std::size_t size(const MyVector& vec) {
    return vec.size;
}

// %% tags=["keep"]
std::size_t capacity(const MyVector& vec) {
    return vec.capacity;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
void print(const MyVector& vec) {
    std::cout << "[";
    for (std::size_t i = 0; i < vec.size; ++i) {
        std::cout << vec.data[i];
        if (i < vec.size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void print_info(const MyVector& vec) {
    std::cout << "size: " << size(vec) << "\n";
    std::cout << "capacity: " << capacity(vec) << "\n";
    std::cout << "data: ";
    print(vec);
    std::cout << "\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Verwendung
//
// - Erzeugen eines `MyVector`-Objekts

// %%
MyVector vec;

// %%
init(vec);

// %%
print_info(vec);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Hinzufügen von Elementen
// - Zugriff auf Elemente

// %%
push_back(vec, 10);

// %% tags=["keep"]
print_info(vec);

// %% tags=["keep"]
at(vec, 0)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Hinzufügen weiterer Elemente
// - Beachten Sie den Unterschied zwischen `size` und `capacity`

// %% tags=["keep"]
push_back(vec, 20);

// %% tags=["keep"]
print_info(vec);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
push_back(vec, 30);

// %% tags=["keep"]
print_info(vec);

// %% tags=["keep"]
at(vec, 2)

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
push_back(vec, 40);
print_info(vec);

// %% tags=["keep"]
push_back(vec, 50);
print_info(vec);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zerstören des `MyVector`-Objekts

// %%
destroy(vec);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Probleme
//
// - `MyVector`-Objekte müssen nach der Erzeugung mit `init()`
//   initialisiert werden.
//   - Diese Two-Step-Initialization ist fehleranfällig.
// - `MyVector`-Objekte müssen nach der Verwendung mit `destroy()`
//   zerstört werden.
//   - Selbst wenn sie in lokalen Variablen gespeichert werden:

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    MyVector vec;
    init(vec);
    // Array for `vec.data` created here...
    push_back(vec, 1);
    // Oops, forgot to call `destroy()`...
}
// Array for `vec.data` leaked here...


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-memory-leak.png" width="75%">


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Probleme
//
// - `MyVector`-Objekte werden nicht richtig kopiert.
//   - `MyVector vec2 = vec;`
//   - Kopiert die Struct
//   - Kopiert **nicht** die Daten auf dem Heap
// - Damit können `MyVector`-Objekte nicht "per value" übergeben werden.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    MyVector vec;
    init(vec);
    push_back(vec, 1);
    push_back(vec, 2);

    MyVector vec2 = vec; // Oops, shallow copy!

    print_info(vec);
    print_info(vec2);

    destroy(vec);
    // destroy(vec2); // Oops, double free!
}

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-copy-error-1.png" width="75%">


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    MyVector vec;
    init(vec);
    push_back(vec, 1);
    push_back(vec, 2);
    push_back(vec, 3);
    MyVector vec2 = vec;

    push_back(vec, 4); // Oops, inconsistent data!

    print_info(vec);
    print_info(vec2);

    destroy(vec);
}

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-copy-error-2.png" width="75%">

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    MyVector vec;
    init(vec);
    push_back(vec, 1);
    push_back(vec, 2);

    MyVector vec2 = vec;

    push_back(vec, 3); // Oops, reallocates!

    print_info(vec);
    print_info(vec2);

    destroy(vec);
}

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-copy-error-3.png" width="75%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-copy-error-4.png" width="75%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-copy-error-5.png" width="75%">


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Rückgabe von `MyVector`-Objekten ist möglich.
// - Aber das ist eher Zufall als Design.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
MyVector return_vec() {
    MyVector res;
    init(res);
    push_back(res, 1);
    push_back(res, 2);
    return res;
}

// %% tags=["keep"]
MyVector vec = return_vec();
print_info(vec);
destroy(vec);

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-return-1.png" width="75%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-return-2.png" width="75%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-return-3.png" width="75%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/vector-return-4.png" width="75%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Return Value Optimization (RVO)
//
// <br><br>
// <img src="../img/vector-return-5.png" width="75%">

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Probleme
//
// - Die Daten von `MyVector`-Objekten sind öffentlich:

// %% tags=["keep"]
{
    MyVector vec;
    init(vec);
    push_back(vec, 1);
    push_back(vec, 2);
    print_info(vec);

    vec.data[0] = 42;
    vec.size = 5;
    print_info(vec);

    destroy(vec);
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Probleme
//
// - Wir können keine Operatoren wie `[]` oder `<<` verwenden.
