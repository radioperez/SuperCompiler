#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Token {
public:
    std::string type;
    Token(std::string t) : type{ t } {}
    virtual std::ostream& print(std::ostream& os) const {
        os << this->type;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Token& tk) {
        return tk.print(os);
    }
};

class Word : public Token {
    std::string value;
public:
    Word(std::string val) : Token("WORD"), value{ val } {}
    std::ostream& print(std::ostream& os) const {
        os << this->type << '_' << this->value;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Word& w) {
        return w.print(os);
    }
};

class Number : public Token {
    int value;
public:
    Number(int val) : Token("NUM"), value{ val } {}
    std::ostream& print(std::ostream& os) const {
        os << this->type << '_' << this->value;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Number& n) {
        return n.print(os);
    }
};

class FractialNumber : public Token {
    float value;
public:
    FractialNumber(float val) : Token("FRAC"), value{ val } {}
    std::ostream& print(std::ostream& os) const {
        os << this->type << '_' << this->value;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const FractialNumber& fn) {
        return fn.print(os);
    }
};

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
        case 'à':
        case 'á':
        case 'â':
        case 'ã':
        case 'ä':
        case 'å':
        case '¸':
        case 'æ':
        case 'ç':
        case 'è':
        case 'é':
        case 'ê':
        case 'ë':
        case 'ì':
        case 'í':
        case 'î':
        case 'ï':
        case 'ð':
        case 'ñ':
        case 'ò':
        case 'ó':
        case 'ô':
        case 'õ':
        case 'ö':
        case '÷':
        case 'ø':
        case 'ù':
        case 'ú':
        case 'û':
        case 'ü':
        case 'ý':
        case 'þ':
        case 'ÿ':
        case 'À':
        case 'Á':
        case 'Â':
        case 'Ã':
        case 'Ä':
        case 'Å':
        case '¨':
        case 'Æ':
        case 'Ç':
        case 'È':
        case 'É':
        case 'Ê':
        case 'Ë':
        case 'Ì':
        case 'Í':
        case 'Î':
        case 'Ï':
        case 'Ð':
        case 'Ñ':
        case 'Ò':
        case 'Ó':
        case 'Ô':
        case 'Õ':
        case 'Ö':
        case '×':
        case 'Ø':
        case 'Ù':
        case 'Ú':
        case 'Û':
        case 'Ü':
        case 'Ý':
        case 'Þ':
        case 'ß':
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
        if (key) get_lexemas();

    }
    const char* m_begin = nullptr;
    char peek() { return *m_begin; }
    char get() { return *m_begin++; }
    void get_lexemas() {
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
