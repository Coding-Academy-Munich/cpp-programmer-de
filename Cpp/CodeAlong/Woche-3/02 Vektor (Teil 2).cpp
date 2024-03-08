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
//  <b>Vektor (Teil 2)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Vektor (Teil 2).cpp -->
// <!-- slides/module_140_collections/topic_154_vector_part2.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Pfade
//
// - Wir können uns jetzt wieder unserem Beispiel zuwenden.
// - Um einen Pfad zu speichern, können wir einen Vektor von `Point`-Objekten
//   verwenden:

// %% tags=["keep"]
#include "point.hpp"

// %% [markdown] lang="de"
//
// Dieser Header definiert die folgende Struktur:
//
// ```cpp
// struct Point {
//     double x;
//     double y;
//     double z;
// };
// ```
//
// Außerdem definiert er Funktionen zum Anzeigen von Punkten und Vektoren von
// Punkten in Notebooks, sowie zum Ausgeben auf `std::cout`.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Point p1{1.0, 2.0, 3.0};
Point p2{2.0, 3.0, 4.0};
Point p3{3.0, 4.0, 5.0};

// %%

// %%

// %% tags=["keep"]
std::vector<Point> path{p1, p2, p3};

// %%

// %% tags=["keep"]
std::vector<Point>{ {1, 2, 3}, {2, 3, 4}, {3, 4, 5} }

// %% tags=["keep"]
std::cout << path;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Vektoren werden "by value" an Funktionen übergeben und von Funktionen
//   zurückgegeben.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
void call_by_value(std::vector<Point> path)
{
    path.push_back({4, 5, 6});
    path[0] = {-1, -2, -3};
    std::cout << path << "\n";
}

// %% tags=["keep"]
path

// %% tags=["keep"]
call_by_value(path);

// %% tags=["keep"]
path


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können Vektoren als `const vector<T>&` übergeben, um sie nicht kopieren
//   zu müssen:

// %% tags=["keep"]
void print_path(const std::vector<Point>& path)
{
    std::cout << "Path:\n";
    for (const Point& p : path) {
        std::cout << "  " << p << "\n";
    }
}

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wenn wir den Vektor verändern wollen übergeben wir ihn als `vector<T>&`:

// %% tags=["keep"]
bool read_next_point(std::vector<Point>& path)
{
    std::cout << "Enter next point (x y z): ";
    Point p;
    std::cin >> p.x >> p.y >> p.z;
    if (!std::cin) {
        return false;
    }
    path.push_back(p);
    return true;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::vector<Point> path{p1, p2, p3};

// %% tags=["keep"]
// read_next_point(path)

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Typischerweise geben wir Vektoren als Werte zurück.
// - Seit C++11 ist das effizient möglich.
//   - Move Semantik
//   - Return Value Optimization (RVO)
// - In älteren C++-Versionen wird der Vektor kopiert.
//   - Daher gibt man oft einen Pointer zurück.
//   - Damit muss man sich aber um die Speicherverwaltung kümmern.

// %% tags=["keep"]
std::vector<Point> read_path()
{
    std::vector<Point> path{};
    while (read_next_point(path));
    return path;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
// path = read_path();

// %%


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Regen-Daten
//
// Ein Meteorologe möchte die Gesamtmenge an Regen für mehrere
// aufeinanderfolgende Monate analysieren. Schreiben Sie ein Programm, das die
// Regendaten (in mm) für jeden Monat vom Benutzer einliest und in einem Vektor
// speichert. Berechnen und drucken Sie den Gesamtniederschlag während des
// Zeitraums, den durchschnittlichen monatlichen Niederschlag und die Indizes
// der Monate mit dem höchsten und dem niedrigsten Niederschlag.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Strukturieren Sie Ihr Programm in Funktionen, so dass jede eine klar
// definierte Aufgabe erfüllt:
//
// - `read_data()`: Liest die Regendaten vom Benutzer ein.
// - `calculate_total()`: Berechnet und gibt den Gesamtniederschlag zurück.
// - `calculate_mean()`: Berechnet und gibt den durchschnittlichen Niederschlag
//   zurück.
// - `calculate_min_indices()`: Berechnet und gibt die Indizes der Monate mit
//    dem geringsten Niederschlag zurück.
// - `calculate_max_indices()`: Berechnet und gibt die Indizes der Monate mit
//    dem höchsten Niederschlag zurück.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Hinweise:
//
// - Verwenden Sie `std::vector<double>` um die Regendaten zu speichern.
// - Sie können `std::numeric_limits<double>::max()` und
//   `std::numeric_limits<double>::lowest()` als Startwerte für die Berechnung
//   des minimalen und maximalen Niederschlags verwenden.
//   [Hier](https://en.cppreference.com/w/cpp/types/numeric_limits) finden Sie
//   weitere Informationen zu `std::numeric_limits`.
// - Beachten Sie, dass es mehrere Monate geben kann, in denen der minimale oder
//   maximale Niederschlag erreicht wird und dass die entsprechenden Funktionen
//   daher Vektoren zurückgeben sollten.

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
std::vector<double> data{2.0, 1.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0, 5.0, 4.0};


// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%
