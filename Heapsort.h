#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>

using namespace std;

// This function calculates the left child 
int left_child(int current) 
{
  return 2 * current + 1;
}

// 
template<typename T>
void percolate_down(vector<T>&v, int current, int n)
{
  int child;
  T tmp;
  
  for(tmp = v[current]; left_child(current) < n; current = child)
  {
    child = left_child(current);
    if(child != n - 1 && v[child] < v[child + 1]) 
      child++;
    if(tmp < v[child]) 
      v[current] = v[child];
    else break;
  } 
  v[current] = tmp;  
}

//
template<typename T>
void heapsort(vector<T>&v)
{
  for(int i = v.size() / 2; i >= 0; i--)
    percolate_down(v, i, v.size());
  for(int j = v.size() - 1; j > 0; j--) 
  {
    swap(v[0], v[j]);
    percolate_down(v, 0, j);
  }
}

#endif
