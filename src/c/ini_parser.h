#ifndef __INI_PARSER_H__
/**
 * $File: ini_parser.h $
 * $Date: 2018-02-12 05:03:46 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */
#define __INI_PARSER_H__


#define STR_LEN 256

/**
 * @struct pair
 * @brief Struct description here..
 */
typedef struct pair {
    char keyword[STR_LEN];  /* keyword of to search. */
    char value[STR_LEN];    /* value to this keyword. */
} pair;


/**
 * @func get_property
 * @brief Get the property value by keyword.
 * @param { pair } in_data : data itself.
 * @param { int } len : length of the data list.
 * @param { char } keyword : keyword to search.
 */
char* get_property(pair **in_data, int len, const char *keyword);

/**
 * @func read_ini_file
 * @brief Read .ini/.properties file.
 * @param { char } filePath : file path.
 */
void read_ini_file(pair **in_data, const char *filePath);

#endif /* __INI_PARSER_H__ */
