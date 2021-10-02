/**
 * Main file 
 *
 * @file   main.cc
 * @author maxrt101
 */

#include <mrt/args/args.h>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "discount.h"
#include "utils.h"

template <typename T>
static void die(const T& val) {
  std::cout << "ERROR: " << val << std::endl;
  exit(1);
}

int main(const int argc, const char ** argv) {
  auto args = mrt::args::Parser("Lab 3 Discount", {
    {"infile", 'V', {"-i", "--infile"}, "Input file name"},
    {"outfile", 'V', {"-o", "--outfile"}, "Output file name"},
    {"interactive", 'F', {"--interactive"}, "Interactive mode"}
  }).parse(argc, argv);

  std::string infile = args.getFirstOr("infile", "discnt.in");
  std::string outfile = args.getFirstOr("outfile", "discnt.out");
  
  DiscountData data;

  try {
    if (args.exists("interactive")) {
      std::string input;
      std::cout << "Prices: ";
      std::getline(std::cin, input);
      data.data = vec_stoull(split(input, ' '));
      std::cout << "Discount: ";
      std::getline(std::cin, input);
      data.discount = std::stoi(input) % 100;
    } else {
      data = DiscountData(infile);
    }
  } catch (const char* s) {
    die(s);
  } catch (const std::exception& e) {
    die(e.what());
  }

  if (data.data.size() > k_max_price_count) {
    die("Can't have more then " + std::to_string(k_max_price_count) + " prices");
  }

  std::sort(data.data.begin(), data.data.end());
  
  auto begin = data.data.begin();
  auto end = data.data.end()-1;

  double discount = data.discount / 100.0; // Get percentage in decimals
  double sum = 0.0;

  while (begin <= end) {
    auto distance = (begin - data.data.begin()) + (data.data.end() - end);
    if (distance && (distance % k_nth_price_for_discount) == 0) {
      sum += static_cast<double>(*end--) * discount;
    } else {
      sum += *begin++;
    }
  }

  if (args.exists("interactive")) {
    std::cout << "Result: " << std::fixed << std::setprecision(k_float_precision) << sum << std::endl;
  } else {
    std::ofstream file(outfile);
    if (!file.good()) {
      die("Cannot open file " + outfile);
    }
    file << std::fixed << std::setprecision(k_float_precision) << sum;
  }

  return 0;
}

