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
//  <b>Docker für Notebooks</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Docker für Notebooks.cpp -->
// <!-- slides/module_110_introduction/topic_170_docker_for_notebooks.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Docker Images für Notebooks
//
// ```bash
// docker pull mhoelzl/cam-cpp-notebook:latest
// docker run -p 8888:8888 -v /path/to/slides:/root/course mhoelzl/cam-cpp-notebook:latest
// ```
//
// - `/path/to/slides` ist der absolute Pfad zu dem Ordner, der die Folien enthält
// - Unter Windows fängt dieser Pfad typischerweise mit `C:\Users\...` an
// - Der Pfad `/root/course` muss genau so stehen bleiben (inclusive des
//   Doppelpunkts)
// - Sie können auch einen Parameter `--name <name>` angeben, um einen Namen für
//   den Container zu vergeben

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Um auf die Notebooks zuzugreifen:
//   - URL: [http://localhost:8888]
//   - Passwort: `CAM`
