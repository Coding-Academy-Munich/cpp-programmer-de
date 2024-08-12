// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Klassen-Templates</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Klassen-Templates.cpp -->
// <!-- slides/module_400_templates/topic_130_class_templates.cpp -->

// %% [markdown]
//
// - Templates erlauben es, Klassen zu definieren, die von einem Typ abhängen
// - Beispiel: `std::vector<T>`
//   - `T` ist der Typ der Elemente im Vektor
//   - `std::vector<int>` ist ein Vektor von `int`s
// - Für jeden Typ, den wir für `T` einsetzen, wird eine neue Vektor-Klasse
//   erzeugt
// - Wir können solche Klassen selbst definieren
// - Dazu verwenden wir das Schlüsselwort `template`, gefolgt von einer
//   Template-Parameter-Liste

// %%
template <typename T>
struct BufferV1
{
    T data[10];

    T& operator[](int index) { return data[index]; }

    void add(T value)
    {
        for (T& v : data) {
            v += value;
        }
    }
};

// %% [markdown]
//
// ## Template-Parameter
//
// - `T` ist ein Template-Parameter (genauer: Typ-Template-Parameter)
// - `T` kann in der Klasse wie ein Typ verwendet werden
// - Beim Instanziieren der Klasse wird `T` durch einen konkreten Typ ersetzt

// %%
BufferV1<int> ib;

// %%
ib[0] = 42;

// %%
ib[0]

// %%
ib.add(1);

// %%
ib[0]

// %%
BufferV1<std::string> sb;

// %%
sb[0] = "Hello";

// %%
sb[0]

// %%
sb.add(" World");

// %%
sb[0]

// %% [markdown]
//
// - Das Instanziieren einer Template-Klasse funktioniert nur, wenn die aufgerufenen
//   Methoden für den konkreten Typ `T` definiert sind:

// %%
#include <vector>

// %%
BufferV1<std::vector<int>> bvi;

// %%
bvi[0] = {1, 2, 3};

// %%
bvi[0]

// %%
// bvi.add({4, 5, 6});

// %% [markdown]
//
// ## Template-Spezialisierung
//
// - Wir können eine Template-Klasse für bestimmte Typen spezialisieren


// %%
template <typename T>
struct BufferV2
{
    T data[10];

    T& operator[](std::size_t index) { return data[index]; }

    void add(T value)
    {
        for (T& v : data) {
            v += value;
        }
    }
};

// %%
template <>
struct BufferV2<std::vector<int>>
{
    std::vector<int> data[10];

    std::vector<int>& operator[](std::size_t index) { return data[index]; }

    void add(std::vector<int> value)
    {
        for (std::vector<int>& v : data) {
            v.insert(v.end(), value.begin(), value.end());
        }
    }

};


// %%
BufferV2<std::vector<int>> bvi2;

// %%
bvi2[0] = {1, 2, 3};

// %%
bvi2[0]

// %%
bvi2.add({4, 5, 6});

// %%
bvi2[0]

// %%
bvi2[1]


// %% [markdown]
//
// ## Partielle Spezialisierung
//
// - Wir haben `BufferV2` für `std::vector<int>` spezialisiert
// - Oft wäre es besser, wenn wir die Spezialisierung für `std::vector<T>`
//   durchführen könnten
// - Das ist mit partieller Spezialisierung möglich:

// %%
template <typename T>
struct BufferV3
{
    T data[10];

    T& operator[](std::size_t index) { return data[index]; }

    void add(T value)
    {
        for (T& v : data) {
            v += value;
        }
    }
};


// %%
template <typename T>
struct BufferV3<std::vector<T>>
{
    std::vector<T> data[10];

    std::vector<T>& operator[](std::size_t index) { return data[index]; }

    void add(std::vector<T> value)
    {
        for (std::vector<T>& v : data) {
            v.insert(v.end(), value.begin(), value.end());
        }
    }

};

// %%
BufferV3<std::vector<std::string>> bvs;

// %%
bvs[0] = {"a", "b", "c"};

// %%
bvs[0]

// %%
bvs.add({"d", "e", "f"});

// %%
bvs[0]

// %%
bvs[1]

// %% [markdown]
//
// - Template-Parameter können auch Werte sein
// - Sie können dann wie Konstanten verwendet werden
// - Beispiel: `std::array<T, N>`
//   - `T` ist der Typ der Elemente im Array
//   - `N` ist die Anzahl der Elemente im Array
// - Für jeden Typ, den wir für `T` und jede Zahl, die wir für `N` einsetzen,
//   wird eine neue Array-Klasse erzeugt

// %%
template <typename T, int N>
struct BufferV4
{
    T data[N];

    T& operator[](std::size_t index) { return data[index]; }

    void add(T value)
    {
        for (T& v : data) {
            v += value;
        }
    }

    int size() const { return N; }
};

// %%
BufferV4<int, 10> ib4;

// %%
ib4.size()

// %%
BufferV4<int, 20> ib5;

// %%
ib5.size()

// %% [markdown]
//
// - Wir können die Werte von Template-Parametern auch berechnen
// - Die Berechnung muss zur Compile-Zeit erfolgen
// - Dazu verwenden wir `constexpr`-Funktionen

// %%
constexpr int square(int x)
{
    return x * x;
}

// %%
BufferV4<int, square(10)> ib6;

// %%
ib6.size()
