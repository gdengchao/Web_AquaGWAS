#pragma once 
#include <map>
#include <string>
#include <memory>
#include "gemmaparam.hpp"
using namespace std;
/**
 * @brief 定义GWAS参数结构体
 * 
 */
struct GwasParam {
    GwasParam(uint8_t qc_type, uint8_t assoc_type, string model_type, string genotype_file, 
              string phenotype_file, string covar_file, string kin_file, 
              string out_path, string maf_qc, string mind_qc, string geno_qc,
              string ld_wind_qc, string ld_step_qc, string ld_r2_qc, uint8_t corr_type,
              shared_ptr<void> moreParameter) 
        : qc(qc_type), 
        assoc(assoc_type), 
        model(model_type),
        genotype(genotype_file),
        phenotype(phenotype_file),
        covar(covar_file),
        kin(kin_file),
        out(out_path),
        maf(maf_qc),
        mind(mind_qc),
        geno(geno_qc),
        ld_wind(ld_wind_qc),
        ld_step(ld_step_qc),
        ld_r2(ld_r2_qc),
        corr(corr_type),
        moreParam(moreParameter) {
        
        if (genotype != "") {
            string dir, fname, bname, suffix;
            splitPath(genotype, dir, fname, bname, suffix);

            if (suffix == "ped") {
                mapfile = dir + "/" + bname + ".map";
            }
            else if (suffix == "tped") {
                mapfile = dir + "/" + fname + ".tfam";
            }
        }

        // if (assoc_type == ASSOC_TYPE_GEMMA) {
            
        // } else if (assoc_type == ASSOC_TYPE_EMMAX) {
        // }
    }

    ~GwasParam() {}

    uint8_t qc;
    uint8_t assoc;
    string model;
    string genotype;
    string mapfile;
    string phenotype;
    string covar;
    string kin;
    string out;
    string maf;
    string mind;
    string geno;
    string ld_wind;
    string ld_step;
    string ld_r2;
    uint8_t corr;
    shared_ptr<void> moreParam;
};