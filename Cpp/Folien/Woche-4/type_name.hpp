#pragma once
#ifndef TYPE_NAME_HPP
#define TYPE_NAME_HPP

#include <string>
#include <typeinfo>
#include <vector>

template <typename T>
struct TypeName
{
    static std::string name()
    {
        static std::string type_name{typeid(T).name()};
        if (type_name.find("class ") == 0) {
            type_name.erase(0, 6);
        }
        return type_name;
    }
};

template <typename T>
struct TypeName<T&>
{
    static std::string name()
    {
        static std::string type_name{TypeName<T>::name() + "&"};
        return type_name;
    }
};

template <typename T>
struct TypeName<T&&>
{
    static std::string name()
    {
        static std::string type_name{TypeName<T>::name() + "&&"};
        return type_name;
    }
};

template <typename T>
struct TypeName<T*>
{
    static std::string name()
    {
        static std::string type_name{TypeName<T>::name() + "*"};
        return type_name;
    }
};

template <typename T>
struct TypeName<const T>
{
    static std::string name()
    {
        static std::string type_name{TypeName<T>::name() + " const"};
        return type_name;
    }
};

template <typename T>
struct TypeName<const T&>
{
    static std::string name()
    {
        static std::string type_name{std::string{"const "} + TypeName<T>::name() + "&"};
        return type_name;
    }
};

template <typename T>
struct TypeName<const T*>
{
    static std::string name()
    {
        static std::string type_name{std::string{"const "} + TypeName<T>::name() + "*"};
        return type_name;
    }
};

template <typename T>
struct TypeName<std::vector<T>>
{
    static std::string name()
    {
        return std::string{"std::vector<"} + TypeName<T>::name() + ">";
    }
};

template <typename T>
std::string type_name()
{
    return TypeName<T>::name();
}

#define DEFINE_TYPE_NAME_ALIAS(T, U)                                                   \
    template <>                                                                        \
    struct TypeName<T>                                                                 \
    {                                                                                  \
        static std::string name() { return #U; }                                       \
    };

#define DEFINE_TYPE_NAME(T) DEFINE_TYPE_NAME_ALIAS(T, T)

DEFINE_TYPE_NAME(bool)
DEFINE_TYPE_NAME(char)
DEFINE_TYPE_NAME(short)
DEFINE_TYPE_NAME(int)
DEFINE_TYPE_NAME(long)
DEFINE_TYPE_NAME(long long)
DEFINE_TYPE_NAME(signed char)
DEFINE_TYPE_NAME(unsigned char)
DEFINE_TYPE_NAME(unsigned short)
DEFINE_TYPE_NAME(unsigned int)
DEFINE_TYPE_NAME(unsigned long)
DEFINE_TYPE_NAME(unsigned long long)
DEFINE_TYPE_NAME(float)
DEFINE_TYPE_NAME(double)
DEFINE_TYPE_NAME(long double)
DEFINE_TYPE_NAME(std::string)

#endif // TYPE_NAME_HPP