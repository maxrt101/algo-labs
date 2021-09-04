/**
 * Common things for all sort functions
 *
 * @file   sort.h
 * @author maxrt101
 */

#ifndef _SORT_H
#define _SORT_H

enum class SortOrder {
  ASC,
  DESC
};

struct SortStats {
  std::chrono::duration<float> execution_time;
  unsigned int comparisons_count = 0;
  unsigned int swaps_count = 0;
};

#endif
