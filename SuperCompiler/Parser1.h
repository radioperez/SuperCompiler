#pragma once
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
#include <sstream>
#include <iostream>
#include "Token.h"

//������, ��� 2 �������, � ������ ���������� �� ���� ������� � �������, ����� ����� ���� ����� ���������� � �������.
//������ ����� - �������, IND.. - ��� ������� ����� (������ S, S1 � ��) ����, ����� ����� �� ������ ������ ���������.
//�������� ����� �������, ������ � ������, ��� ��� ����, ������� �������� ������ ���������� � ��������, � ����� ��������

const std::string Matrix[11][25] = {
	/* ������� �, ������� � */
/* TOKEN INDEXES
   ��� 0, ��� 1, ��� 2, �������� 3, ��� 4, ���� 5, ����� 6, ���� 7,
   := 8, < 9, <= 10, > 11, >= 12, = 13,  != 14, [ 15,  ] 16,
   ( 17,  ) 18,   + 19,    - 20,   * 21, / 22,; 23,  ���� 24

   �� ��������� � �������: { 25, } 26
*/
/*			���						���					Word						Num/Frac		���								����							�����			����						:=			<			<=			 >				 >=			=				!=				[				]      (						)      +				-				*				/				;      T    */
{ /*  S=0*/   "0 2 ind2 23 ind0",	"1 2 ind2 23 ind0", "2 ind10 8 ind6 23 ind0",	"lam",			"4 ind1 2 15 ind6 16 23 ind0",	"5 ind4 25 ind0 26 ind3 ind0",	"lam",			"7 ind4 25 ind0 26 ind0",	"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"},
{ /*���=1*/   "0",					"1",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /* S1=2*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"8 ind6",	"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"},
{ /* S2=3*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"6 25 ind0 26",	"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"},
{ /*���=4*/	  "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "17 ind6 ind5",			"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*���=5*/   "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"9 ind6 18","10 ind6 18","11 ind6 18",	"12 ind6 18","13 ind6 18",	"14 ind6 18",	"err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*  B=6*/   "err",				"err",				"2 ind10 ind9 ind7",		"3 ind9 ind7",	"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "17 ind6 18 ind9 ind7",	"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*  U=7*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "19 ind8 ind7",	"20 ind8 ind7",	"lam",			"lam",			"lam", "lam"},
{ /*  T=8*/   "err",				"err",				"2 ind10 ind9",				"3 ind9",		"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "17 ind6 18 ind9",		"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*  V=9*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"21 ind8 ind9",	"22 ind8 ind9", "lam", "lam"},
{ /*���=10*/  "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"15 ind6 16",	"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"}
};
const std::string MatrixG[11][25] = {
// � ��� ������ 2 � 3 ������� ����� � �����, ��������� - �������, ��� ��� ��� ������ ���� � ���. BL - BLANK, PR..-����� ����������� ���������. 
// � I �� ����, �������� ��� ����
/*			���						���					Word						Num/Frac		���								����							�����			����						:=			<			<=			 >				 >=			=				!=				[				]      (						)      +				-				*				/				;      T    */
{ /*  S=0*/   "pr10 2 bl pr0 bl",	"pr20 2 bl pr0 bl", "2 bl bl := bl bl",			"lam",			"bl bl 2 bl bl bl pr0 bl",		"bl bl pr1 bl bl pr3 bl",		"lam",			"pr4 bl pr1 bl bl pr5 bl",	"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" },
{ /*���=1*/   "pr11",				"pr21",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /* S1=2*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"bl :=",	"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" },
{ /* S2=3*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"pr2 bl bl bl",	"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" },
{ /*���=4*/	  "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "bl bl bl",				"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*���=5*/   "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"bl bl <",	"bl bl <=",	"bl bl >",		"bl bl >=",	"bl bl =",		"bl bl !=",	    "err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*  B=6*/   "err",				"err",				"2 bl bl bl",				"3 bl bl",		"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "bl bl bl bl bl",		"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*  U=7*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "bl bl +",		"bl bl -",		"lam",			"lam",			"lam", "lam" },
{ /*  T=8*/   "err",				"err",				"2 bl bl",					"3 bl",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "bl bl bl bl",			"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*  V=9*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"bl bl *",		"bl bl /",		"lam", "lam" },
{ /*���=10*/  "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"bl bl i",		"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" }
};

class Parser {
public:
	int position;
	std::string ops;
	std::stack<std::string> magazine;
	std::stack<std::string> generator;
	Parser(std::vector<Token*> stroka) {
		position = 0;
		std::stack<Token*> strokacopy;
		for (int i = 10 - 1; i >= 0; i--) {
			strokacopy.push(stroka[i]);
		}
		
		analyse(strokacopy);
	}
private:
	void analyse(std::stack<Token*> stroka) {
		Token top = *stroka.top(); //top.index - ������ �������
		addMag(Matrix[position][top.index]); //���������� ������ ������� � ���� �������� �� �������
		addGen(MatrixG[position][top.index]);//���������� ������ ������� � ���� ����������
		rabotai(stroka);
	}
	void addMag(std::string str)
	{
		std::istringstream ss(str);
		std::string word;
		while (ss >> word)
		{
			magazine.push(word);
		}
		
	}
	void addGen(std::string str)
	{
		std::istringstream ss(str);
		std::string word;
		while (ss >> word)
		{
			generator.push(word);
		}

	}
	void genpop() //�������� �� ����������
	{
		std::string gen;
		gen = generator.top();
		if (gen == "bl") 
		{
			generator.pop();
		}
		else if (gen[0]=='p') //���� ��������� - ���������. �� � ��� �� ������
		{
			//�������
		}
		else if (gen == "2") //���� 2 - ��� ��� - ����� ��� � ������, � �������� ��� � ���
		{
			//���������� �������� ���������� � ���
		}
		else if (gen == "3") //���� 3 - ��� ����� - ����� ����� � ������ � �������� ��� � ���
		{
			//���������� ����� � ���
		}
		else if (gen == "err") //����� ��������� ������
		{

		}
		else //������ ������ ���� =+/ ����������� ����� � ������
		{
			ops += gen;
			generator.pop();
		}

	}
	void rabotai(std::stack<Token*> stroka)
	{
		Token top = *stroka.top();
		std::string word, gen;
		int x=-1, y=-1; //������� ������� �� �������� � �������
		word = magazine.top();
		gen = generator.top();
		magazine.pop();
		//������� ������� ������� � �������� � ����� �� �������
		if (word[0]=='i') //���� ��� ����������(?) �� �����, ���� S, V � ��
		{ 
			word.erase(0, 3);
			y= atoi(word.c_str()); //�������� ������ ������ ������
			addMag(Matrix[y][top.index]); //��������� � �������, ��� ����� "�������" ����������(?)
			genpop();						//������� ������ �� ����������
			addGen(MatrixG[y][top.index]);//��������� ��-�� �������������� ����������� � ���������
			
		}
		else if (word == "lam") //���� �����, �� ������� ������� ����������, � �� �������� ��� ������ �������
		{
			genpop();

		}
		else if (word == "err") //��������� ������
		{

		}
		else //���� ������ ����� -��������� � INT - ��� ������ ������� 
		{
			x = atoi(word.c_str());
			if (top.index == x) //���������, ��������� �� ������� � �� �������� � � ������.
			{
				genpop(); //���� �� - ������� ���� ��-� ����������
				
				stroka.pop(); //������� ���� ����� �� ������
					
				
				//k sled slovy
			}
		
		}
		if (!stroka.empty()) //��� ����� ������ ��������, �� � �� �������, ����� �������� ���������
		{
			rabotai(stroka); //���������
		}
		//������ ���� ��������, �������, ��� � ����������, ��-�� �������������� ������. ������� �� ������ 
		//�������� �� IND0, � ��� ��� ���� �� ������ � ����� �����. �� ��� � ����� ��� ������
	}
	
};