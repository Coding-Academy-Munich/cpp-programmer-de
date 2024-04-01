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
// <!--
// clang-format off
// -->
//
// <div style="text-align:center; font-size:200%;">
//  <b>Boost.Interprocess: Verwaltete Segmente</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 BoostInterprocess Verwaltete Segmente.cpp -->
// <!-- slides/module_300_concurrency/topic_220_managed_segments.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Automatische Verwaltung von Shared Memory
//
// - Erstellen eines verwalteten Speicher-Segments mit `bi::managed_shared_memory`
// - Allozieren von Speicher mit `segment.allocate(size)`
// - Freigeben von Speicher mit `segment.deallocate(ptr)`
// - Handles zum Übergeben an andere Prozesse
// - Mehrere Allokationen möglich
//
// `code/completed/shared_memory/shm_030_managed_segment.cpp`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Handling von mehreren Allokationen
//
// - Allokation von mehreren Speicherbereichen, z.B. für verschiedene Datentypen
// - Ein Handle pro Allokation
// - Allokationen können unabhängig voneinander freigegeben werden
//
// `code/completed/shared_memory/shm_035_managed_segment_multi.cpp`
