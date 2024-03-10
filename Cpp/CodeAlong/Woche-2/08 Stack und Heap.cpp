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
//  <b>Stack und Heap</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Stack und Heap.cpp -->
// <!-- slides/module_140_collections/topic_120_stack_heap.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// Programme haben zwei Speicherbereiche: Stack und Heap.
//
// - Stack:
//   - Speicherbereich für lokale Variablen.
//   - Wird automatisch verwaltet.
//   - Variablen werden beim Verlassen eines Blocks automatisch entfernt.
// - Heap:
//   - Speicherbereich für dynamisch allozierte Variablen.
//   - Muss manuell verwaltet werden.

// %% tags=["keep", "slide"] slideshow={"slide_type": "slide"}
int x{1};
{
    int y{2};
}
{
    int z{3};
}

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-01.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-02.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-03.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-04.png" width="60%">

// %% tags=["keep", "slide"] slideshow={"slide_type": "slide"}
void f(int i) {
    int j{i + 1};
}

// %% tags=["keep"]
void g() {
    int k{1};
    f(k);
}

// %%


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-11.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-12.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-13.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-14.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-15.png" width="80%">


// %% tags=["slide"] slideshow={"slide_type": "slide"}

// %%

// %%

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-21.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-22.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-23.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-24.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-25.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-26.png" width="80%">


// %% tags=["slide"] slideshow={"slide_type": "slide"}

// %%

// %%


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-32.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-34.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-35.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-36.png" width="60%">


// %% tags=["slide"] slideshow={"slide_type": "slide"}

// %%

// %%


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-42.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-43.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-44.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-45.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-46.png" width="60%">

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - `bad_f` gibt einen Zeiger auf ein lokales Objekt zurück.
// - `bad_g` speichert diesen Zeiger in `pk`.
// - `pk` ist ein "dangling Pointer".
// - Das Dereferenzieren eines "dangling Pointers" ist undefiniertes Verhalten.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <div style="text-align:left; font-size:200%; max-width: 100%; line-height: 125%;">
// <a href="https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f43-never-directly-or-indirectly-return-a-pointer-or-a-reference-to-a-local-object">
// CG: F.43: Never (directly or indirectly) return a pointer or a reference to  a local object
// </a>
// </div>

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// `T*` (oder `T&`) als Rückgabewert sind typischerweise:
// - Zeiger oder Referenz, die als Parameter übergeben wurde
//    - Potentiell auch Teil eines Objekts
// - Zeiger auf statisches Objekt
// - Zeiger auf Objekt auf dem Heap
//   - Stattdessen `std::unique_ptr<T>` oder `std::shared_ptr<T>` verwenden!

// %% tags=["slide"] slideshow={"slide_type": "slide"}

// %%

// %%

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Eine statische Variable wird zur Kompilezeit angelegt.
// - Sie wird initialisiert, wenn der Kontrollfluss zum erstenmal die Definition
//   erreicht.
// - Bei jedem weiteren Aufruf der Funktion behält sie ihren Wert.
// - Sie wird zerstört, wenn das Programm beendet wird.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Objekte auf dem Heap werden zur Laufzeit angelegt.
// - Sie werden mit einer `new`-Expression erzeugt.
//   - `new` gibt einen Zeiger auf das angelegte Objekt zurück.
// - Sie müssen mit einer `delete`-Anweisung zerstört werden.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% tags=["slide"] slideshow={"slide_type": "slide"}

// %% [markdown]
//
// <img src="../img/stack-heap-51.png" width="40%">

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %% [markdown]
//
// <img src="../img/stack-heap-52.png" width="40%">

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown]
//
// <img src="../img/stack-heap-53.png" width="40%">

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%


// %% tags=["slide"] slideshow={"slide_type": "slide"}

// %%

// %%


// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-63.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-64.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-65.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-66.png" width="80%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-67.png" width="60%">

// %% [markdown] tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// <img src="../img/stack-heap-68.png" width="60%">


// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Mini-Workshop: Heap und Referenzen
//
// - Referenzen kann man in vielen Fällen genau so wie Zeiger behandeln.
// - Insbesondere ist die Rückgabe von Referenzen auf automatische Variablen zu
//   undefiniertes Verhalten.
//
// Welche der folgenden Funktionen sind korrekt? Warum?

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int& f1(int& i) {
    return i;
}

// %% tags=["keep"]
int& f2(int i) {
    return i;
}

// %% tags=["keep"]
int& f3(int i) {
    int k{i + 1};
    return k;
}

// %% tags=["keep"]
int& f4(int& i) {
    int k{i + 1};
    return k;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct MyStruct {
    int i;
};

// %% tags=["keep"]
int& f5(MyStruct& s) {
    return s.i;
}

// %% [markdown] lang="de" tags=["answer", "subslide"] slideshow={"slide_type": "subslide"}
// *Antwort:* 

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

