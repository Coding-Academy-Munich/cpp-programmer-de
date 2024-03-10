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
//  <b>Das Builder Pattern</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Das Builder Pattern.cpp -->
// <!-- slides/module_470_cpp_patterns/topic_300_builder.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Pattern zum Erstellen von Objekten
// - Trennt die Konstruktion eines komplexen Objekts von seiner Repräsentation
// - Ermöglicht die gleiche Konstruktion, um unterschiedliche Repräsentationen zu
// erzeugen
// - In C++ manchmal auch als Ersatz für
//   - überladene Konstruktoren
//   - benannte Argumente

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Idee
//
// - Verwende Builder Objekt, um die Konfiguration eines Objekts zu speichern
// - Erzeuge das Objekt aus der Konfiguration

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Beispiel
//
// - Dokumenten-Builder
// - Erzeuge Markdown- und HTML-Dokumente

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <memory>
#include <string>
#include <vector>

// %% tags=["keep"]
class DocumentElement;

// %% tags=["keep"]
class DocumentBuilder
{
public:
    DocumentBuilder& addTitle(const std::string& title);
    DocumentBuilder& addHeader(const std::string& header);
    DocumentBuilder& addParagraph(const std::string& paragraph);
    std::string getMarkdown() const;
    std::string getHtml() const;

private:
    std::vector<std::unique_ptr<DocumentElement>> elements;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class DocumentElement
{
public:
    DocumentElement() = default;
    DocumentElement(const DocumentElement&) = delete;
    DocumentElement& operator=(const DocumentElement&) = delete;
    DocumentElement(DocumentElement&&) = delete;
    DocumentElement& operator=(DocumentElement&&) = delete;
    virtual ~DocumentElement() = default;

    virtual std::string getMarkdown() const = 0;
    virtual std::string getHtml() const = 0;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class Title : public DocumentElement
{
public:
    Title(const std::string& title) : title(title) {}
    std::string getMarkdown() const override { return "# " + title + "\n"; }
    std::string getHtml() const override { return "<h1>" + title + "</h1>\n"; }

private:
    std::string title;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class Header : public DocumentElement
{
public:
    Header(const std::string& header) : header(header) {}
    std::string getMarkdown() const override { return "## " + header + "\n"; }
    std::string getHtml() const override { return "<h2>" + header + "</h2>\n"; }

private:
    std::string header;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class Paragraph : public DocumentElement
{
public:
    Paragraph(const std::string& paragraph) : paragraph(paragraph) {}
    std::string getMarkdown() const override { return paragraph + "\n"; }
    std::string getHtml() const override { return "<p>" + paragraph + "</p>\n"; }

private:
    std::string paragraph;
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
DocumentBuilder& DocumentBuilder::addTitle(const std::string& title)
{
    elements.push_back(std::make_unique<Title>(title));
    return *this;
}

// %% tags=["keep"]
DocumentBuilder& DocumentBuilder::addHeader(const std::string& header)
{
    elements.push_back(std::make_unique<Header>(header));
    return *this;
}

// %% tags=["keep"]
DocumentBuilder& DocumentBuilder::addParagraph(const std::string& paragraph)
{
    elements.push_back(std::make_unique<Paragraph>(paragraph));
    return *this;
}

// tags=["keep", "subslide"]
#include <sstream>

// %% tags=["keep"]
std::string DocumentBuilder::getMarkdown() const
{
    std::stringstream result;
    for (const auto& element : elements)
    {
        result << element->getMarkdown();
    }
    return result.str();
}

// %% tags=["keep"]
std::string DocumentBuilder::getHtml() const
{
    std::stringstream result;
    for (const auto& element : elements)
    {
        result << element->getHtml();
    }
    return result.str();
}

// %% tags=["keep, "subslide"]
DocumentBuilder builder;

// %% tags=["keep"]
builder.addTitle("Builder Pattern")
    .addHeader("Introduction")
    .addParagraph("The builder pattern is a creational pattern.")
    .addParagraph("It is used to separate the construction of a complex object from "
                  "its representation.");

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
std::cout << builder.getMarkdown() << std::endl;

// %% tags=["keep"]
std::cout << builder.getHtml() << std::endl;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Builder und Fluent Interface
//
// - Builder Pattern wird oft mit einem Fluent Interface kombiniert
// - Jede der Methoden gibt eine Referenz auf den Builder zurück
// - Ermöglicht das Verketten von Methodenaufrufen

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Builder und Benannte Argumente
//
// - C++ bietet keinen direkten Support für benannte Argumente
// - Builder Pattern kann als Ersatz verwendet werden
// - Jede Methode des Builders nimmt ein Argument entgegen
// - Die ursprüngliche Methode wird mit dem Builder aufgerufen oder als Methode
//   des Builders implementiert

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
void sendRequest(
    std::string url, std::string method = "GET",
    std::map<std::string, std::string> headers = {},
    std::map<std::string, std::string> params = {}, std::string data = "",
    int timeout = 30
)
{
    std::cout << "Sending " << method << " request to " << url << "\n";
    std::cout << "Headers:\n";
    for (const auto& [key, value] : headers)
    {
        std::cout << "  " << key << ": " << value << "\n";
    }
    std::cout << "Parameters:\n";
    for (const auto& [key, value] : params)
    {
        std::cout << "  " << key << ": " << value << "\n";
    }
    std::cout << "Data: " << data << "\n";
    std::cout << "Timeout: " << timeout << " seconds.\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die Funktion `sendRequest` hat viele Argumente, die den gleichen Typ haben.
// - Das macht es schwierig, sich die Reihenfolge der Argumente zu merken.
// - Außerdem müssen potentiell viele Argumente mit Default-Wert angegeben werden,
//   wenn nur ein oder zwei geändert werden sollen.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
sendRequest(
    "https://example.com", "POST", {{"Content-Type", "application/json"}}, {},
    "My Data", 60
);

// %% tags=["keep"]
// Change only the timeout....
sendRequest("https://example.com", "GET", {}, {}, "", 10);

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können einen Builder verwenden, um den Aufbau des Requests zu vereinfachen.
// - Die Argumente werden durch Aufrufe benannter Methoden ersetzt.
// - Der Builder speichert die Konfiguration und erzeugt den Request.
// - Dadurch müssen wir nur die geänderten Werte angeben.
// - Die Reihenfolge der Argumente spielt keine Rolle mehr.
// - Die Funktion der Argumente wird klarer.
// - Leider ist zur Definition des Builders viel Code notwendig.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class RequestBuilder
{
public:
    RequestBuilder& setUrl(const std::string& url);
    RequestBuilder& setMethod(const std::string& method);
    RequestBuilder& addHeader(const std::string& key, const std::string& value);
    RequestBuilder& addParam(const std::string& key, const std::string& value);
    RequestBuilder& setData(const std::string& data);
    RequestBuilder& setTimeout(int timeout);
    void send() const;

private:
    std::string url{"https://example.com"};
    std::string method{"GET"};
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> params;
    std::string data;
    int timeout{30};
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
RequestBuilder& RequestBuilder::setUrl(const std::string& url)
{
    this->url = url;
    return *this;
}

// %% tags=["keep"]
RequestBuilder& RequestBuilder::setMethod(const std::string& method)
{
    this->method = method;
    return *this;
}

// %% tags=["keep"]
RequestBuilder& RequestBuilder::addHeader(
    const std::string& key, const std::string& value
)
{
    headers[key] = value;
    return *this;
}

// %% tags=["keep"]
RequestBuilder& RequestBuilder::addParam(
    const std::string& key, const std::string& value
)
{
    params[key] = value;
    return *this;
}

// %% tags=["keep"]
RequestBuilder& RequestBuilder::setData(const std::string& data)
{
    this->data = data;
    return *this;
}

// %% tags=["keep"]
RequestBuilder& RequestBuilder::setTimeout(int timeout)
{
    this->timeout = timeout;
    return *this;
}

// %% tags=["keep"]
void RequestBuilder::send() const
{
    sendRequest(url, method, headers, params, data, timeout);
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
RequestBuilder request;
request.setUrl("https://example.com")
    .setMethod("POST")
    .addHeader("Content-Type", "application/json")
    .setData("My Data")
    .setTimeout(60)
    .send();

// %% tags=["keep"]
// Change only the timeout....
RequestBuilder{}.setTimeout(10).send();
