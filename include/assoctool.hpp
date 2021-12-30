#pragma once
#include "tool.hpp"

class AssocTool : public Tool {
public:
    AssocTool() {}
    virtual ~AssocTool() {}
    list<string> getSupportedModel(void) {
        return _model;
    }

protected:
    list<string> _model;
};
