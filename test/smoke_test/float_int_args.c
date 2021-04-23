// REQUIRES: system-linux
// RUN: clang -o %t %s
// RUN: llvm-mctoll -d -I /usr/include/stdio.h %t
// RUN: clang -o %t1 %t-dis.ll
// RUN: %t1 2>&1 | FileCheck %s
// CHECK: Returned first arg
// CHECK: Returned second arg
// CHECK: Returned third arg
// CHECK-EMPTY


#include <stdio.h>

double return_third(double a, int i, double b) {
  return b;
}

int return_second(double a, int i, double b) {
  return i;
}

double return_first(double a, int i, double b) {
  return a;
}

int main() {
  double a = return_first(0.5, 1, 1.5);
  if (a == 0.5) {
    printf("Returned first arg\n");
  } else {
    printf("Did not return first arg\n");
  }

  int b = return_second(0.5, 1, 1.5);
  if (b == 1) {
    printf("Returned second arg\n");
  } else {
    printf("Did not return second arg\n");
  }

  double c = return_third(0.5, 1, 1.5);
  if (c == 1.5) {
    printf("Returned third arg\n");
  } else {
    printf("Did not return third arg\n");
  }

  return 0;
}
