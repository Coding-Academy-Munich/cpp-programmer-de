// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Funktions-Parameter</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 Funktions-Parameter.cpp -->
// <!-- slides/module_140_collections/topic_156_functional.cpp -->

// %% [markdown]
//
// - In einem früheren Beispiel haben wir die Indizes der minimalen und
//   maximalen Elemente eines Vektors folgendermaßen berechnet:

// %%
#include <vector>

// %%
std::vector<double> data{2.0, 1.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0, 5.0, 4.0};

// %%
std::vector<std::vector<double>::size_type> calculate_min_indices(const std::vector<double>& data)
{
    std::vector<std::vector<double>::size_type> indices;
    double value{std::numeric_limits<double>::max()};
    for (std::vector<double>::size_type i{0}; i < data.size(); ++i) {
        if (data[i] < value) {
            value = data[i];
            indices.clear();
            indices.push_back(i);
        } else if (data[i] == value) {
            indices.push_back(i);
        }
    }
    return indices;
}

// %%
std::vector<std::vector<double>::size_type> calculate_max_indices(const std::vector<double>& data)
{
    std::vector<std::vector<double>::size_type> indices;
    double value{std::numeric_limits<double>::lowest()};
    for (std::vector<double>::size_type i{0}; i < data.size(); ++i) {
        if (data[i] > value) {
            value = data[i];
            indices.clear();
            indices.push_back(i);
        } else if (data[i] == value) {
            indices.push_back(i);
        }
    }
    return indices;
}

// %% [markdown]
//
// - Diese Funktionen sind sich sehr ähnlich, sie unterscheiden sich nur durch
//   - Den Initialwert von `value`
//   - Den Vergleich von `data[i]` mit `value`: `<` bzw. `>`
// - Es ist leicht, den Wert von `value` als Parameter zu übergeben
// - Können wir das auch für den Vergleich machen?

// %% [markdown]
//
// ## Zeiger auf Funktionen
//
// - Wir können mit `&` auch die Adressen von Funktionen nehmen und in Zeigern
//   speichern
// - Diese Zeiger können wir genau wie andere Zeiger verwenden
//   - Wir können sie an Funktionen übergeben
//   - Wir können sie dereferenzieren und aufrufen

// %%
bool is_less(double x, double y)
{
    return x < y;
}


// %%
bool is_greater(double x, double y)
{
    return x > y;
}

// %%

// %%

// %%

// %%

// %% [markdown]
//
// - Wir brauchen beim Aufruf `pf` nicht explizit dereferenzieren
// - Wir brauchen die Adresse von Funktionen nicht explizit nehmen

// %%

// %%

// %%

// %%


// %% [markdown]
//
// - Funktion `calculate_indices()`
//   - Parameter `data`: Vektor mit `double`-Werten
//   - Parameter `compare`: Zeiger aur Funktion, die zwei `double`-Werte
//     vergleicht und `true` zurückgibt, wenn der erste Wert kleiner als der
//     zweite ist
//   - Parameter `initial_value`: Initialwert von `value`
//   - Gibt die Indizes der Elemente zurück, die den Vergleich mit dem initialen
//     Wert `initial_value` bestehen
// - Damit können wir die Funktionen `calculate_min_indices()` und
//   `calculate_max_indices()` ausdrücken

// %%
std::vector<std::vector<double>::size_type> calculate_indices(
    const std::vector<double>& data,
    bool (*compare)(double, double),   // <<<===
    double initial_value)              // <<<===
{
    std::vector<std::vector<double>::size_type> indices;
    double value{initial_value};       // <<<===
    for (std::vector<double>::size_type i{0}; i < data.size(); ++i) {
        if (compare(data[i], value)) { // <<<===
            value = data[i];
            indices.clear();
            indices.push_back(i);
        } else if (data[i] == value) {
            indices.push_back(i);
        }
    }
    return indices;
}


// %%
#include <limits>

// %%
calculate_indices(data, is_less, std::numeric_limits<double>::max())

// %%
calculate_indices(data, is_greater, std::numeric_limits<double>::lowest())

// %% [markdown]
//
// - Es gibt nicht nur Funktionszeiger, die in dieser Art verwendet werden können:
//   - Lambdas
//   - Instanzen von Klassen mit `operator()`
// - Um alle diese Fälle abzudecken, gibt es `std::function`:

// %%
calculate_indices(
    data,
    [](double x, double y) { return x < y; },
    std::numeric_limits<double>::max())

// %%
calculate_indices(
    data,
    [](double x, double y) { return x > y; },
    std::numeric_limits<double>::lowest())

// %%
std::vector<std::vector<double>::size_type> calculate_indices_2(
    const std::vector<double>& data,
    std::function<bool(double, double)> compare, // <<<===
    double initial_value)
{
    std::vector<std::vector<double>::size_type> indices;
    double value{initial_value};
    for (std::vector<double>::size_type i{0}; i < data.size(); ++i) {
        if (compare(data[i], value)) {
            value = data[i];
            indices.clear();
            indices.push_back(i);
        } else if (data[i] == value) {
            indices.push_back(i);
        }
    }
    return indices;
}

// %%
calculate_indices_2(data, is_less, std::numeric_limits<double>::max())

// %%
calculate_indices_2(data, is_greater, std::numeric_limits<double>::lowest())

// %%
#include <functional>

// %%
calculate_indices_2(data, std::less<double>{}, std::numeric_limits<double>::max())

// %%
calculate_indices_2(data, std::greater<double>{}, std::numeric_limits<double>::lowest())

// %%
calculate_indices_2(
    data,
    [](double x, double y) { return x < y; },
    std::numeric_limits<double>::max())

// %%
calculate_indices_2(
    data,
    [](double x, double y) { return x > y; },
    std::numeric_limits<double>::lowest())

// %% [markdown]
//
// ## Mini-Workshop: Vorhersage von Aktienkursen
//
// - Sie wollen eine Funktion schreiben, die eine Vorhersage für den Preis einer
//   Aktie aus den Preisen der letzten Tage berechnet
// - Der Algorithmus zur Berechnung der Vorhersage soll austauschbar sein und
//   als Parameter übergeben werden
// - Schreiben Sie eine Funktion `print_predictions()`, die einen Vektor von
//   Preisen und einen Algorithmus zur Berechnung der Vorhersage übergeben
//   bekommt, die Vorhersage berechnet und den vorhergesagten Preis ausgibt
// - Schreiben Sie zwei Algorithmen zur Berechnung der Vorhersage:
//   - Einen Algorithmus, der den Durchschnitt aller bekannten Preise als
//     Vorhersage zurückgibt
//   - Einen Algorithmus, der den Maximalwert aller bekannten Preise als
//     Vorhersage zurückgibt

// %%
#include <iostream>
#include <vector>

// %%
std::vector<double> prices{100.0, 102.0, 104.0, 105.0, 106.0, 107.0};

// %%
double average_prediction(const std::vector<double>& prices)
{
    double sum{0.0};
    for (double price : prices) {
        sum += price;
    }
    return sum / prices.size();
}

// %%
average_prediction(prices)

// %%
double max_prediction(const std::vector<double>& prices)
{
    double max{prices[0]};
    for (double price : prices) {
        if (price > max) {
            max = price;
        }
    }
    return max;
}

// %%
max_prediction(prices)

// %%

// %%
print_predictions(prices, average_prediction);

// %%
print_predictions(prices, max_prediction);

// %%
#include <numeric>

// %%

// %%

// %%
