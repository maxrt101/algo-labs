/**
 * Knuth–Morris–Pratt algorithm
 *
 * @file   kmp.h
 * @author maxrt101
 */
#ifndef _KMP_H
#define _KMP_H

#include <cstdint>
#include <vector>
#include <string>

/**
 * Returns the index of sought `substring` string in searched `input` string
 * Returns -1 if `substring` can't be found
 */
std::vector<int64_t> kmp(const std::string& input, const std::string& substring);

#endif
