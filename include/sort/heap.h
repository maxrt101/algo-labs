/**
 * Heap Sort
 * The explanation of Heap Sort algorithm is in the comments fot functions below.
 * Heap Sort Stats:
 *  Time Complexity:
 *   O(n*log n)
 *  Space Complexity:
 *   O(n)
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
 * Heap Sort - Heapify
 *  Makes max heaps out of tree leafs. Runs recursively until there are
 *  no more larger elements or no more elements at all.
 *  So, heapify works by getting iterators for child elements of `it`,
 *  than cheking if any of the child elements is greater/less (depends on sort
 *  order), if one of the child elements is greater or less, it gets swapped
 *  wuth `it`. 
 * @param stats Sort statistics
 * @param compare Comparator for elements
 * @param begin Iterator that points to the begining of the array
 * @param end Iterator that points to the ending of the array
 * @param it Iterator for previous largest element
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
    stats.swaps_count++;
    heapSortHeapify(stats, compare, begin, end, largest);
  }

  stats.comparisons_count++;
}

/**
 * Heap Sort
 *  Implements Heap Sort Algorithm. It works by representing array as a heap,
 *  which is a complete binary tree (and all nodes are greater(or less) than their child nodes)
 *  so that for ith element - 2*i+1 and 2*i+2 are child nodes of that element.
 *  So we have a flattened out binary tree, Next up - we run heapSortHeapify on
 *  each sub tree to get a max heap. Repeat until sorted.
 * @param stats Sort statistics
 * @param compare Comparator for elements
 * @param begin Iterator that points to the begining of the array
 * @param end Iterator that points to the ending of the array
 */
template <typename Iter, typename Compare>
inline void heapSort(SortStats& stats, Compare compare, Iter begin, Iter end) {
  for (Iter it = begin + (end-begin) / 2 - 1; it >= begin; it--) {
    heapSortHeapify(stats, compare, begin, end, it);
  }

  for (Iter it = end - 1; it > begin; it--) {
    std::iter_swap(begin, it);
    stats.swaps_count++;
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
    heapSort(stats, std::greater<T>(), vec.begin(), vec.end());
  } else if (order == SortOrder::DESC) {
    heapSort(stats, std::less<T>(), vec.begin(), vec.end());
  }
  stats.execution_time = std::chrono::system_clock::now() - begin_time;
  return stats;
}

#endif
