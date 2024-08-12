// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Strings</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Strings.cpp -->
// <!-- slides/module_140_collections/topic_190_strings.cpp -->

// %% [markdown]
//
// ## C++ Strings: `std::string`
//
// In den meisten Fällen ist es besser `std::string` anstelle von C-Strings zu
// verwenden.

// %% [markdown]
//
// - `empty`: Prüfen, ob String leer ist

// %%
std::string str1{"Hello, World!"};

// %%
str1.empty()

// %%
std::string str2{};

// %%
str2.empty()

// %% [markdown]
//
// - `length` oder `size`: Länge eines Strings ermitteln

// %%
std::string str{"Hello, World!"};

// %%
std::string::size_type length{str.length()};

// %%
length

// %%
str.size()

// %% [markdown]
//
// - `operator[]`: Zugriff auf einzelne Zeichen

// %%
std::string str{"Hello, World!"};

// %%
str[0]

// %%
str[1]

// %% [markdown]
//
// - `at`: Zugriff auf einzelne Zeichen

// %%
std::string str{"Hello, World!"};

// %%
str.at(0)

// %%
str.at(1)

// %% [markdown]
//
// - `clear`: Löschen des Strings

// %%
std::string str{"Hello, World!"};

// %%
str.clear();

// %%
str

// %% [markdown]
//
// - `substr`: Extrahieren eines Teilstrings

// %%
std::string str{"Hello, World!"};

// %%
str.substr(0, 5)

// %% [markdown]
//
// - `find`: Ermitteln der Position eines Teilstrings

// %%
std::string str{"Hello, World!"};

// %%
std::string::size_type pos{str.find("World")};

// %%
pos

// %%
std::string::size_type pos{str.find("Universe")};

// %%
pos

// %%
pos == std::string::npos

// %% [markdown]
//
// - `append`: Verketten von Strings

// %%
std::string str1{"Hello"};
std::string str2{", World!"};

// %%
str1.append(str2)

// %%
str1

// %% [markdown]
//
// ### Vergleichen von Strings
//
// - `<`, `<=`, `>`, `>=`
// - `compare`

// %%
std::string str1{"apple"};
std::string str2{"banana"};

// %%
str1 < str2

// %%
str1 <= str2

// %%
str1.compare(str2)

// %%
str2.compare(str1)

// %%
str1.compare(str1)

// %% [markdown]
//
// ### Modifizieren von Strings
//
// - `replace`: Ersetzen von Teilstrings

// %%
std::string str{"Hello, World!"};

// %%
str.replace(0, 5, "Goodbye")

// %% [markdown]
//
// - `insert`: Einfügen von Teilstrings

// %%
std::string str{"Hello, World!"};

// %%
str.insert(5, "Goodbye, ")


// %% [markdown]
//
// - `erase`: Löschen von Teilstrings

// %%
std::string str{"Hello, World!"};

// %%
str.erase(5, 7)

// %% [markdown]
//
// - `push_back`: Anhängen eines Zeichens

// %%
std::string str{"Hello, World!"};

// %%
str.push_back('!');

// %%
str

// %% [markdown]
//
// - `pop_back`: Entfernen des letzten Zeichens

// %%
std::string str{"Hello, World!"};

// %%
str.pop_back();

// %%
str

// %% [markdown]
//
// - `c_str`: Zugriff auf C-String

// %%
std::string str{"Hello, World!"};

// %%
str.c_str()

// %% [markdown]
//
// - `data`: Zugriff auf Daten
// - Muss für Versionen vor C++11 nicht mit `'\0'` enden
// - Seit C++11 die gleiche Funktion wie `c_str()`

// %%
std::string str{"Hello, World!"};

// %%
str.data()

// %% [markdown]
//
// - `resize`: Ändern der Länge des Strings
//   - Zweites Argument: Zeichen, mit dem aufgefüllt wird
//   - Ohne zweites Argument: `'0'`

// %%
std::string str{"Hello, World!"};

