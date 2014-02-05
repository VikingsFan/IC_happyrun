#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#include <string>
#endif

#ifndef WORDSHELPER
#define WORDSHELPER

#include "Word.h"
#include <ctime>
#include <cstdlib>

enum WORD_STOCK_NUMBER{FOUR, SIX, GRE};

class WordsHelper
{
public:
	WordsHelper();
	~WordsHelper();
	std::string loadWords();
	Word* getRandWords(int Number);
	void setNumber(int Number);

private:
	int number;
	Word *words;
	int length;
};

extern WordsHelper wordsHelper;
extern WORD_STOCK_NUMBER;
#endif