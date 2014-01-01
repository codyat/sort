#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>

using namespace std;

//function that calculates the left child 
int left_child(int current) 
{
  return 2 * current + 1;
}

//
template<typename T>
void percolate_down(vector<T>&a, int current, int n)
{
  int child;
  T tmp;
  
  for(tmp = a[current]; left_child(current) < n; current = child)
  {
    child = left_child(current);
    if(child != n - 1 && a[child] < a[child + 1]) 
      child++;
    if(tmp < a[child]) 
      a[current] = a[child];
    else break;
  } 
  a[current] = tmp;  
}

//
template<typename T>
void heapsort(vector<T>&a)
{
  for(int i = a.size() / 2; i >= 0; i--)
    percolate_down(a, i, a.size());
  for(int j = a.size() - 1; j > 0; j--) 
  {
    swap(a[0], a[j]);
    percolate_down(a, 0, j);
  }
}

#endif
