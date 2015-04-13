#include <stdio.h>
#include <list>
#include <algorithm>
#include <iostream>
#include "lib/fcl.cpp"
#include <vector>
#include <utility>

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

bool find (const int& n)
{
    return n > 5;
}

bool anyFalse (const int& n)
{
    return n > 20;
}

bool anyTrue (const int& n)
{
    return n > 5;
}

bool allTrue (const int& n)
{
    return n > 0;
}

bool allFalse (const int& n)
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


    printf("{partition}\n");
    std::pair< std::vector < int > , std::vector< int > > pair = fcl::partition(newIntVector(), filter);
    printf("{satisfies}\n");
    fcl::each(pair.first, p);
    printf("{dont satisfies}\n");
    fcl::each(pair.second, p);
    printf("\n");


    printf("{find}\n");
    int found = fcl::find(newIntVector(), find);
    printf("%d\n", found);
    printf("\n");


    printf("{reduce}\n");
    double initialValue = 1000.0;
    double res = fcl::reduce(newIntVector(), initialValue, reduce);
    printf("%f\n", res);
    printf("\n");


    printf("{any}\n");
    bool t = fcl::any(newIntVector(), anyTrue);
    bool f = fcl::any(newIntVector(), anyFalse);
    printf("should be true: %s\n", t ? "true" : "false"); 
    printf("should be false: %s\n", f ? "true" : "false"); 
    printf("\n");


    printf("{all}\n");
    t = fcl::all(newIntVector(), allTrue);
    f = fcl::all(newIntVector(), allFalse);
    printf("should be true: %s\n", t ? "true" : "false"); 
    printf("should be false: %s\n", f ? "true" : "false"); 
    printf("\n");


    printf("{take}\n");
    out = fcl::take(newIntVector(), 3);
    fcl::each(out, p);
    printf("\n");


    printf("{drop}\n");
    out = fcl::drop(newIntVector(), 3);
    fcl::each(out, p);
    printf("\n");

    return 0;
}
