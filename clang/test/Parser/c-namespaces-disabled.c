// RUN: %clang_cc1 -std=c11 -fsyntax-only -verify %s
// expected-no-diagnostics

int namespace = 1;
int using = 2;

int main(void) { return namespace + using - 3; }
