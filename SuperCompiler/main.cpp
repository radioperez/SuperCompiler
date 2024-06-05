#include <string>
#include <fstream>
#include <iostream>
#include "Lexer.h"
#include "Parser.h"


int main() {
    // Чтение кода из файла, чтобы во время тестирования не нужно было перекомпилировать
    setlocale(LC_ALL, "Russian");
    bool key;
    std::string instring;
    std::fstream infile;
    infile.open("input2.txt");
    if (infile.is_open()) {
        for (std::string line; getline(infile, line);) {
            instring += line;
        }
        infile.close();
    }

    Lexer lex(&instring[0]);
    return 0;
}