/**
 * $File: ini_parser.c $
 * $Date: 2018-02-12 03:36:42 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <ini_parser.h>


 /**
  * @enum bool
  * @brief boolean data type.
  */
typedef enum bool {
	false,
	true,
} bool;


/* Check the line is a comment. */
static bool is_comment_line(char *line) {
	char* ch = line;

	while (*ch != '\0') {
		if (*ch != ' ' && *ch != '#')
			return false;

		if (*ch == '#')
			return true;

		ch++;
	}

	return false;
}

/* Get the property value by keyword. */
char* get_property(pair **in_data, int len, const char *keyword) {
	int index;

	for (index = 0;
		index < len;
		index++)
	{
		if (strcmp(in_data[index]->keyword, keyword) == 0)
			return in_data[index]->value;
	}

	return "";
}

/* Read .ini/.properties file. */
void read_ini_file(pair **in_data, const char *filePath) {
	FILE *fp;
	char line[STR_LEN];
	int data_len = 0;

	fp = fopen(filePath, "r");

	while (fgets(line, sizeof(line), fp)) {
		if (is_comment_line(line))
			continue;

		strcpy(in_data[data_len]->keyword, strtok(line, "="));
		strcpy(in_data[data_len]->value, strtok(NULL, "=\n"));

		data_len++;
	}

	fclose(fp);
}
