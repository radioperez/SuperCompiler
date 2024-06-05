#pragma once
#include <iostream>
#include <string>

class Token {
public:
    std::string type;
    int index;
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