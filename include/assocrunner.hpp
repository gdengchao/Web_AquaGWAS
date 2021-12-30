#pragma once 
#include "assoctool.hpp"
#include "gwasparam.hpp"
class AssocRunner {
public:
    AssocRunner(GwasParam param, shared_ptr<AssocTool> assocTool)
        : _param(param),
          _assocTool(assocTool)
     {}
    virtual ~AssocRunner() {}
    virtual bool run() {
        return false;
    }
    
protected:
    GwasParam _param;
    shared_ptr<AssocTool> _assocTool;
};