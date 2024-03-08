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
// <!-- 07 Algorithmen.cpp -->
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
std::for_each(v.begin(), v.end(), print);

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
{
    auto print_lambda = [](int i){ std::cout << i << " "; };
    print_lambda(42);
}

// %%
{
    int factor{3};
    auto times_factor = [factor](int i){ return factor * i; };
    std::cout << times_factor(42) << "\n";
}

// %%
{
    int result{0};
    auto times_two = [&result](int i){ result = 2 * i; };
    times_two(42);
    std::cout << result << "\n";
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::for_each(v.begin(), v.end(), [](int i){ std::cout << i << " "; });


// %%
std::for_each(v.begin(), v.end(), [](int& i){ i %= 6; });

// %%
v

// %%
std::count(v.begin(), v.end(), 1)

// %%
std::count_if(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
v

// %%
auto it{std::find(v.begin(), v.end(), 2)};

// %%
*it

// %%
*(it + 1)

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
auto it2{std::find(it + 1, v.end(), 2)};

// %%
(it2 == v.end())

// %%
*it

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
auto it3{std::find(it2 + 1, v.end(), 2)};

// %%
(it3 == v.end())

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::find_if(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
std::find_if_not(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::all_of(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
std::any_of(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
std::none_of(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
w.clear();
std::copy(v.begin(), v.end(), std::back_inserter(w));

// %%
w

// %%
w.clear();
std::copy_if(v.begin(), v.end(), std::back_inserter(w), [](int i){ return i % 3 == 0; });

// %%
w

// %%
w.resize(20, -1);
std::copy_n(v.begin(), 3, std::begin(w));

// %%
w

// %%
v

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::copy_backward(v.begin(), v.end(), w.end());

// %%
w

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::transform(v.begin(), v.end(), w.begin() + 2, [](int i){ return i * 2; });

// %%
w

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::generate(v.begin(), v.end(), [](){ return rand() % 10; });

// %%
v

// %%
int i{0};
std::generate_n(v.begin(), 5, [&i](){ return i++; });

// %%
v

// %%
std::iota(v.begin(), v.end(), 1);

// %%
v

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::replace(v.begin(), v.end(), 2, 42);

// %%
v

// %%
std::replace_if(v.begin(), v.end(), [](int i){ return i % 3 == 0; }, 21);

// %%
v

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
std::replace_copy(v.begin(), v.end(), w.begin(), 21, 42);

// %%
w

// %%
std::replace_copy_if(v.begin(), v.end(), w.begin() + 5, [](int i){ return i % 5 == 0; }, 15);

// %%
w
