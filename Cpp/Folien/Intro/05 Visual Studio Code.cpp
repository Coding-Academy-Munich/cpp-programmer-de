// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Visual Studio Code</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Visual Studio Code.cpp -->
// <!-- slides/module_110_introduction/topic_134_vscode.cpp -->

// %% [markdown]
//
// - Installieren Sie die folgenden Erweiterungen in VS Code:
//   - C/C++ (`ms-vscode.cpptools`)
//   - C/C++ Extension Pack (`ms-vscode.cpptools-extension-pack`)
//   - CMake Tools (`ms-vscode.cmake-tools`)

// %% [markdown]
//
// - Öffnen Sie das Projekt:
//   - `File` $\rightarrow$ `Open Folder...` $\rightarrow$ `code`-Ordner
//     auswählen
//   - Dialog: "Mehrere Visual Studio Projekte": "Keines Laden" auswählen
// - CMake Preset auswählen:
// - `x64 Debug` oder `x64 Release` für 64-Bit-Windows-Systeme
// - `x86 Debug` oder `x86 Release` für 32-Bit-Windows-Systeme
// - `Linux GCC` oder `Linux Clang` für Linux-Systeme
// - `MacOS Debug` für MacOS-Systeme

// %% [markdown]
//
// - Evtl. Auswahl der Top-Level-`CMakeLists.txt`-Datei
// - Evtl. Command-Palette: `CMake: Configure` oder `CMake: Delete Cache and
//   Reconfigure` auswählen (`Strg+Shift+P`)
// - `code` als aktives `cmake`-Projekt auswählen
// - Auswahl von Build- und Launch-Target
// - Mehr Information: [Visual Studio Code Dokumentation](https://code.visualstudio.com/docs/languages/cpp)

// %% [markdown]
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
