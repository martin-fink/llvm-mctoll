// REQUIRES: system-linux
// RUN: clang -O1 -o %t %s
// RUN: llvm-mctoll -d -I /usr/include/stdio.h %t
// RUN: clang -o %t1 %t-dis.ll
// RUN: %t1 2>&1 | FileCheck %s
// CHECK: 0.5
// CHECK: 3
// CHECK: 1.5
// CHECK-EMPTY

#include <stdio.h>

double get_first(double a, int i, double b) {
  return a;
}

int get_second(double a, int i, double b) {
  return i;
}

double get_third(double a, int i, double b) {
  return b;
}

int main() {
  double a = get_first(0.5, 3, 1.5);
  printf("%.1f\n", a);

  int b = get_second(0.5, 3, 1.5);
  printf("%d\n", b);

  double c = get_third(0.5, 3, 1.5);
  printf("%.1f\n", c);

  return 0;
}
