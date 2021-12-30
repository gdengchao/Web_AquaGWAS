#pragma once 
#include <string>
// #include <unistd.h>
using namespace std;

struct GemmaParam
{
    GemmaParam() {}
    GemmaParam(bool complfamFlag, string matType, string bslmmType, string lmmType) 
        : complfam(complfamFlag),
          mat(matType),
          bslmm(bslmmType),
          lmm(lmmType)
    {}

    bool complfam;
    string mat;
    string bslmm;
    string lmm; 
};