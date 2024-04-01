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
//  <b>Boost.Interprocess: Benannte Objekte</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 BoostInterprocess Benannte Objekte.cpp -->
// <!-- slides/module_300_concurrency/topic_230_named_objects.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Benannte Objekte
//
// - Objekte in einem verwalteten Segment können benannt werden
// - Konstruktion mit `segment.construct<T>(name)(args...)`
//   - Sowohl einzelne Objekte als auch Arrays möglich
// - Zugriff auf benannte Objekte mit `segment.find<T>(name)`
// - Zerstörung mit `segment.destroy<T>(name)`
// - Oft flexibler als Handles
//
// `code/completed/shared_memory/shm_040_named_objects.cpp`
