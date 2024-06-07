#include <string>
#include <fstream>
#include <iostream>
#include "Lexer.h"
#include "ParserExtend.h"

int main() {
    // Чтение кода из файла, чтобы во время тестирования не нужно было перекомпилировать
    setlocale(LC_ALL, "Russian");
    bool key = false;
    std::string instring;
    std::fstream infile;
    infile.open("input1.txt");
    if (infile.is_open()) {
        for (std::string line; getline(infile, line);) {
            instring += line;
        }
        infile.close();
    }

    Lexer lex(&instring[0]);
    Parser pars(lex.get_lexemas());
    std::vector<Token*> ops = pars.get_ops();
    std::cout << std::endl;
    for (auto el : ops) {
        std::cout << *el;
    }
    return 0;
}