// RUN: %clang_cc1 -std=c11 -fc-namespaces -fsyntax-only -verify %s

namespace A {
  typedef int T; // expected-note {{candidate found by name lookup is 'A::T'}}
  int f(int); // expected-note {{previous declaration is here}}
  int f(double); // expected-error {{conflicting types for 'f'}}
}
namespace B {
  typedef long T; // expected-note {{candidate found by name lookup is 'B::T'}}
}

T hidden; // expected-error {{unknown type name 'T'}}

int main(void) {
  using A;
  using B;
  T value; // expected-error {{reference to 'T' is ambiguous}}
  return 0;
}
