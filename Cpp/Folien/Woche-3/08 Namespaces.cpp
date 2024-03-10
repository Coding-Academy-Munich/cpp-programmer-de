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
//  <b>Namespaces</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Namespaces.cpp -->
// <!-- slides/module_150_classes/topic_155_namespaces.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Namespaces in C++
//
// - Mittel zum Vermeiden von Namenskonflikten
// - Jeder Namespace ist ein eigener Gültigkeitsbereich (Scope)
//   - Gleiche Namen in verschiedenen Namespaces sind erlaubt und führen nicht
//     zu Konflikten
// - Kann verschiedene Code-Elemente enthalten:
//   - Variablen, Funktionen, Strukturen, andere Namespaces, ...

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
namespace ns1 {
    int my_var{1};

    void my_function() {
        std::cout << "Hello from ns1!\n";
        std::cout << "my_var = " << my_var << "\n";
    }
}

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Verwenden von Namespaces
//
// - Zugriff mit dem Gültigkeitsbereichsoperator `::` (scope resolution
//   operator)

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
namespace ns2 {
    int my_var{2};
}

// %% tags=["keep"]
std::cout << "ns1::my_var = " << ns1::my_var << "\n";
std::cout << "ns2::my_var = " << ns2::my_var << "\n";

// %%
ns1::my_function();

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mehrere Blöcke
//
// - Ein Namespace kann in mehreren Blöcken definiert werden

// %% tags=["keep"]
namespace ns3 {
    int my_var{3};
}

// %% tags=["keep"]
namespace ns3 {
    void my_function() {
        std::cout << "Hello from ns3!\n";
        std::cout << "my_var = " << my_var << "\n";
    }
}

// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
std::cout << "ns3::my_var = " << ns3::my_var << "\n";

// %%
ns3::my_function();

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Verschachtelte Namespaces
//
// - Namespaces können ineinander verschachtelt werden
// - Zugriff auf Elemente in verschachtelten Namespaces mit mehreren
//   `::`-Operatoren

// %% tags=["keep"]
namespace outer_ns {
    namespace inner_ns {
        int my_var{42};
    }
}

// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
std::cout << "outer_ns::inner_ns::my_var = " << outer_ns::inner_ns::my_var << "\n";

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Verschachtelte Namespaces (C++17)
//
// - Seit C++17 können verschachtelte Namespaces in einer kompakteren Syntax
//   definiert werden:

// %% tags=["keep"]
#include <iostream>

namespace outer_ns_17::inner_ns {
    int my_var{17};
}

// %% tags=["keep"]
std::cout << "outer_ns_17::inner_ns::my_var = " << outer_ns_17::inner_ns::my_var << "\n";

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Namespace-Aliase
//
// - Kürzer/anderer Namen für einen Namespace
// - Syntax: `namespace new_name = old_name;`

// %% tags=["keep"]
namespace very_long_namespace_name {
    int my_var{4};
}

// %% tags=["keep"]
namespace short_name = very_long_namespace_name;

// %% tags=["keep"]
std::cout << "short_name::my_var = " << short_name::my_var << "\n";

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Using-Direktive
//
// - Importieren aller Symbole eines Namespaces in den aktuellen Scope
// - Syntax: `using namespace name;`

// %% tags=["keep"]
#include <iostream>

// %% tags=["keep"]
namespace ns5 {
    int my_var{5};
    int your_var{55};
}

// %% tags=["keep"]
{
    using namespace ns5;

    std::cout << "my_var = " << my_var << "\n";
    std::cout << "your_var = " << your_var << "\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Using-Deklaration
//
// - Importieren einzelner Elemente eines Namespaces in den aktuellen Scope
// - Syntax: `using name::element;`

// %% tags=["keep"]
namespace ns6 {
    int my_var{6};
    int your_var{66};
}

// %% tags=["keep"]
{
    using ns6::my_var;

    std::cout << "my_var = " << my_var << "\n";
    std::cout << "your_var = " << ns6::your_var << "\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Using-Deklaration (C++17)
//
// - Seit C++17 können mehrere Elemente eines Namespaces in den aktuellen Scope
//   importiert werden
// - Syntax: `using name::element1, name::element2, ...;`

// %% tags=["keep"]
namespace ns7 {
    int my_var{7};
    int your_var{77};
}

// %% tags=["keep"]
{
    using ns7::my_var, ns7::your_var;

    std::cout << "my_var = " << my_var << "\n";
    std::cout << "your_var = " << your_var << "\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Using und Overload-Resolution
//
// - Namen, die mit `using` importiert werden, werden bei der Overload-Resolution
//   berücksichtigt:

// %% tags=["keep"]
void foo(bool) { std::cout << "::foo(bool)\n"; }

// %% tags=["keep"]
namespace ns8 {
    void foo(int) { std::cout << "ns8::foo(int)\n"; }
    void foo(double) { std::cout << "ns8::foo(double)\n"; }
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
foo(true);
foo(1);
foo(1.0);

// %% tags=["keep"]
{
    using ::foo;
    using ns8::foo;

    foo(true);
    foo(1);
    foo(1.0);
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
namespace ns8a {
    void foo(bool) { std::cout << "ns8a::foo(bool)\n"; }
}

// %% tags=["keep"]
// {
//     using ::foo;
//     using ns8a::foo;
//     foo(true);
// }

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Anonyme Namespaces
//
// - Ein Namespace ohne Namen
// - Bietet einen eindeutigen Namespace für jede Translation Unit (Source-Datei)
// - Elemente sind nur innerhalb der gleichen Translation Unit zugreifbar
// - Sollte nie in Header-Dateien verwendet werden

// %% tags=["keep"]
namespace {
    int var_in_anonymous_namespace{8};
}

// %% tags=["keep"]
var_in_anonymous_namespace

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Argument-dependent lookup (ADL)
//
// - Namen von Funktionen werden auch in den Namensräumen der Argumente gesucht

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <typeinfo>

template <typename T>
void fun(T t) {
    std::cout << "fun< " << typeid(T).name() << " >(...)\n";
}

template <typename T>
void nofun(T t) {
    std::cout << "nofun< " << typeid(T).name() << " >(...)\n";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
namespace ns10 {
    struct MyStruct {
        int x;
        int y;
    };

    void fun(const MyStruct& ms) {
        std::cout << "fun(MyStruct{" << ms.x << ", " << ms.y << "})\n";
    }
}

// %% tags=["keep"]
ns10::MyStruct ms{10, 20};

// %% tags=["keep"]
fun(ms);

// %% tags=["keep"]
ns10::fun(ms);

// %% tags=["keep"]
::fun(ms);

// %% tags=["keep"]
nofun(ms);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - ADL betrifft nur Namespaces und nicht Klassen
//   - Obwohl der Scope-Operator auch für statische Member von Klassen verwendet
//     werden kann


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct YourStruct {
    int x;
    int y;

    static void fun(const YourStruct& ys) {
        std::cout << "YourStruct::fun()\n";
    }
};

// %% tags=["keep"]
YourStruct ys{30, 40};

// %% tags=["keep"]
YourStruct::fun(ys);

// %% tags=["keep"]
fun(ys);

// %% tags=["keep"]
nofun(ys);
