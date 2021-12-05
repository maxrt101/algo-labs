#include "kmp.h"

#include <mrt/args/args.h>
#include <mrt/console/colors.h>
#include <mrt/test/framework.h>

int main(int argc, const char ** argv) {

  auto args = mrt::args::Parser("Lab 7: KMP. Run with -t or -s and -u", {
    {"str",  'V', {"-s", "--str"},  "String to search in"},
    {"sub",  'V', {"-u", "--sub"},  "Substring to search for"},
    {"test", 'F', {"-t", "--test"}, "Run Tests"}
  }).parse(argc, argv);

  if (args.exists("test")) {
    mrt::test::TestFramework testFramework;

    testFramework.addTest({"Test 1", []() -> mrt::test::Result {
      std::vector<int64_t> expected = {3};

      return {expected == kmp("abcabcd", "abcd"), ""};
    }});
    
    testFramework.addTest({"Test 2", []() -> mrt::test::Result {
      std::vector<int64_t> expected = {0};

      return {expected == kmp("abcd", "abcd"), ""};
    }});
    
    testFramework.addTest({"Test 3", []() -> mrt::test::Result {
      std::vector<int64_t> expected = {0, 6};

      return {expected == kmp("abcdefabc", "abc"), ""};
    }});

    testFramework.addTest({"Test 4", []() -> mrt::test::Result {
      std::vector<int64_t> expected = {6};

      return {expected == kmp("abxabcabcaby", "abcaby"), ""};
    }});
    testFramework.run(true);
  } else if (args.exists("str") && args.exists("sub")) {
    auto res = kmp(args.getFirst("str"), args.getFirst("sub"));
    std::cout << "Result: ";
    for (const auto& i : res) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  } else {
    std::cerr << mrt::console::RED << "ERROR: " << mrt::console::RESET
              << "Invalid arguments: run '" << argv[0] << " -h' for usage" << std::endl;
    return 1;
  }


  return 0;
}

