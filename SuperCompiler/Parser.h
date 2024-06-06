/*
	��������� ��� ������.
	�� ���� �������� ������ Token*, ��������������� ������� Lexer
	� �������� ���������:
	������ ��� �����: ������� � ���������, ���� ���� ������ ���
*/
#pragma once
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "Token.h"

const std::string Matrix[12][25] = {
	/*  ���							���							Word  Num/Frac  ���  ����  �����  ����  :=  <  <=  >  >=  =  !=  [  ]  (  )  +  -  *  /  ;  T */
	{   "S���",	"S���", "S���", "err", "S���", "S����", "err", "S����", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"},
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
		if (directive == "S���") {
			magazine.push("S1"); magazine.push("���"); magazine.push("���");
			generator.push("_blank_"); generator.push("���"); generator.push("10");
		}
		else if (directive == "S���") {
			magazine.push("S1"); magazine.push("���"); magazine.push("���");
			generator.push("_blank_"); generator.push("���"); generator.push("20");
		}
		else if (directive == "S���") {
			magazine.push("S1"); magazine.push("S0"); magazine.push("���");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("���");
		}
		else if (directive == "S���") {
			magazine.push("S3"); magazine.push("���");
			generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "S����") {
			magazine.push("S"); magazine.push("S2"); magazine.push("}"); magazine.push("S"); magazine.push("{");
			magazine.push(")"); magazine.push("�������"); magazine.push("("); magazine.push("����");
			generator.push("3"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("1"); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "����") {
			magazine.push("S"); magazine.push("}"); magazine.push("S"); magazine.push("{");
			magazine.push(")"); magazine.push("�������"); magazine.push("("); magazine.push("����");
			generator.push("5"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("1"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("_blank_"); generator.push("4");
		}
		else if (directive == "lambda") {
			magazine.push("lambda");
			generator.pop();
		}
		else if (directive == "S0[") {
			magazine.push("]"); magazine.push("�"); magazine.push("[");
			generator.push("i"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "S1:=") {
			magazine.push("S"); magazine.push(";"); magazine.push("�"); magazine.push(":=");
			generator.push(":="); generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "S1;") {
			magazine.push("S"); magazine.push(";");
			generator.push("_blank_"); generator.push("_blank_");
		}
		else if (directive == "S2") {
			magazine.push("}"); magazine.push("S"); magazine.push("{"); magazine.push("�����");
			generator.push("_blank_"); generator.push("_blank_"); generator.push("_blank_"); generator.push("2");
		}
		else if (directive == "S3���") {
			magazine.push("S1"); magazine.push("]"); magazine.push("�"); magazine.push("[");
			magazine.push("���"); magazine.push("���");
			generator.push("_blank_"); generator.push("i"); generator.push("_blank_"); generator.push("_blank_");
			generator.push("���"); generator.push("11");
		}
		else if (directive == "S3���") {
			magazine.push("S3"); magazine.push("���");
			generator.push("_blank_"); generator.push("_blank_");
		}
	}
};