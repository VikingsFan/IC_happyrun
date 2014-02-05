#include "WordsHelper.h"

WordsHelper wordsHelper;

WordsHelper::WordsHelper()
{
	srand((unsigned)time(NULL));
	words = new Word[6000];
}

WordsHelper::~WordsHelper()
{
	length = 0;
	delete [] words;
}

std::string WordsHelper::loadWords()
{
	switch(number)
	{
	case WORD_STOCK_NUMBER::FOUR:
		freopen("four.txt", "r", stdin);
		length = 0;
		while (true)
		{
			char str[200];
			gets(str);
			str[101] = '\0';
			std::string word1 = "";
			int now = 0;
			while (str[now] == ' ' && now < 100)
				now++;
			if (now == 100)
				break;
			while (str[now] != ' ')
			{
				word1 += str[now];
				now++;
			}
			std::string word2 = "";
			while (str[now] == ' ' && now < 100)
				now++;			
			while (str[now] != ' ' && now < 100)
			{
				word2 += str[now];
				now++;
			}
			words[length].setName(word1);
			words[length++].setValue(word2);	
		}
		return "CET 4";
	default:
		return "error";
	}
	return "";
}

void WordsHelper::setNumber(int Number)
{
	this -> number = Number;
}

Word* WordsHelper::getRandWords(int Number)
{
	int tot = length / Number;
	int now = rand() % tot + 1;
	Word *randWords = new Word[Number];
	for (int i = 0; i < Number; i++)
		randWords[i] = words[now + tot * i - 1];
	return randWords;
}