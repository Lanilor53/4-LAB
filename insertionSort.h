//
// Created by Lenovo on 31.01.2020.
//

#ifndef RPM_LABS_INSERTIONSORTNEW_H
#define RPM_LABS_INSERTIONSORTNEW_H

/**
 * Sorts an array using insertion sort algorithm
 * @tparam T Type of the array
 * @param array Array to be sorted
 * @param size Size of the array
 * @return Sorted array
 */
template<typename T>
T* insertionSort(T array[], int size){
  for(int i = 1; i < size; i++){
    if(array[i-1]<array[i]) {
    for(int j = i-1; j >= 0; j--){
      if(array[j]<array[j+1]) {
        std::swap(array[j], array[j+1]);
      }
    }
    }
  }

  return array;
}



#endif //RPM_LABS_INSERTIONSORTNEW_H
