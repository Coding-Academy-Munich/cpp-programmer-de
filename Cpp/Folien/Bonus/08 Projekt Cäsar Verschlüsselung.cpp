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
//  <b>Projekt: Cäsar Verschlüsselung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Projekt Cäsar Verschlüsselung.cpp -->
// <!-- slides/projects/project_120_caesar_cipher.cpp -->

// %% [markdown] lang="de"
//
// ## Cäsar-Verschlüsselung
//
// Bei der Cäsar-Verschlüsselung werden die Buchstaben des zu verschlüsselnden
// Wortes im Alphabet um 3 Stellen verschoben, z.B. wird aus der Zeichenkette
// `ABC` die Zeichenkette `DEF`. Die letzten drei Buchstaben des Alphabets
// werden durch die ersten ersetzt, d.h. aus `XYZA` wird `ABCD`.
//
// Typischerweise werden bei historischen Verschlüsselungsverfahren alle
// Buchstaben in Großbuchstaben umgewandelt. Leer- und Sonderzeichen werden
// ignoriert. So wird aus "Ich kam, sah und siegte." der verschlüsselte Text
//
// ```
// LFKNDPVDKXQGVLHJWH
// ```

// %% [markdown] lang="de"
//
// Schreiben Sie eine Funktion `char encodeChar(char c)`, die ein Zeichen `c`
// folgendermaßen verschlüsselt:
//
// - ist `c` einer der Buchstaben `a` bis `z` oder `A` bis `Z` so wird er, falls
//   nötig, in einen Großbuchstaben umgewandelt und mit der
//   Cäsar-Verschlüsselung verschlüsselt;
// - ist `c` eine Ziffer, so wird sie unverändert zurückgegeben;
// - andernfalls wird der Null-Charakter `'\0'` zurückgegeben.
//
// *Hinweis:* Die folgenden beiden Strings sind dabei hilfreich:

