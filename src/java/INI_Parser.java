/**
 * $File: INI_Parser.java $
 * $Date: 2018-02-12 17:06:09 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Properties;

/**
 * Parser .ini/.properties file.
 */
public class INI_Parser {

    private Properties props = new Properties();

    public INI_Parser() {
        // empty..
    }

    /**
     * Read the .ini file and return it values.
     *
     * @param filePath : path to the .ini/.properties file.
     * @return Properties class.
     */
    public Properties ReadINIFile(final String filePath) {
        InputStreamReader fr;
        try {
            fr = new InputStreamReader(new FileInputStream(filePath), "UTF-8");
            props.load(fr);
            fr.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        return props;
    }

    /**
     * Get value/properties by keyword.
     *
     * @param keyword : keyword use to get value.
     * @return Return value.
     */
    public String getProperty(String keyword) {
        return props.getProperty(keyword);
    }
}
