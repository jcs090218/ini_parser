/**
 * $File: ini_test.c $
 * $Date: 2018-02-12 03:37:14 $
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


#include <stdio.h>
#include <stdlib.h>

#include <ini_parser.h>


/**
 * @func main
 * @brief Program Entry Point.
 * @param { int } argc : argument count.
 * @param { char } argv : argument vector.
 * @return { int } : 0, no error. -1, error exit.
 */
int main(int argc, char *argv[])
{
#if defined(_MSC_VER)
    const char *filePath = "../../../../test/test.ini";
#elif defined(__GNUC__)
	const char *filePath = "../../test.ini";
#endif

	const int LIST_LEN = 4;

	pair **dic = (pair**)malloc(LIST_LEN * sizeof(pair*));
	for (int index = 0;
		index < LIST_LEN;
		++index)
	{
		dic[index] = (pair*)malloc(sizeof(pair));
	}
	//------------------------------------------------------------------

    read_ini_file(dic, filePath);

	printf("Version: %s\n", get_property(dic, LIST_LEN, "VERSION"));
	printf("Name: %s\n", get_property(dic, LIST_LEN, "NAME"));
	printf("Age: %s\n", get_property(dic, LIST_LEN, "AGE"));
	printf("Email: %s\n", get_property(dic, LIST_LEN, "EMAIL"));

	//------------------------------------------------------------------
	// free it.
	for (int index = 0;
		index < LIST_LEN;
		++index)
	{
		if (dic[index] != NULL)
			free(dic[index]);
	}
	free(dic);

    /* --------------------- */
    fgetc(stdin);
    return 0;
}
