// RUN: %clang_cc1 -std=c11 -fc-namespaces -emit-llvm -o - %s | FileCheck %s

namespace std::math {
  typedef struct vector3i;
  struct vector3i { int x; int y; int z; };
  int sum(vector3i *v);
  int count = 3;
}

namespace std::math {
  int sum(vector3i *v) { return v->x + v->y + v->z; }
}

namespace other {
  int count = 7;
  int sum(int x) { return x + 1; }
}

int main(void) {
  std::math::vector3i first = { 10, 20, 30 };
  struct std::math::vector3i third = { 0, 0, 0 };
  using std::math;
  vector3i second = { 1, 2, 3 };
  return sum(&first) + std::math::sum(&second) +
         std::math::count + other::count + other::sum(1) + third.x;
}

// CHECK: @_CNS3std4math5count = {{.*}}global i32 3
// CHECK: @_CNS5other5count = {{.*}}global i32 7
// CHECK: define{{.*}} @_CNS3std4math3sum(
// CHECK: define{{.*}} @_CNS5other3sum(
// CHECK: define{{.*}} @main(
// CHECK: call i32 @_CNS3std4math3sum(
