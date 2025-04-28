#include "hamming.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

extern "C" int main(int argc, char *argv[]);

std::string captureStdout(std::function<void()> func) {
  int pipefd[2];
  pipe(pipefd);

  int saved_stdout = dup(STDOUT_FILENO);
  dup2(pipefd[1], STDOUT_FILENO);
  close(pipefd[1]);

  func();

  dup2(saved_stdout, STDOUT_FILENO);
  close(saved_stdout);

  std::vector<char> buffer(4096);
  ssize_t count = read(pipefd[0], buffer.data(), buffer.size());
  close(pipefd[0]);

  return std::string(buffer.data(), count);
}

TEST(HammingBin, CorrectOutput) {
  const char *argv[] = {"hamming", "13", nullptr};
  int argc = 2;

  auto output = captureStdout([&]() { main(argc, const_cast<char **>(argv)); });

  EXPECT_NE(output.find("Talet 13"), std::string::npos);
  EXPECT_NE(output.find("1101"), std::string::npos);
  EXPECT_NE(output.find("3 ettor"), std::string::npos);
}
