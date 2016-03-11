#include <cstdlib>      // provides: rand, RAND_MAX
#include <iostream>     // provides: cout
#include <algorithm>    // provides: swap
#include <vector>

#include "Timer.h"
#include "Heapsort.h"
#include "Mergesort.h"
#include "Quicksort.h"

using namespace std;

// This function should randomize the order of the numbers in the vector 
void permute(vector<size_t>&v)
{
  for(size_t i = 0; i != v.size() - 1; ++i)
  {
    size_t p = rand() / (RAND_MAX / (v.size() - i) + 1);
    swap(v[i], v[i + p]);
  }
}

int main()
{
  // Create the vectors: 1 for permuting and the the second for sorting
  // That way each sorting method is sorting the same permutation
  Timer timer;
  size_t size = 5000000;
  vector<size_t> numbers(size);
  vector<size_t> backup;

  // Initialize the vector with all numbers from 0 to size
  for(size_t i = 0; i < size; ++i) numbers[i] = i;
  permute(numbers);
 
  // Make a backup of the vector
  backup = numbers;
  
  cout << "Sorting a list of 5,000,000 members of size_t: \nSample of the unordered vector: ";
  for(int i = 0; i < 15; i++) cout << numbers[i] << " "; 

  // Running the Heapsort method
  cout << "...\n\nHeapsort: ";
  timer.start();
  heapsort(numbers);
  timer.stop();
  cout << timer.elapsedTime() << " seconds" << endl;   
  cout << "Sample of the ordered vector: ";
  for(int i = 0; i < 15; i++) cout << numbers[i] << " "; 

  // Restoring the original permutation
  numbers = backup;

  // Running the Mergesort method
  cout << "...\n\nMergesort: ";
  timer.start();
  mergesort(numbers);
  timer.stop();
  cout << timer.elapsedTime() << " seconds" << endl;  
  cout << "Sample of the ordered vector: ";
  for(int i = 0; i < 15; i++) cout << numbers[i] << " "; 
  
  // Restoring the original permutation
  numbers = backup;

  // Running the Quicksort method
  cout << "...\n\nQuicksort: ";
  timer.start();
  quicksort(numbers);
  timer.stop();
  cout << timer.elapsedTime() << " seconds" << endl;    
  cout << "Sample of the ordered vector: ";
  for(int i = 0; i < 15; i++) cout << numbers[i] << " "; 
  cout << "...\n\n\n";

  return 0;
}
