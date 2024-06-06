#pragma once
/*
	цЕМЕПЮРНП ноя ЯРПНЙХ.
	мЮ БУНД ОНКСВЮЕР БЕЙРНП Token*, ЯЦЕМЕПХПНБЮММШИ ЙКЮЯЯНЛ Lexer
	б ОПНЖЕЯЯЕ ЦЕМЕПЮЖХХ:
	УПЮМХР ДБЮ ЯРЮЙЮ: лЮЦЮГХМ Х цЕМЕПЮРНП, ОКЧЯ НДХМ БЕЙРНП ноя
*/
#pragma once
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include "Token.h"

//йнпнве, рср 2 рюакхжш, ъ пеьхкю гюохяшбюрэ ме яюлх яхлбнкш ю хмдейяш, врнаш онрнл ашкн опные япюбмхбюрэ я рнйемнл.
//опнярн жхтпш - хмдейяш, IND.. - щрн хмдейяш ярпнй (блеярн S, S1 х рд) рнфе, врнаш япюгс мю мсфмши хфдейя оепеундрэ.
//нярюкэмн бпнде онмърмн, рнкэйн ъ гюашкю, врн щрн ярей, онщрнлс опхдеряъ ярпнйх пюгбепмсрэ б рюакхжюу, ъ онрнл пюгбепмс

