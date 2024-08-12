// -*- coding: utf-8 -*-
// %% [markdown]
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

// %% [markdown]
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

// %% [markdown]
//
// - Um auf die Notebooks zuzugreifen:
//   - URL: [http://localhost:8888]
//   - Passwort: `CAM`
