// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Weak Pointer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Weak Pointer.cpp -->
// <!-- slides/module_160_raii/topic_150_weak_ptr.cpp -->

// %% [markdown]
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

// %%
#include <iostream>
#include <memory>

#include "lifetime_observer.hpp"
#include "print_info.hpp"

// %%
std::shared_ptr<Obs> obs{std::make_shared<Obs>(1)};

// %%
std::weak_ptr<Obs> weak_obs{obs};

// %%
weak_obs.use_count()

// %%
weak_obs.expired()

// %%
{
    std::shared_ptr<Obs> shared_obs{weak_obs.lock()};
    print_use_count("shared_obs", shared_obs);
    print_use_count("weak_obs", weak_obs);
}

// %%
{
    std::shared_ptr<Obs> shared_obs{weak_obs.lock()};
    obs.reset();
    print_use_count("shared_obs", shared_obs);
    print_use_count("weak_obs", weak_obs);
}

// %%
weak_obs.expired()

// %%
weak_obs.use_count()

// %%
print_null(weak_obs.lock());

// %%
struct NoCycle
{
    NoCycle(int value) : value(value) {}
    ~NoCycle() { std::cout << "NoCycle::~NoCycle()\n"; }
    int value;
    std::weak_ptr<NoCycle> other;
};

// %%
{
    std::shared_ptr<NoCycle> c1{std::make_shared<NoCycle>(1)};
    std::shared_ptr<NoCycle> c2{std::make_shared<NoCycle>(2)};
    c1->other = c2;
    c2->other = c1;
    print_use_count("c1", c1);
    print_use_count("c2", c2);
}

// %%
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
