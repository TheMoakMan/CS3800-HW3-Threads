/*
  Programmer: Evan Moak
  Assignment: CS3800 HW3 (Threads)
  Date:       10-2-2018
*/



#include <iostream>
#include <thread>
#include "functions.h"

using namespace std;

const string  DATA_FILE = "files.dat";
const int MAX_THREADS = 4;


int main()
{
  ProtectedQueue<string> fileQueue;       //Queue to hold the filenames from the DATA_FILE
  string fileName;                        //Temporary string to hold name of a single file from DATA_FILE
  string target;                          //Target string to be searched for within text files.
  int wordCount = 0;  
  int numLogs = 0;
  int threadCount = 0;
  ProtectedQueue<int> wordLog;

  cout << "Enter Target to Be Searched For: ";
  getline(cin, target, '\n');
  target = make_valid(target);

  ifstream fileIn;
  fileIn.open(DATA_FILE);

  //Populate the file queue from the DATA_FILE
  while(getline(fileIn, fileName, '\n')){
    fileQueue.push(fileName);
  }

  //Create an array of thread Pointers and allocate mapper threads.
  thread * threadLog[MAX_THREADS];

  numLogs = fileQueue.size();
  if(numLogs > 0 && numLogs < MAX_THREADS){
    for(int i = 0; i < numLogs; i++)
      threadLog[i] = new thread(mapper, ref(fileQueue), ref(wordLog), target);
  }
  else{
    for(int i = 0; i < MAX_THREADS; i++)
      threadLog[i] = new thread(mapper, ref(fileQueue), ref(wordLog), target);
  }
 
  //Call reducer function to count total number of instances.
  wordCount = reducer(wordLog, numLogs);
  cout << "Total Word Count for " << target << " is: " << wordCount << endl;
  
  for(int i = 0; i < MAX_THREADS; i++){
    threadLog[i]->join();
    delete threadLog[i];
  }

  fileIn.close();

  return 0;
}


