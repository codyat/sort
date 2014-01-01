#include <cstdlib>      // provides: rand, RAND_MAX
#include <iostream>     // provides: cout
#include <algorithm>    // provides: swap
#include <vector>

#include "Timer.h"
#include "Heapsort.h"
#include "Mergesort.h"
#include "Quicksort.h"

using namespace std;

void permute(vector<size_t> & a)
{
  for(size_t i = 0; i != a.size() - 1; ++i)
  {
    size_t p = rand() / (RAND_MAX / (a.size() - i) + 1);
    swap(a[i], a[i + p]);
  }
}

int main()
{
  vector<size_t> a;
    
  Timer timer;
  size_t size = 5000000;
  vector<size_t> b(size);
  for(size_t i = 0; i < size; ++i) b[i] = i;
  permute(b);
  a = b;
  
  cerr << "Sorting a list of 5,000,000 members of size_t: \nSample of the unordered vector: ";
  for(int i = 0; i < 15; i++) cerr << a[i] << " "; 

  cerr << "...\n\nHeapsort: ";
  timer.start();
  heapsort(b);
  timer.stop();
  cerr << timer.elapsedTime() << " seconds" << endl;   
  cerr << "Sample of the ordered vector: ";
  for(int i = 0; i < 15; i++) cerr << b[i] << " "; 
    
  b = a;
  cerr << "...\n\nMergesort: ";
  timer.start();
  mergesort(b);
  timer.stop();
  cerr << timer.elapsedTime() << " seconds" << endl;  
  cerr << "Sample of the ordered vector: ";
  for(int i = 0; i < 15; i++) cerr << b[i] << " "; 
  
  b = a;
  cerr << "...\n\nQuicksort: ";
  timer.start();
  quicksort(b);
  timer.stop();
  cerr << timer.elapsedTime() << " seconds" << endl;    
  cerr << "Sample of the ordered vector: ";
  for(int i = 0; i < 15; i++) cerr << b[i] << " "; 
  cerr << "...\n\n\n";

  return 0;
}
