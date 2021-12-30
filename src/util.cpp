#include "util.hpp"
#include <string>
#include <list>
#include <regex>
#include <sys/stat.h>
#include <sys/io.h>
#include <unistd.h>
#include <string>
using namespace std;

/**
 * @brief   check file existence
 * 
 * @param file 
 * @return true 
 * @return false 
 */
bool isExist(string file) {
    if (access(file.c_str(), F_OK) == -1) {
        return false;
    }

    return true;
}

/**
 * @brief 判断路径是否为有效路径
 * 
 * @param path      文件路径
 * @param mode      文件权限 (存在: F_OK, 可读: R_OK, 可写 W_OK, 可执行: X_OK）
 * @param isDir 
 * @return true 
 * @return false 
 */
bool isValidPath(string path, int mode, bool isDir) {
    if (access(path.c_str(), mode) == -1) {
        return false;
    }

    struct stat buf;
    stat(path.c_str(), &buf);
    if (isDir) {
        return S_ISDIR(buf.st_mode);
    } else {
        return S_ISREG(buf.st_mode);
    }
}

/**
 * @brief execute command
 * 
 * @param cmd 
 * @return int 
 */
int systemCmd(string cmd) {
    if (cmd == "") {
        return -1; 
    }
    return system(cmd.c_str());
}

/**
 * @brief execute command and return the output
 * 
 * @param cmd 
 * @return string 
 */
string systemCmdRetStr(string cmd) {
    FILE* fp = NULL;
    char buf[1024];
    string ret;
    // 管道：执行命令，输出到管道
    if (NULL == (fp = popen(cmd.c_str(), "r"))) {
        return "systemCmdRetStr ERROR";
    }
   
    while (!feof(fp)) {
        if (fgets(buf, sizeof(buf), fp) != NULL) {
            ret += string(buf);
        }
    }
    pclose(fp);
    fp = NULL;
 
    return ret;
}

/**
 * @brief Get the File Size object, directory will be unpredictable
 * 
 * @param file 
 * @return int 
 */
int getFileSize(string file) {
    struct stat st;

    if (stat(file.c_str(), &st) != 0) {
        return -1;
    }
    return st.st_size;
}

/**
 * @brief           split file path, return values by parameters.
 *                      path must be separated by '/'
 * @param path      "/path/hello/222.vcf.gz"
 * @param dir       /path/hello
 * @param fname     222.vcf.gz
 * @param bname     222
 * @param suffix    gz
 */
void splitPath(const string path, string& dir, string& fname, string& bname, string& suffix) {
    int plen = path.size();
    auto spos = path.rfind('/');
    if (spos == 0) {   // 为根目录下的文件，如/hello
        dir = "/";
    }
    else if (spos == path.npos) {   // 没有路径，默认当前路径，hello
        dir = ".";
    }
    dir = path.substr(0, spos);
    int flen = plen - spos - 1;
    fname = path.substr(spos + 1, flen);

    auto ldpos = fname.find('.');
    if (ldpos == fname.npos) {
        bname = fname;
    } else {
        bname = fname.substr(0, ldpos);
    }

    auto rdpos = fname.rfind('.');
    if (rdpos != fname.npos) {
        suffix = fname.substr(rdpos + 1, flen-rdpos-1);
    }
}
/**
 * @brief 以正则表达式regstr分割字符串input
 * 
 * @param str   待分割字符串
 * @param reg   正则表达式
 * @return list<string> 
 */
list<string> split(const string& str, const string& reg) {
    list<string> ret;
    regex pattern(reg);
    const std::sregex_token_iterator end;
    for (std::sregex_token_iterator i(str.begin(), str.end(), pattern, -1); i != end ; ++i)  {
        ret.push_back(*i);
    }

    return ret;
}


string joinList(list<string> l, string sep = " ") {
    if (l.empty()) return "";
    auto iter = l.begin();
    string ret = *iter++;
    while (iter != l.end()) {
        ret += sep + *iter++;
    }

    return ret;
}

/**
 * @brief 将list拼接成string
 * 
 * @param l     list列表
 * @param sep   分隔符，用来连接各个子串
 * @return string 
 */
string joinList(list<string> l, char sep) {
    if (l.empty()) return "";
    auto iter = l.begin();
    string ret = *iter++;
    while (iter != l.end()) {
        ret += sep + *iter++;
    }

    return ret;
}

/**
 * @brief 检查文件是否存在，若存在则删除
 * 
 * @param file 
 */
void removeFile(string file) {
    if (isExist(file)) {
        remove(file.c_str());
    }
}

/**
 * @brief 拷贝srcFile到desFile
 * 
 * @param srcFile 
 * @param desFile 
 */
void copyFile(string srcFile, string desFile) {
    systemCmdRetStr("cp " + srcFile + " " + desFile);
}