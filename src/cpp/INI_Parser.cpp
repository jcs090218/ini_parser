/**
 * $File: INI_Parser.cpp $
 * $Date: 2018-02-12 03:36:28 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */

#include <INI_Parser.h>

#include <iostream>
#include <fstream>


INI_Parser::INI_Parser()
{

}

INI_Parser::~INI_Parser()
{

}

/* Read the .ini/.properties file. */
std::map<std::string, std::string> INI_Parser::ReadINIFile(const std::string path)
{
	// clear it.
	this->m_iniData = std::map<std::string, std::string>();

	std::ifstream input(path);
	std::string delimiter = "=";

	for (std::string line; 
		getline(input, line); 
		)
	{
		if (CheckIfComment(line))
			continue;

		auto keyword = line.substr(0, line.find(delimiter));
		auto value = line.substr(line.find(delimiter) + 1, line.length());
		m_iniData[keyword] = value;
	}

	return this->m_iniData;
}

/* Check if line is a comment. */
bool INI_Parser::CheckIfComment(std::string line)
{
	for (unsigned int index = 0;
		index < line.length();
		++index)
	{
		char ch = line[index];

		if (ch != ' ' && ch != '#')
			return false;

		// check if first character the comment character.
		if (ch == '#')
			return true;
	}

    return false;
}
