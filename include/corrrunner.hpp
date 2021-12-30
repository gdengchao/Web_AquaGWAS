#pragma once
#include <string>
using namespace std;

class CorrRunner
{
public:
    void stepDownQc();
    void fdrQc();
    void bonnferoniQc(); 

private:
    string genotype;
    string output;
};