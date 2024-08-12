// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Algorithmen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 14 Algorithmen.cpp -->
// <!-- slides/module_200_stl_collections/topic_170_algorithms.cpp -->

// %% [markdown]
//
// - C++ bietet viele Algorithmen, die auf Containern arbeiten.
// - Die meisten Algorithmen sind in der Header-Datei `<algorithm>` definiert.
// - Algorithmen arbeiten mit einem Iterator-Paar, das den Bereich der
//   Container-Elemente angibt, auf dem der Algorithmus arbeitet.
// - Die Iterator-Paare werden mit den Funktionen `begin()` und `end()`
//   erzeugt.

// %% [markdown]
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

// %% [markdown]
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

// %%
#include <algorithm>
#include <iostream>
#include <vector>

// %%
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> w(9);

// %%
void print(int i)
{
    std::cout << i << " ";
}

// %%
std::for_each(v.begin(), v.end(), print);

// %% [markdown]
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

// %%
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

// %%
std::for_each(v.begin(), v.end(), [](int i){ std::cout << i << " "; });


// %%
std::for_each(v.begin(), v.end(), [](int& i){ i %= 6; });

// %%
v

// %%
std::count(v.begin(), v.end(), 1)

// %%
std::count_if(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
v

// %%
auto it{std::find(v.begin(), v.end(), 2)};

// %%
*it

// %%
*(it + 1)

// %%
auto it2{std::find(it + 1, v.end(), 2)};

// %%
(it2 == v.end())

// %%
*it

// %%
auto it3{std::find(it2 + 1, v.end(), 2)};

// %%
(it3 == v.end())

// %%
std::find_if(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
std::find_if_not(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
std::all_of(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
std::any_of(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
std::none_of(v.begin(), v.end(), [](int i){ return i % 3 == 0; })

// %%
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

// %%
std::copy_backward(v.begin(), v.end(), w.end());

// %%
w

// %%
std::transform(v.begin(), v.end(), w.begin() + 2, [](int i){ return i * 2; });

// %%
w

// %%
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

// %%
std::replace(v.begin(), v.end(), 2, 42);

// %%
v

// %%
std::replace_if(v.begin(), v.end(), [](int i){ return i % 3 == 0; }, 21);

// %%
v

// %%
std::replace_copy(v.begin(), v.end(), w.begin(), 21, 42);

// %%
w

// %%
std::replace_copy_if(v.begin(), v.end(), w.begin() + 5, [](int i){ return i % 5 == 0; }, 15);

// %%
w