// %%
str.resize(5);

// %%
str

// %%
str.resize(20, '!');

// %%
str

// %% [markdown]
//
// - `reserve`: Reservieren von Speicherplatz

// %%
std::string str{"Hello, World!"};

// %%
str.reserve(100);

// %%
str

// %% [markdown]
//
// - `shrink_to_fit`: Freigeben von nicht benötigtem Speicherplatz

// %%
std::string str{"Hello, World!"};
str.reserve(100);

// %%
str.capacity()

// %%
str.shrink_to_fit();

// %%
str.capacity()

// %% [markdown]
//
// ### Iteration über Strings
//
// - Range-based `for`-Schleife
// - (Iteratoren)

// %%
std::string str{"Hello, World!"};

// %%
#include <iostream>

// %%
for (char c : str) {
    std::cout << c << '\n';
}

// %% [markdown]
//
// ## C++-String-Literale
//
// - In C++ gibt es benutzerdefinierte Literale
// - Die Standardbibliothek definiert ein Literal für `std::string`
// - Benötigt `<string>` Header und `using namespace std::string_literals;`
// - Syntax: String-Literal gefolgt von `s`

// %%
#include <string>
using namespace std::string_literals;

// %%
auto str{"Hello, World!"s};

// %%
str

// %%
str.size()


// %% [markdown]
//
// ## Mini-Workshop: Strings
//
// - Schreiben Sie ein Programm, das einen String vom Benutzer einliest und alle
//   Vorkommen `Dollar` durch `Euro` ersetzt.
// - *Hinweise:*
//   - Zum Einlesen eines Strings mit Leerzeichen ist es zweckmäßig, die
//     Funktion `std::getline(std::cin, str)` zu verwenden.
//   - Es genügt, wenn Sie eine Zeile einlesen.

// %%
#include <iostream>
#include <string>

using namespace std::string_literals;

// %%
std::string& dollar_to_euro(std::string& str) {
    const std::string::size_type len{"Dollar"s.size()};
    for (std::string::size_type i{0}; i < str.size() - len; ++i) {
        if (str.substr(i, len) == "Dollar") {
            str.replace(i, len, "Euro");
        }
    }
    return str;
}

// %%
std::string text{"I'm on the grind, chasing a Dollar and a dream. But mostly a Dollar."};
std::string text2{"Dollar and Dollar"};

// %%
dollar_to_euro(text)


// %%
dollar_to_euro(text2)

// %%
std::string& dollar_to_euro_2(std::string& str) {
    const std::string::size_type len{"Dollar"s.size()};
    std::string::size_type pos;
    while ((pos = str.find("Dollar")) != std::string::npos) {
        str.replace(pos, len, "Euro");
    }
    return str;
}

// %%
dollar_to_euro_2(text)

// %%
dollar_to_euro_2(text2)

// %%
void read_string_and_convert_dollar_to_euro(std::string& (*fun)(std::string&)) {
    std::string str;
    std::cout << "Please enter a string: ";
    std::getline(std::cin, str);
    std::cout << fun(str);
}

// %%
// read_string_and_convert_dollar_to_euro(dollar_to_euro);

// %%
// read_string_and_convert_dollar_to_euro(dollar_to_euro_2);

// %% [markdown]
//
// - Schreiben Sie ein Programm, das einen String vom Benutzer einliest und
//   ausgibt, wie viele Vokale (`a`, `e`, `i`, `o`, `u`) der String enthält.
//   Verwenden Sie für diese Aufgabe `std::string`.

// %%
#include <iostream>
#include <string>

// %%
int count_vowels(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            ++count;
        }
    }
    return count;
}

// %%
count_vowels("An easy task. Easy, I say!"s)

// %%
void ask_and_count_vowels()
{
    std::string input;
    std::getline(std::cin, input);
    std::cout << "Number of vowels: " << count_vowels(input) << "\n";
}

// %%
// ask_and_count_vowels()

// %%
