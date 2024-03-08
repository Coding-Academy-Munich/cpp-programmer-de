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
//  <b>Vektor-Implementierung (V2)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Vektor-Implementierung (V2).cpp -->
// <!-- slides/module_150_classes/topic_120_my_vector_v2.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `MyVector`-Struct
//
// Mit Member-Funktionen und Inline-Initialisierung können wir das Interface von
// `MyVector` besser an das von `std::vector` angleichen:

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct MyVector {
    int* data_{nullptr};
    std::size_t size_{0};
    std::size_t capacity_{0};

    void destroy();

    void push_back(int value);
    int at(std::size_t index) const;
    int& at(std::size_t index);
    std::size_t size() const;
    std::size_t capacity() const;
    void print() const;
};

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `MyVector`-Implementierung
//

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void MyVector::destroy() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void MyVector::push_back(int value) {
    if (size_ == capacity_) {
        std::size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
        int* new_data = new int[new_capacity];
        for (std::size_t i = 0; i != size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
    data_[size_] = value;
    ++size_;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
int MyVector::at(std::size_t index) const {
    // The `at()` method should do bounds checking...
    return data_[index];
}

// %% tags=["keep"]
int& MyVector::at(std::size_t index) {
    // ...but we don't do it here since we haven't talked about exceptions yet
    return data_[index];
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::size_t MyVector::size() const {
    return size_;
}

// %% tags=["keep"]
std::size_t MyVector::capacity() const {
    return capacity_;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
void MyVector::print() const {
    std::cout << "[";
    for (std::size_t i = 0; i < size_; ++i) {
        std::cout << data_[i];
        if (i < size_ - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
void print_info(const MyVector& vec) {
    std::cout << "size: " << vec.size() << "\n";
    std::cout << "capacity: " << vec.capacity() << "\n";
    std::cout << "data: ";
    vec.print();
    std::cout << "\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Verwenden von `MyVector`
//
// - Die Verwendung von `MyVector` ist nun ähnlicher zu `std::vector`
// - Wir müssen aber immer noch explizit `destroy()` aufrufen!
// - Wir können nur leere Vektoren erzeugen

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
MyVector vec;
print_info(vec);

// %% tags=["keep"]
vec.push_back(1);
print_info(vec);

// %% tags=["keep"]
vec.at(0)

// %% tags=["keep"]
vec.at(0) = 11;
print_info(vec);

// %% tags=["keep"]
vec.push_back(2);
print_info(vec);

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
vec.push_back(3);
print_info(vec);

// %% tags=["keep"]
vec.push_back(4);
vec.push_back(5);
print_info(vec);

// %% tags=["keep"]
vec.at(6)

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
const MyVector& vec2{vec};

// %% tags=["keep"]
vec2.at(0)

// %% tags=["keep"]
// vec2.at(0) = 0;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
vec.destroy();
print_info(vec);
