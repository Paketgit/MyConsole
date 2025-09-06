#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>

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
	void varENV(const string args);
};
