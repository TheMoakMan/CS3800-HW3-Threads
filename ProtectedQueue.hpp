template <typename T> 
void ProtectedQueue<T>::push(T & val)
{
  lock_guard<mutex> guard(r_mu);
  records.push(val);
}

template <typename T>
T ProtectedQueue<T>::pop()
{
  lock_guard<mutex> guard(r_mu);
  T temp = records.front();
  records.pop();

  return temp;
}
