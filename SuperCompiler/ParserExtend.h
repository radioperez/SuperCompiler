#pragma once
#include "TokenExtend.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>

void Token::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else {
		/* pop() строки, top() генератора и на этой команде exec() */
	}
}

void Word::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		/* pop() строки, top() генератора и на этой команде exec() */
	}
}

void Number::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		/* pop() строки, top() генератора и на этой команде exec() */
	}
}

void FractialNumber::exec(Token* tk) {
	if (this->type != tk->type) { std::cout << "Mismatch error"; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		/* pop() строки, top() генератора и на этой команде exec() */
	}
};

void NonTerm::exec(Token* tk) {
	if (tk->index == 999) { std::cout << "Token Not in Table error"; }
	else {
		/* 1. вз€ть из таблицы по tk->index, добавить в магазин 
		   2. вз€ть из таблицы дл€ генератора по tk->index, 
		   3. проверить, €вл€етс€ ли топ() генератора бланком, если да то сначала удалить его,
			    затем добавить в генератор из таблицы
			  если топ() генератора не бланк то просто добавить
		*/
	}
};
void Command::exec(Token* tk) {
	/* «десь надо описать команды 0, 1, 2, 3, 4, 5, 10, 11, 20, 21 из теоретического файла,
	*  команду »м€/«начение которые будут добавл€ть значение “окена в ќѕ—,
	*  команду ќпераци€ дл€ добавлени€ < = != > + - * / i := в ќѕ—,
	*  и команду blank / bl котора€ ничего не делает
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

		ParserString.push(new Token("end")); /*  оторый перевернута€ “ */
		for (auto index = stroka.rbegin(); index != stroka.rend(); ++index) {
			ParserString.push(*index);
		}
		ParserMagazine.push(new Token("end"));
		ParserMagazine.push(new NonTerm("S"));
		ParserGenerator.push(new Command("bl"));
		ParserGenerator.push(new Command("bl"));

		while (!ParserMagazine.empty()) {
			/* основной цикл работы
			   1. топ() магазина
			   2. топ() строки
			   3. элемент магазина.exec(элемент строки)
			*/
		}
	};
	std::string get_ops() {
		return OPS;
	}
};