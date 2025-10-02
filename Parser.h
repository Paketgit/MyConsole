#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <sstream>
#include <iostream>
#include <format>

using namespace std;
class Parser {
	vector<string> pullRequest;
	map<string, void(Parser::*)(const vector<string>&)> fnMap;

public:
	Parser();
	void parsing(const string& request);
private:
	void ls(const vector<string>& args);
	void exit(const vector<string>& args);
	string varENV(const string args);
	void help(const vector<string>& args);
	void execute(string commandName, const vector<string>& args = {});

};