// %% tags=["keep"]
const std::string lettersInAlphabeticalOrder{"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
const std::string lettersInEncodedOrder{"DEFGHIJKLMNOPQRSTUVWXYZABC1234567890"};

// %%
#include <algorithm> // For std::find
#include <string>

char encodeChar(char c)
{
    // Convert to uppercase
    char cToUpper = toupper(c);
    auto pos = lettersInAlphabeticalOrder.find(cToUpper);

    if (pos != std::string::npos)
    {
        return lettersInEncodedOrder[pos];
    }
    else
    {
        return '\0'; // Indicates character should be deleted
    }
}

// %% [markdown] lang="de"
// Testen Sie Ihre Implementierung mit einigen Werten

// %% tags=["keep"]
#include <iostream>

// %%
std::cout << encodeChar('a') << std::endl;

// %%
std::cout << encodeChar('x') << std::endl;

// %% tags=["alt"]
std::cout << encodeChar('3') << std::endl;

// %% tags=["alt"]
std::cout << std::boolalpha << (encodeChar('!') == '\0') << std::endl;

// %% [markdown] lang="de"
//
// Schreiben Sie eine Funktion
// `std::string encodeCaesar(const std::string& text)`, die einen String
// `text` mittels der Cäsar-Verschlüsselung verschlüsselt.

// %%
#include <sstream>
#include <string>

std::string encodeCaesar(const std::string& text)
{
    std::stringstream encoded;
    for (char c : text)
    {
        if (char encodedChar{encodeChar(c)}; encodedChar != '\0')
        { // Only append if character was encoded
            encoded << encodedChar;
        }
    }
    return encoded.str();
}

// %% [markdown] lang="de"
// Überprüfen Sie Ihr Programm mit den folgenden Beispielen:

// %% tags=["keep"]
std::string pangram{"Sphinx of black quartz, judge my vow!"};

// %%
std::string encodedPangram{encodeCaesar(pangram)};
std::cout << encodedPangram << std::endl;

// %% tags=["alt"]
std::string sortedPangram{encodedPangram};
std::sort(sortedPangram.begin(), sortedPangram.end());
std::cout << sortedPangram << std::endl;

// %% tags=["alt"]
sortedPangram.erase(std::unique(sortedPangram.begin(), sortedPangram.end()), sortedPangram.end());
std::cout << sortedPangram << " (length = " << sortedPangram.size() << ")" << std::endl;

// %% tags=["keep"]
std::string verlaine{"1. Les sanglots longs\n"
                     "2. Des violons\n"
                     "3. De l'automne\n"
                     "4. Blessent mon coeur\n"
                     "5. D'une langueur\n"
                     "6. Monotone.\n"
                     "\n"
                     "(Verlaine, 1866)\n"
                     "Gesendet vom BBC 1944-06-01 um Operation Overlord anzukündigen\n"
};

// %%
std::string encodedVerlaine{encodeCaesar(verlaine)};
std::cout << encodedVerlaine << std::endl;

// %% [markdown] lang="de"
//
// Schreiben Sie jetzt Funktionen `char decodeChar(char c)`
// und `std::string decodeCaesar(const std::string& text)`,
// die einen mit der Cäsar-Verschlüsselung verschlüsselten Text entschlüsseln.
// Um robust zu sein, sollen diese Funktionen Zeichen, die keine Buchstaben oder
// Ziffern sind, unverändert zurückgeben.

// %%
char decodeChar(char c)
{
    auto pos = lettersInEncodedOrder.find(c);
    if (pos != std::string::npos)
    {
        return lettersInAlphabeticalOrder[pos];
    }
    else
    {
        return c; // Return unchanged if not a letter or digit
    }
}

// %%
std::string decodeCaesar(const std::string& text)
{
    std::stringstream decodedText;

    for (char c : text)
    {
        decodedText << decodeChar(c);
    }
    return decodedText.str();
}

// %% [markdown] lang="de"
// Testen Sie `decodeCaesar()` mit `pangram` und `verlaine`.

// %%
std::string decodedPangram{decodeCaesar(encodedPangram)};
std::cout << decodedPangram << std::endl;

// %%
std::string decodedVerlaine{decodeCaesar(encodedVerlaine)};
std::cout << decodedVerlaine << std::endl;

// %% [markdown] lang="de"
// Entschlüsseln Sie den folgenden Text:
// ```
// SDFN PB ERA ZLWK ILYH GRCHQ OLTXRU MXJV
// (SDQJUDP IURP QDVD'V VSDFH VKXWWOH SURJUDP)
// ```

// %% tags=["keep"]
std::string secretText{"SDFN PB ERA ZLWK ILYH GRCHQ OLTXRU MXJV\n"
                       "(SDQJUDP IURP QDVD'V VSDFH VKXWWOH SURJUDP)"};

// %%
std::cout << decodeCaesar(secretText) << std::endl;

// %% [markdown] lang="de"
//
// Die Funktionen `encodeChar()` und `decodeChar()` sind relativ ähnlich: Beide
// geben ein Zeichen zurück, das um eine feste Anzahl von Stellen im Alphabet
// verschoben ist. Können Sie eine Funktion `char rotNChars(char c, int n, ...)`
// schreiben, die die Funktionalität beider Funktionen verallgemeinert? Dabei
// steht `...` für evtl. nötige optionale Argumente, die das Verhalten der
// Funktion beeinflussen.

// %%
char rotNChars(char c, int n, bool keepNonLetters = false)
{
    char cToUpper = toupper(c);
    auto pos = lettersInAlphabeticalOrder.find(cToUpper);

    if (pos != std::string::npos)
    {
        size_t targetIndex = (pos + n) % lettersInAlphabeticalOrder.length();
        return lettersInAlphabeticalOrder[targetIndex];
    }
    else if (keepNonLetters)
    {
        return cToUpper;
    }
    else
    {
        return '\0'; // Return empty character for non-letters when not keeping them
    }
}

// %% [markdown] lang="de"
//
// Wie würden Sie `encodeCaesar()` und `decodeCaesar()` unter
// Zuhilfenahme dieser Funktion implementieren?

// %%
std::string encodeCaesar2(const std::string& text)
{
    std::stringstream encodedText;
    for (char c : text)
    {
        if (char encodedChar{rotNChars(c, 3)}; encodedChar != '\0')
        {
            encodedText << encodedChar;
        }
    }
    return encodedText.str();
}

// %%
std::string decodeCaesar2(const std::string& text)
{
    std::stringstream decodedText;
    for (char c : text)
    {
        decodedText << rotNChars(c, -3, true);
    }
    return decodedText.str();
}

// %% [markdown] lang="de"
//
// Testen Sie die neuen Funktionen mittels `secretText` und `verlaine`.
// Sind alte und neue Implementierungen kompatibel?

// %%
std::cout << decodeCaesar2(secretText) << std::endl;

// %%
std::string encodedVerlaine2{encodeCaesar2(verlaine)};
std::cout << encodedVerlaine2 << std::endl;

// %% tags=["alt"]
std::cout << decodeCaesar2(encodedVerlaine2) << std::endl;

// %% tags=["alt"]
std::cout << decodeCaesar(encodedVerlaine2) << std::endl;

// %% [markdown] lang="de"
//
// Möglicherweise zeigen die Tests, dass Ihre
// neue Implementierung einen Fehler hat, der bei der Verallgemeinerung häufig
// passiert: Es kann sein, dass der generalisierte Code Zahlen und Buchstaben
// vermischt und manche Buchstaben falsch decodiert.
//
// Gratulation, falls Sie diesen Fehler vermieden haben!
// Wie können wir den Fehler beseitigen, falls er bei Ihnen auftritt?

// %%
#include <cctype> // For std::isdigit, std::toupper

// %%
char rotNChars(char c, int n, bool keepNonLetters = false)
{
    std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cToUpper = std::toupper(c);
    auto pos = letters.find(cToUpper);

    if (pos != std::string::npos)
    {
        size_t targetIndex{(pos + n + letters.length()) % letters.length()};
        return letters[targetIndex];
    }
    else if (std::isdigit(c) || keepNonLetters)
    {
        return cToUpper;
    }
    else
    {
        return '\0'; // Return empty character for non-letters and non-digits when not
                     // keeping them
    }
}

// %%
std::string encodeCaesar2(const std::string& text)
{
    std::stringstream encodedText;
    for (char c : text)
    {
        if (char encodedChar{rotNChars(c, 3)}; encodedChar != '\0')
        {
            encodedText << encodedChar;
        }
    }
    return encodedText.str();
}

// %%
std::string decodeCaesar2(const std::string& text)
{
    std::stringstream decodedText;
    for (char c : text)
    {
        decodedText << rotNChars(c, -3, true);
    }
    return decodedText.str();
}


// %% [markdown] lang="de"
// Testen Sie die neue Implementierung indem Sie `secretText` decodieren.

// %%
std::cout << decodeCaesar2(secretText) << std::endl;

// %% [markdown] lang="de"
// Testen Sie die neue Implementierung mit `pangram` und `verlaine`.

// %%
std::string encodedVerlaine2 = encodeCaesar2(verlaine);
std::cout << encodedVerlaine2 << std::endl;

// %%
std::cout << decodeCaesar2(encodedVerlaine2) << std::endl;

// %%
std::cout << decodeCaesar(encodedVerlaine2) << std::endl;

// %% tags=["alt"]
assert(encodeCaesar(pangram) == encodeCaesar2(pangram))

// %% tags=["alt"]
assert(encodeCaesar(verlaine) == encodeCaesar2(verlaine))

// %% tags=["alt"]
assert(decodeCaesar(encodedVerlaine) == decodeCaesar2(encodedVerlaine));

// %% tags=["alt"]
assert(decodeCaesar(encodedVerlaine2) == decodeCaesar2(encodedVerlaine2));
