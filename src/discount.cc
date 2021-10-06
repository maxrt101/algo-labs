/**
 * Discount Counter
 *
 * @file   discount.cc
 * @author maxrt101
 */

#include <string>
#include <fstream>
#include <iostream>

#include "discount.h"
#include "utils.h"

DiscountData::DiscountData(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.good()) {
    throw "Nonexistent File";
  }

  std::string prices;
  std::getline(file, prices);

  this->data = vec_stoull(split(prices, ' '));

  std::string discount_str;
  std::getline(file, discount_str);

  int discount = std::stoi(discount_str);
  this->discount = discount > 100 ? discount % 100 : discount;
}


