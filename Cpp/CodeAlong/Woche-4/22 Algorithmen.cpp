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
//  <b>Algorithmen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 22 Algorithmen.cpp -->
// <!-- slides/module_200_stl_collections/topic_170_algorithms.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - C++ bietet viele Algorithmen, die auf Containern arbeiten.
// - Die meisten Algorithmen sind in der Header-Datei `<algorithm>` definiert.
// - Algorithmen arbeiten mit einem Iterator-Paar, das den Bereich der
//   Container-Elemente angibt, auf dem der Algorithmus arbeitet.
// - Die Iterator-Paare werden mit den Funktionen `begin()` und `end()`
//   erzeugt.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die folgenden Tabellen zeigen einige Algorithmen und ihre Verwendung:
//
// | Algorithmus            | Verwendung                                             |
// | :------------          | :-----------                                           |
// | `std::for_each`        | `std::for_each(begin, end, function)`                  |
// | `std::count`           | `std::count(begin, end, value)`                        |
// | `std::count_if`        | `std::count_if(begin, end, function)`                  |
// | `std::find`            | `std::find(begin, end, value)`                         |
// | `std::find_if`         | `std::find_if(begin, end, function)`                   |
// | `std::find_if_not`     | `std::find_if_not(begin, end, function)`               |
// | `std::all_of`          | `std::all_of(begin, end, function)`                    |
// | `std::any_of`          | `std::any_of(begin, end, function)`                    |
// | `std::none_of`         | `std::none_of(begin, end, function)`                   |

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// | Algorithmus            | Verwendung                                             |
// | :------------          | :-----------                                           |
// | `std::copy`            | `std::copy(begin, end, out)`                           |
// | `std::copy_if`         | `std::copy_if(begin, end, out, function)`              |
// | `std::copy_n`          | `std::copy_n(begin, count, out)`                       |
// | `std::copy_backward`   | `std::copy_backward(begin, end, out)`                  |
// | `std::transform`       | `std::transform(begin, end, out, function)`            |
// | `std::generate`        | `std::generate(begin, end, function)`                  |
// | `std::generate_n`      | `std::generate_n(begin, count, function)`              |
// | `std::iota`            | `std::iota(begin, end, value)`                         |
// | `std::replace`         | `std::replace(begin, end, old, new)`                   |
// | `std::replace_if`      | `std::replace_if(begin, end, function, new)`           |
// | `std::replace_copy`    | `std::replace_copy(begin, end, out, old, new)`         |
// | `std::replace_copy_if` | `std::replace_copy_if(begin, end, out, function, new)` |
// | ...                    | ...                                                    |

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <algorithm>
#include <iostream>
#include <vector>

// %% tags=["keep"]
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> w(9);

// %% tags=["keep"]
void print(int i)
{
    std::cout << i << " ";
}

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Lambda-Ausdrücke
//
// - Es ist umständlich, eine Funktion zu schreiben, die nur einmal verwendet
//   wird
// - Lambda-Ausdrücke sind anonyme Funktionen, die direkt an Ort und Stelle
//   definiert werden können
// - Syntax:
//   ```cpp
//   [capture](parameters) -> return_type { body }
//   ```

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}


// %%

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%
