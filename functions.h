#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "ProtectedQueue.h"
#include <fstream>
#include <regex>
#include <mutex>

/*
  Takes integer values from a queue of word count logs and sums up the total
  number of occurances.
*/
int reducer(ProtectedQueue<int> & wLog, int numLogs);

/*
  Reads files from the file queue and, parses them for all occuranes of a target string,
  and updates the word count log with the number of occurances in each file.
*/
void mapper(ProtectedQueue<string> & fQueue, ProtectedQueue<int> & log, string target);

/*
  Reads a text file, line by line and counts the number of occurances of a target substring
  and returns the number of occurances.
  This function is called by the mapper function.
*/
int get_word_count(string & fName, string & tgt);

/*
  Uses substrings to find the number of occurances a target in a larger string.
  Called by the get_word_count function, and passed a single line from the text file. 
*/
int substr_word_count(string & source, string & substr);

/*
  Formats the input string to match criteria of assignment.
*/
string make_valid(string & target);

#endif
