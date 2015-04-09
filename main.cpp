#include <stdio.h>
#include <list>
#include <algorithm>
#include <iostream>
#include "fcl.cpp"
#include <vector>

/* functional collection library */
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


void p(const int& n)
{
    printf("[element]: %d\n", n);
}

int f(const int& n)
{
    return n + 1;
}

bool filter(const int& n)
{
    return n > 5;
}

double reduce( const double& a, const int& b )
{
    return ( (int) a ) + b;
}

int main(void)
{
    std::vector<int> out;

    printf("{each}\n");
    fcl::each(newIntList(), p);
    printf("\n");


    printf("{map}\n");
    out = fcl::map(newIntVector(), f);
    fcl::each(out, p);
    printf("\n");


    printf("{filter}\n");
    out = fcl::filter(newIntVector(), filter);
    fcl::each(out, p);
    printf("\n");


    printf("{reduce}\n");
    double initialValue = 1000.0;
    double res = fcl::reduce(newIntVector(), initialValue, reduce);
    printf("%f\n", res);

    printf("\n");


    return 0;
}
