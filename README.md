# study_c

Code written for the purpose of studying C the programming language.

## data_structures

Common data structures implemented in C.

Some of these are used in other parts of this repo.

### Run

```bash
cd data_structures
make
./<data_structure>_test
make clean
```

Note that if asan is set up properly then leaks will be detected when you run the tests.

## c_programming_a_modern_approach

Solutions to the exercises and projects in the book "C Programming: A Modern Approach (2nd Edition)".

Note that some exercises and projects are skipped.

Answers can be found here: http://knking.com/books/c2/answers/index.html

### Run

```bash
cd c_programming_a_modern_approach/chapter_x
make
./<exercise_x>
./<project_x>
make clean
```

### Chapters

- Basic Features of C
  - [X] Chp 1: Introducing C
  - [X] Chp 2: C fundamentals
  - [X] Chp 3: Formatted Input/Output
  - [X] Chp 4: Expression
  - [X] Chp 5: Selection Statements
  - [X] Chp 6: Loops
  - [X] Chp 7: Basic Types
  - [X] Chp 8: Arrays
  - [X] Chp 9: Functions
  - [X] Chp 10: Program Organization
- Advanced Features of C
  - [X] Chp 11: Pointers
  - [X] Chp 12: Pointers and Arrays
  - [X] Chp 13: Strings
  - [X] Chp 14: The Preprocessor
  - [X] Chp 15: Writing Large Programs
  - [X] Chp 16: Structures, Unions, and Enumerations
  - [ ] Chp 17: Advanced Uses of Pointers
  - [ ] Chp 18: Declarations
  - [ ] Chp 19: Program Design
  - [ ] Chp 20: Low-Level Programming
- The Standard C Library
  - [ ] Chp 21: The Standard Library
  - [ ] Chp 22: Input/Output
  - [ ] Chp 23: Library Support for Numbers and Character Data
  - [ ] Chp 24: Error Handling
  - [ ] Chp 25: International Features
  - [ ] Chp 26: Miscellaneous Library Functions
  - [ ] Chp 27: Additionally C99 Support for Mathematics
