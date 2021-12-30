#pragma once 

/**
 * @file conf.hpp
 * @author your name (you@domain.com)
 * @brief   定义一些全局变量、默认值等
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
using namespace std;

const string IP = "0.0.0.0";
const int PORT = 8990;

#define _DEBUG
/**
 * @brief default path 
 * 
 */
#ifndef _DEBUG
const string DEF_TOOLDIR = "./tools/";
const string DEF_SCRIPTDIR = "./script/";
const string DEF_OUTDIR = "./output/";
const string DEF_PRONAMR = "pro1";
#else
const string DEF_TOOLDIR = "/mnt/my_share/dchao/Web_AquaGWAS/tools/";
const string DEF_SCRIPTDIR = "/mnt/my_share/dchao/Web_AquaGWAS/script/";
const string DEF_OUTDIR = "/mnt/my_share/dchao/Web_AquaGWAS/output/";
const string DEF_PRONAMR = "web";
#endif 

const string DEF_LOG_FILE = "./AquaGWAS.log";

/**
 * @brief Quality control type define
 * 
 */
const uint8_t QC_TYPE_NO =  0;
const uint8_t QC_TYPE_MAF =  1;
const uint8_t QC_TYPE_GENO =  2;
const uint8_t QC_TYPE_MIND =  4;
const uint8_t QC_TYPE_LD =  8;

/**
 * @brief Association type define
 * 
 */
const uint8_t ASSOC_TYPE_NO = 0;
const uint8_t ASSOC_TYPE_PLINK = 1;
const uint8_t ASSOC_TYPE_GEMMA = 2;
const uint8_t ASSOC_TYPE_EMMAX = 4;

/**
 * @brief Correction type define
 * 
 */
const uint8_t CORR_TYPE_NO = 0;
const uint8_t CORR_TYPE_STEP = 1;
const uint8_t CORR_TYPE_FDR = 2;
const uint8_t CORR_TYPE_BONF = 4;


/**
 * @brief PCA type define
 * 
 */
const uint8_t PCA_TYPE_NO = 0; 
const uint8_t PCA_TYPE_GCTA = 1; 


/**
 * @brief LD type define
 * 
 */
const uint8_t LD_TYPE_NO = 0;
const uint8_t LD_TYPE_POPLDDEAC = 1;

/**
 * @brief Annotation type define
 * 
 */
const uint8_t ANNO_TYPE_NO = 0;
const uint8_t ANNO_TYPE_STEP = 1;
const uint8_t ANNO_TYPE_STUCT = 2;
const uint8_t ANNO_TYPE_FUNC = 4;

/**
 * @brief 定义客户端、服务端传递参数使用的<键值>字符串常量
 *        P 表示 parameter
 */
const string P_GENOTYPE = "genotype";
const string P_PHENOTYPE = "phenotype";
const string P_COVAR = "covar";
const string P_KIN = "kin";
const string P_PVAL = "pval";
const string P_OUT = "out";
const string P_ASSOC = "assoc";
const string P_MODEL = "model";
const string P_PCA = "pca";
const string P_LD = "ld";
const string P_LD_WIN = "ld_win";
const string P_LD_STEP = "ld_step";
const string P_LD_R2 = "ld_r2";
const string P_CORR = "corr";
const string P_ANNO = "anno";
const string P_MAF = "maf";
const string P_MIND = "mind";
const string P_GENO = "geno";
// P_G_* 为gemma专用
const string P_G_COMPLFAM = "gemma_complfam";
const string P_G_MATTYPE = "gemma_mat";
const string P_G_BSLMMMDL = "gemma_bslmm";
const string P_G_LMMTEST = "gemma_lmm";

/**
 * @brief Gemma param value
 *        这里的值与gemma设定一致, 后面会直接传给gemma
 */
// matrix type
const uint8_t G_MAT_CEN = 1;            // central matrix
const uint8_t G_MAT_STD = 2;            // standard matrix
const uint8_t G_MAT_DEF = G_MAT_CEN;            // 默认值
// lmm test type
const uint8_t G_LMM_TEST_WALD = 1;      // Wald test
const uint8_t G_LMM_TEST_LHR = 2;       // likelihood ratio test
const uint8_t G_LMM_TEST_SCORE = 3;     // score test
const uint8_t G_LMM_TEST_ALL = 4;       // all three tests 
const uint8_t G_LMM_TEST_DEF = G_LMM_TEST_WALD;       // 默认值
// bslmm model
const uint8_t G_BSLMM_MDL_STDL = 1;     // standard linear BSLMM
const uint8_t G_BSLMM_MDL_RG = 2;       // Ridge regression (GBLUP)
const uint8_t G_BSLMM_MDL_PROBIT = 3;   // probit BSLMM
const uint8_t G_BSLMM_MDL_DEF = G_BSLMM_MDL_STDL;      // 默认值