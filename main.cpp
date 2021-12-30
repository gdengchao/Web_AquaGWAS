#include <iostream>
#include <string>
#include <list>
#include "util.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "mainworker.hpp"
using namespace std;

int main(int, char**)  {
    // string p = "/path/hello/222";

    // string dir;
    // string fname;
    // string bname;
    // string suffix;

    // splitPath(p, dir, fname, bname, suffix);

    // map<string, string> param = {{"1", "a"}, {"2", "b"}};

    // cout << param.at("2") << endl;

    map<string, string> param = {{P_ASSOC, to_string(ASSOC_TYPE_GEMMA)}, {P_G_LMMTEST, to_string(G_LMM_TEST_WALD)},
                                 {P_GENOTYPE, "/home/yingwang/dchao/data/222_filter1.bed"},
                                 {P_PHENOTYPE, "/home/yingwang/dchao/data/phenotype/fall_time.phe"},
                                 {P_G_MATTYPE, to_string(G_MAT_CEN)},
                                 {P_OUT, DEF_OUTDIR} };
    MainWorker mainWorker(param);
    mainWorker.run();

    return 0;
}

// std::shared_ptr<Derived> derived = std::dynamic_pointer_cast<Derived> (base);
