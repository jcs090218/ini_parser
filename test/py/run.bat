:: ========================================================================
:: $File: run.bat $
:: $Date: 2018-02-15 15:45:47 $
:: $Revision: $
:: $Creator: Jen-Chieh Shen $
:: $Notice: See LICENSE.txt for modification and distribution information
::                   Copyright © 2018 by Shen, Jen-Chieh $
:: ========================================================================


:: Copy core file.
cp ../../src/py/ini_parser.py ./

:: Run it.
python ini_parser_test.py
