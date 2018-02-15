/**
 * $File: INI_Parser_Test.java $
 * $Date: 2018-02-12 17:17:18 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */

/**
 * Test parser.
 */
public class INI_Parser_Test {

    /* File path to .ini/.properties file. */
    public static final String FILE_PATH = "./test.ini";

    /**
     * Program Entry.
     *
     * @param args : Argument vector.
     */
    public static final void main(final String[] args) {
        INI_Parser parser = new INI_Parser();
        parser.ReadINIFile(FILE_PATH);

        System.out.println("Version: " + parser.getProperty("VERSION"));
        System.out.println("Name: " + parser.getProperty("NAME"));
        System.out.println("Age: " + parser.getProperty("AGE"));
        System.out.println("Email: " + parser.getProperty("EMAIL"));
    }
}
