#include "Parser.h"
#include <sstream>
#include <iostream>
using namespace std;

Parser::Parser() {
    fnMap["ls"] = &Parser::ls;
    fnMap["exit"] = &Parser::exit;
}

void Parser::parsing(const string& request) {
    pullRequest.clear();

    stringstream ss(request);
    string token;
    while (ss >> token) {
        pullRequest.push_back(token);
    }
    if (pullRequest.empty()) {
        return;
    }
    token = pullRequest[0];

    if (token.front() == '%' && token.back() == '%') {
        token = token.substr(1, token.size() - 2);
        return
        varENV(token);
    }

    auto it = fnMap.find(pullRequest[0]);
    if (it == fnMap.end()) {
        return;
    }
    pullRequest.erase(pullRequest.begin(), pullRequest.begin()+1);

    (this->*it->second)(pullRequest);
}

void Parser::ls(const vector<string>& args) {
    for (string var : args) {
        cout << var << "\n";
    }
}

void Parser::varENV(const string varName) {
    char* pValue;
    size_t len;
    
    _dupenv_s(&pValue, &len, varName.c_str()); // нужно %str% -> str 
    cout << pValue << endl;

}

void Parser::exit(const vector<string>&) {
    std::exit(0);
}


