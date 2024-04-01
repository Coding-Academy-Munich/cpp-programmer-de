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
//  <b>Boost.Interprocess: Mapped Regions</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 BoostInterprocess Mapped Regions.cpp -->
// <!-- slides/module_300_concurrency/topic_215_mapped_regions.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Manuelle Verwaltung von Shared Memory
//
// - Erstellen eines Speicherbereichs mit `bi::shared_memory_object`
// - Festlegen der Größe mit `shmem.truncate(size)`
// - Abbildung des Speicherbereichs in den Adressraum mit `bi::mapped_region`
// - Entfernen des Speicherbereichs mit `shmem.remove(name)`
//
// `code/completed/shared_memory/shm_020_mapped_region.cpp`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Manuelle Verwaltung von mehreren Shared Memory Bereichen
//
// - Möglich, aber fehleranfällig
//
// `code/completed/shared_memory/shm_025_mapped_region_multi.cpp`
