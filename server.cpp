#include <iostream>
#include "rpc/server.h"
#include "util.hpp"
#include "mainworker.hpp"
using namespace std;

int main()  {
    rpc::server srv("0.0.0.0", 8990); // rpc::constants::DEFAULT_POR
    srv.bind("isValidPath", &isValidPath);
    srv.bind("system", &systemCmd);
    srv.bind("system_r", &systemCmdRetStr);
    srv.bind("getFileSize", &getFileSize);
    
    // srv.bind("run", [](const map<string, string>& param) -> bool {
    //     MainWorker mainWorker(param);
    //     return mainWorker.run();
    // });
    

    srv.run();  // 死循环  
    return 0;
}
