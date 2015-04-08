#include <stdio.h>
#include <list>
#include <algorithm>
#include <iostream>
#include "fcl.cpp"
#include <vector>

/* mock factory */
std::vector<int> newIntVector()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);

    return v;
}

std::vector<int> newIntList()
{
    std::vector<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);

    return l;
}

/*****************************************************/
/****************** EACH TEST ************************/
/*****************************************************/
void p(const int& n)
{
    printf("[element]: %d\n", n);
}

int f(const int& n)
{
    return n + 1;
}

int main(void)
{
    std::vector<int> out;
    std::vector<int>::iterator it;

    out = fcl::map(newIntVector(), f);

    fcl::map(out, p);

    return 0;
}
