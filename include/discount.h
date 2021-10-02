/**
 * Discount Counter Definitions
 *
 * @file   discount.h
 * @author maxrt101
 */

#ifndef _DISCOUNT_H
#define _DISCOUNT_H

#include <string>
#include <vector>
#include <cstdint>

constexpr auto k_max_price_count = 10000;         // How much prices can there be
constexpr auto k_max_price = 1000000000;          // Max price value
constexpr auto k_nth_price_for_discount = 3;      // At what place in the prices queue, the discount is applied
constexpr auto k_float_precision = 2;             // How much decimal places there are in the sum
constexpr auto k_default_infile  = "discnt.in";   // Default input file
constexpr auto k_default_outfile = "discnt.out";  // Default output file

/**
 * Represents data, needed by application
 */
struct DiscountData {
  std::vector<uint64_t> data;
  uint8_t discount; // %

  DiscountData() = default;

  /**
   * Constructs the struct from the file
   * File structure:
   * 1st line - list of prices (space separated)
   * 2nd line - discount percentage
   */
  DiscountData(const std::string& filename);
};

#endif

