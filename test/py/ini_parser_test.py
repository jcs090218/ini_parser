# ========================================================================
# $File: ini_parser_test.py $
# $Date: 2018-02-12 18:52:47 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright (c) 2018 by Shen, Jen-Chieh $
# ========================================================================

from ini_parser import INI_Parser

def main():

    filePath = "../test.ini"

    # create parser.
    parser = INI_Parser()

    # read the target ini file.
    parser.readINIFile(filePath)

    # print out some sample.
    print("Version: " + parser.getProperty("VERSION"))
    print("Name: " + parser.getProperty("NAME"))
    print("Age: " + parser.getProperty("AGE"))
    print("Email: " + parser.getProperty("EMAIL"))

main()
