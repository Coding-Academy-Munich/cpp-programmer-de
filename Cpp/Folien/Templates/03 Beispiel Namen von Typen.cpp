// -*- coding: utf-8 -*-
// %% [markdown]
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

// %% [markdown]
//
// - C++ hat keine guten Reflection-Fähigkeiten
//   - Laufzeit-Informationen über Typen (RTTI) sind sehr begrenzt
//   - Keine gute Möglichkeit, den Namen eines Typs zur Laufzeit zu ermitteln
//   - Wert von `std::type_info::name()` ist nicht standardisiert
// - Aber: Compiler kennt die Namen der Typen
//   - Können wir den Compiler dazu bringen, uns diese Namen zur Verfügung zu stellen?

// %%
#include <typeinfo>

// %%
typeid(int).name()

// %% [markdown]
//
// ## Idee: Template-Metaprogrammierung
//
// - Funktion `type_name<T>()`
//   - gibt den Namen des Typs `T` zurück
//   - kann für benutzerdefinierte Typen erweitert werden

// %% [markdown]
//
// ## Version 1: Direkte Implementierung


// %%
#include <string>
#include <typeinfo>

// %%
template <typename T>
std::string type_name_v1()
{
    std::string type_name{typeid(T).name()};
    if (type_name.find("class ") == 0) {
        type_name.erase(0, 6);
    }
    return type_name;
}

// %% [markdown]
//
// - Template-Spezialisierung für bestimmte Typen

// %%
template <>
std::string type_name_v1<int>()
{
    return "int";
}

// %%
type_name_v1<int>()

// %%
type_name_v1<std::string>()

// %%
type_name_v1<std::vector<int>>()

// %% [markdown]
//
// - Funktioniert, aber:
//   - `type_name_v1<std::vector<int>>()` ist nicht sehr schön
//   - Es ist schwierig einen passenden Overload zu definieren
//   - Partielle Spezialisierung von Funktions-Templates ist nicht erlaubt

// %%
// template <typename T>
// std::string type_name_v1<std::vector<T>>()
// {
//     return "std::vector<" + type_name_v1<T>() + ">";
// }

// %% [markdown]
//
// ## Version 2: Type-Traits
//
// - Im Gegensatz zu Funktionen können Klassen partiell spezialisiert werden
// - Wir können also eine Klasse `TypeName` definieren, die den Namen eines Typs enthält
// - Die Klasse `TypeName` kann dann partiell spezialisiert werden:

// %%
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

// %%
template <>
struct TypeName<int>
{
    static std::string name()
    {
        return "int";
    }
};

// %%
template <>
struct TypeName<std::string>
{
    static std::string name()
    {
        return "std::string";
    }
};

// %%
template <typename T>
struct TypeName<std::vector<T>>
{
    static std::string name()
    {
        return "std::vector<" + TypeName<T>::name() + ">";
    }
};

// %%
TypeName<int>::name()

// %%
TypeName<bool>::name()

// %%
TypeName<std::string>::name()

// %%
TypeName<std::vector<int>>::name()

// %%
TypeName<std::vector<bool>>::name()

// %%
TypeName<std::vector<std::vector<std::string>>>::name()

// %% [markdown]
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

// %% [markdown]
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

// %%
#include "type_name.hpp"

// %%
type_name<int>()

// %%
struct MyStruct
{
    int x;
    std::string y;
};

// %%
namespace tn {
using ::MyStruct;
DEFINE_TYPE_NAME(MyStruct);
}

// %%
type_name<MyStruct>()

// %%
type_name<const int&>()

// %%
type_name<const int*>()

// %%
type_name<int* const>()

// %%
type_name<const int* const>()

// %%
type_name<const std::vector<const MyStruct*>&>()

// %%
