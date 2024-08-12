// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#ifndef COMPLETED_TEST_EXAMPLES_COUT_REDIRECT_H
#define COMPLETED_TEST_EXAMPLES_COUT_REDIRECT_H

#include <iostream>
#include <sstream>
#include <string>

class CoutRedirect
{
public:
    CoutRedirect()
    {
        coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(ss.rdbuf());
    }

    ~CoutRedirect() { std::cout.rdbuf(coutbuf); }

    std::string get_output() { return ss.str(); }

private:
    std::streambuf* coutbuf;
    std::stringstream ss;
};

#endif // COMPLETED_TEST_EXAMPLES_COUT_REDIRECT_H
