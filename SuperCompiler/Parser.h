/*
	��������� ��� ������.
	�� ���� �������� ������ Token*, ��������������� ������� Lexer
	� �������� ���������:
	������ ��� �����: ������� � ���������, ���� ���� ������ ���
*/
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "Token.h"

const int Matrix[12][25] = {
	/*  ���  ���  Word  Num/Frac  ���  ����  �����  ����  :=  <  <=  >  >=  =  !=  [  ]  (  )  +  -  *  /  ;  T */
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