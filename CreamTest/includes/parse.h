//parse.h - routines for parsing text files

#ifndef PARSE_H_
#define PARSE_H_

#include <iostream>
#include <cctype>
#include <string>

bool skipWhiteSpace(std::string &line, std::string::iterator &itr);
int getNumber(std::string &line, std::string::iterator &itr);

#endif