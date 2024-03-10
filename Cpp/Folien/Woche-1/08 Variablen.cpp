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
//  <b>Variablen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Variablen.cpp -->
// <!-- slides/module_120_basics/topic_130_variables.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Objekte und Variablen
//
// - Ein *Objekt* in C++
//     - ist ein Speicherbereich
//     - mit einem bestimmten Typ
// - Eine *Variable*
//     - ist ein benanntes Objekt

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Variablendefinition
//
// - Die **Definition** einer Variablen
//     - reserviert den Speicherplatz für die Variable und
//     - führt den Namen ins Programm ein.
// - Eine Variablendefinition *kann* die Variable initialisieren.

// %%
int i{1};

// %%
i

// %%
int j{i};

// %%
int k;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Eine initialisierte Variable hat einen definierten Wert.
// - Uninitialisierte Variablen können beliebige Werte enthalten.
// - Das Lesen einer uninitialisierten Variable ist undefiniertes Verhalten und
//   kann zu Absturz des Programms führen.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Variablendefinition:
//   - *Typ* *Name* `;`
//   - Beispiel: `int i;`
//   - Optionale Initialisierung
//   - Beispiel: `int i{1};`
// - Falls keine explizite Initialisierung erfolgt, hängt es vom Typ der Variablen
//   und der Stelle im Programm ab, ob die Variable initialisiert ist oder nicht.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Core Guidelines zur Initialisierung
//
// - [ES.20: Always initialize an
//   object](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es20-always-initialize-an-object)
// - [ES.21: Don’t introduce a variable (or constant) before you need to use
//   it](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es21-dont-introduce-a-variable-or-constant-before-you-need-to-use-it)
// - [ES.22: Don’t declare a variable until you have a value to initialize it
//   with](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es22-dont-declare-a-variable-until-you-have-a-value-to-initialize-it-with)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Es gibt mehrere Varianten für die Initialisierung von Variablen:

// %%
int i1 = 10;
int i2(20);
int i3{30};
int i4 = {40};

// %%
i1

// %%
i2

// %%
i3

// %%
i4

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Unterschiede bei der Initialisierung
//
// - Manche Formen der Initialisierung führen verlustbehaftete Konversionen
//   durch.
// - Die Initialisierung mit Klammern `int i(1)` kann manchmal vom Compiler als
//   Funktionsdeklaration interpretiert werden ("most vexing parse")

// %%
double value{10.5};

// %%
int i1 = value;

// %%
i1

// %%
int i2(value);

// %%
i2

// %% lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
// int i3{value};    // Fehler: verlustbehaftete Konversion

// %% lang="de"
// int i4 = {value}; // Fehler: verlustbehaftete Konversion

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Im Allgemeinen ist die `{}`-Syntax die bevorzugte Variante.
// - [Core Guidelines ES.23: Prefer the `{}`-initializer
//   Syntax](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-list)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Value-Initialisierung
//
// - Wenn ein Objekt mit leerem Initialisierer erzeugt wird, spricht man von
//   [*Value-Initialisierung*](https://en.cppreference.com/w/cpp/language/value_initialization).
// - Damit kann man sicherstellen, dass ein Objekt mit einem Standardwert
//   initialisiert wird ohne ihn explizit angeben zu müssen.

// %% lang="de"
// Value-Initialisierung; i ist immer initialisiert
int i{};

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### `{}`-Syntax der Variablendefinition
//
// - Die `{}`-Syntax der Variablendefinition ist:
//
// ```cpp
// T var{};
// T var{arg};
// T var{arg1, arg2, ...};
// ```

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Gleichzeitige Definition mehrerer Variablen
//
// - Wir können mehrere Variablen gleichzeitig definieren.
// - Die Variablen können mit allen gezeigten Initialisierungsformen
//   initialisiert werden oder uninitialisiert bleiben.
// - Das kann leicht unübersichtlich werden, vor allem wenn wir Modifikatoren
//   verwenden.

// %%
int i1{1}, i2{2}, i3{3};

// %%
i1

// %%
i2

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Core Guidelines
//
// - [ES.10: Declare one name (only) per
//   declaration](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es10-declare-one-name-only-per-declaration)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Zuweisung von Werten
//
// - `=` ist der Zuweisungsoperator.
// - Bei der Zuweisung wird der Typ der Variablen nicht mehr angegeben.
// - Die Variable muss bereits definiert sein, bevor wir ihr einen Wert
//   zuweisen.

// %%
i = 10;

// %%
i

// %%
i = 20;

// %%
i

// %% tags=["keep"]
// an_undefined_variable = 1;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zuweisung

// %% tags=["keep"]
i = 123;

// %% [markdown] lang="de"
//
// - Keine Zuweisung sondern neue Definition:

// %% tags=["keep"]
int i = 1;

// %% [markdown] lang="de"
//
// Mehrfache Definitionen der gleichen Variablen (in einem Scope) sind nur in
// Notebooks erlaubt, nicht in C++-Programmen!

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können auf der rechten Seite der Zuweisung den alten Wert der Variablen
//   verwenden.


// %% tags=["keep"]
int i{1};

// %%
i

// %%
i = i + 1;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Der Typ der rechten Seite muss mit dem Typ der linken Seite kompatibel sein.
// - Dabei werden implizite Konversionen durchgeführt.
// - Konversionen können verlustbehaftet sein.

// %%
double d{1.5};

// %%
d = 10;

// %%
d

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int i{1};

// %%
i = 2.5;

// %%
i

// %%
// i = "abc";

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können den Zuweisungsoperator auch mit anderen Operatoren kombinieren:

// %% tags=["keep"]
int i{1};

// %%
i += 1;

// %%
i


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `i += 1` ist eine Kurzform für `i = i + 1;`
// - Entsprechend gibt es auch `-=`, `*=`, `/=`, `%=`, usw.

// %% tags=["keep"]
int i{2};

// %%
i *= 3 + i;

// %%
i


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Variablen
//
// Welche der folgenden Initialisierungen sind gültig?
//
// Versuchen Sie sich zu überlegen, welches Ergebnis Sie erwarten
// und überprüfen Sie es dann indem Sie die Zelle evaluieren.

// %% tags=["keep"]
// int i1 = 1;

// %% tags=["keep"]
// signed short i2(65535u);

// %% tags=["keep"]
// i2

// %% tags=["keep"]
// long i3{3};

// %% tags=["keep"]
// int i4 = {4.0};

// %% tags=["keep"]
// int i5 = 4.0;

// %% tags=["keep"]
// int i6 = 4.5;


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Was ist der Wert von `v1` und `v2` nach der Ausführung der folgenden
//   Anweisungen?
// - (Versuchen Sie, die Werte erst zu bestimmen, ohne die Zelle auszuführen)

// %% tags=["keep"]
int v1{1}, v2{2};
v1 = v1 + 1;
v1 += v2;
v2 *= v2;

// %% tags=["keep"]
v1

// %% tags=["keep"]
v2
