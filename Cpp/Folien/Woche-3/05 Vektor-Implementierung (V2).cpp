// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Vektor-Implementierung (V2)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Vektor-Implementierung (V2).cpp -->
// <!-- slides/module_150_classes/topic_120_my_vector_v2.cpp -->

// %% [markdown]
//
// ## `MyVector`-Struct
//
// Mit Member-Funktionen und Inline-Initialisierung können wir das Interface von
// `MyVector` besser an das von `std::vector` angleichen:

// %%
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

// %% [markdown]
//
// ## `MyVector`-Implementierung
//

// %%
void MyVector::destroy() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

// %%
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

// %%
int MyVector::at(std::size_t index) const {
    // The `at()` method should do bounds checking...
    return data_[index];
}

// %%
int& MyVector::at(std::size_t index) {
    // ...but we don't do it here since we haven't talked about exceptions yet
    return data_[index];
}

// %%
std::size_t MyVector::size() const {
    return size_;
}

// %%
std::size_t MyVector::capacity() const {
    return capacity_;
}

// %%
#include <iostream>

// %%
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

// %%
void print_info(const MyVector& vec) {
    std::cout << "size: " << vec.size() << "\n";
    std::cout << "capacity: " << vec.capacity() << "\n";
    std::cout << "data: ";
    vec.print();
    std::cout << "\n";
}

// %% [markdown]
//
// ## Verwenden von `MyVector`
//
// - Die Verwendung von `MyVector` ist nun ähnlicher zu `std::vector`
// - Wir müssen aber immer noch explizit `destroy()` aufrufen!
// - Wir können nur leere Vektoren erzeugen

// %%
MyVector vec;
print_info(vec);

// %%
vec.push_back(1);
print_info(vec);

// %%
vec.at(0)

// %%
vec.at(0) = 11;
print_info(vec);

// %%
vec.push_back(2);
print_info(vec);

// %%
vec.push_back(3);
print_info(vec);

// %%
vec.push_back(4);
vec.push_back(5);
print_info(vec);

// %%
vec.at(6)

// %%
const MyVector& vec2{vec};

// %%
vec2.at(0)

// %%
// vec2.at(0) = 0;

// %%
vec.destroy();
print_info(vec);
