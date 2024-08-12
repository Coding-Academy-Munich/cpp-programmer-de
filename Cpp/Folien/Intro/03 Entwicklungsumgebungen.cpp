// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Entwicklungsumgebungen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Entwicklungsumgebungen.cpp -->
// <!-- slides/module_110_introduction/topic_130_dev_env.cpp -->

// %% [markdown]
//
// # Entwicklungsumgebungen
//
// - Die meisten aktuellen C++ Entwicklungsumgebungen sind geeignet
// - CMake $\geq$ 3.20

// %% [markdown]
//
// - Unter Windows z.B.
//   - Visual Studio 2022, jede Edition und Version (getestet mit 17.5.4).
//   - Visual Studio 2019, jede Edition, Version $\geq$ 16.11.26.
//   - JetBrains CLion mit einer entsprechenden Toolchain
//   - Visual Studio Code mit den C++- und CMake-Tools und einer entsprechenden
//     Toolchain

// %% [markdown]
//
// - Unter Unix/Linux, z.B
//   - als Compiler.
//     - GCC/G++ version $\geq$ 10
//     - Clang version $\geq$ 10
//   - als Build-System
//     - Makefile
//     - Ninja
//   - als Editor
//     - Visual Studio Code mit den C++- und CMake-Tools
//     - JetBrains CLion mit einer entsprechenden Toolchain

// %% [markdown]
//
// ## Docker Image für den Code
//
// - Vorkonfiguriertes Docker-Image mit allen benötigten Tools
// - Docker-Hub:
//   - `mhoelzl/cam-cpp-dev:latest`
// - Download und Installation des Docker Images in gesonderten Video

// %% [markdown]
//
// ## Interaktive Notebooks
//
// - Für die Folien verwenden wir interaktive Notebooks:
//   - Jupyter Notebooks
//   - Xeus Jupyter Kernel
// - Nur Linux und MacOS
// - Wir haben ein Docker-Image mit allen benötigten Tools vorkonfiguriert

// %% [markdown]
//
// ## Docker Image für Notebooks
//
// - Vorkonfiguriertes Docker Image für Notebooks:
//   - `mhoelzl/cam-cpp-notebook:latest`
// - URL des Jupyter Servers: `http://localhost:8888`
// - Password: `CAM`
// - Download und Installation des Docker Images in einem gesonderten Video
