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
//  <b>Shared Memory</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Shared Memory.cpp -->
// <!-- slides/module_300_concurrency/topic_200_shared_memory.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Shared Memory ist ein Mechanismus, um Daten zwischen Prozessen auszutauschen
// - Daten werden in einem gemeinsamen Speicherbereich abgelegt
// - Prozesse können auf diesen Speicherbereich zugreifen
// - Shared Memory ist schnell, da keine Kopien der Daten erstellt werden müssen
// - Shared Memory ist schwierig zu handhaben, da keine Synchronisation durch das Betriebssystem erfolgt

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="img/shared_memory_01.svg"
//      style="display:block;margin:auto;width:30%"/>

