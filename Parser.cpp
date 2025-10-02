#include "Parser.h"

using namespace std;

Parser::Parser() {
    fnMap["ls"] = &Parser::ls;
    fnMap["exit"] = &Parser::exit;
    fnMap["help"] = &Parser::help;
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

    //if (token.front() == '%' && token.back() == '%') {
    //    token = token.substr(1, token.size() - 2);
    //    return
    //    varENV(token);
    //}
    //auto it = fnMap.find(pullRequest[0]);
    //if (it == fnMap.end()) {
    //    cout << "Не удалось выполнить комнду, посмотрите доступный список команд help" << '\n';
    //    return;
    //}
    pullRequest.erase(pullRequest.begin(), pullRequest.begin()+1);

    //(this->*it->second)(pullRequest);

    execute(token, pullRequest);
    
}

void Parser::execute(string commandName, const vector<string>& args) {
    string var = commandName; 
    if (var.front() == '%' && var.back() == '%') {
        var = var.substr(1, var.size() - 2);
        var = varENV(var);
        cout << var << '\n';
        return;

    }

    auto it = fnMap.find(commandName);
    
    if (it == fnMap.end()) {
        // СДЕЛАТЬ ВЫВОД КАКАЯ КОМНАДА НЕ СДЕЛАНА
        cout << "Не удалось выполнить комнду " << commandName << ", посмотрите доступный список команд help " << endl;
        return;
    }
    
    (this->*it->second)(args);
    
}

void Parser::ls(const vector<string>& args) {
    if (args.empty()) { return; }

    for (string var : args) {
        if (var.front() == '%' && var.back() == '%') {
            var = var.substr(1, var.size() - 2);
            var = varENV(var);
        }
        cout << var << '\n';
        //execute(var);

    }
}

string Parser::varENV(const string varName) {
    char* pValue;
    size_t len;
    errno_t error = _dupenv_s(&pValue, &len, varName.c_str()); // нужно %str% -> str 
    if (error != 0 || pValue == nullptr) {
        return "";//"Не удалось получить доступ к переменной: " + varName;
    }
    return pValue;

}

void Parser::exit(const vector<string>&) {
    std::exit(0);
}

void Parser::help(const vector<string>& args) {
    for (auto name = fnMap.begin(); name != fnMap.end(); name++) {
        cout << name->first << "\n";
    }
}


