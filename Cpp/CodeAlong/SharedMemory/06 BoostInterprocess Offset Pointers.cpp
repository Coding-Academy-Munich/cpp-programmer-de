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
//  <b>Boost.Interprocess: Offset Pointers</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 BoostInterprocess Offset Pointers.cpp -->
// <!-- slides/module_300_concurrency/topic_240_offset_pointers.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Shared Memory und Pointer
//
// - Pointer in Shared Memory sind problematisch
//   - Pointer zeigen auf Adressen im Adressraum des Prozesses
//   - Adressen können sich zwischen Prozessen unterscheiden
//
// `code/completed/shared_memory/shm_050_bad_pointer.cpp`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Offset Pointer
//
// - Pointer, der auf einen Offset im Shared Memory zeigt
// - Keine direkte Adressierung
// - Automatische Anpassung der Adressen zwischen Prozessen
//
// `code/completed/shared_memory/shm_060_offset_pointer.cpp`
