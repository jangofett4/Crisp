# C namespaces

Use `-fc-namespaces` when compiling C source files that contain namespace
declarations or qualified names. The flag is opt-in and applies to headers
included by those files.

```c
namespace std::math {
  typedef struct vector3i;
  struct vector3i { int x, y, z; };
  int sum(vector3i *value);
}

int main(void) {
  std::math::vector3i value = { 1, 2, 3 };
  using std::math;
  return sum(&value);
}
```

`namespace` definitions can be reopened. `using` imports names from a
namespace into the current scope. The shorthand
`typedef struct name;` is accepted inside a C namespace and declares the
ordinary typedef name for the struct tag. The usual C spelling
`typedef struct name name;` also works.

The declarations keep C types and calling conventions. C function overloading
is not enabled. Functions and variables inside named namespaces receive a
linker name formed from `_CNS` followed by each namespace component and the
declaration name, each prefixed by its byte length. For example,
`std::math::sum` becomes `_CNS3std4math3sum`. Types themselves have no
linker symbol. All translation units using a namespaced declaration must be
compiled with `-fc-namespaces`.
