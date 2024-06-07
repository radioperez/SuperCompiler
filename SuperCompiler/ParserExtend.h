#pragma once
#include "TokenExtend.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>

void Token::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else {
		/* pop() ������, top() ���������� � �� ���� ������� exec() */
	}
}

void Word::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		/* pop() ������, top() ���������� � �� ���� ������� exec() */
	}
}

void Number::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		/* pop() ������, top() ���������� � �� ���� ������� exec() */
	}
}

void FractialNumber::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		/* pop() ������, top() ���������� � �� ���� ������� exec() */
	}
};

void NonTerm::exec(Token* tk) {
	if (tk->index == 999) { std::cout << "Token Not in Table error"; }
	else {
		/* 1. ����� �� ������� �� tk->index, �������� � ������� 
		   2. ����� �� ������� ��� ���������� �� tk->index, 
		   3. ���������, �������� �� ���() ���������� �������, ���� �� �� ������� ������� ���,
			    ����� �������� � ��������� �� �������
			  ���� ���() ���������� �� ����� �� ������ ��������
		*/
	}
};
void Command::exec(Token* tk) {
	/* ����� ���� ������� ������� 0, 1, 2, 3, 4, 5, 10, 11, 20, 21 �� �������������� �����,
	*  ������� ���/�������� ������� ����� ��������� �������� ������ � ���,
	*  ������� �������� ��� ���������� < = != > + - * / i := � ���,
	*  � ������� blank / bl ������� ������ �� ������
	*/
};

std::stack<Token*> ParserString;
std::stack<Token*> ParserMagazine;
std::stack<Token*> ParserGenerator;
std::string OPS;
class Parser {
public:
	Parser(std::vector<Token*> stroka) {
		ParserString = {};
		ParserMagazine = {};
		ParserGenerator = {};
		OPS = "";

		ParserString.push(new Token("end")); /* ������� ������������ � */
		for (auto index = stroka.rbegin(); index != stroka.rend(); ++index) {
			ParserString.push(*index);
		}
		ParserMagazine.push(new Token("end"));
		ParserMagazine.push(new NonTerm("S"));
		ParserGenerator.push(new Command("bl"));
		ParserGenerator.push(new Command("bl"));

		while (!ParserMagazine.empty()) {
			/* �������� ���� ������
			   1. ���() ��������
			   2. ���() ������
			   3. ������� ��������.exec(������� ������)
			*/
		}
	};
	std::string get_ops() {
		return OPS;
	}
};