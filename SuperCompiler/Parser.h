/*
	Генератор ОПС строки.
	На вход получает вектор Token*, сгенерированный классом Lexer
	В процессе генерации:
	хранит два стака: Магазин и Генератор, плюс один вектор ОПС
*/
#pragma once
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "Token.h"

const std::string Matrix[12][25] = {
	/*  цел							вещ							Word  Num/Frac  мас  если  иначе  пока  :=  <  <=  >  >=  =  !=  [  ]  (  )  +  -  *  /  ;  T */
	{   "Sцел",	"Sвещ", "Sимя", "err", "Sмас", "Sесли", "err", "Sпока", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"},
		{},
		{},
		{},
};

class Parser {
public:
	std::string ops;
	std::stack<std::string> magazine;
	std::stack<std::string> generator;
	Parser(std::vector<Token*> stroka) {
		std::stack<Token*> strokacopy;
		for (int i = stroka.size() - 1; i >= 0; i--) {
			strokacopy.push(stroka[i]);
		}

		analyse(strokacopy);
	}
private:
	void analyse(std::stack<Token*> stroka) {
		for (Token* token = stroka.top(); stroka.empty(); stroka.pop()) {
			ops = token->type;
		}
	}
	void command(std::string directive) {
		if (directive == "Sцел") {
			magazine.push("S1"); magazine.push("имя"); magazine.push("цел");
			generator.push("_blank_"); generator.push("имя"); generator.push("10");
		}
		else if (directive == "Sвещ") {
			magazine.push("S1"); magazine.push("имя"); magazine.push("вещ");
			generator.push("_blank_"); generator.push("имя"); generator.push("20");
		}
		else if (directive == "Sимя") {
			magazine.push("S1"); magazine.push("S0"); magazine.push("имя");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("имя");
		}
		else if (directive == "Sмас") {
			magazine.push("S3"); magazine.push("мас");
			generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "Sесли") {
			magazine.push("S"); magazine.push("S2"); magazine.push("}"); magazine.push("S"); magazine.push("{");
			magazine.push(")"); magazine.push("Условие"); magazine.push("("); magazine.push("если");
			generator.push("3"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("1"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "пока") {
			magazine.push("S"); magazine.push("}"); magazine.push("S"); magazine.push("{");
			magazine.push(")"); magazine.push("Условие"); magazine.push("("); magazine.push("пока");
			generator.push("5"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("1"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("_blank_"); generator.push("4");
		}
		else if (directive == "lambda") {
			magazine.push("lambda");
			generator.pop();
		}
		else if (directive == "S0[") {
			magazine.push("]"); magazine.push("В"); magazine.push("[");
			generator.push("i"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "S1:=") {
			magazine.push("S"); magazine.push(";"); magazine.push("В"); magazine.push(":=");
			generator.push(":="); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "S1;") {
			magazine.push("S"); magazine.push(";");
			generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "S2") {
			magazine.push("}"); magazine.push("S"); magazine.push("{"); magazine.push("иначе");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("2");
		}
		else if (directive == "S3цел") {
			magazine.push("S1"); magazine.push("]"); magazine.push("В"); magazine.push("[");
			magazine.push("имя"); magazine.push("цел");
			generator.push("_blank_"); generator.push("i"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("имя"); generator.push("11");
		}
		else if (directive == "S3вещ") {
			magazine.push("S3"); magazine.push("мас");
			generator.push("_blank_"); generator.push("_blank_");
		}
	}
};