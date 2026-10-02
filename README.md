# Crisp

Crisp is an experimental Clang fork for people who like C's directness but
want better developer ergonomics. The aim is to add a small set of opt-in
language features while keeping C's types, calling conventions, and runtime
model recognizable. It is a proof of concept, not a new C standard or a
production-ready compiler.

The first implemented feature is **C namespaces**. With `-fc-namespaces`, C
code can declare nested namespaces, use qualified names such as
`std::math::vector3i`, and import names into a scope with `using std::math;`.
Namespaced functions and variables get distinct linker symbols while retaining
C calling conventions. See the [namespace documentation](clang/docs/CNamespaces.md)
for syntax and build examples.

Ideas for later experiments include a `defer` statement, monomorphic templates,
and scoped enums when a header is brought in with `#import`. Those features
are **not implemented**. The immediate goal is to see whether namespaces make
for a useful, coherent C extension before expanding the experiment.

## Authorship and review

**The Clang/LLVM modifications in Crisp so far were generated and implemented
by OpenAI Codex, an LLM assistant, at the project owner's direction. They were
not written by the project owner.** The owner has tested the namespace proof
of concept, but has not yet personally audited the compiler changes. The plan
is to study the Clang/LLVM source and write or revise the implementation
personally if the proof of concept is worth pursuing. Please treat the current
changes as experimental and review them accordingly.

## Build and try the namespace proof of concept

From the repository root, with CMake and Ninja installed:

```sh
cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS=clang -DLLVM_TARGETS_TO_BUILD=X86
cmake --build build --target clang
build/bin/clang -std=c11 -fc-namespaces your_file.c -o your_program
```

---

# The LLVM Compiler Infrastructure

[![OpenSSF Scorecard](https://api.securityscorecards.dev/projects/github.com/llvm/llvm-project/badge)](https://securityscorecards.dev/viewer/?uri=github.com/llvm/llvm-project)
[![OpenSSF Best Practices](https://www.bestpractices.dev/projects/8273/badge)](https://www.bestpractices.dev/projects/8273)
[![libc++](https://github.com/llvm/llvm-project/actions/workflows/libcxx-pr-conformance-tests.yaml/badge.svg?branch=main&event=schedule)](https://github.com/llvm/llvm-project/actions/workflows/libcxx-pr-conformance-tests.yaml?query=event%3Aschedule)

Welcome to the LLVM project!

This repository contains the source code for LLVM, a toolkit for the
construction of highly optimized compilers, optimizers, and run-time
environments.

The LLVM project has multiple components. The core of the project is
itself called "LLVM". This contains all of the tools, libraries, and header
files needed to process intermediate representations and convert them into
object files. Tools include an assembler, disassembler, bitcode analyzer, and
bitcode optimizer.

C-like languages use the [Clang](https://clang.llvm.org/) frontend. This
component compiles C, C++, Objective-C, and Objective-C++ code into LLVM bitcode
-- and from there into object files, using LLVM.

Other components include:
the [libc++ C++ standard library](https://libcxx.llvm.org),
the [LLD linker](https://lld.llvm.org), and more.

## Getting the Source Code and Building LLVM

Consult the
[Getting Started with LLVM](https://llvm.org/docs/GettingStarted.html#getting-the-source-code-and-building-llvm)
page for information on building and running LLVM.

For information on how to contribute to the LLVM project, please take a look at
the [Contributing to LLVM](https://llvm.org/docs/Contributing.html) guide.

## Getting in touch

Join the [LLVM Discourse forums](https://discourse.llvm.org/), [Discord
chat](https://discord.gg/xS7Z362),
[LLVM Office Hours](https://llvm.org/docs/GettingInvolved.html#office-hours) or
[Regular sync-ups](https://llvm.org/docs/GettingInvolved.html#online-sync-ups).

The LLVM project has adopted a [code of conduct](https://llvm.org/docs/CodeOfConduct.html) for
participants to all modes of communication within the project.
