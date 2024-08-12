// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Einführung in Docker</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Einführung in Docker.cpp -->
// <!-- slides/module_110_introduction/topic_160_docker_intro.cpp -->

// %% [markdown]
//
// ## Docker
//
// - Docker ist eine Container-Laufzeitumgebung
// - Download: [Docker Website](https://www.docker.com/products/docker-desktop/)
// - Test: `docker info`

// %% [markdown]
//
// ## Docker Images
//
// - Docker Images sind Vorlagen für Container
// - Sie enthalten alle notwendigen Informationen, um einen Container zu starten
// - Sie können Docker Images von einem Docker Registry herunterladen
// - Die offizielle Registry ist [Docker Hub](https://hub.docker.com/)
// - Sie können auch eigene Docker Images erstellen
// - Das ist aber nicht notwendig, um die Docker Images für den Kurs zu verwenden

// %% [markdown]
//
// ## Herunterladen und Ausführen von Docker Images
//
// - `docker pull hello-world`
// - `docker run hello-world`

// %% [markdown]
//
// ## Docker Images für den Kurs
//
// - Die Docker Images für den Kurs können Sie mit den folgenden Befehlen
//   herunterladen:
// - `docker pull mhoelzl/cam-cpp-notebook:latest`
// - `docker pull mhoelzl/cam-cpp-dev:latest`
// - Die Images sind relativ groß, weil sie eine komplette Entwicklungsumgebung
//   enthalten
// - Wir werden in späteren Videos sehen, wie Sie die Images verwenden können
