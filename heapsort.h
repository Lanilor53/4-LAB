//
// Created by Lenovo on 31.01.2020.
//

#ifndef RPM_LABS_HEAPSORTNEW_H
#define RPM_LABS_HEAPSORTNEW_H

/**
 * Used to keep heap in order
 * @param array Heap array
 * @param size Heap size
 * @param root Heap root
 */
void heapify(int *array, int size, int root) {
  int largest = root;
  int left = 2*root + 1;
  int right = 2*root + 2;
  if (left < size && array[left] > array[largest]) {
    largest = left;
  }
  if (right < size && array[right] > array[largest]) {
    largest = right;
  }
  if (largest != root)
  {
    std::swap(array[root], array[largest]);
    heapify(array, size, largest);
  }
}

/**
 * Sorts an array using heapsort algorithm
 * @tparam T Array type
 * @param array Array to be sorted
 * @param size Array size
 * @return Sorted array
 */
template<typename T>
T* heapSort(T* array, int size) {
  // Create heap
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }

  T* result = array;
  for (int j = size-1; j >= 0; j--){
    for (int i = j / 2 - 1; i >= 0; i--) {
      heapify(result+(size-j), j, i);
    }
  }

  return result;
}

#endif //RPM_LABS_HEAPSORTNEW_H
