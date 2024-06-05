#include <string>
#include <fstream>
#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main() {
    // ������ ���� �� �����, ����� �� ����� ������������ �� ����� ���� �����������������
    setlocale(LC_ALL, "Russian");
    bool key = false;
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
    Parser pars(lex.get_lexemas());
    return 0;
}