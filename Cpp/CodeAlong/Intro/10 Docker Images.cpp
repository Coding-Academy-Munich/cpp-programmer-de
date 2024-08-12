// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Docker Images</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 10 Docker Images.cpp -->
// <!-- slides/module_110_introduction/topic_164_docker_images.cpp -->

// %% [markdown]
//
// ## Manuelles Starten der Docker Images
//
// - Sie die Docker Images auch manuell starten, wenn Sie den Devcontainer nicht
//   verwenden wollen
//
// ```bash
// docker pull mhoelzl/cam-cpp-dev:latest
// docker run -it --rm -v /path/to/code:/root/course mhoelzl/cam-cpp-dev:latest
// ```
//
// - Ersetzen Sie `/path/to/code` durch den absoluten Pfad zum Ordner `code`

// %% [markdown]
//
// ### Erstellen der Projekte im Container
//
// ```bash
// cd /root/course
// cmake --preset linux-clang
// cmake --build out/build/linux-clang --target hello_world
// ./out/build/linux-clang/completed/hello_world/hello_world
// ```

// %% [markdown]
//
// ### Erstellen von `blocks_sk` (nativer Build)
//
// `blocks_sk` lässt sich im Container erstellen, aber nicht ohne zusätzliche
// Konfiguration ausführen:
//
// ```bash
// cd /root/course
// cmake --preset linux-clang
// cmake --build out/build/linux-clang/ --target blocks_sk
// ./out/build/linux-clang/starter_kits/blocks_sk/blocks_sk # Schlägt fehl
// ```
//
// Die Konfiguration von X11 Forwarding übersteigt den Rahmen dieses Kurses.

// %% [markdown]
//
// ### Erstellen von `blocks_sk` (Web Build)
//
// Alternativ kann `blocks_sk` auch als Web-Anwendung erstellt werden:
//
// ```bash
// cd /root/course
// source /root/emsdk/emsdk_env.sh
// emcmake cmake --preset=web-debug
// emmake cmake --build ./out/build/web-debug --target blocks_sk
// cd out/build/web-debug/starter_kits/blocks_sk
// python -m http.server
// ```

// %% [markdown]
//
// Um auf die Web-Anwendung zuzugreifen muss das Docker Image mit der Option
// `-p 8000:8000` gestartet werden:
//
// ```bash
// docker run -it --rm -p 8000:8000 -v /path/to/code:/root/course mhoelzl/cam-cpp-dev:latest
// ```
//
// Öffnen Sie dann [http://localhost:8000/blocks_sk.html] im Browser
