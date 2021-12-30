/**
 * @file gwas_runner.hpp
 * @author your name (you@domain.com)
 * @brief   实现GWAS(QC、GWAS、CORR、PLOT)相关流程
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <string>
#include <memory>
#include "assoctool.hpp"
#include "assocrunner.hpp"
#include "qcrunner.hpp"
#include "corrrunner.hpp"
#include "qqmanrunner.hpp"
#include "gwasparam.hpp"

class GwasRunner {
public:
    GwasRunner(GwasParam param,
               shared_ptr<QcRunner> qcRunner = nullptr, 
               shared_ptr<CorrRunner> corrRunner = nullptr)
        : _param(param),
          _qcRunner(qcRunner),
          _corrRunner(corrRunner)  {}
    ~GwasRunner() {}
    bool run();

private:
    string _msg;
    GwasParam _param;
    shared_ptr<AssocRunner> _assocRunner;
    shared_ptr<QcRunner> _qcRunner;
    shared_ptr<CorrRunner> _corrRunner;
}; 