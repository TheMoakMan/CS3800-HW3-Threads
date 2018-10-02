#include "functions.h"
#include <iostream>

int reducer(ProtectedQueue<int> & wLog, int numLogs)
{
  int sum = 0;
  
  while(numLogs > 0){  
    if(wLog.size() > 0){
      auto temp = wLog.pop();
      sum += temp;
      numLogs--;
    }
  }

  return sum;
}

void mapper(ProtectedQueue<string> & fQueue, ProtectedQueue<int> & log, string target)
{
  string file;
  int w_count;
  mutex q_lock;

  while(fQueue.size() > 0){
   try{
     file = fQueue.pop();
     w_count = get_word_count(file, target);
     cout << file << ":" << w_count << endl;
     log.push(w_count);
   }
   catch(...){}
  }
}

int get_word_count(string & str, string & tgt)
{
  string line_in;
  int count = 0;

  ifstream fin;
  fin.open(str);

  /*
  smatch t_match;
  regex t_find(tgt);

  while(getline(fin, line_in, '\n')){
    regex_search(line_in, t_match, t_find);
    count += t_match.size();
  }
  */

  while(getline(fin, line_in, '\n')){
    count += vector_word_count(str, tgt);
  }

  return count;
}

int vector_word_count(string & source, string & substr)
{
  vector<size_t> occurances;
  size_t pos = source.find(substr);

  while(pos != string::npos){
    occurances.push_back(pos);
    pos = source.find(substr, pos + substr.size());
  }
  
  return occurances.size();
}
string build_regex(string & target)
{
  string new_target;

  return new_target;
}