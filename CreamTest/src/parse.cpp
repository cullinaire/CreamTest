#include "parse.h"

//itr will be set to the first non-whitespace character from where it started from
bool skipWhiteSpace(std::string &line, std::string::iterator &itr)
{
	for(;itr != line.end();++itr)
	{
		if(*itr != ' ' && *itr != '\t')	//skip spaces and tabs
			return true;
	}
	return false;	//gets here if end of line is reached
}

//Returns the first whole integer read from the current iterator position
//skips initial whitespace from initial position
//Possible issue is the default return value coinciding with an actual value of 0
int getNumber(std::string &line, std::string::iterator &itr)
{
	int number = 0;
	std::string num;

	num.clear();

	if(!skipWhiteSpace(line, itr))
		return number;

	for(;itr != line.end();++itr)
	{
		if(!isdigit(*itr))
			break;
		else
			num.push_back(*itr);
	}

	number = std::stoi(num);
	return number;
}