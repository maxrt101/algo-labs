/**
 * Tests
 *
 * @file   test.cc
 * @author maxrt101
 */

#include <mrt/test/framework.h>
#include <mrt/args/args.h>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

constexpr auto k_input_file  = "discount_test.in";
constexpr auto k_output_file = "discount_test.out";

struct TestResult {
  std::string input;
  std::string output;
};

static const std::vector<TestResult> g_test_results {
  {"50 20 30 17 100\n10", "207.00"},
  {"1 2 3 4 5 6 7\n100", "15.00"},
  {"1 1 1\n33", "2.67"}
};

int main(const int argc, const char ** argv) {
  auto args = mrt::args::Parser("Lab 3: Tests", {
    {"bin", 'P', {}, "Discount binary path"},
  }).parse(argc, argv);

  if (!args.exists("bin")) {
    std::cout << "Error: You must supply binary name" << std::endl;
    return -1;
  }

  const std::string binary = args.getFirst("bin");

  mrt::test::TestFramework testFramework;

  for (int i = 0; i < g_test_results.size(); i++) {
    testFramework.addTest({"Discount Test " + std::to_string(i),
      [i, &binary]() -> bool {
        {
          std::ofstream in_file(k_input_file);
          if (!in_file.good()) return false;
          in_file << g_test_results[i].input;
        }

        std::string command = binary + " -i " + k_input_file + " -o " + k_output_file;
        system(command.c_str());

        std::ifstream in_file(k_output_file);
        if (!in_file.good()) return false;
        std::string output;
        std::getline(in_file, output);
 
        return output == g_test_results[i].output;
      }
    });
  }

  bool result = testFramework.run(true);

  std::string rm_command = std::string("rm ") + k_input_file + " " + k_output_file;
  system(rm_command.c_str());

  return !result;
}

