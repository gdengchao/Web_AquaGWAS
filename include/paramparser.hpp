/**
 * @file paramparser.hpp
 * @author your name (you@domain.com)
 * @brief 解析客户端发送的参数, param<string, string>
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <map>
#include <string>
using namespace std;

class ParamParser final {
public:
    ParamParser(map<string, string> param)
        : _param(param)
    {}

    ~ParamParser() {}

    uint8_t assocType() {
        if (!_param.count(P_ASSOC))
            return ASSOC_TYPE_NO;
        return stoi(_param.at(P_ASSOC));
    }

    uint8_t qcType() {
        uint8_t type = QC_TYPE_NO;
        if (_param.count(P_MAF))
            type |= QC_TYPE_MAF;
        if (_param.count(P_MIND))
            type |= QC_TYPE_MIND;
        if (_param.count(P_GENO))
            type |= QC_TYPE_GENO;
        if (_param.count(P_LD_WIN) && _param.count(P_LD_STEP) && _param.count(P_LD_R2))
            type |= QC_TYPE_LD;
        return type;
    }

    uint8_t corrType() {
        if (!_param.count(P_CORR))
            return CORR_TYPE_NO;
        return stoi(_param.at(P_CORR));
    }
    
    uint8_t pcaType() {
        if (!_param.count(P_PCA))
            return PCA_TYPE_NO;
        // return stoi(_param.at(P_PCA));
        return PCA_TYPE_GCTA;
    }

    uint8_t ldType() {
        if (!_param.count(P_LD))
            return LD_TYPE_NO;
        // 当前版本默认只有PopLDdecay，所以不传值
        // return stoi(_param.at(P_LD));
        return LD_TYPE_POPLDDEAC;
    }

    uint8_t annoType() {
        if (!_param.count(P_ANNO))
            return ANNO_TYPE_NO;
        return stoi(_param.at(P_ANNO));
    }  

    string model() {
        if (!_param.count(P_MODEL))
            return "";
        return _param.at(P_MODEL);
    }

    string genotype() {
        if (!_param.count(P_GENOTYPE))
            return "";
        return _param.at(P_GENOTYPE);
    }

    string phenotype() {
        if (!_param.count(P_PHENOTYPE))
            return "";
        return _param.at(P_PHENOTYPE);
    }

    string covar() {
        if (!_param.count(P_COVAR))
            return "";
        return _param.at(P_COVAR);
    }

    string kin() {
        if (!_param.count(P_KIN))
            return "";
        return _param.at(P_KIN);
    }

    string out() {
        if (!_param.count(P_OUT))
            return "";
        return _param.at(P_OUT);
    }

    string maf() {
        if (!_param.count(P_MAF))
            return "";
        return _param.at(P_MAF);
    }

    string mind() {
        if (!_param.count(P_MIND))
            return "";
        return _param.at(P_MIND);
    }
    
    string geno() {
        if (!_param.count(P_GENO))
            return "";
        return _param.at(P_GENO);
    }

    string ld_win() {
        if (!_param.count(P_LD_WIN))
            return "";
        return _param.at(P_LD_WIN);
    }

    string ld_step() {
        if (!_param.count(P_LD_STEP))
            return "";
        return _param.at(P_LD_STEP);
    }

    string ld_r2() {
        if (!_param.count(P_LD_R2))
            return "";
        return _param.at(P_LD_R2);
    }

    shared_ptr<void> moreParam() {
        uint8_t assoc = assocType();
        if (assoc == ASSOC_TYPE_GEMMA) {    // Gemma专用参数
            return gemmaParam();
        } else if (assoc == ASSOC_TYPE_EMMAX) { // Emmas专用参数
            return emmaxParam();
        }
        return nullptr;
    }
    
private:
    shared_ptr<void> gemmaParam() {    
        // GemmaParam p;

        shared_ptr<GemmaParam> gemmaMoreParam(new GemmaParam);
        gemmaMoreParam->complfam = (_param.count(P_G_COMPLFAM) ? true : false);
        gemmaMoreParam->mat = (_param.count(P_G_MATTYPE) ? _param.at(P_G_MATTYPE) : "");
        gemmaMoreParam->lmm = (_param.count(P_G_LMMTEST) ? _param.at(P_G_LMMTEST) : "");
        gemmaMoreParam->bslmm = (_param.count(P_G_BSLMMMDL) ? _param.at(P_G_BSLMMMDL) : "");
        
        return gemmaMoreParam;
    }
    shared_ptr<void> emmaxParam() {
        shared_ptr<void> emmaxMoreParam;
        return emmaxMoreParam;
    }

private:
    const map<string, string> _param;
};