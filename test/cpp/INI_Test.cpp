/**
 * $File: INI_Test.cpp $
 * $Date: 2018-02-12 03:40:08 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */

#ifdef _DEBUG
#if defined(_MSC_VER)
#include <vld.h>
#elif defined(__GNUC__)

#elif defined(__clang__)

#endif
#endif /* _DEBUG */

#include <iostream>
#include <string>
#include <stdio.h>

#include <INI_Parser.h>


/**
 * @func main
 * @brief Program Entry Point.
 * @param { int } argc : argument count.
 * @param { char } argv : argument vector.
 * @return { int } : 0, no error. -1, error exit.
 */
int main(int argc, char *argv[])
{
    INI_Parser* parser = new INI_Parser();

	// Setup file path.
	std::string filePath = "../../../../test/test.ini";

	// Read it.
	std::map<std::string, std::string> ini_data = parser->ReadINIFile(filePath);

	std::cout << "Version: " << ini_data["VERSION"] << std::endl;
	std::cout << "Name: " << ini_data["NAME"] << std::endl;
	std::cout << "Age: " << ini_data["AGE"] << std::endl;
	std::cout << "Email: " << ini_data["EMAIL"] << std::endl;

    // clean it.
    delete parser;

    // -------------------
    fgetc(stdin);
    return 0;
}
