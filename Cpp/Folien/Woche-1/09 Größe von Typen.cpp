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
//  <b>Größe von Typen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Größe von Typen.cpp -->
// <!-- slides/module_120_basics/topic_200_size_of_types.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Werte
//
// - Ein *Wert*
//     - ist ein Speicherbereich
//     - der entsprechend den Regeln eines Typs interpretiert wird
//     - z.B. Bits `0x3f800000`
//         - `1.f` als `float`
//         - `1065353216` als `int`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Wiederholung: Einige Fundamentale Typen
//
// | Typ         | Beschreibung      | Größe   | Werte     | &nbsp;   | Literale Syntax   |
// | :---------- | :---------------- | ------: | :-------: | :------: | ----------------- |
// | `bool`      | Boolesche Werte   | N/A     | `false`   | `true`   | `true`            |
// | `char`      | Zeichen           | 8 Bit   | 0         | 127      | `'a'`             |
// | `int`       | Zahlen            | 16 Bit  | -32768    | 32767    | `123`, `0xF1`     |
// | `unsigned`  | positive Zahlen   | 16 Bit  | 0         | 65535    | `123u`            |
// | `long`      | große Zahlen      | 32 Bit  | -2^31     | 2^31 - 1 | `123L`            |
// | `long long` | sehr große Zahlen | 64 Bit  | -2^63     | 2^63 - 1 | `123LL`           |
// | `float`     | Gleitkommazahlen  | 6 SD    | 10.0^-38  | 10.0^38  | `1.0f`, `123e-2f` |
// | `double`    | Gleitkommazahlen  | 10 SD   | 10.0^-308 | 10.0^308 | `1.23`, `123e-2`  |
//
// - (SD = Significant Digits, Signifikante Stellen)
// - Typischerweise sind `int` und `unsigned` 32 Bit, aber das ist nicht vom Standard garantiert.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Größe von Typen
//
// - Die Größe von Typen ist abhängig von der Plattform
// - Mit dem `sizeof()`-Operator kann die Größe eines Typs ermittelt werden
// - Der kleinste Typ ist `char`
//   - `sizeof(char)` ist immer 1
//   - `char` ist ein Zeichen im Zeichensatz der Plattform
// - Für andere Typen gibt `sizeof()` den Faktor an, um den der Typ größer als
//   `char` ist.
// - Auf den meisten Plattformen ist das die Größe in Bytes.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
sizeof(char)

// %%
sizeof(int)

// %%
sizeof(long)

// %%
sizeof(long long)

// %%
sizeof(float)

// %%
sizeof(double)


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Integrale Typen mit Größenangabe
//
// - Die Mindestgrößen der eingebauten Typen sind oft zu klein.
// - Im Header `<cstdint>` sind Typen mit Größenangabe definiert, die es
//   erlauben portablen Code zu schreiben.
//
// | Type           | Description             | Size    | Values    | &nbsp;   | Optional |
// | :------------- | :---------------------- | ------: | :-------: | :------: | :------- |
// | `int8_t`       | 8-Bit Zahlen            | 8 Bit   | -128      | 127      | Ja       |
// | `uint8_t`      | 8-Bit positive Zahlen   | 8 Bit   | 0         | 255      | Ja       |
// | `int_fast8_t`  | schnellste 8-Bit Zahlen | 8 Bit   | -128      | 127      | Nein     |
// | `int_least8_t` | kleinste 8-Bit Zahlen   | 8 Bit   | -128      | 127      | Nein     |
// | `int16_t`      | 16-Bit Zahlen           | 16 Bit  | -32768    | 32767    | Ja       |
// | `int32_t`      | 32-Bit Zahlen           | 32 Bit  | -2^31     | 2^31 - 1 | Ja       |
// | `int64_t`      | 64-Bit Zahlen           | 64 Bit  | -2^63     | 2^63 - 1 | Ja       |

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
#include <cstdint>

// %%
sizeof(int8_t)

// %%
sizeof(uint8_t)

// %%
sizeof(int_fast8_t)

// %%
sizeof(int_least8_t)

// %%
sizeof(int32_t)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Integer-Typen mit Größenangabe
//
// Stellen Sie fest, wie groß folgende Typen auf Ihrem System sind:
//
// - `int16_t`
// - `uint16_t`
// - `int_fast16_t`
// - `int_least16_t`
// - `int64_t`

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
#include <cstdint>

// %%
sizeof(int16_t)

// %%
sizeof(uint16_t)

// %%
sizeof(int_fast16_t)

// %%
sizeof(int_least16_t)

// %%
sizeof(int64_t)

