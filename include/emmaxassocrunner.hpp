

#pragma once 

#include <string>
#include <memory>
#include "assoctool.hpp"
#include "gwasparam.hpp"
#include "assocrunner.hpp"
#include "emmax.hpp"

class EmmaxAssocRunner : public AssocRunner{
public:
    EmmaxAssocRunner(GwasParam param) 
        : AssocRunner(param, shared_ptr<AssocTool>(new Emmax))
    {}
    ~EmmaxAssocRunner() {}
    bool run() {
        return true;
    }
private:
    shared_ptr<AssocTool> _assocTool;
};