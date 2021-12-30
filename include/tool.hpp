#pragma once
#include <string>
#include <list>
#include "util.hpp"
using namespace std;

class Tool {
public:
    Tool() {}
    virtual ~Tool() {}

    list<string> getParamList(void) {    // Every param can't have any space.
        return _paramlist;
    }
    string getParamStr(void) {
        string ret;
        for (string item:_paramlist) {
            ret += item + " ";
        }
        return ret;
    }
    void setParam(list<string> param) {
        _paramlist = param;
    }
    void setParam(string param) {
        // "\\" 是为了转义'\'
        _paramlist = split(param, "\\s+");
    }
    
protected:
    list<string> _paramlist;
};