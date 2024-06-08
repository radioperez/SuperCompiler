#pragma once
#include <iostream>
#include <string>
/* Дополнение к Токенам: Нетерминалы и Команды как дети Токена, что позволяет их хранить в стэке */

/* TOKEN INDEXES
   цел 0, вещ 1, имя 2, значение 3, мас 4, если 5, иначе 6, пока 7, := 8, < 9, <= 10, > 11, >= 12,
   = 13,  != 14, [ 15,  ] 16,       ( 17,  ) 18,   + 19,    - 20,   * 21, / 22,; 23,  терм 24, { 25, } 26
*/

class Token {
public:
    std::string type;
    int index;
    Token(std::string t) : type{ t } {
        if (t == ":=") index = 8;
        else if (t == "<") index = 9;
        else if (t == "<=") index = 10;
        else if (t == ">") index = 11;
        else if (t == ">=") index = 12;
        else if (t == "=") index = 13;
        else if (t == "!=") index = 14;
        else if (t == "[") index = 15;
        else if (t == "]") index = 16;
        else if (t == "(") index = 17;
        else if (t == ")") index = 18;
        else if (t == "+") index = 19;
        else if (t == "-") index = 20;
        else if (t == "*") index = 21;
        else if (t == "/") index = 22;
        else if (t == ";") index = 23;
        else if (t == "end") index = 24;
        else if (t == "{") index = 25;
        else if (t == "}") index = 26;
        else index = 999;
    }
    virtual void exec(Token* tk);

    virtual std::ostream& print(std::ostream& os) const {
        os << this->type;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Token& tk) {
        return tk.print(os);
    }
};

class NonTerm : public Token {
public:
    NonTerm(std::string nt) : Token(nt) {
        if (nt == "S") index = 0;
        else if (nt == "Присваивание") index = 1;
        else if (nt == "Тип") index = 2;
        else if (nt == "S1") index = 3;
        else if (nt == "S2") index = 4;
        else if (nt == "Условие") index = 5;
        else if (nt == "Логическое") index = 6;
        else if (nt == "B") index = 7;
        else if (nt == "U") index = 8;
        else if (nt == "T") index = 9;
        else if (nt == "V") index = 10;
        else if (nt == "F") index = 11;
        else if (nt == "Индекс") index = 12;
        else index = 999;
    };
    void exec(Token* tk);
};

class Command : public Token {
public:
    Command(std::string c) : Token(c) {};
    void exec(Token* tk);
};

class Mark : public Token {
public:
    int index;
    Mark(int index_) : Token("m"), index(index_) {}
    void exec(Token* tk);

    std::ostream& print(std::ostream& os) const {
        os << this->type << '_' << this->index;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Mark& m) {
        return m.print(os);
    }
};

class Word : public Token {
public:
    std::string value;
    Word(std::string val) : Token("WORD"), value{ val } {
        if (val == "цел") index = 0;
        else if (val == "вещ") index = 1;
        else if (val == "мас") index = 4;
        else if (val == "если") index = 5;
        else if (val == "иначе") index = 6;
        else if (val == "пока") index = 7;
        else index = 2;
    }
    void exec(Token* tk);

    std::ostream& print(std::ostream& os) const {
        os << this->value;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Word& w) {
        return w.print(os);
    }
};

class Number : public Token { 
public:
    int value;
    Number(int val) : Token("NUM"), value{ val } {
        index = 3;
    }
    void exec(Token* tk);

    std::ostream& print(std::ostream& os) const {
        os << this->value;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Number& n) {
        return n.print(os);
    }
};

class FractialNumber : public Token {
public:
    float value;
    FractialNumber(float val) : Token("FRAC"), value{ val } {
        index = 3;
    }
    void exec(Token* tk);

    std::ostream& print(std::ostream& os) const {
        os << this->value;
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const FractialNumber& fn) {
        return fn.print(os);
    }
};