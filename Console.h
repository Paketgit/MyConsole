#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
class Console
{
public:
	int start(string& cdVFS, string& cdCommandsFile);
private:
	int fileMode(string& cdCommandsFile);
	int commonMode();
};

