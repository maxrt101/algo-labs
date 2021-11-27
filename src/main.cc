/**
 * Indiana Jones Tests
 * 
 * @file   main.cc
 * @author maxrt101
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <mrt/test/framework.h>
#include <mrt/args/args.h>

#include "utils.h"
#include "ijones.h"

template <typename T>
[[noreturn]] static void die(const T& val) {
  std::cout << "ERROR: " << val << std::endl;
  exit(1);
}

int main(int argc, const char ** argv) {
  auto args = mrt::args::Parser("Lab 6: Indiana Jones", {
    {"infile",  'V', {"-i", "--infile"},  "Input file name"},
    {"outfile", 'V', {"-o", "--outfile"}, "Output file name"},
    {"test",    'F', {"-t", "--test"},    "Run Tests"}
  }).parse(argc, argv);

  if (args.exists("test")) {
    mrt::test::TestFramework testFramework;

    testFramework.addTest({"Test 1", []() -> bool {
      std::vector<std::string> input {
        "aaa",
        "cab",
        "def"
      };

      return ijones(input) == 5;
    }});

    testFramework.addTest({"Test 2", []() -> bool {
      std::vector<std::string> input {
        "abcdefaghi"
      };

      return ijones(input) == 2;
    }});

    testFramework.addTest({"Test 3", []() -> bool {
      std::vector<std::string> input {
        "aaaaaaa",
        "aaaaaaa",
        "aaaaaaa",
        "aaaaaaa",
        "aaaaaaa",
        "aaaaaaa"
      };

      return ijones(input) == 201684;
    }});

    testFramework.run(true);
  } else {
    try {
      auto input = loadFromFile(args.getFirstOr("infile", kInFile));
      std::ofstream file(args.getFirstOr("outfile", kOutFile));
      file << std::to_string(ijones(input));
    } catch (const char* msg) {
      die(msg);
    } catch (const std::exception& e) {
      die(e.what());
    }
  }

  return 0;
}
