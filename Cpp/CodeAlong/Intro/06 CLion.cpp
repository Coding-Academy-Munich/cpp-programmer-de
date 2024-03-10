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
//  <b>CLion</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 CLion.cpp -->
// <!-- slides/module_110_introduction/topic_136_clion.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Öffnen des Projekts:
//   - `File` $\rightarrow$ `Open` $\rightarrow$ `code/CMakeLists.txt`-Datei auswählen
// - `Open as Project` auswählen
// - Die Targets werden automatisch erkannt
// - Die Konfigurationen aus `CMakePresets.json` können in den Einstellungen
//   ausgewählt werden
//   - Normalerweise ist das nicht notwendig

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Einige Targets
//
// - `hello_world`: Hello-World Programm zum Testen des Build-Prozesses
// - `hello_world_sk`: Hello-World Starter-Kit
// - `blocks_sk`: Refactoring Workshop mit graphischer Ausgabe
//   - Abschluss-Workshop für Refactorings
//   - Verwendet [raylib](https://github.com/raysan5/raylib)
//   - Bitte lassen Sie mich wissen, wenn das Beispiel beim Übersetzen Probleme macht
//   - Dann können wir einen anderen Workshop auswählen
