#pragma once
#include "TokenExtend.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include "Tables.h"

class Interpreter {
	std::vector<Token*> ops;
	int current;
	std::stack<Token*> magazine;
public:
	Interpreter(std::vector<Token*> ops_) : ops(ops_), current(0) {
		while (current < ops.size()) {
			Token* curToken = peek(current);
			if (curToken->type == "WORD") {
				/* Проверяем сущестование в таблице Tables */
				bool ExistCheck = (INTS.count(dynamic_cast<Word*>(curToken)->value) != FLOATS.count(dynamic_cast<Word*>(curToken)->value));
				if (!ExistCheck) std::cout << "Several vars with same name";
				else {
					magazine.push(curToken);
				}
			}
			else if (curToken->type == "NUM" || curToken->type == "FRAC") {
				magazine.push(curToken);
			}
			else if (curToken->type == "+") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				std::cout << *left << curToken->type << *right << std::endl;

				if (left->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value + dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else {
					float result = dynamic_cast<FractialNumber*>(left)->value + dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			else if (curToken->type == "-") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				std::cout << *left << curToken->type << *right << std::endl;

				if (left->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value - dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else {
					float result = dynamic_cast<FractialNumber*>(left)->value - dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			else if (curToken->type == "*") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				std::cout << *left << curToken->type << *right << std::endl;

				if (left->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value * dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else {
					float result = dynamic_cast<FractialNumber*>(left)->value * dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			else if (curToken->type == "/") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				std::cout << *left << curToken->type << *right << std::endl;

				if (left->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value / dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else {
					float result = dynamic_cast<FractialNumber*>(left)->value / dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			else if (curToken->type == ":=") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();

				if (INTS.count(dynamic_cast<Word*>(left)->value) == 1) {
					INTS[dynamic_cast<Word*>(left)->value] = dynamic_cast<Number*>(right)->value;
				}
				else {
					FLOATS[dynamic_cast<Word*>(left)->value] = dynamic_cast<FractialNumber*>(right)->value;
				}
			}
			current++;
		}
	};
	Token* peek(int index) {
		return ops.at(index);
	};
};