#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
T find_pivot(vector<T>&a, unsigned int left, unsigned int right) 
{
  unsigned int center = (left + right) / 2;
	
  if(a[center] < a[left]) swap(a[left], a[center]);
  if(a[right] < a[left]) swap(a[right], a[left]);
  if(a[right] < a[center]) swap(a[right], a[center]);

  return a[center];
}

template<typename T>
void insertion_sort(vector<T>&a, int left, int right)
{
  unsigned int j; 
	
  for(int p = left; p < right + 1; p++) 
  {
    T tmp = a[p];
    for(j = p; j > 0 && tmp < a[j-1]; j--)
      a[j] = a[j-1];
    a[j] = tmp;
  }
}

template<typename T>
void quicksorter(vector<T>&a, int left, int right)
{
  if(a.size() <= 1) return;
  if(left + 10 <= right)
  {
    T pivot = find_pivot(a, left, right);
		
    int i  = left;
    int j = right - 1;
        
    bool swapi = false;
    bool swapj = false;
        
    while(i < j) 
    {
      if(a[i] < pivot) i++;
      else swapi = true;
      if(pivot <= a[j]) j--;
      else swapj = true;
			
      if(swapi && swapj) swap (a[i], a[j]);
    }
    quicksorter(a, left, j);
    quicksorter(a, i, right); 
  }
  else insertion_sort(a, left, right);	
}

template<typename T>
void quicksort(vector<T>&a)
{
  quicksorter(a, 0, a.size() - 1);
}

#endif






/*
///////////////////
0 1 2 3 4 5 6 7 8 9
///////////////////

7 4 2 5 1 6 0 8 9 3 

left = 7
right = 3
center = 1

pivot = 3

1 4 2 5 3 6 0 8 9 7
  4         0       
1 0 2 5 3 6 4 8 9 7
      5 3
1 0 2 3 5 6 4 8 9 7

////////////////////////////////////////////////////
1 0 2 3               |||                5 6 4 8 9 7
////////////////////////////////////////////////////
left = 1                                 left = 5
right = 3                                right = 7 
center = 0                               center = 4

pivot = 1                                pivot = 5

1 0 2 3                                  5 6 4 8 9 7
                                           6 4
                                         5 4 6 8 9 7
///////////                              ///////////////
1 0 ||| 2 3                              5 4 ||| 6 8 9 7
///////////                              ///////////////
0 1 2 3                                  4 5                       6 8 9 7

                                                                   left = 6
                                                                   right = 7
                                                                   center = 8
                                                                   
                                                                   pivot = 7
                                                                   
                                                                   6 8 9 7
                                                                     8   7
                                                                   6 7 9 8
                                                                   ///////////
                                                                   6 7 ||| 9 8
                                                                   ///////////
                                                                   6 7 8 9


0 1 2 3 4 5 6 7 8 9
*/
