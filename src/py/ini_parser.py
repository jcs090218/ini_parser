# ========================================================================
# $File: ini_parser.py $
# $Date: 2018-02-12 18:52:25 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright (c) 2018 by Shen, Jen-Chieh $
# ========================================================================


class INI_Parser(object):
    """Parse .ini/.properties file.
    """

    #*********************************************#
    #*             Public Variables              *#
    #*********************************************#

    #*********************************************#
    #              Private Variables             *#
    #*********************************************#

    #*********************************************#
    #              Protected Variables           *#
    #*********************************************#

    #*********************************************#
    #                Constructor                 *#
    #*********************************************#
    def __init__(self):
        """Constructor."""

        self.in_data = []

    #====================
    # Public Methods

    @classmethod
    def readINIFile(self, filePath):
        """Read an .ini/.properties file.

        @param { typename } filePath : file path .ini/.properties file.
        """
        fd = open(filePath, "r")

        line = fd.readline()

        list = []

        while line:
            # check comment line.
            if self.__isCommentLine(line):
                line = fd.readline()
                continue

            keyword, value = line.split("=")

            # NOTE(jenchieh): `rstrip' removes trailing newline.
            list.append(keyword)
            list.append(value.rstrip())

            line = fd.readline()

        fd.close();

        # assign to current object/memory space.
        self.in_data = list

        return list

    @classmethod
    def getProperty(self, keyword):
        """Get a property from loaded ini file.

        @param { typename } keyword : keyword to search for value.
        """

        listLen = len(self.in_data)
        index = 0

        while index < listLen:

            if self.in_data[index] == keyword:
                return self.in_data[index + 1]

            index += 2

    #====================
    # Protected Methods

    #====================
    # Private Methods

    @classmethod
    def __isCommentLine(self, line):
        """Check if line a comment line.

        @param { typename } line : line to check.
        """

        for ch in line:
            if ch != ' ' and ch != '#':
                return False

            if ch == '#':
                return True

        return False

    #====================
    # setter / getter
