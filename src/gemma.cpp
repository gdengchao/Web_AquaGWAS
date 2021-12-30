#include "gemma.hpp"
#include "conf.hpp"
#include <fstream>
#include <iostream>

Gemma::Gemma() {
    _model.push_back("LMM");
    // _model.push_back("BSLMM");
    _paramlist.clear();
}

/**
 * @brief Gemma::makeKinship
 * @param binGenoBaseName:binary file, without suffix, need .bed/.fam/.bim in the same path.
 * @param out: a file base name.
 * @return
 */
bool Gemma:: makeKinship(string binGenoBaseName, string out, shared_ptr<GemmaParam> moreParam) {
    if (binGenoBaseName.empty() || out.empty()) {
        return false;
    }

    // gemma -bfile 222_filter1 -gk 1 -o 222_filter1
    _paramlist.clear();
    _paramlist.push_back("-bfile");
    _paramlist.push_back(binGenoBaseName);

    _paramlist.push_back("-gk");
    _paramlist.push_back(moreParam->mat);
    _paramlist.push_back("-o");
    _paramlist.push_back(out);

    return true;
}

/**
 * @brief Gemma::runGWAS
 * @param binGenoBaseName: the prefix of binary file.
 * @param phenotype
 * @param covariate
 * @param kinship
 * @param out
 * @param model: lmm, bslmm
 * @param moreParam: gemma 专用参数
 * @return
 */
bool Gemma::runAssoc(string binGenoBaseName, string phenotype, string covariate, string kinship,
                    string out,/* string model,*/shared_ptr<GemmaParam> moreParam) {
    _paramlist.clear();            // Clear paramlist before set parameter.
    if (binGenoBaseName.empty() || phenotype.empty()/* || model.empty()*/) {
        return false;
    }

    _paramlist.push_back("-bfile");
    _paramlist.push_back(binGenoBaseName);

    // gemma -bfile 222_filter1 -k 222_filter1.cXX.txt -lmm 1 -n 2 -o 222_filter1
    // if (model == "LMM" || model == "lmm") {   
    if (!moreParam->lmm.empty()) {
        _paramlist.push_back("-k");
        _paramlist.push_back(kinship);
        _paramlist.push_back("-lmm");
        _paramlist.push_back(moreParam->lmm);   // wald:1   likelihood:2    score:3     all:4
        _paramlist.push_back("-n");
        _paramlist.push_back("2");
        if (!covariate.empty()) {    // Can't for BSLMM 
            _paramlist.push_back("-c");
            _paramlist.push_back(covariate);
        }
    }
    // gemma -bfile 222_filter1 -bslmm 1 -n 2 -o tmp
    //if (model == "BSLMM" || model == "bslmm") {  
    else if (!moreParam->bslmm.empty()) {
        _paramlist.push_back("-bslmm");
        _paramlist.push_back(moreParam->bslmm);     // 
        _paramlist.push_back("-n");
        _paramlist.push_back("2");
    }

    _paramlist.push_back("-o");
    _paramlist.push_back(out);

    return true;
}

/**
 * @brief Gemma::phe_fam_Preparation. 
 *        Replace "NA" to "-9", then complete .fam with phe.
 *        新建一个fam文件
 * @param phe                           phenotype file path
 * @param fam                           .fam file path
 * @param newFam                        A new file to save the final data of fam file.
 * @return
 */
bool Gemma::phe_fam_Preparation(string phe, string fam, string newFam) {   
    // .fam: FID IID PID MID Sex 1 Phe  (phenotype data to the 7th column of .fam)
    if (phe.empty() || fam.empty()) {
        return false;
    }

    string famFileName;
    string famFileAbPath;
    string famFileBaseName;
    string famFileSuffix;
    splitPath(fam, famFileAbPath, famFileName, famFileBaseName, famFileSuffix);

    ofstream tmpFamStream(newFam, ios::out);
    ifstream pheStream(phe, ios::in);
    ifstream famStream(fam, ios::in);

    if (!tmpFamStream.is_open() ||
        !famStream.is_open() ||
        !pheStream.is_open()) {   // Open file error.
        return false;
    }
    
    int curLine = 0;
    string famCurLine;
    string pheCurLine;
    while (!pheStream.eof() && !famStream.eof()) {   // Read file line by line respectively.
        ++curLine;
        getline(famStream, famCurLine);
        getline(pheStream, pheCurLine);

        if (famCurLine.empty() || pheCurLine.empty()) {
            // 最后可能出现空行情况
            continue;
        }

        if (curLine == 592) {
            std::cout << "curLine: " << curLine << std::endl;
        }

        // Replace "NA" to "-9"
        list<string> pheCurLineList = split(pheCurLine, "\\s+"); //pheCurLine.replace("NA", "-9").split(QRegExp("\\s+"), string::SkipEmptyParts);
        // Split by space(s)
        list<string> famCurLineList = split(famCurLine, "\\s+");

        while (famCurLineList.size() > 5)  {   // Only retain the first 5 columns.(FID IIF PID MID Sex)
            famCurLineList.pop_back();
        }

        // .fam: FID IID PID MID Sex 1 Phe  (phenotype data to the 7th column of .fam)
        tmpFamStream << joinList(famCurLineList, "\t") << "\t1\t"
                     << pheCurLineList.back() << "\n";       
        cout << joinList(famCurLineList, "\t") << "\t1\t"
                     << pheCurLineList.back() << "\n";           
    }

    if (!pheStream.eof() || !famStream.eof()) {   // Not end synchronously.
        return false;
    }

    return true;
}
