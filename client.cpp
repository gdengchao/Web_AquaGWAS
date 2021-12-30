#include "rpc/client.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "conf.hpp"

class WorkerInfo final {
public:
    WorkerInfo()
        : _toolDir(DEF_TOOLDIR),
          _scriptDir(DEF_SCRIPTDIR),
          _outDir(DEF_OUTDIR),
          _proName(DEF_PRONAMR) {}

    ~WorkerInfo() {}

    string getOutDir() {
        return _outDir;
    }
    void setOutDir(string dir) {
        _outDir = dir;
    }
    string getProName() {
        return _proName;
    }
    void setProName(string name) {
        _proName = name;
    }

public:
    const string _toolDir;
    const string _scriptDir;
private:
    string _outDir;
    string _proName;
};

int main() {
    rpc::client client("127.0.0.1", 8990); // rpc::constants::DEFAULT_PORT

    // std::string pathDir = "/mnt/my_share/dchao/Web_AquaGWAS/build/";
    // std::string pathFile = "/mnt/my_share/dchao/Web_AquaGWAS/build/client";
    // std::cout << client.call("isValidPath", pathDir, F_OK, true).as<bool>() << std::endl;
    // std::cout << client.call("isValidPath", pathDir, F_OK, false).as<bool>() << std::endl;
    // std::cout << client.call("isValidPath", pathFile, F_OK, true).as<bool>() << std::endl;
    // std::cout << client.call("isValidPath", pathFile, F_OK, false).as<bool>() << std::endl;
    
    // client.call("system", "pwd");
    // client.call("system", "ls -lh");
    std::cout << client.call("system_r", "pwd").as<std::string>() << std::endl;
    std::cout << client.call("system_r", "ls -lS").as<std::string>() << std::endl;

    std::string path;
    while (std::cin >> path) {
        std::cout << client.call("getFileSize", path).as<int>() << std::endl;
    }
    
    return 0;
}
