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
//  <b>Entwicklungsumgebungen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Entwicklungsumgebungen.cpp -->
// <!-- slides/module_110_introduction/topic_130_dev_env.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Entwicklungsumgebungen
//
// - Die meisten aktuellen C++ Entwicklungsumgebungen sind geeignet
// - CMake $\geq$ 3.20

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Unter Windows z.B.
//   - Visual Studio 2022, jede Edition und Version (getestet mit 17.5.4).
//   - Visual Studio 2019, jede Edition, Version $\geq$ 16.11.26.
//   - JetBrains CLion mit einer entsprechenden Toolchain
//   - Visual Studio Code mit den C++- und CMake-Tools und einer entsprechenden
//     Toolchain

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
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

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Docker Image für den Code
//
// - Vorkonfiguriertes Docker-Image mit allen benötigten Tools
// - Docker-Hub:
//   - `mhoelzl/cam-cpp-dev:latest`
// - Download und Installation des Docker Images in gesonderten Video

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Interaktive Notebooks
//
// - Für die Folien verwenden wir interaktive Notebooks:
//   - Jupyter Notebooks
//   - Xeus Jupyter Kernel
// - Nur Linux und MacOS
// - Wir haben ein Docker-Image mit allen benötigten Tools vorkonfiguriert

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Docker Image für Notebooks
//
// - Vorkonfiguriertes Docker Image für Notebooks:
//   - `mhoelzl/cam-cpp-notebook:latest`
// - URL des Jupyter Servers: `http://localhost:8888`
// - Password: `CAM`
// - Download und Installation des Docker Images in einem gesonderten Video
