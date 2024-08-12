// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Vektor-Implementierung (V3)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 14 Vektor-Implementierung (V3).cpp -->
// <!-- slides/module_150_classes/topic_180_my_vector_v3.cpp -->

// %% [markdown]
//
// ## `MyVector`-Class
//
// Wir können jetzt die folgenden Verbesserungen vornehmen:
//
// - Kapseln der Implementierung
// - Mehrere Konstruktoren
// - Automatische Freigabe des Heap-Speichers beim Zerstören des Objekts
// - Korrektes Kopieren von Vektoren

// %%
#include <algorithm>
#include <iostream>

// %%
class MyVector
{
public:
    MyVector() = default;
    explicit MyVector(std::size_t size, int value = 0);
    MyVector(std::initializer_list<int> init);
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other) {
        std::cout << "MyVector::operator=(const MyVector&)\n";
        if (this != &other) {
            if (capacity_ < other.size_) {
                delete[] data_;
                data_ = new int[other.capacity_];
                capacity_ = other.capacity_;
            }
            size_ = other.size_;
            std::copy(other.data_, other.data_ + other.size_, data_);
        }
        return *this;
    }
    ~MyVector();

    void push_back(int value);
    int at(std::size_t index) const;
    int& at(std::size_t index);
    std::size_t size() const;
    std::size_t capacity() const;
    void print() const;

private:
    std::size_t size_{0};
    std::size_t capacity_{0};
    int* data_{nullptr};
};

// %% [markdown]
//
// ## `MyVector`-Implementierung
//

// %%
MyVector::MyVector(std::size_t size, int value)
    : size_(size), capacity_(size), data_(new int[size_])
{
    for (std::size_t i = 0; i != size_; ++i)
    {
        data_[i] = value;
    }
    // Alternative:
    // std::fill_n(data_, size_, value);
}

// %%
MyVector::MyVector(std::initializer_list<int> init)
    : size_(init.size()), capacity_(init.size()), data_(new int[size_])
{
    std::copy(init.begin(), init.end(), data_);
}

// %%
MyVector::MyVector(const MyVector& other)
    : size_(other.size_), capacity_(other.capacity_), data_(new int[other.capacity_])
{
    std::cout << "MyVector(const MyVector&)\n";
    std::copy(other.data_, other.data_ + other.size_, data_);
}

// %%
MyVector::~MyVector()
{
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    std::cout << "~MyVector()\n";
}

// %%
void MyVector::push_back(int value)
{
    if (size_ == capacity_)
    {
        std::size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
        int* new_data = new int[new_capacity];
        for (std::size_t i = 0; i != size_; ++i)
        {
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
int MyVector::at(std::size_t index) const
{
    // The `at()` method should do bounds checking...
    return data_[index];
}

// %%
int& MyVector::at(std::size_t index)
{
    // ...but we don't do it here since we haven't talked about exceptions yet
    return data_[index];
}

// %%
std::size_t MyVector::size() const { return size_; }

// %%
std::size_t MyVector::capacity() const { return capacity_; }

// %%
#include <iostream>

// %%
void MyVector::print() const
{
    std::cout << "[";
    for (std::size_t i = 0; i < size_; ++i)
    {
        std::cout << data_[i];
        if (i < size_ - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

// %%
void print_info(const MyVector& vec)
{
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
// - Die Verwaltung des Speichers ist transparent, wir müssen `destroy()` nicht
//   mehr aufrufen
// - Aber es werden potentiell zu viele unnötige Kopien gemacht, z.B.:
//   - Bei der Übergabe von temporären `MyVector`-Objekten an Funktionen
//   - Bei der Rückgabe von `MyVector`-Objekten aus Funktionen

// %%
{
    const MyVector vec{1, 2, 3};
    int i{vec.at(0)};
    print_info(vec);
}

// %%
{
    MyVector vec(4);
    vec.push_back(1);
    print_info(vec);
}

// %%
{
    MyVector vec{1, 2, 3, 4, 5};
    MyVector vec2{vec};
    vec.at(0) = 42;
    vec2.push_back(6);
    print_info(vec);
    print_info(vec2);
}

// %%
const MyVector* vec{new MyVector(3, 4)};
print_info(*vec);

// %%
delete vec;
