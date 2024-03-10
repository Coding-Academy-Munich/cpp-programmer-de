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
//  <b>Visual Studio</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Visual Studio.cpp -->
// <!-- slides/module_110_introduction/topic_132_vs.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Öffnen des Projekts:
//   - Startbildschirm: `Open a local folder` $\rightarrow$ `code`-Ordner auswählen
//   - Menü `Open` $\rightarrow$ `Folder` $\rightarrow$ `code`-Ordner auswählen
// - `Local Machine`
// - `x64 Debug` oder `x64 Release` für 64-Bit-Systeme
// - `x86 Debug` oder `x86 Release` für 32-Bit-Systeme
// - `Select Startup Item...` $\rightarrow$ das gewünschte Target auswählen
// - Mehr Information: [Visual Studio Dokumentation](https://learn.microsoft.com/de-de/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Einige Targets
//
// - `hello_world.exe`: Hello-World Programm zum Testen des Build-Prozesses
// - `hello_world_sk.exe`: Hello-World Starter-Kit
// - `blocks_sk.exe`: Refactoring Workshop mit graphischer Ausgabe
//   - Abschluss-Workshop für Refactorings
//   - Verwendet [raylib](https://github.com/raysan5/raylib)
//   - Bitte lassen Sie mich wissen, wenn das Beispiel beim Übersetzen Probleme macht
//   - Dann können wir einen anderen Workshop auswählen
