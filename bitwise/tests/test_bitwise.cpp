#include <cstdlib>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Helper function to run the binary and capture its output
std::string RunBiary(const std::string &command) {
  char buffer[128];
  std::string result;
  FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    result += buffer;
  }
  pclose(pipe);
  return result;
}

TEST(SwapTest, TenTwenty) {
  // Run the binary with the '-s' flag and arguments '10 20'
  std::string output = RunBiary("../../bin/bitwise -s 10 20");

  // Define the expected output
  std::string expected_output = "Flag: s\n"
                                "Before: 10 20\n"
                                "After: 20 10\n";

  // Compare
  EXPECT_EQ(output, expected_output);
}
