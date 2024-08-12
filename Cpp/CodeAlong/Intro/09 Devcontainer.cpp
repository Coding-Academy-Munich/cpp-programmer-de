// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Devcontainer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Devcontainer.cpp -->
// <!-- slides/module_110_introduction/topic_162_devcontainer.cpp -->

// %% [markdown]
//
// - Wir haben Docker Images erstellt, die eine Entwicklungsumgebung für die
//   Workshops enthalten
// - Um diese zu verwenden, müssen Sie Docker installiert haben
// - Typischerweise ist [Docker Desktop](https://www.docker.com/products/docker-desktop/)
//   die einfachste Möglichkeit
// - Um zu testen, ob Docker funktioniert, führen Sie `docker info` aus

// %% [markdown]
//
// ## Devcontainer
//
// - Am Einfachsten ist es, diese Images als "Dev Container" in VS Code (oder
//   Visual Studio) zu verwenden
// - Installieren Sie die folgenden Erweiterungen in VS Code:
//   - Dev Containers (`ms-vscode-remote.remote-containers`)
//   - C/C++ (`ms-vscode.cpptools`)
//   - C/C++ Extension Pack (`ms-vscode.cpptools-extension-pack`)
//   - CMake Tools (`ms-vscode.cmake-tools`)
// - Öffnen Sie einfach den Ordner `code` in VS Code und wählen Sie "Reopen in
//   Container"
