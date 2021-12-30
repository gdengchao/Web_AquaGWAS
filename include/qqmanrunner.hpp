#pragma once
#include <string>
using namespace std;

class QqmanRunner {
public:
    void manhattanPlot();
    void qqPlot();

private:
    string pvalFile;
    string output;
};