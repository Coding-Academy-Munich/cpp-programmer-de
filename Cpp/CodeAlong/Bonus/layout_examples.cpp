// Generate the memory layout dump with:
// clang++ -cc1 -emit-llvm -fdump-record-layouts layout_examples.cpp > layout_examples.txt

class PlainOldClass
{
public:
    int x;
    PlainOldClass(int x) : x{x} {}

    void print() const {}
};

class BaseV1
{
public:
    int x;
    BaseV1(int x) : x{x} {}

    void print() const {}
};

class DerivedV1 : public BaseV1
{
public:
    int y;
    DerivedV1(int x, int y) : BaseV1{x}, y{y} {}

    void print() const {}
};

class BaseV2
{
public:
    int x;
    BaseV2(int x) : x{x} {}

    virtual void print() const {}
};

class DerivedV2 : public BaseV2
{
public:
    int y;
    DerivedV2(int x, int y) : BaseV2{x}, y{y} {}

    void print() const override {}
};

class BaseV3
{
public:
    int y;
    BaseV3(int y) : y{y} {}

    virtual void foo() const {}
};

class DerivedV3
    : public BaseV2
    , public BaseV3
{
public:
    int z;
    DerivedV3(int x, int y, int z) : BaseV2{x}, BaseV3{y}, z{z} {}

    void print() const override {}
};

int main()
{
    PlainOldClass poc{1};

    BaseV1 b1{1};
    DerivedV1 d1{2, 3};
    BaseV2 b2{1};
    DerivedV2 d2{2, 3};
    BaseV3 b3{1};
    DerivedV3 d3{2, 3, 4};

    b1.print();
    d1.print();
    b2.print();
    d2.print();
    b3.foo();
    d3.foo();

    BaseV1* pb1 = &b1;
    pb1->print();
    pb1 = &d1;
    pb1->print();

    BaseV2* pb2 = &b2;
    pb2->print();
    pb2 = &d2;
    pb2->print();
    pb2 = &d3;
    pb2->print();

    BaseV3* pb3 = &b3;
    pb3->foo();
    pb3 = &d3;
    pb3->foo();

    DerivedV3* pd3 = &d3;
    pd3->print();
    pd3->foo();

    return 0;
}