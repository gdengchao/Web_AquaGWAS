#include <iostream>
#include "gwasrunner.hpp"
#include "plinkassocrunner.hpp"
#include "emmaxassocrunner.hpp"
#include "gemmaassocrunner.hpp"
#include "util.hpp"
#include "plink.hpp"
#include "conf.hpp"
using namespace std;

bool GwasRunner::run() {
    if (_param.qc != QC_TYPE_NO 
            && _param.qc != QC_TYPE_LD
            && _param.assoc != ASSOC_TYPE_PLINK) {
        // 如果使用plink进行关联分析，maf、mind、geno可直接在关联分析过程中使用
        // 否则先进行质量控制
    
    }
    
    if (_param.assoc == ASSOC_TYPE_PLINK) {
        _assocRunner = make_shared<PlinkAssocRunner>(PlinkAssocRunner(_param));
    } else if (_param.assoc == ASSOC_TYPE_GEMMA) {
        _assocRunner = make_shared<GemmaAssocRunner>(GemmaAssocRunner(_param));
    } else if (_param.assoc == ASSOC_TYPE_EMMAX) {
        _assocRunner = make_shared<EmmaxAssocRunner>(EmmaxAssocRunner(_param));
    }
    
    if(!_assocRunner->run()) {
        return false;
    }

    return true;
}