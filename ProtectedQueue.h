#ifndef PROTECTEDQUEUE_H
#define PROTECTEDQUEUE_H

#include <queue>
#include <mutex>

using namespace std;

template <typename T>
class ProtectedQueue
{
  private: 
    queue<T> records;
    mutex r_mu;

  public:
     void push(T & val);
     T pop();
     T front() {return records.front();}
     int size() {return records.size();}
};

#include "ProtectedQueue.hpp"
#endif
