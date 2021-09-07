/**
 * Heap Sort
 *
 * @file   sort/heap.h
 * @author maxrt101
 */

#ifndef _HEAP_H
#define _HEAP_H

#include <functional>
#include <algorithm>
#include <utility>
#include <chrono>
#include <vector>

#include "sort.h"

/**
 *
 */
template <typename Iter, typename Compare>
inline void heapSortHeapify(SortStats& stats, Compare compare, Iter begin, Iter end, Iter it) {
  Iter largest = it;
  Iter left = begin + 2 * (it-begin) + 1;
  Iter right = left + 1;

  if (left < end && compare(*left, *largest)) {
    largest = left;
  }
  
  if (right < end && compare(*right, *largest)) {
    largest = right;
  }

  if (largest != it) {
    std::iter_swap(largest, it);
    heapSortHeapify(stats, compare, begin, end, largest);
  }
}

/**
 *
 */
template <typename Iter, typename Compare>
inline void heapSort(SortStats& stats, Compare compare, Iter begin, Iter end) {
  for (Iter it = begin + (end-begin) / 2 - 1; it >= begin; it--) {
    heapSortHeapify(stats, compare, begin, end, it);
  }

  for (Iter it = end - 1; it > begin; it--) {
    std::iter_swap(begin, it);
    heapSortHeapify(stats, compare, begin, it, begin);
  }
}

/**
 * Sorts a vector of integers using Heap Sort Algorithm
 * @param vec Vector to sort
 * @param order Sort order
 * @return sorting statistics
 */
template <typename T>
inline SortStats heapSort(std::vector<T>& vec, SortOrder order) {
  SortStats stats;
  auto begin_time = std::chrono::system_clock::now();
  if (order == SortOrder::ASC) {
    heapSort(stats, std::less<T>(), vec.begin(), vec.end());
  } else if (order == SortOrder::DESC) {
    heapSort(stats, std::greater<T>(), vec.begin(), vec.end());
  }
  stats.execution_time = std::chrono::system_clock::now() - begin_time;
  return stats;
}

#endif
