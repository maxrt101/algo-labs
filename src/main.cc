/** 
 * Lab 1 from Algorithms and Data Structures Course
 *
 * Sorts an array supplied from command line. Supports
 * ascending and descending sorting orders.
 *
 * @file   main.cc
 * @author maxrt101
 */

#include <unordered_map>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include "utils.h"
#include "sort.h"
#include "sort/quick.h"
#include "sort/merge.h"
#include "sort/heap.h"

using SortFunction = std::function<SortStats(std::vector<int>&, SortOrder)>;

constexpr char g_array_delimiter = ',';
constexpr auto g_default_sort_type = "merge";
constexpr auto g_default_sort_order = "asc";

static std::unordered_map<std::string, SortFunction> g_sort_functions {
  {"quick", quickSort<int>},
  {"merge", mergeSort<int>},
  {"heap", heapSort<int>}
};

/**
 * Prints command line usage
 * @param executable_name Name of the executable (argv[0])
 */
void usage(const char* executable_name) {
  printf("Usage: %s [SORT_TYPE] [ORDER] ARRAY\n"
         "Options:\n"
         "  SORT_TYPE - Either quick, merge or heap (case insensitive) default - merge\n"
         "  ORDER     - Either asc or desc (case insensitive) default - asc\n"
         "  ARRAY     - Comma separated list of integers\n"
         "Note: you can't pass SORT_TYPE if ORDER isn't present\n",
         executable_name);
}

/**
 * Parses command line arguments and calles sort
 */
int main(int argc, char** argv) {
  // With sort type & order being optional, we can have either 2, 3 or 4 args
  if (argc < 2 || argc > 4) {
    usage(argv[0]);
    return 1;
  }

  SortOrder order;
  std::string order_str;
  std::string sort_type = g_default_sort_type;
  std::string input_arr_str;

  if (argc == 2) { // ./sort ARRAY
    order_str = g_default_sort_order;
    input_arr_str = argv[1];
  } else if (argc == 3) { // ./sort ORDER ARRAY
    order_str = to_lowercase(argv[1]);
    input_arr_str = argv[2];
  } else if (argc == 4) { // ./sort SORT_TYPE ORDER ARRAY
    sort_type = to_lowercase(argv[1]);
    order_str = to_lowercase(argv[2]);
    input_arr_str = argv[3];
  }

  // Check sort order
  if (order_str == "asc") {
    order = SortOrder::ASC;
  } else if (order_str == "desc") {
    order = SortOrder::DESC;
  } else {
    printf("Error: Invalid sort order '%s'\n", order_str.c_str());
    usage(argv[0]);
    return 1;
  }

  auto tokens_of_array = split(input_arr_str, g_array_delimiter);
  std::vector<int> sort_vec;

  // Convert array of string tokens to array of ints
  for (auto& str : tokens_of_array) {
    try {
      sort_vec.push_back(std::stoi(str));
    } catch (std::invalid_argument e) {
      printf("Error: '%s' cannot be converted to int\n", str.c_str());
      return 1;
    } catch (std::out_of_range e) {
      printf("Error: '%s' is out of range\n", str.c_str());
      return 1;
    }
  }

  SortStats stats;

  // Call sort function that corresponds to chosen sort_type
  try {
    stats = g_sort_functions.at(sort_type)(sort_vec, order);
  } catch (std::out_of_range e) {
    printf("Error: Invalid sort type '%s'\n", sort_type.c_str());
    usage(argv[0]);
    return 1;
  }

  // Print sort stats
  printf("%s Sort:\n"
         "Execution time: %llums\n"
         "Comparisons: %u\n"
         "Swaps: %u\n",
         capitalise(sort_type).c_str(),
         std::chrono::duration_cast<std::chrono::milliseconds>(stats.execution_time).count(),
         stats.comparisons_count,
         stats.swaps_count);

  // Print sorted vector
  for (auto element : sort_vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
  
  return 0;
}

