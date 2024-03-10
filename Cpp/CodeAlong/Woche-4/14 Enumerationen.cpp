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
//  <b>Enumerationen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 14 Enumerationen.cpp -->
// <!-- slides/module_120_basics/topic_220_enumerations.cpp -->

// %% [markdown] Lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Enumerations
//
// - Enumerationen sind eine Möglichkeit, eine Menge von zusammengehörigen,
//   numerischen Werten zu definieren.
// - In C++ gibt es zwei Arten von Enumerationen:
//     - `enum class` (scoped Enumeration, C++11)
//     - `enum` (unscoped Enumeration, C++98)
// - `enum class` ist typischerweise empfehlenswert, weil
//    - die Enumerations-Werte im Namespace der Enumeration definiert werden
//    - sie nicht implizit in einen `int`-Wert konvertiert.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Scoped Enumerations
//
// - Die Werte einer scoped Enumeration werden durch den Namen der Enumeration
//   und den Enumerator angegeben:

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
enum class Color
{
    Red,
    Green,
    Blue
};

// %% tags=["keep"]
Color color{Color::Red};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
if (color == Color::Red) {
    std::cout << "Red";
}

// %% tags=["keep"]
color = Color::Green;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Verschiedene Enumerationen können den gleichen Enumerator haben:

// %% tags=["keep"]
enum class TrafficLight
{
    Red,
    Yellow,
    Green
};

// %% tags=["keep"]
TrafficLight light{TrafficLight::Red};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
void print_light(TrafficLight light)
{
    switch (light) {
    case TrafficLight::Red: std::cout << "Red"; break;
    case TrafficLight::Yellow: std::cout << "Yellow"; break;
    case TrafficLight::Green: std::cout << "Green"; break;
    }
}

// %% tags=["keep"]
print_light(light);

// %% tags=["keep"]
print_light(TrafficLight::Green);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Jede Enumeration definiert einen eigenen Typ.
// - Bei Scoped Enumerations können die Werte nur mit dem Typ der Enumeration
//   verwendet werden.

// %% tags=["keep"]
// color == light

// %% tags=["keep"]
// color = TrafficLight::Green;

// %% tags=["keep"]
// print_light(Color::Green);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Um den Wert einer scoped Enumeration in einen `int`-Wert zu konvertieren
//   muss man einen Cast verwenden.
// - Enumerations-Werte können aus ganzen Zahlen erzeugt werden.

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
// int my_int{TrafficLight::Red};

// %% tags=["keep"]
// int my_int(TrafficLight::Red);

// %% tags=["keep"]
static_cast<int>(TrafficLight::Red)

// %% tags=["keep"]
static_cast<int>(TrafficLight::Yellow)

// %% tags=["keep"]
static_cast<int>(TrafficLight::Green)

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
TrafficLight red_light{0};

// %% tags=["keep"]
print_light(red_light);

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
TrafficLight weird_light{42};

// %% tags=["keep"]
print_light(weird_light);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Unscoped Enumerations
//
// - Die Werte einer unscoped Enumeration werden durch den Namen des Enumerators
//   ohne Präfix angegeben:

// %% tags=["keep"]
enum Color2 {
    Red,
    Green,
    Blue
};

// %% tags=["keep"]
Color2 color2{Red};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
if (color2 == Red) {
    std::cout << "Red!";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Unscoped Enumerations können implizit in einen `int`-Wert konvertiert werden.

// %% tags=["keep"]
color2 = Green;

// %% tags=["keep"]
if (color2 == 1) {
    std::cout << "Green!";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Verschiedene Enumerationen können nicht den gleichen Enumerator haben.
// - Es ist (bei scoped und unscoped Enumerations) möglich den zugrunde
//   liegenden Typ anzugeben.
// - Man kann auch die Werte für die Enumeratoren explizit angeben.

// %% tags=["keep"]
// enum TrafficLight2
// {
//     Red,
//     Yellow,
//     Green
// };

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <cstdint>

// %% tags=["keep"]
enum TrafficLight2 : std::uint8_t
{
    TLRed = 1,
    TLYellow,
    TLGreen
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
void print_light(TrafficLight2 light)
{
    if (light == TLRed)
        std::cout << "TLRed";
    else if (light == TLYellow)
        std::cout << "TLYellow";
    else if (light == TLGreen)
        std::cout << "TLGreen";
    else
        std::cout << "???";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
TrafficLight2 light2{TLRed};

// %% tags=["keep"]
print_light(light2);

// %% tags=["keep"]
// if (light2 == Green) {
//     std::cout << "Green?";
// }

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Unscoped Enumerations können von Int-Werten erzeugt werden, wenn ihr
//   zugrundeliegender Typ festgelegt ist.
//   - Das ist nur dann der Fall, wenn er explizit angegeben wurde
// - Bei unscoped Enumerations können die Werte implizit in `int`-Werte
//   konvertiert werden.

// %% tags=["keep"]
// Color2 red_color2{0};

// %% tags=["keep"]
TrafficLight2 red_light2{1};

// %% tags=["keep"]
if (red_light2 == TLRed) {
    std::cout << "TLRed!";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int my_int{light2};

// %% tags=["keep"]
my_int

// %% tags=["keep"]
TrafficLight2 weird_light2{42};

// %% tags=["keep"]
static_cast<int>(weird_light2)

// %% tags=["keep"]
print_light(weird_light2);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Wochentage
//
// - Schreiben Sie eine Enumeration `Weekday`, die Wochentage repräsentieren
//   kann.
// - Schreiben Sie eine Funktion `is_weekend()`, die einen Wochentag als
//   Parameter entgegennimmt und `true` zurückgibt, wenn es sich um einen Tag am
//   Wochenende handelt.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%
