# Instructions

The purpose of this exercise is to gain some familiarity with GoogleTest assertions and matchers. This is achieved by
getting you to write some simple tests.

To complete this exercise, simply replace the `FAIL` assertions with appropriate assertions in line with the `TODO`
comments in each failing test in OrderTests.cpp.

Hint: Use the [Matchers Reference](https://google.github.io/googletest/reference/matchers.html) documentation to learn
the variety of matchers that are available.

## Prepare your environment

This project uses Bazel to run the tests. You will need to install Bazel and have an appropriate C++ compiler installed.
We recommend using GCC or Clang. We use Bazelisk to ensure the correct version of Bazel is installed. The instructions
on installing Bazelisk can be found on [Bazelisk](https://github.com/bazelbuild/bazelisk).

The Bazel project requires a C++17 compliant compiler. We use C++20 internally , so feel free to change this in the
.bazelrc, but we have the minimum as C++17 to cater to the variety of development environments that you have.

## Run the tests

To run the tests you can use the following command:

```bash
bazel test //... --test_output=all
```

## Problems getting Bazel to run successfully?

### Try specifying your compiler directly to Bazel

If you have problems getting Bazel to run, try specifying your compiler directly using the `CXX` and `CC` variables.
This prevent issues with sandboxing that Bazel has by default. An example of specifying the environment variables are:

```bash
export CXX=/usr/local/bin/g++-12
export CC=/usr/local/bin/gcc-12
```

Note: You need **both** `CXX` and `CC` environment variables when you specify the compiler.

## Try disabling the sandbox

Bazel uses a sandbox to produce reproducible builds. You can disable this and run the compiler directly on your working
tree by running the bazel test command with `--spawn_strategy=local`.

### Alternatively use Compiler Explorer

If you have problems getting Bazel to run, you can perform this exercise on Compiler Explorer instead by using the link
below:

[Exercise on Compiler Explorer](https://gcc.godbolt.org/z/eYznT7v93)
