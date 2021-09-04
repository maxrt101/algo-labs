#ifndef _MERGE_H
#define _MERGE_H

#include <algorithm>
#include <chrono>
#include <vector>

#include "sort.h"

/**
 * Sorts a vector of integers using Merge Sort Algorithm
 * @param vec Vector to sort
 * @param order Sort order
 * @return sorting statistics
 */
template <typename T>
SortStats mergeSort(std::vector<T>& vec, SortOrder order) {
  SortStats stats;
  auto begin_time = std::chrono::system_clock::now();
  stats.execution_time = std::chrono::system_clock::now() - begin_time;
  return stats;
}

#endif
