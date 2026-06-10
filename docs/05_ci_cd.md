# CI/CD for TwoSum C++ Project

This document explains how GitHub Actions is used to build and test the TwoSum implementation automatically.

## Workflow Overview

The workflow file is located at `.github/workflows/ci.yml`.

### Trigger events
- `push` to `main`
- `pull_request` targeting `main`

### Environments
- `ubuntu-latest`
- `windows-latest`

## What the workflow does

1. Checks out the repository.
2. Builds the project using a C++20 compiler.
3. Runs the executable and verifies test output.

## Linux build steps

- Installs `g++`.
- Compiles `src/main.cpp` and `src/twosum.cpp`.
- Runs `./twosum_test`.

## Windows build steps

- Installs MinGW via Chocolatey.
- Uses GCC `g++` to compile `src/main.cpp` and `src/twosum.cpp`.
- Runs `twosum_test.exe`.

## Local testing

You can run tests locally before pushing:

- With `g++`:
  ```bash
  g++ -std=c++20 -Wall -Wextra src/main.cpp src/twosum.cpp -o twosum_test
  ./twosum_test
  ```

- With MSVC `cl.exe`:
  ```cmd
  cl /EHsc /std:c++20 src\main.cpp src\twosum.cpp /Fe:twosum_test.exe
  twosum_test.exe
  ```

## Why CI is useful

- Ensures code changes do not break the project.
- Runs the same tests on multiple operating systems.
- Provides an automatic verification step for pull requests.
- Documents the expected build and test process.

## Notes for future study

- GitHub Actions workflows are written in YAML.
- `jobs` are the units of work; `steps` are commands inside jobs.
- `matrix` allows the same job to run with different OS or compiler setups.
- For larger projects, consider using a test framework like Google Test.
