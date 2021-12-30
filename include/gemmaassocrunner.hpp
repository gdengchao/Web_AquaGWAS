

#pragma once 

#include <string>
#include <memory>
#include "assoctool.hpp"
#include "gwasparam.hpp"
#include "assocrunner.hpp"
#include "gemma.hpp"
#include "util.hpp"

class GemmaAssocRunner : public AssocRunner {
public:
    GemmaAssocRunner(GwasParam param) 
        : AssocRunner(param, shared_ptr<AssocTool>(new Gemma))
    {}
    
    ~GemmaAssocRunner() {}

    bool run() {
        cout << "GemmaAssocRunner::run()" << endl;

        shared_ptr<Gemma> gemma = dynamic_pointer_cast<Gemma>(_assocTool);
/* gemma::runAssoc 的声明如下
         bool runAssoc(string binGenoBaseName, string phenotype, string covariate, string kinship, string out,
                  string model, map<string, string> moreParam); */
        
        
        string fname, bname, suffix, dir;
        splitPath(_param.genotype, dir, fname, bname, suffix);
        string binGenoPath = dir + "/" + bname;         // 路径+文件名
        
        shared_ptr<GemmaParam> gemmaParam = static_pointer_cast<GemmaParam>(_param.moreParam);
        
        string originFam = binGenoPath + ".fam";
        string originBed = binGenoPath + ".bed";
        string originBim = binGenoPath + ".bim";
        string compBinGenoPath = binGenoPath + "_comp";
        string complFam = compBinGenoPath + ".fam";
        string complBed = compBinGenoPath + ".bed";
        string complBim = compBinGenoPath + ".bim";
        gemma->phe_fam_Preparation(_param.phenotype, originFam, complFam);
        copyFile(originBed, complBed);
        copyFile(originBim, complBim);
        
        if (_param.kin.empty()) {
            if (!gemma->makeKinship(compBinGenoPath, bname, gemmaParam)) {
                cout << "gemma make kinship error" << endl;
                return false;
            }

            cout << DEF_TOOLDIR+"/"+"gemma " + gemma->getParamStr() << endl;
            cout << systemCmdRetStr(DEF_TOOLDIR+"/"+"gemma " + gemma->getParamStr()) << endl;
            
            if (stoi(gemmaParam->mat) == G_MAT_CEN) {
                _param.kin = "/output/" + bname +"_tmp" + ".cXX.txt";
            } else if (stoi(gemmaParam->mat) == G_MAT_STD) {
                _param.kin = "/output/" + bname +"_tmp" + ".sXX.txt";
            }
            if (isExist(_param.kin)) {  // 判断是否生成了kinship文件
                cout << "gemma make kinship ok" << endl;
            } else {
                cout << "gemma make kinship error" << endl;
                return false;
            }
        }
        
        // if (!gemma->runAssoc(compBinGenoPath, _param.phenotype, _param.covar, 
        //                      _param.kin, _param.out,/* _param.model, */
        //                      static_pointer_cast<GemmaParam>(_param.moreParam))) {
        //     cout << "gemma run association error" << endl;
        //     return false;
        // }
        // cout << systemCmdRetStr(DEF_TOOLDIR+"/"+"gemma " + gemma->getParamStr()) << endl;

        cout << "OK" << endl;

        // 删除补全后的fam文件以及复制的bed和bim
        // removeFile(complBed);
        // removeFile(complFam);
        // removeFile(complBim);

        return true;
    }
};