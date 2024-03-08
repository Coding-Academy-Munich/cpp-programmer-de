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
//  <b>Kursmaterialien</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Kursmaterialien.cpp -->
// <!-- slides/module_110_introduction/topic_120_course_files.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Kursmaterialien
//
// - Auf den Kurs-Seiten finden Sie für jede Woche ein ZIP-Archiv mit den Materialien
// - Darin befinden sich mehrere Ordner:
//   - `Notebooks` enthält die interaktiven Notebooks
//   - `Html` enthält statische Versionen der Notebooks
//   - `Cpp` enthält die Notebooks als C++-Dateien, um es einfach zu machen, Code-Schnipsel zu kopieren
//   - `Code` enthält CMake-Projekte mit Code für Beispiele und größere Workshops

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Die Folien
//
// - Sind Interaktiv
// - Können nur mit der Jupyter-Notebook Umgebung angesehen und bearbeitet werden

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Die HTML-Seiten
//
// - Enthalten genau die gleichen Inhalte wie die interaktiven Notebooks
// - Sind statisch
// - Können aber einfach im Browser angesehen werden

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Zu jedem Notebook korrespondiert
//
// - Ein Video, in dem die eigentlichen Inhalte diskutiert werden
// - Potentiell weitere Workshop-Videos, in denen Lösungen zu Workshops
//   diskutiert werden

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Struktur der `Notebooks` und `Html` Ordner
//
// - Jeder dieser Ordner enthält zwei Unterordner
//   - `Folien`
//     - Darin sind die vollständig ausgefüllten Folien und Workshops mit Musterlösungen enthalten
//     - Diese Folien entsprechen dem Endzustand des jeweiligen Videos
//   - `CodeAlong`
//     - Hier fehlen große Teile des Codes und die Lösungen zu Workshops
//     - Das ist der Zustand der Folien am Anfang des Videos
//     - Verwenden Sie die Code-Alongs als Ausgangspunkt für die Workshops!

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Struktur des `Code` Ordners
//
// - Auch hier gibt es zwei wichtige Unterordner
//   - `starter_kits`
//     - Projekt-Gerüste, die z.B. zur Lösung von Workshops verwendet werden
//   - `completed`
//     - Vollständige Projekte, z.B. Musterlösungen von Workshops
// - Die Ordner sind als CMake-Projekte strukturiert
