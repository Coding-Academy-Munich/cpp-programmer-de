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
//  <b>Beispiel: Namen von Typen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Beispiel Namen von Typen.cpp -->
// <!-- slides/module_400_templates/topic_200_type_name.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - C++ hat keine guten Reflection-Fähigkeiten
//   - Laufzeit-Informationen über Typen (RTTI) sind sehr begrenzt
//   - Keine gute Möglichkeit, den Namen eines Typs zur Laufzeit zu ermitteln
//   - Wert von `std::type_info::name()` ist nicht standardisiert
// - Aber: Compiler kennt die Namen der Typen
//   - Können wir den Compiler dazu bringen, uns diese Namen zur Verfügung zu stellen?

// %% tags=["keep"]
#include <typeinfo>

// %% tags=["keep"]
typeid(int).name()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Idee: Template-Metaprogrammierung
//
// - Funktion `type_name<T>()`
//   - gibt den Namen des Typs `T` zurück
//   - kann für benutzerdefinierte Typen erweitert werden

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Version 1: Direkte Implementierung


// %% tags=["keep"]
#include <string>
#include <typeinfo>

// %% tags=["keep"]
template <typename T>
std::string type_name_v1()
{
    std::string type_name{typeid(T).name()};
    if (type_name.find("class ") == 0) {
        type_name.erase(0, 6);
    }
    return type_name;
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Template-Spezialisierung für bestimmte Typen

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
template <>
std::string type_name_v1<int>()
{
    return "int";
}

// %% tags=["keep"]
type_name_v1<int>()

// %% tags=["keep"]
type_name_v1<std::string>()

// %% tags=["keep"]
type_name_v1<std::vector<int>>()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Funktioniert, aber:
//   - `type_name_v1<std::vector<int>>()` ist nicht sehr schön
//   - Es ist schwierig einen passenden Overload zu definieren
//   - Partielle Spezialisierung von Funktions-Templates ist nicht erlaubt

// %% tags=["keep"]
// template <typename T>
// std::string type_name_v1<std::vector<T>>()
// {
//     return "std::vector<" + type_name_v1<T>() + ">";
// }

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Version 2: Type-Traits
//
// - Im Gegensatz zu Funktionen können Klassen partiell spezialisiert werden
// - Wir können also eine Klasse `TypeName` definieren, die den Namen eines Typs enthält
// - Die Klasse `TypeName` kann dann partiell spezialisiert werden:

// %% tags=["keep"]
template <typename T>
struct TypeName
{
    static std::string name()
    {
        std::string type_name{typeid(T).name()};
        if (type_name.find("class ") == 0) {
            type_name.erase(0, 6);
        }
        return type_name;
    }
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
template <>
struct TypeName<int>
{
    static std::string name()
    {
        return "int";
    }
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
template <>
struct TypeName<std::string>
{
    static std::string name()
    {
        return "std::string";
    }
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
template <typename T>
struct TypeName<std::vector<T>>
{
    static std::string name()
    {
        return "std::vector<" + TypeName<T>::name() + ">";
    }
};

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
TypeName<int>::name()

// %% tags=["keep"]
TypeName<bool>::name()

// %% tags=["keep"]
TypeName<std::string>::name()

// %% tags=["keep"]
TypeName<std::vector<int>>::name()

// %% tags=["keep"]
TypeName<std::vector<bool>>::name()

// %% tags=["keep"]
TypeName<std::vector<std::vector<std::string>>>::name()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Eine solche Struct nennen wir einen *Type-Trait*
// - Wir können jetzt das Erzeugen des Type-Traits in eine Funktion auslagern:

// %%
template <typename T>
std::string type_name_v2()
{
    return TypeName<T>::name();
}

// %%
type_name_v2<int>()

// %%
type_name_v2<std::string>()

// %%
type_name_v2<std::vector<int>>()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Im Header `type_name.hpp` finden Sie eine vollständigere Implementierung
// - Der Header definiert auch zwei Macros
//   - `DEFINE_TYPE_NAME(T)`, das die partielle Spezialisierung für `T`
//     definiert
//   - `DEFINE_TYPE_NAME_ALIAS(T, U)`, der eine partielle Spezialisierung für
//     `T` definiert, die `U` als Namen verwendet
//   - Um Namenskonflikte zu vermeiden, definiert die Version von
//     `type_name.hpp`, die in diesem Notebook verwendet wird, den Trait
//     `TypeName` im Namespace `tn`
//   - Daher müssen die Macros auch in diesem Namespace aufgerufen werden

// %% tags=["keep"]
#include "type_name.hpp"

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
type_name<int>()

// %% tags=["keep"]
struct MyStruct
{
    int x;
    std::string y;
};

// %% tags=["keep"]
namespace tn {
using ::MyStruct;
DEFINE_TYPE_NAME(MyStruct);
}

// %% tags=["keep"]
type_name<MyStruct>()

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
type_name<const int&>()

// %% tags=["keep"]
type_name<const int*>()

// %% tags=["keep"]
type_name<int* const>()

// %% tags=["keep"]
type_name<const int* const>()

// %% tags=["keep"]
type_name<const std::vector<const MyStruct*>&>()

// %%
