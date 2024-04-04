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
//  <b>Synchronisierung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Synchronisierung.cpp -->
// <!-- slides/module_300_concurrency/topic_260_synchronization.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Um Shared Memory sicher zu verwenden, müssen Zugriffe synchronisiert werden
// - Boost.Interprocess bietet verschiedene Arten von Synchronisierungsmechanismen
// - Benannt/anonym
// - Mutex, Condition Variablen, Semaphoren, ...

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mutex
//
// - **Mut**ual **Ex**clusion
// - Kann gesperrt und entsperrt werden: `mutex.lock()`, `mutex.unlock()`
// - Nur ein Thread/Prozess kann den Mutex sperren
// - Andere Threads/Prozesse warten, bis der Mutex entsperrt wird
// - Boost.Interprocess bietet rekursive und nicht-rekursive Mutexe

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Scoped Lock
//
// - Automatisches Sperren und Entsperren eines Mutex
// - Verhindert das Vergessen des Entsperrens

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Condition Variable
//
// - Mit einem Mutex kann man nicht (effizient) auf ein Ereignis warten
// - Condition Variables ermöglichen das Warten auf ein Ereignis
// - `condition_variable.wait(mutex)`
//   - Thread wird blockiert, bis ein anderer Thread/Prozess ihn weckt
//   - `mutex` muss gesperrt sein, bevor `wait` aufgerufen wird
//   - `mutex` wird automatisch entsperrt, während der Thread blockiert ist
//   - Das passiert atomar
//   - Wenn der Thread aufwacht, ist `mutex` wieder gesperrt

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - `condition_variable.notify_one()`
//   - Weckt einen wartenden Thread
// - `condition_variable.notify_all()`
//   - Weckt alle wartenden Threads
