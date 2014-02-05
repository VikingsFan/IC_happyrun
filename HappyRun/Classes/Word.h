#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#include <string>
#endif

#ifndef WORDH
#define WORDH

class Word
{
public:
	Word()
	{
		name = "";
		identity = "";
		value = "";
	}

	Word(const Word& word)
	{
		name = word.getName();
		identity = word.getIdentity();
		value = word.getValue();
	}

	Word(std::string name, std::string identity, std::string value)
	{
		this->name = name;
		this->identity = identity;
		this->value = value;
	}

	std::string getName() const
	{
		return name;
	}

	void setName(std::string name)
	{
		this -> name = name;
	}

	void setValue(std::string value)
	{
		this -> value = value;
	}

	std::string getIdentity() const
	{
		return identity;
	}

	std::string getValue() const
	{
		return value;
	}

private:
	std::string name;
	std::string identity;
	std::string value;
};

#endif