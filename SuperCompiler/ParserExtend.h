#pragma once
#include "TokenExtend.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>

std::stack<Token*> ParserString{ {new Token("end")} };
std::stack<Token*> ParserMagazine{ {new Token("end"), new NonTerm("S")} };
std::stack<Token*> ParserGenerator{ {new Command("blank"), new Command("blank")} };
std::vector<Token*> OPS;
std::stack<Mark*> MarkMagazine = {};

void Token::exec(Token* tk) {
	if (tk == nullptr) {
		OPS.push_back(this);
	}
	else if (this->type != tk->type) { std::cout << " " << this->type << "<>" << tk->type << " "; }
	else {
		ParserString.pop();
		Token* cmd = ParserGenerator.top();
		ParserGenerator.pop();
		cmd->exec(nullptr);
		/* pop() строки, top() генератора и на этой команде exec() */
	}
}

void Word::exec(Token* tk) {
	if (tk == nullptr) {
		OPS.push_back(this);
	}
	else if (this->type != tk->type) { std::cout << " " << this->type << "<>" << tk->type << " "; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		ParserString.pop();
		Token* cmd = ParserGenerator.top();
		ParserGenerator.pop();
		cmd->exec(nullptr);
		/* pop() строки, top() генератора и на этой команде exec() */
	}
}

void Number::exec(Token* tk) {
	if (tk == nullptr) {
		OPS.push_back(this);
	}
	else if (this->type != tk->type) { std::cout << " " << this->type << "<>" << tk->type << " "; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		ParserString.pop();
		Token* cmd = ParserGenerator.top();
		ParserGenerator.pop();
		cmd->exec(nullptr);
		/* pop() строки, top() генератора и на этой команде exec() */
	}
}

void FractialNumber::exec(Token* tk) {
	if (tk == nullptr) {
		OPS.push_back(this);
	}
	else if (this->type != tk->type) { std::cout << " " << this->type << "<>" << tk->type << " "; }
	else if (this->index != tk->index) { std::cout << "Wrong words"; }
	else {
		ParserString.pop();
		Token* cmd = ParserGenerator.top();
		ParserGenerator.pop();
		cmd->exec(nullptr);
		/* pop() строки, top() генератора и на этой команде exec() */
	}
};

