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
//  <b>Weak Pointer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Weak Pointer.cpp -->
// <!-- slides/module_160_raii/topic_150_weak_ptr.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Weak Pointers
//
// - Zum Auflösen von Zyklen kann man Weak Pointer verwenden
// - Weak Pointer zeigen auf ein Objekt, das von einem Shared Pointer verwaltet
//   wird
//   - Weak Pointer sind keine Eigentümer
//   - `std::weak_ptr::lock()`
//     - Shared Pointer auf das Objekt, falls es noch existiert
//     - Sonst `nullptr`

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <memory>

#include "lifetime_observer.hpp"
#include "print_info.hpp"

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::shared_ptr<Obs> obs{std::make_shared<Obs>(1)};

// %% tags=["keep"]
std::weak_ptr<Obs> weak_obs{obs};

// %% tags=["keep"]
weak_obs.use_count()

// %% tags=["keep"]
weak_obs.expired()

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    std::shared_ptr<Obs> shared_obs{weak_obs.lock()};
    print_use_count("shared_obs", shared_obs);
    print_use_count("weak_obs", weak_obs);
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    std::shared_ptr<Obs> shared_obs{weak_obs.lock()};
    obs.reset();
    print_use_count("shared_obs", shared_obs);
    print_use_count("weak_obs", weak_obs);
}

// %% tags=["keep"]
weak_obs.expired()

// %% tags=["keep"]
weak_obs.use_count()

// %% tags=["keep"]
print_null(weak_obs.lock());

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct NoCycle
{
    NoCycle(int value) : value(value) {}
    ~NoCycle() { std::cout << "NoCycle::~NoCycle()\n"; }
    int value;
    std::weak_ptr<NoCycle> other;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    std::shared_ptr<NoCycle> c1{std::make_shared<NoCycle>(1)};
    std::shared_ptr<NoCycle> c2{std::make_shared<NoCycle>(2)};
    c1->other = c2;
    c2->other = c1;
    print_use_count("c1", c1);
    print_use_count("c2", c2);
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::weak_ptr<NoCycle> wp;
{
    std::shared_ptr<NoCycle> c1{std::make_shared<NoCycle>(1)};
    std::shared_ptr<NoCycle> c2{std::make_shared<NoCycle>(2)};
    c1->other = c2;
    c2->other = c1;
    wp = c1;
    print_null("wp", wp.lock());
}
print_null("wp", wp.lock());

// %%
