#pragma once 
#include <string>
#include <list>
#include <regex>
#include <sys/stat.h>
#include <sys/io.h>
#include <unistd.h>
#include <string>
using namespace std;

bool isExist(string file);
bool isValidPath(string path, int mode, bool isDir);
int systemCmd(string cmd);
string systemCmdRetStr(string cmd);
int getFileSize(string file);
void splitPath(const string path, string& dir, string& fname, string& bname, string& suffix);
list<string> split(const string& str, const string& reg);
string joinList(list<string> l, string sep);
string joinList(list<string> l, char sep);
void removeFile(string file);
void copyFile(string srcFile, string desFile);
