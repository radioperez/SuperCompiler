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
	/* РУССКАЯ Т, РУССКАЯ В */
	/*  цел		вещ		Word    Num/Frac мас     если     иначе  пока     :=     <      <=     >      >=     =      !=     [      ]      (      )      +      -      *      /      ;      T    */
	{   "Sцел",	"Sвещ", "Sимя", "err",   "Sмас", "Sесли", "err", "Sпока", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"},
	{   "lam",  "lam",  "lam",  "lam",   "lam",  "lam",   "lam", "lam",   "lam", "lam", "lam", "lam", "lam", "lam", "lam", "S0",  "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam"},
	{   "err",  "err",  "err",  "err",   "err",  "err",   "err", "err",   "S1:=","err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "S1;", "err"},
	{   "lam",  "lam",  "lam",  "lam",   "lam",  "lam",   "S2",  "lam",   "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam"},
	{	"S3цел","S3вещ","err",  "err",   "err",  "err",   "err", "err",   "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"},
	{   "err",  "err",  "Уимя", "Узнач", "err",  "err",   "err", "err",   "err", "err", "err", "err", "err", "err", "err", "err", "err", "У(",  "err", "err", "err", "err", "err", "err", "err"},
	{   "err",  "err",  "err",  "err",   "err",  "err",   "err", "err",   "err", "<",   "<=",  ">",   ">=",  "=",   "!=",  "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"},
	{   "err",  "err",  "Вимя", "Взнач", "err",  "err",   "err", "err",   "err", "err", "err", "err", "err", "err", "err", "err", "err", "В(",  "err", "err", "err", "err", "err", "err", "err"},
	{   "lam",  "lam",  "lam",  "lam",   "lam",  "lam",   "lam", "lam",   "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "+",   "-",   "lam", "lam", "lam", "lam"},
	{   "err",  "err",  "Тимя", "Тзнач", "err",  "err",   "err", "err",   "err", "err", "err", "err", "err", "err", "err", "err", "err", "Т(",  "err", "err", "err", "err", "err", "err", "err"},
	{   "lam",  "lam",  "lam",  "lam",   "lam",  "lam",   "lam", "lam",   "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "lam", "*",   "/",   "lam", "lam"},
	{   "lam",  "lam",  "lam",  "lam",   "lam",  "lam",   "lam", "lam",   "lam", "lam", "lam", "lam", "lam", "lam", "lam", "И[",  "lam", "lam", "lam", "lam", "lam", "*",   "/",   "lam", "lam"}
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
		else if (directive == "lam") {
			magazine.push("lam");
			generator.pop();
		}
		else if (directive == "S0") {
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
			magazine.push("S1"); magazine.push("]"); magazine.push("В"); magazine.push("["); 
			magazine.push("имя"); magazine.push("вещ");
			generator.push("_blank_"); generator.push("i"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("имя"); generator.push("21");
		}
		else if (directive == "Уимя") {
			magazine.push("В"); magazine.push("Логическое"); magazine.push("U"); magazine.push("V");
			magazine.push("Индекс"); magazine.push("имя");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("_blank_"); generator.push("имя");
		}
		else if (directive == "Узнач") {
			magazine.push("В"); magazine.push("Логическое"); magazine.push("U"); magazine.push("V");
			magazine.push("Индекс"); magazine.push("значение");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("_blank_"); generator.push("значение");
		}
		else if (directive == "У(") {
			magazine.push("В"); magazine.push("Логическое"); magazine.push("U"); magazine.push("V");
			magazine.push(")"); magazine.push("В"); magazine.push("(");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "<") {
			magazine.push("<");
			generator.push("<");
		}
		else if (directive == "<=") {
			magazine.push("<=");
			generator.push("<=");
		}
		else if (directive == ">") {
			magazine.push(">");
			generator.push(">=");
		}
		else if (directive == ">=") {
			magazine.push(">=");
			generator.push(">=");
		}
		else if (directive == "=") {
			magazine.push("=");
			generator.push("=");
		}
		else if (directive == "!=") {
			magazine.push("!=");
			generator.push("!=");
		}
		else if (directive == "Вимя") {
			magazine.push("U"); magazine.push("V"); magazine.push("Индекс"); magazine.push("имя");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("имя");
		}
		else if (directive == "Взнач") {
			magazine.push("U"); magazine.push("V"); magazine.push("значение");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("значение");
		}
		else if (directive == "В(") {
			magazine.push("U"); magazine.push("V"); magazine.push(")"); magazine.push("В"); magazine.push("(");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); 
			generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "+") {
			/* РУССКАЯ Т */
			magazine.push("U"); magazine.push("T"); magazine.push("+");
			generator.push("+"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "-") {
			/* РУССКАЯ Т */
			magazine.push("U"); magazine.push("T"); magazine.push("-");
			generator.push("-"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "Тимя") {
			/* РУССКАЯ Т */
			magazine.push("V"); magazine.push("Индекс"); magazine.push("имя");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("имя");
		}
		else if (directive == "Тзнач") {
			/* РУССКАЯ Т */
			magazine.push("V"); magazine.push("значение"); 
			generator.push("_blank_"); generator.push("значение");
		}
		else if (directive == "Т(") {
			/* РУССКАЯ Т */
			magazine.push("V"); magazine.push(")"); magazine.push("В"); magazine.push("(");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "*") {
			magazine.push("V"); magazine.push("Т"); magazine.push("*");
			generator.push("*"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "/") {
			magazine.push("V"); magazine.push("Т"); magazine.push("/");
			generator.push("/"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "И[") {
			magazine.push("]"); magazine.push("В"); magazine.push("[");
			generator.push("i"); generator.push("_blank_"); generator.push("_blank_");
		}
	}
};