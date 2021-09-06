/**
 * Merge Sort
 *
 * @file   sort/merge.h
 * @author maxrt101
 */

#ifndef _MERGE_H
#define _MERGE_H

#include <functional>
#include <algorithm>
#include <utility>
#include <chrono>
#include <vector>

#include "sort.h"

/**
 * Merge Sort - Merge
 *  
 * @param stats Sort statistics
 * @param compare Comparator for elements
 * @param begin Iterator that points to the begining of the array
 * @param end Iterator that points to the ending of the array
 */
template <typename Iter, typename Compare>
inline std::vector<typename Iter::value_type>
mergeSortMerge(SortStats& stats, Compare compare, Iter begin, Iter middle, Iter end) {
  std::vector<typename Iter::value_type> vec;
  vec.reserve(end - begin);

  Iter left(begin);
  Iter right(middle);

  while (left != middle && right != end) {
    vec.push_back(compare(*left, *right) ? *left++ : *right++);
    stats.comparisons_count++;
    stats.swaps_count++;
  }

  vec.insert(vec.end(), left, middle);
  vec.insert(vec.end(), right, end);

  return vec;
}

/**
 * Merge Sort
 *
 * @param stats Sort statistics
 * @param compare Comparator for elements
 * @param begin Iterator that points to the begining of the array
 * @param end Iterator that points to the ending of the array
 */
template <typename Iter, typename Compare>
inline void mergeSort(SortStats& stats, Compare compare, Iter begin, Iter end) {
  if (end - begin >= 2) {
    Iter middle = begin + (end - begin) / 2;
    
    mergeSort(stats, compare, begin, middle);
    mergeSort(stats, compare, middle, end);
    
    auto vec = mergeSortMerge(stats, compare, begin, middle, end);
    std::move(vec.begin(), vec.end(), begin);
  }
}

/**
 * Sorts a vector of integers using Merge Sort Algorithm
 * @param vec Vector to sort
 * @param order Sort order
 * @return sorting statistics
 */
template <typename T>
inline SortStats mergeSort(std::vector<T>& vec, SortOrder order) {
  SortStats stats;
  auto begin_time = std::chrono::system_clock::now();
  if (order == SortOrder::ASC) {
    mergeSort(stats, std::less_equal<T>(), vec.begin(), vec.end());
  } else if (order == SortOrder::DESC) {
    mergeSort(stats, std::greater_equal<T>(), vec.begin(), vec.end());
  }
  stats.execution_time = std::chrono::system_clock::now() - begin_time;
  return stats;
}

#endif