int Matrix[12][27] = {
/*   ц	в	имя	зн	м	е	и	п	:=	<	<=	>	>=	=	!=	[	]	(	)	+	-	*	/	;	end {  }*/
	{1,	2,	3,	0,	4,	5,	0,	6,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0, 0},
	{7,	8,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1, -1,	-1,-1},
	{0,	0,	0,	0,	0,	0,	0,	0,	9,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	10,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{-1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	11,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
	{-1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	12,	13,	14,	15, 16,	17, -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
	{-1,-1,	18,	19,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	20,	-1,	-1,	-1,	-1, -1,	-1,	-1,	-1,	-1},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	21,	22,	0,	0,	0,	0,	0,	0},
	{-1,-1,	23,	24,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	25,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	26, 27,	0,	0,	0,	0},
	{-1,-1,	28,	29,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	30,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	31,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
};

void NonTerm::exec(Token* tk_) {
	Token* tk;
	if (tk_->type == "WORD") tk = new Word(dynamic_cast<Word*>(tk_)->value);
	else if (tk_->type == "NUM") tk = new Number(dynamic_cast<Number*>(tk_)->value);
	else if (tk_->type == "FRAC") tk = new FractialNumber(dynamic_cast<FractialNumber*>(tk_)->value);
	else tk = new Token(tk_->type);
	
	if (tk->index == 999) { std::cout << "Token Not in Table error"; }
	else {
		int command = Matrix[this->index][tk->index];
		if (ParserGenerator.top()->type == "blank" && command != 0) ParserGenerator.pop();
		switch (command) {
		case 0:
			/* Лямбда. Забираем и исполняем последнюю команду из генератора */
			ParserGenerator.top()->exec(nullptr);
			ParserGenerator.pop();
			break;
		case 1:
			/* S -> цел имя S1; S*/
			ParserMagazine.push(new NonTerm("S"));
			ParserMagazine.push(new Token(";")); ParserMagazine.push(new NonTerm("S1"));
			ParserMagazine.push(tk); ParserMagazine.push(new Word("цел"));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("0"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(tk);
			ParserGenerator.push(new Command("10"));
			break;
		case 2:
			/* S -> вещ имя S1; S*/
			ParserMagazine.push(new NonTerm("S"));
			ParserMagazine.push(new Token(";")); ParserMagazine.push(new NonTerm("S1"));
			ParserMagazine.push(tk); ParserMagazine.push(new Word("вещ"));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("0"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(tk);
			ParserGenerator.push(new Command("20"));
			break;
		case 3:
			/* S -> имя Индекс := B; S */
			ParserMagazine.push(new NonTerm("S"));
			ParserMagazine.push(new Token(";")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token(":=")); ParserMagazine.push(new NonTerm("Индекс")); 
			ParserMagazine.push(tk);

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Token(":="));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(tk);
			break;
		case 4: 
			/* S -> мас Тип имя [B]; S */
			ParserMagazine.push(new NonTerm("S"));
			ParserMagazine.push(new Token(";")); ParserMagazine.push(new Token("]"));
			ParserMagazine.push(new NonTerm("B")); ParserMagazine.push(new Token("["));
			ParserMagazine.push(tk); ParserMagazine.push(new NonTerm("Тип"));
			ParserMagazine.push(new Word("мас"));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("0"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(tk);
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 5: 
			/* S -> если Условие {S} S2 S */
			ParserMagazine.push(new NonTerm("S"));
			ParserMagazine.push(new NonTerm("S2")); ParserMagazine.push(new Token("}")); 
			ParserMagazine.push(new NonTerm("S")); ParserMagazine.push(new Token("{"));
			ParserMagazine.push(new NonTerm("Условие")); ParserMagazine.push(new Word("если"));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank")); 
			ParserGenerator.push(new Command("3")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("1")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank"));
			break;
		case 6: 
			/* S -> пока Условие {S} S*/
			ParserMagazine.push(new NonTerm("S"));
			ParserMagazine.push(new Token("}")); ParserMagazine.push(new NonTerm("S")); ParserMagazine.push(new Token("{"));
			ParserMagazine.push(new NonTerm("Условие")); ParserMagazine.push(new Word("пока"));

			ParserGenerator.push(new Command("5")); ParserGenerator.push(new Command("blank")); 
			ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("1")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("4"));
			break;
		case 7:
			/* Тип -> цел */
			ParserMagazine.push(new Word("цел"));
			ParserGenerator.push(new Command("11"));
			break;
		case 8:
			/* Тип -> вещ */
			ParserMagazine.push(new Word("вещ"));
			ParserGenerator.push(new Command("21"));
			break;
		case 9:
			/* S1 -> := B */
			ParserMagazine.push(new NonTerm("B")); ParserMagazine.push(new Token(":="));
			ParserGenerator.push(new Command(":=")); ParserGenerator.push(new Command("blank"));
			break;
		case 10:
			/* S2 -> иначе { S } */
			ParserMagazine.push(new Token("}")); ParserMagazine.push(new NonTerm("S"));
			ParserMagazine.push(new Token("{")); ParserMagazine.push(new Word("иначе"));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("2"));
			break;
		case 11:
			/* Условие -> ( B Логическое */
			ParserMagazine.push(new NonTerm("Логическое")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token("("));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank"));
			break;
		case 12:
			/* Логическое -> < B ) */
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B")); 
			ParserMagazine.push(new Token("<"));

			ParserGenerator.push(new Token("<"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 13:
			/* Логическое -> <= B ) */
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token("<="));

			ParserGenerator.push(new Token("<="));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 14:
			/* Логическое -> > B ) */
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token(">"));

			ParserGenerator.push(new Token(">"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 15:
			/* Логическое -> >= B ) */
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token(">="));

			ParserGenerator.push(new Token(">="));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 16:
			/* Логическое -> = B ) */
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token("="));

			ParserGenerator.push(new Token("="));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 17:
			/* Логическое -> != B ) */
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token("!="));

			ParserGenerator.push(new Token("!="));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));	
			break;
		case 18:
			/* B -> имя Индекс V U */
			ParserMagazine.push(new NonTerm("U")); ParserMagazine.push(new NonTerm("V"));
			ParserMagazine.push(new NonTerm("Индекс")); ParserMagazine.push(tk);

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(tk);
			break;
		case 19:
			/* B -> значение V U */
			ParserMagazine.push(new NonTerm("U")); ParserMagazine.push(new NonTerm("V"));
			ParserMagazine.push(tk);

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(tk);
			break;
		case 20:
			/* B -> (B) V U */
			ParserMagazine.push(new NonTerm("U")); ParserMagazine.push(new NonTerm("V"));
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token("("));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank"));
			break;
		case 21:
			/* U -> +TU */
			ParserMagazine.push(new NonTerm("U")); ParserMagazine.push(new NonTerm("T"));
			ParserMagazine.push(new Token("+"));

			ParserGenerator.push(new Token("+"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 22:
			/* U -> -TU */
			ParserMagazine.push(new NonTerm("U")); ParserMagazine.push(new NonTerm("T"));
			ParserMagazine.push(new Token("-"));

			ParserGenerator.push(new Token("-"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 23:
			/* T -> имя Индекс V */
			ParserMagazine.push(new NonTerm("V")); ParserMagazine.push(new NonTerm("Индекс")); 
			ParserMagazine.push(tk);

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank")); 
			ParserGenerator.push(tk);
			break;
		case 24:
			/* T -> значение V */
			ParserMagazine.push(new NonTerm("V")); ParserMagazine.push(tk);

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(tk);
			break;
		case 25:
			/* T -> (B) V */
			ParserMagazine.push(new NonTerm("V")); ParserMagazine.push(new Token(")")); 
			ParserMagazine.push(new NonTerm("B")); ParserMagazine.push(new Token("("));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 26:
			/* V -> *FV */
			ParserMagazine.push(new NonTerm("V")); ParserMagazine.push(new NonTerm("F"));
			ParserMagazine.push(new Token("*"));

			ParserGenerator.push(new Token("*"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 27:
			/* V -> /FV */
			ParserMagazine.push(new NonTerm("V")); ParserMagazine.push(new NonTerm("F"));
			ParserMagazine.push(new Token("/"));

			ParserGenerator.push(new Token("/"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		case 28:
			/* F -> имя Индекс */
			ParserMagazine.push(new NonTerm("Индекс")); ParserMagazine.push(tk);

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(tk);
			break;
		case 29:
			/* F -> значение */
			ParserMagazine.push(tk);
			ParserGenerator.push(tk);
			break;
		case 30:
			/* F -> (B) */
			ParserMagazine.push(new Token(")")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token("("));

			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			ParserGenerator.push(new Command("blank"));
			break;
		case 31:
			/* Индекс -> [B] */
			ParserMagazine.push(new Token("]")); ParserMagazine.push(new NonTerm("B"));
			ParserMagazine.push(new Token("["));

			ParserGenerator.push(new Token("i"));
			ParserGenerator.push(new Command("blank")); ParserGenerator.push(new Command("blank"));
			break;
		default:
			std::cout << "Rule error";
		}
		/* 1. взять из таблицы по tk->index, добавить в магазин 
		   2. взять из таблицы для генератора по tk->index, 
		   3. проверить, является ли топ() генератора бланком, если да то сначала удалить его,
			    затем добавить в генератор из таблицы
			  если топ() генератора не бланк то просто добавить
		*/
	}
};

void Command::exec(Token* tk) {
	if (this->type == "blank") {}
	else if (this->type == "0") {
		/* Проверка имени против служебных слов */
		
	}
	else if (this->type == "1") {
		/* В магазин меток записывается k, в опс записывается пустое место и jf */
		MarkMagazine.push(new Mark(OPS.size()));
		OPS.push_back(nullptr); OPS.push_back(new Token("jf"));
	}
	else if (this->type == "2") {
		/* В опс[верхний элемент магазина меток] записывается k+2, В магазин меток записывается k,
		в опс записывается пустое место и j */
		OPS.at(MarkMagazine.top()->index) = new Mark(OPS.size() +2);
		MarkMagazine.pop(); MarkMagazine.push(new Mark(OPS.size()));
		OPS.push_back(nullptr); OPS.push_back(new Token("j"));
	}
	else if (this->type == "3") {
		/* В опс[верхний элемент магазина меток] записывается k */
		OPS.at(MarkMagazine.top()->index) = new Mark(OPS.size());
		MarkMagazine.pop();
	}
	else if (this->type == "4") {
		/* В магазин меток записывается k */
		MarkMagazine.push(new Mark(OPS.size()));
	}
	else if (this->type == "5") {
		/* В опс[верхний элемент магазина меток] записывается k+2, 
		   В опс записывается верхняя метка и j */
		OPS.at(MarkMagazine.top()->index) = new Mark(OPS.size() + 2);
		OPS.push_back(MarkMagazine.top()); OPS.push_back(new Token("j"));
	}
	else if (this->type == "10") {
		/* Режим заполнения таблицы целочисленных переменных */
	}
	else if (this->type == "11") std::cout << "11";
	else if (this->type == "20") std::cout << "20";
	else if (this->type == "21") std::cout << "21";
};

void Mark::exec(Token* tk) {};

class Parser {
public:
	Parser(std::vector<Token*> stroka) {
		for (auto index = stroka.rbegin(); index != stroka.rend(); index++) {
			ParserString.push(*index);
		}

		while (!ParserString.empty()) {
			Token* mgz = ParserMagazine.top();
			ParserMagazine.pop();
			Token* str = ParserString.top();
			std::cout << "[" << mgz->type << " vs " << str->type << "]" << std::endl;
			mgz->exec(str);
			/* основной цикл работы
			   1. топ() магазина
			   2. топ() строки
			   3. элемент магазина.exec(элемент строки)
			*/
		}
	};
	std::vector<Token*> get_ops() {
		return OPS;
	}
};