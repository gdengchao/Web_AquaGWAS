/**
 * @file mainworker.hpp
 * @author your name (you@domain.com)
 * @brief 分析客户端参数，调用对应Runner执行相关动作(GWAS, PCA, LD, ANNO)
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <string>
#include <map>
#include "util.hpp"
#include "conf.hpp"
#include "gwasrunner.hpp"
#include "pcarunner.hpp"
#include "ldrunner.hpp"
#include "paramparser.hpp"

using namespace std;

// enum WorkerState
// {
//     OK,
//     ERROR,
//     ING
// };
// enum GwasState
// {
//     PRE,
//     QC,
//     GWAS,
//     CORR
// };

class MainWorker final {
public:
    MainWorker(const map<string, string>& param)
        : _param(param),
          _gwasRunner(nullptr) {}

    ~MainWorker() {}
    bool run();
    
private:    
    ParamParser _param;
    shared_ptr<GwasRunner> _gwasRunner;
    shared_ptr<PcaRunner> _pcaRunner;
    shared_ptr<LdRunner> _ldRunner;
};