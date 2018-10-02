#include <iostream>
#include <thread>
#include "functions.h"

using namespace std;

const string  DATA_FILE = "files.dat";

void read_file(string str, string &target, ProtectedQueue<int> & log);  //Rename to file_search()

int main()
{
  ProtectedQueue<string> fileQueue;       //Queue to hold the filenames from the DATA_FILE
  string fileName;               //Temporary string to hold name of a single file from DATA_FILE
  string target;                 //Target string to be searched for within text files.
  int wordCount = 0;
  int numLogs = 0;
  int threadCount = 0;
  ProtectedQueue<int> wordLog;

  cout << "Enter Target to Be Searched For: ";
  getline(cin, target, '\n');

  ifstream fileIn;
  fileIn.open(DATA_FILE);

  //Populate the file queue from the DATA_FILE
  while(getline(fileIn, fileName, '\n')){
    fileQueue.push(fileName);
  }

  numLogs = fileQueue.size();

  //thread * t_1 = new thread(mapper, ref(fileQueue), ref(wordLog), target);
  mapper(fileQueue, wordLog, target);
  
  /*
  int size = fileQueue.size();
  for(int i = 0; i < size; i++){
    read_file(fileQueue.pop(), target, wordLog);
  }
  */
 
  wordCount = reducer(wordLog, numLogs);
  cout << "Total Word Count for " << target << " is: " << wordCount << endl;
  
  //t_1->join();
  //delete t_1;

  fileIn.close();
  /*	
    1. Open data.dat and read in files in to queue.
    2. Read in word to find from user.
    3. Create Threads and pass the word finder function.
    4. Create 1 thread for each text document with no more then 4 threads active at once.
    
    Mapper Functions read from files. Reducer Functions (once mapper is done reading a file) adds up all their totals. 
    Think of each thread(mapper) depositing their "number" into a queue and the reducer takes from the queue and reads the values. 
    Need to be able to have a lock on who can access the queue at a time. As many mappers can add but once reducer comes in, no 
    mappers can deposit until reducer is done.

    Possible implementation: Mappers send a signal when finished to spawn a reducer thread that uses a mutex to lock the queue until he has taken
    his data element and processed it. 
    Could write a shell script to test the function, write a for loop and use diff to compare outputs until a difference occurs. :w

  */

  return 0;
}

void read_file(string str, string &target, ProtectedQueue<int> & log)
{
  cerr << "CALLED WITH: " << str << endl;

  string line_in;
  int count = 0;

  ifstream fin;
  fin.open(str);

  smatch t_match;
  regex t_find(target);
  
  while(getline(fin, line_in, '\n')){
      regex_search(line_in, t_match, t_find);
      count += t_match.size();
  }
  
 // log.push(count);

  fin.close();
}


