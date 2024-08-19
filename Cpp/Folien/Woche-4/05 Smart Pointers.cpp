// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Smart Pointers</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Smart Pointers.cpp -->
// <!-- slides/module_160_raii/topic_120_smart_pointers.cpp -->

// %% [markdown]
//
// - Die Verwendung von `new` und `delete` ist fehleranfällig
// - Wir können in vielen Fällen Pointer mit RAII verwalten
// - Smart Pointer sind Objekte, die sich wie Pointer verhalten, aber
//   automatisch den Speicher freigeben, wenn sie nicht mehr benötigt werden

// %% [markdown]
//
// ## Eigentum (Ownership)
//
// - Der Eigentümer (Owner) eines Objekts ist für das Löschen des Objekts
//   verantwortlich
// - Der Eigentümer eines Objekts kann das Eigentum an ein anderes Objekt
//   übertragen
// - Die korrekte Verwaltung des Eigentums ist ein wesentlicher Bestandteil
//   von robustem und wartbarem C++-Code

// %% [markdown]
//
// ## C++ Core Guidelines for Ownership
//
// - [R.3: A raw pointer (a `T*`) is
//   non-owning](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r3-a-raw-pointer-a-t-is-non-owning)
// - [R.4: A raw reference (a `T&`) is
//   non-owning](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r4-a-raw-reference-a-t-is-non-owning)

// %% [markdown]
//
// ## C++ Core Guidelines für Speicher-Management
//
// - [R.5: Prefer scoped objects, don’t heap-allocate
//   unnecessarily](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r5-prefer-scoped-objects-dont-heap-allocate-unnecessarily)
// - [R.10: Avoid `malloc()` and
//   `free()`](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r10-avoid-malloc-and-free)
// - [R.11: Avoid calling `new` and `delete`
//   explicitly](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r11-avoid-calling-new-and-delete-explicitly)
// - [R.12: Immediately give the result of an explicit resource allocation to a
//   manager
//   object](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r12-immediately-give-the-result-of-an-explicit-resource-allocation-to-a-manager-object)

// %% [markdown]
//
// - Smart Pointer sind in der Header-Datei `<memory>` definiert.
// - Es gibt verschiedene Arten von Smart Pointern:
//   - `std::unique_ptr`: alleiniges Eigentum
//   - `std::shared_ptr`: gemeinsames Eigentum
//   - `std::weak_ptr`: kein Eigentum, hält ein Objekt nicht am Leben

// %% [markdown]
//
// ## C++ Core Guidelines für Smart Pointer
//
// - [R.20: Use `unique_ptr` or `shared_ptr` to represent
//   ownership](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r20-use-unique_ptr-or-shared_ptr-to-represent-ownership)
// - [R.21: Prefer `unique_ptr` over `shared_ptr` unless you need to share
//   ownership](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r21-prefer-unique_ptr-over-shared_ptr-unless-you-need-to-share-ownership)
// - [R.22: Use `make_shared()` to make
//   `shared_ptr`s](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r22-use-make_shared-to-make-shared_ptrs)
// - [R.23: Use `make_unique()` to make
//   `unique_ptr`s](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r23-use-make_unique-to-make-unique_ptrs)
// - [R.24: Use std::weak_ptr to break cycles of
//   `shared_ptr`s](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r24-use-stdweak_ptr-to-break-cycles-of-shared_ptrs)

