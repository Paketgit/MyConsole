#include <iostream>
#include <cstdlib>
#include "Parser.h"

using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	string userRequest;
	std::cout << "Количество аргументов: " << argc << std::endl; // Выводит количество аргументов
	for (int i = 0; i < argc; ++i) {
		std::cout << "Аргумент " << i << ": " << argv[i] << std::endl; // Выводит каждый аргумент
	}	
	Parser* parser = new Parser();
	while (true) {
		cout << "VFS>";
		getline(cin, userRequest);
		parser->parsing(userRequest);
		//cout << path_var;
	}
	delete parser;
}
