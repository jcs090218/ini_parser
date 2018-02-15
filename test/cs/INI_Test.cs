/**
 * $File: INI_Test.cs $
 * $Date: 2018-02-12 02:39:19 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */
using System;
using System.Collections.Generic;


/// <summary>
/// Main test file.
/// </summary>
public class INI_Test
{
    /// <summary>
    /// Where .ini data store.
    /// </summary>
    private Dictionary<string, string> ini_data = new Dictionary<string, string>();

    private static string INI_FILE_PATH = "../../../../../../test/test.ini";

    public INI_Test()
    {
        // empty..
    }

    /// <summary>
    /// Run the test.
    /// </summary>
    public void run()
    {
        ini_data = INI_Parser.ReadINIFile(INI_FILE_PATH);

        Console.WriteLine("Version: " + ini_data["VERSION"]);
        Console.WriteLine("Name: " + ini_data["NAME"]);
        Console.WriteLine("Age: " + ini_data["AGE"]);
        Console.WriteLine("Email: " + ini_data["EMAIL"]);
    }

}
