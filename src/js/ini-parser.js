/**
 * $File: ini-parser.js $
 * $Date: 2018-02-12 17:59:52 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2018 by Shen, Jen-Chieh $
 */

"use strict";

/*
 * References:
 * @url https://gist.github.com/Arahnoid/9925725
 */


/**
 * Read a .ini/.properties file.
 *
 * TODO(jenchieh): currently only work in NodeJS environment.
 *
 * @param { string } filePath : file path to ini.
 */
function readINIFile(filePath) {
  // dictionary object.
  var ini_data = {};

  var txtFile = new File(filePath);
  txtFile.open("r");

  while (!txtFile.eof) {
    var line = txtFile.readln();

    if (isCommentLine(line))
      continue;

    var keyword = line.split('=')[0];
    var value = line.split('=')[1];
    ini_data[keyword] = value;
  }

  return ini_data;
}

/**
 * Check if line a comment line.
 * @param { string } line : line to check.
 * @return { bool } : true, is comment line. false, is data line.
 */
function isCommentLine(line) {
  for (var index = 0;
       index < line.length;
       ++index) {
    var ch = line.charAt(index);

    if (ch != ' ' && ch != '#')
      return false;

    if (ch == '#')
      return true;
  }

  return false;
}
