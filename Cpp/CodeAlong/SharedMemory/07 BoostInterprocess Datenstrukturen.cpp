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
//  <b>Boost.Interprocess: Datenstrukturen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 BoostInterprocess Datenstrukturen.cpp -->
// <!-- slides/module_300_concurrency/topic_250_data_structures.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Container in Shared Memory
//
// - Boost.Interprocess bietet STL-kompatible Allokatoren
// - STL-Implementierungen sind oft nicht kompatibel
// - Boost.Interprocess bietet eigene Container mit STL-Interface
//
// `code/completed/shared_memory/shm_070_allocator.cpp`
