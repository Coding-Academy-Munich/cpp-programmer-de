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
//  <b>Boost.Interprocess</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 BoostInterprocess.cpp -->
// <!-- slides/module_300_concurrency/topic_210_boost_interprocess.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Shared Memory mit Boost.Interprocess
//
// - Plattformunabhängige Bibliothek
// - Open Source, liberale Lizenz
// - Viele Hilfsmittel zur Interprozesskommunikation:
//   - Shared Memory
//   - Memory Mapped Files
//   - Synchronisation
//   - ...


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Vorbereitung
//
// - Starten eines Subprozesses mit `std::system`
// - Einbinden von Boost.Interprocess
// - Zugriff auf die Prozess-ID mit `...::get_current_process_id()`
//
// `code/completed/shared_memory/shm_010_starter.cpp`
