#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "ProtectedQueue.h"
#include <fstream>
#include <regex>
#include <mutex>
#include <vector>

int reducer(ProtectedQueue<int> & wLog, int numLogs);
void mapper(ProtectedQueue<string> & fQueue, ProtectedQueue<int> & log, string target);
int get_word_count(string & str, string & tgt);
int vector_word_count(string & source, string & substr);
string build_regex(string & target);






#endif
