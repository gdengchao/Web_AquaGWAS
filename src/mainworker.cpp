#include "mainworker.hpp"
#include "conf.hpp"
#include "toolfactory.hpp"
#include "assoctool.hpp"
#include "qcrunner.hpp"
#include "corrrunner.hpp"
#include "pcarunner.hpp"
#include "ldrunner.hpp"
#include "gwasparam.hpp"
#include <memory>
using namespace std;

bool MainWorker::run() {   // 调用Runner执行
    if (_param.assocType()) {
        // 执行GWAS （QC, ）
        GwasParam gwasParam(_param.qcType(), _param.assocType(), _param.model(), _param.genotype(), 
                            _param.phenotype(), _param.covar(), _param.kin(), _param.out(), 
                            _param.maf(), _param.mind(), _param.geno(), _param.ld_win(),
                            _param.ld_step(), _param.ld_r2(), _param.corrType(), _param.moreParam());
        _gwasRunner = make_shared<GwasRunner>(GwasRunner(gwasParam));
        _gwasRunner->run();
    }


    return true;
}