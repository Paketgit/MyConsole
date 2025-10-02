#include "Console.h"
#include "Parser.h"
int Console::start(string& cdVFS, string& cdCommandsFile) {
	if (cdVFS.empty()) return 1;
	string userRequest;
	Parser* parser = new Parser();
	if (!cdCommandsFile.empty()) {
		ifstream file(cdCommandsFile);
		if (!file.is_open()) return 1;
		string line;
		while (getline(file, line)) {
			parser->parsing(line);
		}
	}
	while (true) {
		cout << "VFS>";
		getline(cin, userRequest);
		parser->parsing(userRequest);
	}
	delete parser;
	return 0;
}
//string userRequest;
//Parser* parser = new Parser();
//while (true) {
//	cout << "VFS>";
//	getline(cin, userRequest);
//	parser->parsing(userRequest);
//	//cout << path_var;
//}
//delete parser;