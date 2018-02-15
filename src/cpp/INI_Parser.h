#ifndef __INI_PARSER_H__
/**
 * $File: INI_Parser.h $
 * $Date: 2018-02-12 03:43:26 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */
#define __INI_PARSER_H__


#include <map>
#include <string>

/**
 * @class INI_Parser
 * @brief .ini parser class.
 */
class INI_Parser
{
private:
	std::map<std::string, std::string> m_iniData;

public:
    INI_Parser();
    ~INI_Parser();

	/**
	 * @func ReadINIFile
	 * @brief Read the .ini/.properties file.
	 * @param { string } path : file path.
	 */
	std::map<std::string, std::string> ReadINIFile(const std::string path);

    /* operator */

    /* setter */

    /* getter */

private:
	/**
	* @func CheckIfComment
	* @brief Function description here..
	* @param { char } line : Line to check.
	* @return { bool } : true, is comment line. false, is data value.
	*/
	bool CheckIfComment(std::string line);

};

#endif /* __INI_PARSER_H__ */
