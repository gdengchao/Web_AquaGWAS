#pragma once 
#include "assoctool.hpp"
#include <map>
#include "gemmaparam.hpp"

class Gemma : public AssocTool {
public:
    Gemma();
    ~Gemma() {}
    bool runAssoc(string binGenoBaseName, string phenotype, string covariate, string kinship, string out,
                /* string model, */shared_ptr<GemmaParam> moreParam);
    bool makeKinship(string binGenoBaseName, string out, shared_ptr<GemmaParam> moreParam);
    bool phe_fam_Preparation(string phe, string fam, string newFam);
};