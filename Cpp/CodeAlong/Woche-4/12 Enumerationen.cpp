// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Enumerationen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 Enumerationen.cpp -->
// <!-- slides/module_120_basics/topic_220_enumerations.cpp -->

// %% [markdown]
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

// %% [markdown]
//
// ## Scoped Enumerations
//
// - Die Werte einer scoped Enumeration werden durch den Namen der Enumeration
//   und den Enumerator angegeben:

// %%
enum class Color
{
    Red,
    Green,
    Blue
};

// %%
Color color{Color::Red};

// %%
#include <iostream>

// %%
if (color == Color::Red) {
    std::cout << "Red";
}

// %%
color = Color::Green;

// %% [markdown]
//
// - Verschiedene Enumerationen können den gleichen Enumerator haben:

// %%
enum class TrafficLight
{
    Red,
    Yellow,
    Green
};

// %%
TrafficLight light{TrafficLight::Red};

// %%
void print_light(TrafficLight light)
{
    switch (light) {
    case TrafficLight::Red: std::cout << "Red"; break;
    case TrafficLight::Yellow: std::cout << "Yellow"; break;
    case TrafficLight::Green: std::cout << "Green"; break;
    }
}

// %%
print_light(light);

// %%
print_light(TrafficLight::Green);

// %% [markdown]
//
// - Jede Enumeration definiert einen eigenen Typ.
// - Bei Scoped Enumerations können die Werte nur mit dem Typ der Enumeration
//   verwendet werden.

// %%
// color == light

// %%
// color = TrafficLight::Green;

// %%
// print_light(Color::Green);

// %% [markdown]
//
// - Um den Wert einer scoped Enumeration in einen `int`-Wert zu konvertieren
//   muss man einen Cast verwenden.
// - Enumerations-Werte können aus ganzen Zahlen erzeugt werden.

// %%
// int my_int{TrafficLight::Red};

// %%
// int my_int(TrafficLight::Red);

// %%
static_cast<int>(TrafficLight::Red)

// %%
static_cast<int>(TrafficLight::Yellow)

// %%
static_cast<int>(TrafficLight::Green)

// %%
TrafficLight red_light{0};

// %%
print_light(red_light);

// %%
TrafficLight weird_light{42};

// %%
print_light(weird_light);

// %% [markdown]
//
// ## Unscoped Enumerations
//
// - Die Werte einer unscoped Enumeration werden durch den Namen des Enumerators
//   ohne Präfix angegeben:

// %%
enum Color2 {
    Red,
    Green,
    Blue
};

// %%
Color2 color2{Red};

// %%
#include <iostream>

// %%
if (color2 == Red) {
    std::cout << "Red!";
}

// %% [markdown]
//
// - Unscoped Enumerations können implizit in einen `int`-Wert konvertiert werden.

// %%
color2 = Green;

// %%
if (color2 == 1) {
    std::cout << "Green!";
}

// %% [markdown]
//
// - Verschiedene Enumerationen können nicht den gleichen Enumerator haben.
// - Es ist (bei scoped und unscoped Enumerations) möglich den zugrunde
//   liegenden Typ anzugeben.
// - Man kann auch die Werte für die Enumeratoren explizit angeben.

// %%
// enum TrafficLight2
// {
//     Red,
//     Yellow,
//     Green
// };

// %%
#include <cstdint>

// %%
enum TrafficLight2 : std::uint8_t
{
    TLRed = 1,
    TLYellow,
    TLGreen
};

// %%
#include <iostream>

// %%
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

// %%
TrafficLight2 light2{TLRed};

// %%
print_light(light2);

// %%
// if (light2 == Green) {
//     std::cout << "Green?";
// }

// %% [markdown]
//
// - Unscoped Enumerations können von Int-Werten erzeugt werden, wenn ihr
//   zugrundeliegender Typ festgelegt ist.
//   - Das ist nur dann der Fall, wenn er explizit angegeben wurde
// - Bei unscoped Enumerations können die Werte implizit in `int`-Werte
//   konvertiert werden.

// %%
// Color2 red_color2{0};

// %%
TrafficLight2 red_light2{1};

// %%
if (red_light2 == TLRed) {
    std::cout << "TLRed!";
}

// %%
int my_int{light2};

// %%
my_int

// %%
TrafficLight2 weird_light2{42};

// %%
static_cast<int>(weird_light2)

// %%
print_light(weird_light2);

// %% [markdown]
//
// ## Mini-Workshop: Wochentage
//
// - Schreiben Sie eine Enumeration `Weekday`, die Wochentage repräsentieren
//   kann.
// - Schreiben Sie eine Funktion `is_weekend()`, die einen Wochentag als
//   Parameter entgegennimmt und `true` zurückgibt, wenn es sich um einen Tag am
//   Wochenende handelt.

// %%

// %%

// %%

// %%
