#include <iostream>
#include <ctime>
#include <random>
#include <fstream>
#include <chrono>
#include "heapsort.h"
#include "insertionSort.h"


/**
 * Prints the array in format [1,2,...n] to cout
 * @tparam T Type of the array
 * @param array Array to be printed
 * @param size Size of the array
 */
template<typename T>
void printArr(T* array, int size){
  std::cout << "[";
  for(int i = 0; i < size; i++){
    std::cout << array[i] << ", ";
  }
  std::cout << "\b\b]\n";
}

/**
 * Prints the array in format [1,2,...n] to a file
 * @tparam T Type of the array
 * @param array Array to be printed
 * @param size Size of the array
 * @param filename Destination file
 */
template<typename T>
void printArr(T* array, int size, const std::string filename){
  std::ofstream file(filename);
  if (!file.is_open())
  {
    throw std::logic_error("Unable to open file");
  }
  file << array[0];
  for(int i = 1; i < size; i++){
    file << ", " << array[i];
  }
  file.close();
}

// TODO: Visualisation?

int main() {
  //Setup random
  std::mt19937 mt(time(nullptr));
  int RANDOM_MIN = -10000;
  int RANDOM_MAX = 10000;
  std::uniform_int_distribution<int> uid(RANDOM_MIN,RANDOM_MAX);
  // Generating the 10-element array
  const int SMALLARRSIZE = 10;
  int SmallArr[SMALLARRSIZE];
  for(int i = 0; i < SMALLARRSIZE; i++){
    SmallArr[i] = uid(mt);
  }
  std::cout << "Small array: ";
  printArr<int>(SmallArr, SMALLARRSIZE);

  // Sorting the small array
  std::cout << "Sorted by insertion sort:\n";
  std::cout << "Array: ";
  int* SmallArrSorted = insertionSort(SmallArr, SMALLARRSIZE);
  printArr<int>(SmallArrSorted, SMALLARRSIZE);

  for(int i = 0; i < SMALLARRSIZE; i++){
    SmallArr[i] = uid(mt);
  }
  std::cout << "Regenerated small array: ";
  printArr<int>(SmallArr, SMALLARRSIZE);

  std::cout << "Sorted by heapsort:\n";

  std::cout << "Array: ";
  SmallArrSorted = heapSort(SmallArr, SMALLARRSIZE);
  printArr<int>(SmallArrSorted, SMALLARRSIZE);


  // User array
  int size;
  std::cout << "Size:  ";
  std::cin >> size;
  int userArray[size];
  std::time_t time1 = time(nullptr);
  mt = std::mt19937(time1);
  for(int i = 0; i < size; i++){
    userArray[i] = uid(mt);
  }

  printArr<int>(userArray, size, ".\\out.txt");
  std::cout << "User-size array written to out.txt.\n";
  auto begin = std::chrono::steady_clock::now();
  int* userArrayHSorted = heapSort(userArray, size);
  auto now = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
  std::cout << "Cost of heap sort is " << elapsed.count() << " milliseconds" << std::endl;

  mt = std::mt19937(time1);
  for(int i = 0; i < size; i++){
    userArray[i] = uid(mt);
  }
  begin = std::chrono::steady_clock::now();
  int* userArrayISorted = insertionSort(userArray, size);
  now = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
  std::cout << "Cost of insertion sort is " << elapsed.count() << " milliseconds" << std::endl;

  printArr<int>(userArrayHSorted, size, ".\\outHeapSorted.txt");
  std::cout << "Heap-sorted array written to out.txt.\n";
  printArr<int>(userArrayISorted, size, ".\\outInsertionSorted.txt");
  std::cout << "Insertion-sorted array written to out.txt.\n";


  return 0;
}