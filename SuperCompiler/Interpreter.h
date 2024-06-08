#pragma once
#include "TokenExtend.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>

class Interpreter {
	std::vector<Token*> ops;
	int current;
	std::stack<Token*> magazine;
public:
	Interpreter(std::vector<Token*> ops_) : ops(ops_), current(0) {
		while (current < ops.size()) {
			Token* curToken = peek(current);
			if (curToken->type == "WORD") {

			}
			else if (curToken->type == "NUM" || curToken->type == "FRAC") {
				magazine.push(curToken);
			}
			else if (curToken->type == "+") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				if (right->type != left->type) std::cout << "TYPE MISMATCH";
				else if (right->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value + dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else if (right->type == "FRAC") {
					float result = dynamic_cast<FractialNumber*>(left)->value + dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			else if (curToken->type == "-") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				if (right->type != left->type) std::cout << "TYPE MISMATCH";
				else if (right->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value - dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else if (right->type == "FRAC") {
					float result = dynamic_cast<FractialNumber*>(left)->value - dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			else if (curToken->type == "*") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				if (right->type != left->type) std::cout << "TYPE MISMATCH";
				else if (right->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value * dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else if (right->type == "FRAC") {
					float result = dynamic_cast<FractialNumber*>(left)->value * dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			else if (curToken->type == "/") {
				Token* right = magazine.top(); magazine.pop();
				Token* left = magazine.top(); magazine.pop();
				if (right->type != left->type) std::cout << "TYPE MISMATCH";
				else if (right->type == "NUM") {
					int result = dynamic_cast<Number*>(left)->value / dynamic_cast<Number*>(right)->value;
					magazine.push(new Number(result));
				}
				else if (right->type == "FRAC") {
					float result = dynamic_cast<FractialNumber*>(left)->value / dynamic_cast<FractialNumber*>(right)->value;
					magazine.push(new FractialNumber(result));
				}
			}
			current++;
		}
	};
	Token* peek(int index) {
		return ops.at(index);
	};
};