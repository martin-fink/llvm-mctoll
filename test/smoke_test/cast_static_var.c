// REQUIRES: system-linux
// RUN: clang -o %t %s -O0
// RUN: llvm-mctoll -d -I /usr/include/stdio.h %t
// RUN: clang -o %t1 %t-dis.ll
// RUN: %t1 2>&1 | FileCheck %s
// CHECK: *r = 0xaabbccdd
// CHECK-EMPTY

#include <stdio.h>

void access_static_var() {
  static unsigned char r[4];

  *(unsigned long *)r = 0xaabbccdd;

  printf("*r = 0x%x\n", *(unsigned int *)r);
}

int main() {
  access_static_var();
  return 0;
}
