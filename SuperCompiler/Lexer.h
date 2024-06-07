#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TokenExtend.h"

class Lexer {
private:
    std::vector <std::string> lexemas;
    std::vector<Token*> lexes;
    bool is_space(char c) {
        switch (c) {
        case ' ':
        case '\n':
        case '\r':
        case '\t':
            return true;
        default:
            return false;
        }
    }
    bool is_number(char c) {
        switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
        }
    }
    bool is_letter(char c) {
        switch (c) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'а':
        case 'б':
        case 'в':
        case 'г':
        case 'д':
        case 'е':
        case 'ё':
        case 'ж':
        case 'з':
        case 'и':
        case 'й':
        case 'к':
        case 'л':
        case 'м':
        case 'н':
        case 'о':
        case 'п':
        case 'р':
        case 'с':
        case 'т':
        case 'у':
        case 'ф':
        case 'х':
        case 'ц':
        case 'ч':
        case 'ш':
        case 'щ':
        case 'ъ':
        case 'ы':
        case 'ь':
        case 'э':
        case 'ю':
        case 'я':
        case 'А':
        case 'Б':
        case 'В':
        case 'Г':
        case 'Д':
        case 'Е':
        case 'Ё':
        case 'Ж':
        case 'З':
        case 'И':
        case 'Й':
        case 'К':
        case 'Л':
        case 'М':
        case 'Н':
        case 'О':
        case 'П':
        case 'Р':
        case 'С':
        case 'Т':
        case 'У':
        case 'Ф':
        case 'Х':
        case 'Ц':
        case 'Ч':
        case 'Ш':
        case 'Щ':
        case 'Ъ':
        case 'Ы':
        case 'Ь':
        case 'Э':
        case 'Ю':
        case 'Я':
            return true;
        default:
            return false;
        }
    }
    bool is_single_char_lexema(char c) {
        switch (c) {
        case '=':
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
            return true;
        default:
            return false;
        }
    }
    bool is_multi_char_lexema(char c) {
        switch (c) {
        case ':':
        case '!':
        case '<':
        case '>':
            return true;
        default:
            return false;
        }
    }
    bool number() {
        bool key = true;
        int number = 0;
        while (is_number(peek())) {
            number *= 10;
            number += get() - '0';
        }
        if (peek() == '.') {
            get();
            float frac = fraction();
            if (frac == -1)
            {
                key = false;
                return key;
            }
            else {
                frac += number;
                std::cout << "Got fractial number: " << frac << std::endl;
                lexes.push_back(new FractialNumber(frac));
                lexemas.push_back("NUM_" + std::to_string(frac));
                return key;
            }
        }
        else if (is_letter(peek()))
        {
            key = false;
            return key;
        }

        std::cout << "Got number: " << number << std::endl;
        lexes.push_back(new Number(number));
        lexemas.push_back("NUM_" + std::to_string(number));
        return key;


    }
    float fraction() {
        float fraction = 0;
        float power = 1;
        while (is_number(peek())) {
            power /= 10;
            fraction += (get() - '0') * power;
        }
        if (is_letter(peek()))
        {
            return -1;
        }
        return fraction;
    }
    void word() {
        std::string word = "";
        while (is_letter(peek()) || is_number(peek())) {
            word += get();
        }
        std::cout << "Got word: " << word << std::endl;
        /*TODO проверка на служебные слова*/
        lexes.push_back(new Word(word));
        lexemas.push_back("WRD_" + word);
    }
    void comment() {
        get();
        std::string comment = "";
        while (peek() != '?') {
            comment += get();
        }
        std::cout << "Got comment: " << comment << std::endl;
        lexemas.push_back("COM_<" + comment + ">");
        get();
    }
    void single_char_lexema() {
        std::string lexema;
        lexema += get();
        std::cout << "Got lexema: " << lexema << std::endl;
        lexes.push_back(new Token(lexema));
        lexemas.push_back(lexema);
    }
    bool multi_char_lexema() {
        char firstchar = get();
        std::string lexema;
        lexema += firstchar;
        if (peek() == '=') {
            lexema += get();
            std::cout << "Got lexema: " << lexema << std::endl;
            lexemas.push_back(lexema);
            lexes.push_back(new Token(lexema));
            return true;
        }
        else if ((firstchar == '<' || firstchar == '>') && (peek() != '=') && (is_letter(peek()) || is_number(peek()) || is_space(peek()) || peek() == '(')) {
            std::cout << "Got lexema: " << lexema << std::endl;
            lexemas.push_back(lexema);
            lexes.push_back(new Token(lexema));
            return true;
        }
        else if (((firstchar == '!') || (firstchar == ':')) && (peek() != '=')) {
            //std::cout << "Unknown lexema: " << lexema << std::endl;
            return false;
        }
        else return false;
    }
    bool analyse() {
        bool key = true;
        while ((peek() != '\0') && (key == true)) {
            if (is_space(peek())) get();
            else if (is_number(peek())) key = number();
            else if (is_letter(peek())) word();
            else if (peek() == '?') comment();
            else if (is_single_char_lexema(peek())) single_char_lexema();
            else if (is_multi_char_lexema(peek())) key = multi_char_lexema();
            else if (peek() == ';') {
                std::string lexema;
                lexema += peek();
                lexemas.push_back(lexema);
                lexes.push_back(new Token(lexema));
                get();
            }
            else {
                key = false;

            }
            if (!key) {
                std::cout << "Unknown lexema" << std::endl;
            }
        }
        return key;
    }
public:
    Lexer(const char* beg) : m_begin{ beg } {
        lexemas.clear();
        lexes.clear();
        bool key = true;
        key = analyse();
        if (key) print_tokens();

    }
    const char* m_begin = nullptr;
    char peek() const { return *m_begin; }
    char get() { return *m_begin++; }
    std::vector<Token*> get_lexemas() {
        return lexes;
    }
    void print_tokens() {
        for (auto token : lexes) {
            std::cout << *token << '\ ';
        }
    }
    void print_lexemas() {
        int n = lexemas.size();
        int i = 0;
        while (i != n)
        {
            while (lexemas[i] != ";")
            {
                std::cout << lexemas[i] << ' ';
                i++;
            }
            std::cout << lexemas[i] << std::endl;
            i++;
        }

        std::cout << std::endl << "Token method: " << std::endl;
        for (auto l : lexes) {
            std::cout << *l << '\ ';
        }
    }
};
