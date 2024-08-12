// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Größe von Typen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Größe von Typen.cpp -->
// <!-- slides/module_120_basics/topic_200_size_of_types.cpp -->

// %% [markdown]
//
// ## Werte
//
// - Ein *Wert*
//     - ist ein Speicherbereich
//     - der entsprechend den Regeln eines Typs interpretiert wird
//     - z.B. Bits `0x3f800000`
//         - `1.f` als `float`
//         - `1065353216` als `int`

// %% [markdown]
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

// %% [markdown]
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

// %%

// %%

// %%

// %%

// %%

// %%


// %% [markdown]
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

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
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

// %%

// %%

// %%

// %%

// %%

// %%

