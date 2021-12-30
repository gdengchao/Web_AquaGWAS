
#pragma once 

#include <string>
#include <memory>
#include "assoctool.hpp"
#include "gwasparam.hpp"
#include "assocrunner.hpp"
#include "util.hpp"
#include "conf.hpp"

class PlinkAssocRunner : public AssocRunner {
public: 
    PlinkAssocRunner(GwasParam param) 
        : AssocRunner(param, shared_ptr<AssocTool>(new Plink))
    {}
    ~PlinkAssocRunner() {} 

    bool run() {
        cout << "PlinkAssocRunner::run()" << endl;

        shared_ptr<Plink> plink = dynamic_pointer_cast<Plink>(_assocTool);

        plink->runAssoc(_param.phenotype, _param.genotype, _param.mapfile, _param.covar, _param.kin,
                    _param.model, _param.maf, _param.mind, _param.geno, _param.out);

        cout << systemCmdRetStr(DEF_TOOLDIR+"/"+"plink " + plink->getParamStr()) << endl;

        cout << "OK" << endl;

        return true;
    }
};