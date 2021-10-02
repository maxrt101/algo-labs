#ifndef _DISCOUNT_H
#define _DISCOUNT_H

#include <string>
#include <vector>
#include <cstdint>

constexpr auto k_max_price_count = 10000;
constexpr auto k_max_price = 1000000000;
constexpr auto k_nth_price_for_discount = 3;
constexpr auto k_float_precision = 2;

/**
 */
struct DiscountData {
  std::vector<uint64_t> data;
  uint8_t discount; // %

  DiscountData() = default;
  /**
   */
  DiscountData(const std::string& filename);
};

#endif

