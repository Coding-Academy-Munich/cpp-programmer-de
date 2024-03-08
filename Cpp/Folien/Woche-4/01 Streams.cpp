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
//  <b>Streams</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Streams.cpp -->
// <!-- slides/module_160_raii/topic_100_streams.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Ein- und Ausgabe-Streams
//
// - `std::ostream` konvertiert Daten in Zeichen
//   - `operator<<()`
// - `std::istream` konvertiert Zeichen in Daten
//   - `operator>>()`
//   - `std::getline()`
// - `std::iostream` konvertiert in beide Richtungen

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Klassen für Output-Stream
//
// - [`std::ostream`](https://en.cppreference.com/w/cpp/io/basic_ostream) ist
//   die Basisklasse für alle Ausgabe-Streams
// - [`std::ofstream`](https://en.cppreference.com/w/cpp/io/basic_ofstream) ist
//   ein Ausgabe-Stream für Dateien
// - [`std::ostringstream`](https://en.cppreference.com/w/cpp/io/basic_ostringstream)
//   ist ein Ausgabe-Stream für Strings

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Klassen für Input-Stream
//
// - [`std::istream`](https://en.cppreference.com/w/cpp/io/basic_istream) ist
//   die Basisklasse für alle Eingabe-Streams
// - [`std::ifstream`](https://en.cppreference.com/w/cpp/io/basic_ifstream) ist
//   ein Eingabe-Stream für Dateien
// - [`std::istringstream`](https://en.cppreference.com/w/cpp/io/basic_istringstream)
//   ist ein Eingabe-Stream für Strings

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Vordefinierte Streams
//
// - `std::cin` ist ein globaler Eingabe-Stream
// - `std::cout` ist ein globaler Ausgabe-Stream
// - `std::cerr` ist ein globaler Ausgabe-Stream für Fehlermeldungen
// - `std::clog` ist ein globaler Ausgabe-Stream für Log-Nachrichten

// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
std::cout << "Hello World!\n";

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Streams sind zustandsbehaftet
// - Mit Manipulatoren kann man z.B. das Ausgabeformat ändern oder ein Schreiben
//   des Puffers erzwingen

// %% tags=["keep"]
#include <iomanip>

// %% tags=["keep"]
std::cout << std::hex << 42 << std::endl;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Zustände von Streams
//
// Streams haben Methoden, mit denen man ihren Zustand abfragen kann:
//
// - `good()`: `true` wenn kein Fehler aufgetreten ist, I/O möglich
// - `eof()`: `true` wenn das Ende des Streams erreicht wurde
// - `fail()`, `bad()`: `true` wenn ein Fehler aufgetreten ist
// - `operator bool()`: `true` wenn kein Fehler aufgetreten ist
//
// Die verlinkte
// [Tabelle](https://en.cppreference.com/w/cpp/io/ios_base/iostate) zeigt
// die genaue Bedeutung der Zustände

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void print_stream_state(const std::istream& is)
{
    std::cout << std::boolalpha
              << "good: " << is.good() << "\n"
              << "eof:  " << is.eof() << "\n"
              << "fail: " << is.fail() << "\n"
              << "bad:  " << is.bad() << "\n";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <sstream>

// %% tags=["keep"]
std::istringstream iss("Hello World!\n");
std::string line;

// %% tags=["keep"]
print_stream_state(iss);

// %% tags=["keep"]
std::getline(iss, line);

// %% tags=["keep"]
print_stream_state(iss);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::getline(iss, line);

// %% tags=["keep"]
print_stream_state(iss);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Mit `clear()` kann man den Zustand zurücksetzen
// - Mit `setstate()` kann man einzelne Bits im Zustand setzen

// %% tags=["keep"]
iss.clear();

// %% tags=["keep"]
print_stream_state(iss);

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Richtlinien für Streams
//
// - [CG: SL.io.3: Prefer `iostreams` for
//   I/O](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio3-prefer-iostreams-for-io)
// - [CG: SL.io.10: Unless you use printf-family functions call
//   ios_base::sync_with_stdio(false)](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio10-unless-you-use-printf-family-functions-call-ios_basesync_with_stdiofalse)
// - [CG: SL.io.50: Avoid
//   endl](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slio50-avoid-endl)