const std::string Matrix[11][25] = {
	/* псяяйюъ р, псяяйюъ б */
/* TOKEN INDEXES
   ЖЕК 0, БЕЫ 1, ХЛЪ 2, ГМЮВЕМХЕ 3, ЛЮЯ 4, ЕЯКХ 5, ХМЮВЕ 6, ОНЙЮ 7,
   := 8, < 9, <= 10, > 11, >= 12, = 13,  != 14, [ 15,  ] 16,
   ( 17,  ) 18,   + 19,    - 20,   * 21, / 22,; 23,  РЕПЛ 24

   МЕ СВЮЯРБСЧР Б РЮАКХЖЕ: { 25, } 26
*/
/*			ЖЕК						БЕЫ					Word						Num/Frac		ЛЮЯ								ЕЯКХ							ХМЮВЕ			ОНЙЮ						:=			<			<=			 >				 >=			=				!=				[				]      (						)      +				-				*				/				;      T    */
{ /*  S=0*/   "0 2 ind2 23 ind0",	"1 2 ind2 23 ind0", "2 ind10 8 ind6 23 ind0",	"lam",			"4 ind1 2 15 ind6 16 23 ind0",	"5 ind4 25 ind0 26 ind3 ind0",	"lam",			"7 ind4 25 ind0 26 ind0",	"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"},
{ /*рХО=1*/   "0",					"1",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /* S1=2*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"8 ind6",	"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"},
{ /* S2=3*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"6 25 ind0 26",	"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"},
{ /*сЯК=4*/	  "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "17 ind6 ind5",			"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*кНЦ=5*/   "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"9 ind6 18","10 ind6 18","11 ind6 18",	"12 ind6 18","13 ind6 18",	"14 ind6 18",	"err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*  B=6*/   "err",				"err",				"2 ind10 ind9 ind7",		"3 ind9 ind7",	"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "17 ind6 18 ind9 ind7",	"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*  U=7*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "19 ind8 ind7",	"20 ind8 ind7",	"lam",			"lam",			"lam", "lam"},
{ /*  T=8*/   "err",				"err",				"2 ind10 ind9",				"3 ind9",		"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "17 ind6 18 ind9",		"err", "err",			"err",			"err",			"err",			"err", "err"},
{ /*  V=9*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"21 ind8 ind9",	"22 ind8 ind9", "lam", "lam"},
{ /*хМД=10*/  "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"15 ind6 16",	"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam"}
};
const std::string MatrixG[11][25] = {
// ю рср рнкэйн 2 х 3 хмдейяш хлемх х вхяек, нярюкэмне - яхлбнкш, рюй йюй нмх днкфмш ашрэ б ноя. BL - BLANK, PR..-мнлеп бшонкмъелни опнцпюллш. 
// я I ме гмюч, нярюбхкю йюй еярэ
/*			ЖЕК						БЕЫ					Word						Num/Frac		ЛЮЯ								ЕЯКХ							ХМЮВЕ			ОНЙЮ						:=			<			<=			 >				 >=			=				!=				[				]      (						)      +				-				*				/				;      T    */
{ /*  S=0*/   "pr10 2 bl pr0 bl",	"pr20 2 bl pr0 bl", "2 bl bl := bl bl",			"lam",			"bl bl 2 bl bl bl pr0 bl",		"bl bl pr1 bl bl pr3 bl",		"lam",			"pr4 bl pr1 bl bl pr5 bl",	"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" },
{ /*рХО=1*/   "pr11",				"pr21",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /* S1=2*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"bl :=",	"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" },
{ /* S2=3*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"pr2 bl bl bl",	"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" },
{ /*сЯК=4*/	  "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "bl bl bl",				"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*кНЦ=5*/   "err",				"err",				"err",						"err",			"err",							"err",							"err",			"err",						"err",		"bl bl <",	"bl bl <=",	"bl bl >",		"bl bl >=",	"bl bl =",		"bl bl !=",	    "err",			"err", "err",					"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*  B=6*/   "err",				"err",				"2 bl bl bl",				"3 bl bl",		"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "bl bl bl bl bl",		"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*  U=7*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "bl bl +",		"bl bl -",		"lam",			"lam",			"lam", "lam" },
{ /*  T=8*/   "err",				"err",				"2 bl bl",					"3 bl",			"err",							"err",							"err",			"err",						"err",		"err",		"err",		"err",			"err",		"err",			"err",			"err",			"err", "bl bl bl bl",			"err", "err",			"err",			"err",			"err",			"err", "err" },
{ /*  V=9*/   "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"lam",			"lam", "lam",					"lam", "lam",			"lam",			"bl bl *",		"bl bl /",		"lam", "lam" },
{ /*хМД=10*/  "lam",				"lam",				"lam",						"lam",			"lam",							"lam",							"lam",			"lam",						"lam",		"lam",		"lam",		"lam",			"lam",		"lam",			"lam",			"bl bl i",		"lam", "lam",					"lam", "lam",			"lam",			"lam",			"lam",			"lam", "lam" }
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
		Token top = *stroka.top(); //top.index - ХМДЕЙЯ КЕЙЯЕЛШ
		addMag(Matrix[position][top.index]); //днаюбкемхе ъвеийх рюакхжш б ярей люцюгхмю он онпъдйс
		addGen(MatrixG[position][top.index]);//днаюбкемхе ъвеийх рюакхжш б ярей цемепюрнпю
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
	void genpop() //сдюкемхе хг цемепюрнпю
	{
		std::string gen;
		gen = generator.top();
		if (gen == "bl") 
		{
			generator.pop();
		}
		else if (gen[0]=='p') //еякх опнцпюллю - бшонкмхрэ. ху ъ еые ме охяюкю
		{
			//ЙНЛЮМДШ
		}
		else if (gen == "2") //еякх 2 - щрн хлъ - бгърэ хлъ с рнйемю, х днаюбхрэ ецн б ноя
		{
			//ДНАЮБКЕМХЕ МЮГБЮМХЪ ОЕПЕЛЕММНИ Б НОЯ
		}
		else if (gen == "3") //еякх 3 - щрн вхякн - бгърэ вхякн с рнйемю х днаюбхрэ ецн б ноя
		{
			//ДНАЮБКЕМХЕ ВХЯКЮ Б НОЯ
		}
		else if (gen == "err") //мсфмю напюанрйю ньханй
		{

		}
		else //дпсцни яхлбнк рхою =+/ днаюбкъеряъ япюгс б ярпнйс
		{
			ops += gen;
			generator.pop();
		}

	}
	void rabotai(std::stack<Token*> stroka)
	{
		Token top = *stroka.top();
		std::string word, gen;
		int x=-1, y=-1; //ХМДЕЙЯШ РЮАКХЖШ ОН ЯРНКАЖЮЛ Х ЯРПНЙЮЛ
		word = magazine.top();
		gen = generator.top();
		magazine.pop();
		//ялнрпхл рейсысч кейяелс б люцюгхме х япюгс ее сдюкъел
		if (word[0]=='i') //еякх щрн мереплхмюк(?) ме онлмч, рхою S, V х рд
		{ 
			word.erase(0, 3);
			y= atoi(word.c_str()); //онксвюел хмдейя мсфмни ярпнйх
			addMag(Matrix[y][top.index]); //днаюбкъел б люцюгхм, рел яюлшл "гюлемъъ" мереплхмюк(?)
			genpop();						//сахпюел яхлбнк хг цемепюрнпю
			addGen(MatrixG[y][top.index]);//днаюбкъел щк-рш яннрберябсчыхе мереплхмюкс б цемепюрнп
			
		}
		else if (word == "lam") //еякх кълдю, рн сдюкъел щкелемр цемепюрнпю, ю хг люцюгхмю сфе сдюкем гюпюмее
		{
			genpop();

		}
		else if (word == "err") //напюанрйю ньханй
		{

		}
		else //еякх опнярн жхтпю -оепебндхл б INT - щрн хмдейя ярнкажю 
		{
			x = atoi(word.c_str());
			if (top.index == x) //опнбепъел, янбоюдючр кх хмдейяш с щк люцюгхмю х с рнйемю.
			{
				genpop(); //еякх дю - сдюкъел ндхм щк-р цемепюрнпю
				
				stroka.pop(); //сдюкъел ндхм рнйем хг ярпнйх
					
				
				//k sled slovy
			}
		
		}
		if (!stroka.empty()) //рср мсфмю дпсцюъ опнбепйю, мн ъ ме сбепемю, йнцдю юкцнпхрл йнмвюеряъ
		{
			rabotai(stroka); //онбрнпъел
		}
		//яеивюя еярэ опнакелю, йнрнпюъ, йюй ъ онднгпебюч, хг-гю меоепебепмсршу рюакхж. онщрнлс нм бяецдю 
		//нярюеряъ мю IND0, ю рюй нмх ашкх аш дюкейн б йнмже ярейю. мн щрн ъ онрнл сфе ядекюч
	}
	
};