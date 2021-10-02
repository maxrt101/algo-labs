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

  std::string discount;
  std::getline(file, discount);

  this->discount = std::stoi(discount) % 100;
}


