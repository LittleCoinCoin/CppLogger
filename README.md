# Cpp Logger

The CppLogger repository provides a logging system for C++ projects. It allows to dispatch log messages to different "sinks" (outputs) with various log levels such as Debug, Trace, Warning, and Error.

## Documentation

Please, visit the dedicated [documentation page](https://littlecoincoin.github.io/CppLogger/) for more information on how to use this repository.

## Tested platforms

Here is a table indicating the build configurations that have been tested based on the workflows:

| Platform | Compiler | Build Configurations | Additional Configurations |
|----------|----------|----------------------|---------------------------|
| Linux    | Clang    | Release, Debug       | Clang versions: 17, 18, 19 |
| Linux    | GCC      | Release, Debug       | GCC versions: 11, 12, 13   |
| Windows  | MSVC     | Release, Debug       | MSVC toolsets: v141, v142, v143, Architectures: x64, x86 |
| MacOS    | Clang    | Release, Debug       | None                      |

You can view the files:
- [Linux Workflow](https://github.com/LittleCoinCoin/CppLogger/blob/main/.github/workflows/tests_linux.yml)
- [Windows Workflow](https://github.com/LittleCoinCoin/CppLogger/blob/main/.github/workflows/tests_windows.yml)
- [MacOS Workflow](https://github.com/LittleCoinCoin/CppLogger/blob/main/.github/workflows/tests_macos.yml)