#include <cstdlib>
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

// Helper function to run the binary and capture its output
std::string RunBinary(const std::string &binary, const std::string &flag,
                      const std::vector<std::string> &args) {
  std::string command = binary + " " + flag;
  for (const auto &arg : args) {
    command += " " + arg;
  }
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

const std::string binary_path = BINARY_PATH; // Defined in CMake
                                             //
TEST(SwapTest, TenTwenty) {
  std::string flag = "-s";
  std::vector<std::string> args = {"10", "20"};
  // Run the binary with the '-s' flag and arguments '10 20'
  std::string output = RunBinary(binary_path, flag, args);

  // Define the expected output
  std::string expected_output = "Flag: s\n"
                                "Before: 10 20\n"
                                "After: 20 10\n";
  // Compare
  EXPECT_EQ(output, expected_output);
}

TEST(SwapTest, FifteenForty) {
  std::string flag = "-s";
  std::vector<std::string> args = {"15", "40"};
  // Run the binary with the '-s' flag and arguments '10 20'
  std::string output = RunBinary(binary_path, flag, args);

  // Define the expected output
  std::string expected_output = "Flag: s\n"
                                "Before: 15 40\n"
                                "After: 40 15\n";
  // Compare
  EXPECT_EQ(output, expected_output);
}
