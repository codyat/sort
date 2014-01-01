#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

template<typename T>
void merge(vector<T>&a, vector<T>&tmp, int left, int center, int right)
{
  int left_end = center - 1;
  int temp = left;
  int elements = right - left + 1;
	
  while(left <= left_end && center <= right) 
  {
    if(a[left] <= a[center]) 
      tmp[temp++] = a[left++];
    else
      tmp[temp++] = a[center++];
  }	
  while(left <= left_end) 
    tmp[temp++] = a[left++];
  while(center <= right) 
    tmp[temp++] = a[center++];	
  for(int i = 0; i < elements; ++i, --right)
    a[right] = tmp[right];
} 

template<typename T>
void mergesorter(vector<T>&a, vector<T>&tmp, int left, int right)
{
  if(left < right)
  {
    int center = (left + right) / 2;
    mergesorter(a, tmp, left, center);
    mergesorter(a, tmp, center + 1, right);
    merge(a, tmp, left, center + 1, right);
  }
}

template<typename T>
void mergesort(vector<T> & a)
{
  vector<T>tmp(a.size());
  mergesorter(a, tmp, 0, a.size() - 1);
}

#endif
