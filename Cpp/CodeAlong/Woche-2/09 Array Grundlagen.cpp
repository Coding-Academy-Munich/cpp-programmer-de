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
//  <b>Array Grundlagen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Array Grundlagen.cpp -->
// <!-- slides/module_140_collections/topic_110_array_basics.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Arrays in C++
//
// - Zusammenhängender Speicherbereich
// - Speichert Elemente des gleichen Datentyps
// - Feste Größe, zur Kompilierzeit bestimmt
// - Indizierung beginnt bei 0

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Definition von Arrays
//
// - Syntax: `T name[size]`.
// - Größe ist Teil des Typs, muss zur Kompilierzeit bekannt sein.
// - Definition mit oder ohne Initialwerte möglich.
// - Lokale Arrays werden auf dem Stack gespeichert.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Ohne Initialwerte
//
// - Größe muss angegeben werden.
// - Elemente werden nicht initialisiert.


// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Mit Initialwerten
//
// - Initialwerte als Initialisierungsliste angeben.
// - Größe wird automatisch bestimmt.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Teilweise Initialisierung
//
// - Nicht alle Werte müssen angegeben werden.
// - In diesem Fall muss die Größe angegeben werden.
// - Restliche Elemente werden automatisch mit 0 initialisiert, wenn weniger
//   Werte angegeben werden.

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Zugriff auf Elemente
//
// - Zugriff auf Elemente mittels Index.
// - Syntax: `array[index]`.
// - Indizes beginnen bei 0.
// - Zugriff auf nicht existierende Elemente führt zu undefiniertem Verhalten.
// - Zugriff auf Elemente ist schnell.


// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Modifikation von Arrays
//
// - Es gibt keine Operationen zur Modifikation des gesamten Arrays.
// - Z.B. `array_1 = array_2` ist nicht möglich.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Iteration über Arrays
//
// - Schleifen zur Iteration über Elemente:
//   - Range-based for loop
//   - Indexierte for-Schleife
// - Range-based for loop immer verwenden, wenn möglich.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Range-based For Loop
//
// - Iteriert über alle Elemente eines Arrays.
// - Syntax: `for (T element : array) { ... }`

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Indexierte For-Schleife
//
// - Iteriert über alle Indizes eines Arrays.
// - Zugriff auf Elemente mittels Index.
// - Syntax: `for (std::size_t i{0}; i < size; ++i) { ... }`
// - Problem: Größe muss bekannt sein.

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Übergeben von Arrays als Funktionsargumenten
//
// - Array-Typen können als Parametertypen verwendet werden.
// - Aber: Arrays können nicht als Wert übergeben werden.
// - Werden als Zeiger behandelt.


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
// void print_array_5(int arr[5])
// {
//     for (int elt : arr) {
//         std::cout << elt << " ";
//     }
// }

// %%

// %% tags=["keep"]
int numbers[]{1, 2, 3, 4, 5};

// %%

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void inc_array_5(int arr[5])
{
    for (std::size_t i{0}; i < 5; ++i) {
        ++arr[i];
    }
}

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Typ `array[]` ist "unvollständiger Typ."
// - Wird beim Funktionsaufruf wie ein Zeiger behandelt.
// - Größe des Arrays geht verloren.
//   - Sentinel-Wert
//   - Größe des Arrays als zusätzlicher Parameter

// %% tags=["keep"]
void print_array_incomplete(int arr[], std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

// %% tags=["keep"]
int numbers[]{1, 2, 3, 4, 5};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Ein Array kann implizit in einen Zeiger auf das erste Element konvertiert
//   werden ("decay").
// - Größe des Arrays geht verloren.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void print_array(int* arr, std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

// %% tags=["keep"]
int numbers[]{1, 2, 3, 4, 5};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Arrays und Zeiger
//
// - Arrays und Zeiger sind eng miteinander verwandt.
// - Arrays können implizit in Zeiger konvertiert werden.
// - Zeiger unterstützen Addition und Subtraktion.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Arrays
//
// - Schreiben Sie eine Funktion `max()`, die das größte Element eines Arrays
//   von `unsigned int`-Werten zurückgibt.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
unsigned values[]{1, 8, 3, 5, 2, 9, 4, 7, 6};

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Schreiben Sie eine Funktion `add()`, die zwei Arrays der gleichen Länge
//   elementweise addiert.
// - Welche Argumente müssen Sie an die Funktion übergeben?

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
int a1[]{1, 2};
int a2[]{10, 20};
int a3[2];

// %%

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
int b1[]{1, 2, 3, 4, 5};
int b2[]{5, 4, 3, 2, 1};
int b3[5];

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Schreiben Sie eine Funktion `reverse()`, die ein Array in-place umdreht.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
int c[]{1, 2, 3, 4, 5};

// %%

// %%
