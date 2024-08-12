// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Projekt: Cäsar Verschlüsselung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Projekt Cäsar Verschlüsselung.cpp -->
// <!-- slides/projects/project_120_caesar_cipher.cpp -->

// %% [markdown]
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

// %% [markdown]
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

// %%
const std::string lettersInAlphabeticalOrder{"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
const std::string lettersInEncodedOrder{"DEFGHIJKLMNOPQRSTUVWXYZABC1234567890"};

// %%

// %% [markdown]
// Testen Sie Ihre Implementierung mit einigen Werten

// %%
#include <iostream>

// %%

// %%

// %% [markdown]
//
// Schreiben Sie eine Funktion
// `std::string encodeCaesar(const std::string& text)`, die einen String
// `text` mittels der Cäsar-Verschlüsselung verschlüsselt.

// %%

// %% [markdown]
// Überprüfen Sie Ihr Programm mit den folgenden Beispielen:

// %%
std::string pangram{"Sphinx of black quartz, judge my vow!"};

// %%

// %%
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

// %% [markdown]
//
// Schreiben Sie jetzt Funktionen `char decodeChar(char c)`
// und `std::string decodeCaesar(const std::string& text)`,
// die einen mit der Cäsar-Verschlüsselung verschlüsselten Text entschlüsseln.
// Um robust zu sein, sollen diese Funktionen Zeichen, die keine Buchstaben oder
// Ziffern sind, unverändert zurückgeben.

// %%

// %%

// %% [markdown]
// Testen Sie `decodeCaesar()` mit `pangram` und `verlaine`.

// %%

// %%

// %% [markdown]
// Entschlüsseln Sie den folgenden Text:
// ```
// SDFN PB ERA ZLWK ILYH GRCHQ OLTXRU MXJV
// (SDQJUDP IURP QDVD'V VSDFH VKXWWOH SURJUDP)
// ```

// %%
std::string secretText{"SDFN PB ERA ZLWK ILYH GRCHQ OLTXRU MXJV\n"
                       "(SDQJUDP IURP QDVD'V VSDFH VKXWWOH SURJUDP)"};

// %%

// %% [markdown]
//
// Die Funktionen `encodeChar()` und `decodeChar()` sind relativ ähnlich: Beide
// geben ein Zeichen zurück, das um eine feste Anzahl von Stellen im Alphabet
// verschoben ist. Können Sie eine Funktion `char rotNChars(char c, int n, ...)`
// schreiben, die die Funktionalität beider Funktionen verallgemeinert? Dabei
// steht `...` für evtl. nötige optionale Argumente, die das Verhalten der
// Funktion beeinflussen.

// %%

// %% [markdown]
//
// Wie würden Sie `encodeCaesar()` und `decodeCaesar()` unter
// Zuhilfenahme dieser Funktion implementieren?

// %%

// %%

// %% [markdown]
//
// Testen Sie die neuen Funktionen mittels `secretText` und `verlaine`.
// Sind alte und neue Implementierungen kompatibel?

// %%

// %%

// %% [markdown]
//
// Möglicherweise zeigen die Tests, dass Ihre
// neue Implementierung einen Fehler hat, der bei der Verallgemeinerung häufig
// passiert: Es kann sein, dass der generalisierte Code Zahlen und Buchstaben
// vermischt und manche Buchstaben falsch decodiert.
//
// Gratulation, falls Sie diesen Fehler vermieden haben!
// Wie können wir den Fehler beseitigen, falls er bei Ihnen auftritt?

// %%

// %%

// %%

// %%


// %% [markdown]
// Testen Sie die neue Implementierung indem Sie `secretText` decodieren.

// %%

// %% [markdown]
// Testen Sie die neue Implementierung mit `pangram` und `verlaine`.

// %%

// %%

// %%
