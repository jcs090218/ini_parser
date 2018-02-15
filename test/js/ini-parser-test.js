/**
 * $File: ini-parser-test.js $
 * $Date: 2018-02-12 18:04:21 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */

"use strict";


// File path to .ini/.properties file.
var FILE_PATH = "../test.ini";

/**
 * Program Entry Point.
 */
function main() {
  var in_data = readINIFile(FILE_PATH);

  console.log("Version: " + in_data["VERSION"]);
  console.log("Name: " + in_data["NAME"]);
  console.log("Age: " + in_data["Age"]);
  console.log("Email: " + in_data["Email"]);
}

// call it
main();
