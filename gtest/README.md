# Include Google Test in your project
```bash
git clone https://github.com/google/googletest.git
```
The header file of google test is in `${workFolder}/googletest/googletest/include`.

The library file of google test is in `${workFolder}/googletest/build/lib`.

# How to link several test files together
- Write a `gtest_main.cpp` which is the entry of whole test. Just copy from the example.
- Every independent test file has a independent namespace. 

2023-10-31 Successfully run on VsCode.