// REQUIRES: system-linux
// RUN: clang -o %t %s
// RUN: llvm-mctoll -d -I /usr/include/stdio.h %t
// RUN: clang -o %t1 %t-dis.ll
// RUN: %t1 2>&1 | FileCheck %s
// CHECK: Hello world! 0.500000

#include <stdio.h>

int main(int argc, char **argv) {
  printf("Hello world! %f\n", 0.5);
  printf("Hello world! %d, %f\n", 1, 0.5);
  return 0;
}
