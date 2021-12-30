#pragma once
#include <string>
#include "plink.hpp"
using namespace std;

class QcRunner {
public:
    void QcWithMafMindGeno();
    void QcWithLD();

private:
    string genotype;
    string output;
    string maf;
    string geno;
    string mind;
    string ld_step;
    string ld_win;
    string ld_r2;
    Plink plink;
};