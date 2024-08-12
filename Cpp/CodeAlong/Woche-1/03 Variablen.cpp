// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Variablen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Variablen.cpp -->
// <!-- slides/module_120_basics/topic_130_variables.cpp -->

// %% [markdown]
//
// # Objekte und Variablen
//
// - Ein *Objekt* in C++
//     - ist ein Speicherbereich
//     - mit einem bestimmten Typ
// - Eine *Variable*
//     - ist ein benanntes Objekt

// %% [markdown]
//
// ## Variablendefinition
//
// - Die **Definition** einer Variablen
//     - reserviert den Speicherplatz für die Variable und
//     - führt den Namen ins Programm ein.
// - Eine Variablendefinition *kann* die Variable initialisieren.

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Eine initialisierte Variable hat einen definierten Wert.
// - Uninitialisierte Variablen können beliebige Werte enthalten.
// - Das Lesen einer uninitialisierten Variable ist undefiniertes Verhalten und
//   kann zu Absturz des Programms führen.

// %% [markdown]
//
// - Variablendefinition:
//   - *Typ* *Name* `;`
//   - Beispiel: `int i;`
//   - Optionale Initialisierung
//   - Beispiel: `int i{1};`
// - Falls keine explizite Initialisierung erfolgt, hängt es vom Typ der Variablen
//   und der Stelle im Programm ab, ob die Variable initialisiert ist oder nicht.

// %% [markdown]
//
// ### Core Guidelines zur Initialisierung
//
// - [ES.20: Always initialize an
//   object](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es20-always-initialize-an-object)
// - [ES.21: Don’t introduce a variable (or constant) before you need to use
//   it](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es21-dont-introduce-a-variable-or-constant-before-you-need-to-use-it)
// - [ES.22: Don’t declare a variable until you have a value to initialize it
//   with](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es22-dont-declare-a-variable-until-you-have-a-value-to-initialize-it-with)

// %% [markdown]
//
// Es gibt mehrere Varianten für die Initialisierung von Variablen:

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Unterschiede bei der Initialisierung
//
// - Manche Formen der Initialisierung führen verlustbehaftete Konversionen
//   durch.
// - Die Initialisierung mit Klammern `int i(1)` kann manchmal vom Compiler als
//   Funktionsdeklaration interpretiert werden ("most vexing parse")

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Im Allgemeinen ist die `{}`-Syntax die bevorzugte Variante.
// - [Core Guidelines ES.23: Prefer the `{}`-initializer
//   Syntax](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-list)

// %% [markdown]
//
// ### Value-Initialisierung
//
// - Wenn ein Objekt mit leerem Initialisierer erzeugt wird, spricht man von
//   [*Value-Initialisierung*](https://en.cppreference.com/w/cpp/language/value_initialization).
// - Damit kann man sicherstellen, dass ein Objekt mit einem Standardwert
//   initialisiert wird ohne ihn explizit angeben zu müssen.

// %%

// %% [markdown]
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

// %% [markdown]
//
// ### Gleichzeitige Definition mehrerer Variablen
//
// - Wir können mehrere Variablen gleichzeitig definieren.
// - Die Variablen können mit allen gezeigten Initialisierungsformen
//   initialisiert werden oder uninitialisiert bleiben.
// - Das kann leicht unübersichtlich werden, vor allem wenn wir Modifikatoren
//   verwenden.

// %%

// %%

// %%

// %% [markdown]
//
// ### Core Guidelines
//
// - [ES.10: Declare one name (only) per
//   declaration](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es10-declare-one-name-only-per-declaration)

// %% [markdown]
//
// ## Zuweisung von Werten
//
// - `=` ist der Zuweisungsoperator.
// - Bei der Zuweisung wird der Typ der Variablen nicht mehr angegeben.
// - Die Variable muss bereits definiert sein, bevor wir ihr einen Wert
//   zuweisen.

// %%

// %%

// %%

// %%

// %%
// an_undefined_variable = 1;

// %% [markdown]
//
// - Zuweisung

// %%
i = 123;

// %% [markdown]
//
// - Keine Zuweisung sondern neue Definition:

// %%
int i = 1;

// %% [markdown]
//
// Mehrfache Definitionen der gleichen Variablen (in einem Scope) sind nur in
// Notebooks erlaubt, nicht in C++-Programmen!

// %% [markdown]
//
// - Wir können auf der rechten Seite der Zuweisung den alten Wert der Variablen
//   verwenden.


// %%
int i{1};

// %%

// %%

// %% [markdown]
//
// - Der Typ der rechten Seite muss mit dem Typ der linken Seite kompatibel sein.
// - Dabei werden implizite Konversionen durchgeführt.
// - Konversionen können verlustbehaftet sein.

// %%

// %%

// %%

// %%
int i{1};

// %%

// %%

// %%

// %% [markdown]
//
// - Wir können den Zuweisungsoperator auch mit anderen Operatoren kombinieren:

// %%
int i{1};

// %%

// %%


// %% [markdown]
//
// - `i += 1` ist eine Kurzform für `i = i + 1;`
// - Entsprechend gibt es auch `-=`, `*=`, `/=`, `%=`, usw.

// %%
int i{2};

// %%

// %%


// %% [markdown]
//
// ## Mini-Workshop: Variablen
//
// Welche der folgenden Initialisierungen sind gültig?
//
// Versuchen Sie sich zu überlegen, welches Ergebnis Sie erwarten
// und überprüfen Sie es dann indem Sie die Zelle evaluieren.

// %%
// int i1 = 1;

// %%
// signed short i2(65535u);

// %%
// i2

// %%
// long i3{3};

// %%
// int i4 = {4.0};

// %%
// int i5 = 4.0;

// %%
// int i6 = 4.5;


// %% [markdown]
//
// - Was ist der Wert von `v1` und `v2` nach der Ausführung der folgenden
//   Anweisungen?
// - (Versuchen Sie, die Werte erst zu bestimmen, ohne die Zelle auszuführen)

// %%
int v1{1}, v2{2};
v1 = v1 + 1;
v1 += v2;
v2 *= v2;

// %%
v1

// %%
v2
