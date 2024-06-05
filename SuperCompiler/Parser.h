/*
	Генератор ОПС строки.
	На вход получает вектор Token*, сгенерированный классом Lexer
	В процессе генерации:
	хранит два стака: Магазин и Генератор, плюс один вектор ОПС
*/
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "Token.h"

const int Matrix[12][25] = {
	/*  цел  вещ  Word  Num/Frac  мас  если  иначе  пока  :=  <  <=  >  >=  =  !=  [  ]  (  )  +  -  *  /  ;  T */
	{   0,	 1,	  2,	3,		  4,   5,	 6,		7,	  8,  9, 10, 11,12, 13,14, 15,16,17,18,19,20,21,22,23,24},
		{},
		{},
		{},
};

class Parser {
public:
	std::string ops;
	Parser(std::vector<Token*> stroka) {
		std::vector<Token*> strokacopy;
		std::stack<Token*> magazine;
		std::stack<Token*> generator;

		ops = "LOL";
	}
private:
	

};