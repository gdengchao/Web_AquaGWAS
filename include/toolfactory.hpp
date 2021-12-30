#pragma once 
#include "assoctool.hpp"
#include "plink.hpp"
#include "emmax.hpp"
#include "gemma.hpp"
#include "conf.hpp"

class AssocToolFactory
{
public:
    static AssocTool* createAssocTool(uint8_t gwasType)
    {
        switch(gwasType)
        {
        case ASSOC_TYPE_PLINK:
            return new Plink;
            break;
        case ASSOC_TYPE_GEMMA:
            return new Gemma;
            break;
        case ASSOC_TYPE_EMMAX:
            return new Emmax;
            break;
        default:
            return nullptr;
        }
    }
};
