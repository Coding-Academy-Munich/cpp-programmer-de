// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Namespaces</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Namespaces.cpp -->
// <!-- slides/module_150_classes/topic_155_namespaces.cpp -->

// %% [markdown]
//
// # Namespaces in C++
//
// - Mittel zum Vermeiden von Namenskonflikten
// - Jeder Namespace ist ein eigener Gültigkeitsbereich (Scope)
//   - Gleiche Namen in verschiedenen Namespaces sind erlaubt und führen nicht
//     zu Konflikten
// - Kann verschiedene Code-Elemente enthalten:
//   - Variablen, Funktionen, Strukturen, andere Namespaces, ...

// %%
#include <iostream>

// %%
namespace ns1 {
    int my_var{1};

    void my_function() {
        std::cout << "Hello from ns1!\n";
        std::cout << "my_var = " << my_var << "\n";
    }
}

// %% [markdown]
//
// ## Verwenden von Namespaces
//
// - Zugriff mit dem Gültigkeitsbereichsoperator `::` (scope resolution
//   operator)

// %%
namespace ns2 {
    int my_var{2};
}

// %%
std::cout << "ns1::my_var = " << ns1::my_var << "\n";
std::cout << "ns2::my_var = " << ns2::my_var << "\n";

// %%
ns1::my_function();

// %% [markdown]
//
// ## Mehrere Blöcke
//
// - Ein Namespace kann in mehreren Blöcken definiert werden

// %%
namespace ns3 {
    int my_var{3};
}

// %%
namespace ns3 {
    void my_function() {
        std::cout << "Hello from ns3!\n";
        std::cout << "my_var = " << my_var << "\n";
    }
}

// %%
#include <iostream>

// %%
std::cout << "ns3::my_var = " << ns3::my_var << "\n";

// %%
ns3::my_function();

// %% [markdown]
//
// ## Verschachtelte Namespaces
//
// - Namespaces können ineinander verschachtelt werden
// - Zugriff auf Elemente in verschachtelten Namespaces mit mehreren
//   `::`-Operatoren

// %%
namespace outer_ns {
    namespace inner_ns {
        int my_var{42};
    }
}

// %%
#include <iostream>

// %%
std::cout << "outer_ns::inner_ns::my_var = " << outer_ns::inner_ns::my_var << "\n";

// %% [markdown]
//
// ## Verschachtelte Namespaces (C++17)
//
// - Seit C++17 können verschachtelte Namespaces in einer kompakteren Syntax
//   definiert werden:

// %%
#include <iostream>

namespace outer_ns_17::inner_ns {
    int my_var{17};
}

// %%
std::cout << "outer_ns_17::inner_ns::my_var = " << outer_ns_17::inner_ns::my_var << "\n";

// %% [markdown]
//
// ## Namespace-Aliase
//
// - Kürzer/anderer Namen für einen Namespace
// - Syntax: `namespace new_name = old_name;`

// %%
namespace very_long_namespace_name {
    int my_var{4};
}

// %%
namespace short_name = very_long_namespace_name;

// %%
std::cout << "short_name::my_var = " << short_name::my_var << "\n";

// %% [markdown]
//
// ## Using-Direktive
//
// - Importieren aller Symbole eines Namespaces in den aktuellen Scope
// - Syntax: `using namespace name;`

// %%
#include <iostream>

// %%
namespace ns5 {
    int my_var{5};
    int your_var{55};
}

// %%
{
    using namespace ns5;

    std::cout << "my_var = " << my_var << "\n";
    std::cout << "your_var = " << your_var << "\n";
}

// %% [markdown]
//
// ## Using-Deklaration
//
// - Importieren einzelner Elemente eines Namespaces in den aktuellen Scope
// - Syntax: `using name::element;`

// %%
namespace ns6 {
    int my_var{6};
    int your_var{66};
}

// %%
{
    using ns6::my_var;

    std::cout << "my_var = " << my_var << "\n";
    std::cout << "your_var = " << ns6::your_var << "\n";
}

// %% [markdown]
//
// ## Using-Deklaration (C++17)
//
// - Seit C++17 können mehrere Elemente eines Namespaces in den aktuellen Scope
//   importiert werden
// - Syntax: `using name::element1, name::element2, ...;`

// %%
namespace ns7 {
    int my_var{7};
    int your_var{77};
}

// %%
{
    using ns7::my_var, ns7::your_var;

    std::cout << "my_var = " << my_var << "\n";
    std::cout << "your_var = " << your_var << "\n";
}

// %% [markdown]
//
// ## Using und Overload-Resolution
//
// - Namen, die mit `using` importiert werden, werden bei der Overload-Resolution
//   berücksichtigt:

// %%
void foo(bool) { std::cout << "::foo(bool)\n"; }

// %%
namespace ns8 {
    void foo(int) { std::cout << "ns8::foo(int)\n"; }
    void foo(double) { std::cout << "ns8::foo(double)\n"; }
}

// %%
foo(true);
foo(1);
foo(1.0);

// %%
{
    using ::foo;
    using ns8::foo;

    foo(true);
    foo(1);
    foo(1.0);
}

// %%
namespace ns8a {
    void foo(bool) { std::cout << "ns8a::foo(bool)\n"; }
}

// %%
// {
//     using ::foo;
//     using ns8a::foo;
//     foo(true);
// }

// %% [markdown]
//
// ## Anonyme Namespaces
//
// - Ein Namespace ohne Namen
// - Bietet einen eindeutigen Namespace für jede Translation Unit (Source-Datei)
// - Elemente sind nur innerhalb der gleichen Translation Unit zugreifbar
// - Sollte nie in Header-Dateien verwendet werden

// %%
namespace {
    int var_in_anonymous_namespace{8};
}

// %%
var_in_anonymous_namespace

// %% [markdown]
//
// ## Argument-dependent lookup (ADL)
//
// - Namen von Funktionen werden auch in den Namensräumen der Argumente gesucht

// %%
#include <typeinfo>

template <typename T>
void fun(T t) {
    std::cout << "fun< " << typeid(T).name() << " >(...)\n";
}

template <typename T>
void nofun(T t) {
    std::cout << "nofun< " << typeid(T).name() << " >(...)\n";
}

// %%
namespace ns10 {
    struct MyStruct {
        int x;
        int y;
    };

    void fun(const MyStruct& ms) {
        std::cout << "fun(MyStruct{" << ms.x << ", " << ms.y << "})\n";
    }
}

// %%
ns10::MyStruct ms{10, 20};

// %%
fun(ms);

// %%
ns10::fun(ms);

// %%
::fun(ms);

// %%
nofun(ms);

// %% [markdown]
//
// - ADL betrifft nur Namespaces und nicht Klassen
//   - Obwohl der Scope-Operator auch für statische Member von Klassen verwendet
//     werden kann


// %%
struct YourStruct {
    int x;
    int y;

    static void fun(const YourStruct& ys) {
        std::cout << "YourStruct::fun()\n";
    }
};

// %%
YourStruct ys{30, 40};

// %%
YourStruct::fun(ys);

// %%
fun(ys);

// %%
nofun(ys);
