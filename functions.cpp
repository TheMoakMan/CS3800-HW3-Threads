#include "functions.h"

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

