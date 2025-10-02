#include <iostream>
#include <cstdlib>
#include "Console.h"

using namespace std;
int main(string cdVFS, string cdCommandsFile)
{
	setlocale(LC_ALL, "Russian");
	Console* console = new Console();
	console->start(cdVFS, cdCommandsFile);
	//string userRequest;
	//Parser* parser = new Parser();
	//while (true) {
	//	cout << "VFS>";
	//	getline(cin, userRequest);
	//	parser->parsing(userRequest);
	//	//cout << path_var;
	//}
	//delete parser;
}
