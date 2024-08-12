// -*- coding: utf-8 -*-
// %% [markdown]
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

// %% [markdown]
//
// # Arrays in C++
//
// - Zusammenhängender Speicherbereich
// - Speichert Elemente des gleichen Datentyps
// - Feste Größe, zur Kompilierzeit bestimmt
// - Indizierung beginnt bei 0

// %% [markdown]
//
// ## Definition von Arrays
//
// - Syntax: `T name[size]`.
// - Größe ist Teil des Typs, muss zur Kompilierzeit bekannt sein.
// - Definition mit oder ohne Initialwerte möglich.
// - Lokale Arrays werden auf dem Stack gespeichert.

// %% [markdown]
//
// ### Ohne Initialwerte
//
// - Größe muss angegeben werden.
// - Elemente werden nicht initialisiert.


// %%
int numbers[5];

// %% [markdown]
//
// ### Mit Initialwerten
//
// - Initialwerte als Initialisierungsliste angeben.
// - Größe wird automatisch bestimmt.

// %%
int numbers[]{1, 2, 3, 4, 5};

// %% [markdown]
//
// ### Teilweise Initialisierung
//
// - Nicht alle Werte müssen angegeben werden.
// - In diesem Fall muss die Größe angegeben werden.
// - Restliche Elemente werden automatisch mit 0 initialisiert, wenn weniger
//   Werte angegeben werden.

// %%
// First three elements initialized, others set to 0
int numbers[5]{1, 2, 3};

// %%
int numbers[5]{};

// %% [markdown]
//
// ## Zugriff auf Elemente
//
// - Zugriff auf Elemente mittels Index.
// - Syntax: `array[index]`.
// - Indizes beginnen bei 0.
// - Zugriff auf nicht existierende Elemente führt zu undefiniertem Verhalten.
// - Zugriff auf Elemente ist schnell.


// %%
int first_number = numbers[0];

// %%
numbers[1] = 42;

// %% [markdown]
//
// ## Modifikation von Arrays
//
// - Es gibt keine Operationen zur Modifikation des gesamten Arrays.
// - Z.B. `array_1 = array_2` ist nicht möglich.

// %% [markdown]
//
// ## Iteration über Arrays
//
// - Schleifen zur Iteration über Elemente:
//   - Range-based for loop
//   - Indexierte for-Schleife
// - Range-based for loop immer verwenden, wenn möglich.

// %% [markdown]
//
// ### Range-based For Loop
//
// - Iteriert über alle Elemente eines Arrays.
// - Syntax: `for (T element : array) { ... }`

// %%
#include <iostream>

// %%
for (int number : numbers) {
    std::cout << number << " ";
}

// %% [markdown]
//
// ### Indexierte For-Schleife
//
// - Iteriert über alle Indizes eines Arrays.
// - Zugriff auf Elemente mittels Index.
// - Syntax: `for (std::size_t i{0}; i < size; ++i) { ... }`
// - Problem: Größe muss bekannt sein.

// %%
for (std::size_t i{0}; i < 5; ++i) {
    std::cout << numbers[i] << " ";
}

// %% [markdown]
//
// ## Übergeben von Arrays als Funktionsargumenten
//
// - Array-Typen können als Parametertypen verwendet werden.
// - Aber: Arrays können nicht als Wert übergeben werden.
// - Werden als Zeiger behandelt.


// %%
// void print_array_5(int arr[5])
// {
//     for (int elt : arr) {
//         std::cout << elt << " ";
//     }
// }

// %%
void print_array_5(int arr[5])
{
    for (std::size_t i{0}; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
}

// %%
int numbers[]{1, 2, 3, 4, 5};

// %%
print_array_5(numbers);

// %%
void inc_array_5(int arr[5])
{
    for (std::size_t i{0}; i < 5; ++i) {
        ++arr[i];
    }
}

// %%
inc_array_5(numbers);
print_array_5(numbers);

// %% [markdown]
//
// - Typ `array[]` ist "unvollständiger Typ."
// - Wird beim Funktionsaufruf wie ein Zeiger behandelt.
// - Größe des Arrays geht verloren.
//   - Sentinel-Wert
//   - Größe des Arrays als zusätzlicher Parameter

// %%
void print_array_incomplete(int arr[], std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

// %%
int numbers[]{1, 2, 3, 4, 5};

// %%
print_array_incomplete(numbers, 5);

// %% [markdown]
//
// - Ein Array kann implizit in einen Zeiger auf das erste Element konvertiert
//   werden ("decay").
// - Größe des Arrays geht verloren.

// %%
void print_array(int* arr, std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

// %%
int numbers[]{1, 2, 3, 4, 5};

// %%
print_array(numbers, 5);

// %% [markdown]
//
// ## Arrays und Zeiger
//
// - Arrays und Zeiger sind eng miteinander verwandt.
// - Arrays können implizit in Zeiger konvertiert werden.
// - Zeiger unterstützen Addition und Subtraktion.

// %%
numbers[0]

// %%
&numbers[0] == numbers

// %%
&numbers[1] == numbers + 1

// %%
std::cout << (numbers[1] == *(numbers + 1));

// %%
&numbers[2] == numbers + 2

// %%
numbers + 2 == 2 + numbers

// %%
2[numbers]

// %% [markdown]
//
// ## Mini-Workshop: Arrays
//
// - Schreiben Sie eine Funktion `max()`, die das größte Element eines Arrays
//   von `unsigned int`-Werten zurückgibt.

// %%
unsigned max(const unsigned* arr, std::size_t size)
{
    unsigned result{0};
    for (std::size_t i{0}; i < size; ++i) {
        if (arr[i] > result) {
            result = arr[i];
        }
    }
    return result;
}

// %%
unsigned values[]{1, 8, 3, 5, 2, 9, 4, 7, 6};

// %%
max(values, 9)


// %% [markdown]
//
// - Schreiben Sie eine Funktion `add()`, die zwei Arrays der gleichen Länge
//   elementweise addiert.
// - Welche Argumente müssen Sie an die Funktion übergeben?

// %%
void add(const int* a, const int* b, int* c, std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i) {
        c[i] = a[i] + b[i];
    }
}

// %%
int a1[]{1, 2};
int a2[]{10, 20};
int a3[2];

// %%
add(a1, a2, a3, 2);
a3

// %%
int b1[]{1, 2, 3, 4, 5};
int b2[]{5, 4, 3, 2, 1};
int b3[5];

// %%
add(b1, b2, b3, 5);
b3

// %% [markdown]
//
// - Schreiben Sie eine Funktion `reverse()`, die ein Array in-place umdreht.

// %%
void reverse(int* arr, std::size_t size)
{
    for (std::size_t i{0}; i < size / 2; ++i) {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

// %%
int c[]{1, 2, 3, 4, 5};

// %%
reverse(c, 5);

// %%
c
