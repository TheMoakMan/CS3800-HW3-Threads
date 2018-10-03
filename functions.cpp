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

  while(getline(fin, line_in, '\n')){
    count += vector_word_count(line_in, tgt);
  }

  return count;
}

int vector_word_count(string & source, string & substr)
{
  int count = 0;
  size_t pos = source.find(substr, 0);

  while(pos != std::string::npos){
    count++;
    pos = source.find(substr, pos + substr.size());
  }
  
  return count;
}

string make_valid(string & target)
{
  string new_target = " ";
  new_target.append(target);
  new_target.append(" ");

  return new_target;
}
