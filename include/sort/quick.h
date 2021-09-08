/**
 * Quick Sort
 * The explanation of the idea behind quick sort is in
 * description of quickSort function.
 * Quick Sort Stats:
 *  Time Complexity:
 *   Worst: O(n^2)
 *   Best: O(n*log n)
 *  Space Complexity:
 *   O(log n)
 *
 * @file   sort/quick.h
 * @author maxrt101
 */

#ifndef _QUICK_H
#define _QUICK_H

#include <functional>
#include <algorithm>
#include <utility>
#include <chrono>
#include <vector>

#include "sort.h"

/**
 * Quick Sort - Partition
 *  Rearranges the array according to the partition point. It works by iterating
 *  through the array and comparing every element with a partiion (pivot) point
 *  (I selected the rightmost element to be a pivot point). If element is greted/less
 *  then the pivot element, the element gets swapped with previously marked element.
 * @param stats Sort statistics
 * @param compare Comparator for elements
 * @param begin Iterator that points to the begining of the array
 * @param end Iterator that points to the ending of the array
 * @return Iterator to pivot point
 */
template <typename Iter, typename Compare>
inline Iter quickSortPartition(SortStats& stats, Compare compare, Iter begin, Iter end) {
  Iter prev = begin;

  for (Iter it = begin; it != end; it++) {
    if (compare(*it, *end)) {
      if (*prev != *it) {
        std::iter_swap(prev, it);
        stats.swaps_count++;
      }
      prev++;
    }
    stats.comparisons_count++;
  }

  if (*prev != *end) {
    std::iter_swap(prev, end);
    stats.swaps_count++;
  }

  return prev;
}

/**
 * Quick Sort
 *  Quick Sort works by dividing the array into sub-arrays by selecting a pivot element.
 *  After selecting a pivot, elements of the array are rearranged in such a way,
 *  that elements with values less than pivot's, are moved to the left side, and
 *  elements that values greater than pivot's, are moved to the right. Left and
 *  right arrays are divided in the same way. In the end we have a sorted array.
 * @param stats Sort statistics
 * @param compare Comparator for elements
 * @param begin Iterator that points to the begining of the array
 * @param end Iterator that points to the ending of the array
 */
template <typename Iter, typename Compare>
inline void quickSort(SortStats& stats, Compare compare, Iter begin, Iter end) {
  if (begin < end) {
    Iter partition_point = quickSortPartition(stats, compare, begin, end);
    quickSort(stats, compare, begin, partition_point - 1);
    quickSort(stats, compare, partition_point, end);
  }
}

/**
 * Sorts a vector of integers using Quick Sort Algorithm
 * @param vec Vector to sort
 * @param order Sort order
 * @return sorting statistics
 */
template <typename T>
inline SortStats quickSort(std::vector<T>& vec, SortOrder order) {
  SortStats stats;
  auto begin_time = std::chrono::system_clock::now();
  if (order == SortOrder::ASC) {
    quickSort(stats, std::less_equal<T>(), vec.begin(), vec.end()-1);
  } else if (order == SortOrder::DESC) {
    quickSort(stats, std::greater_equal<T>(), vec.begin(), vec.end()-1);
  }
  stats.execution_time = std::chrono::system_clock::now() - begin_time;
  return stats;
}

#endif
