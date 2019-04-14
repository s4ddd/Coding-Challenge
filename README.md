# Coding-Challenge

## Overview of files
### q1 - question 1 files
- tests
  - default - test sets taken from the question description
  - fail - tests that should be failed
  - random - tests of random length containing a random combination of numbers
  - repeats - tests of random length containing a selection of 1000 different numbers
  - check.cpp - checks if the output for a given input is correct
  - testing.sh - script for running tests
  - tests.cpp - generates tests for 'random' and 'repeat'
- solution.cpp - solution for question 1

#### to test
1) Compile and run tests/tests.cpp to create the test-input
2) Run tests/testing.sh


### q2 - questions 2 files
- tests
  - default - test sets taken from the question description
  - other
    - 0 - contains input and output for tests 0-499
    - 500 - contains input and output for tests 500-999
    - 1000 - contains input and output for tests 1000-1499
    - 1500 - contains input and output for tests 1500-1599
    - tests.cpp - generates tests
- solution.cpp - solution for question 2

#### to test
1) Compile and run tests/other/tests.cpp to create the test-input
2) Run tests/testing.sh
