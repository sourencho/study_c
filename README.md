# study_c

Code written for the purpose of studying C the programming language.

## Resources

- [Book] Kim N. King: C Programming: A Modern Approach
- [Book] Peter van der Linden: Expert C Programming, Deep C Secrets
- [Book] Robert Sedgewick: Algorithms in C, Parts 1-4: Fundamentals, Data Structures, Sorting, Searching: Fundamentals, Data Structures, Sorting, Searching

## Code

### projects

- Small projects implemented in C
    - [cnake](projects/cnake/): Snake terminal clone written in C99 with ncurses

### data_structures

- Common data structures implemented in C
    - [X] stack
    - [ ] linked_list


#### Run

```bash
cd data_structures
make
./<data_structure>_test
make clean
```

Notes:
- If asan is set up properly then leaks will be detected when you run the tests
- I think you need to use llvm@8 on macos to get asan working:
  - ```
    $ which clang
    /usr/local/opt/llvm@8/bin/clang
    ```


### c_programming_a_modern_approach

- Solutions to the exercises and projects in the book "C Programming: A Modern Approach (2nd Edition)".
- Some exercises and projects are skipped.
- Answers can be found here: http://knking.com/books/c2/answers/index.html

- Chapters:
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
        - [X] Chp 17: Advanced Uses of Pointers
        - [X] Chp 18: Declarations
        - [X] Chp 19: Program Design
        - [X] Chp 20: Low-Level Programming
    - The Standard C Library
        - [ ] Chp 21: The Standard Library
        - [ ] Chp 22: Input/Output
        - [ ] Chp 23: Library Support for Numbers and Character Data
        - [ ] Chp 24: Error Handling
        - [ ] Chp 25: International Features
        - [ ] Chp 26: Miscellaneous Library Functions
        - [ ] Chp 27: Additionally C99 Support for Mathematics

#### Run

```bash
cd c_programming_a_modern_approach/chapter_x
make
./<exercise_x>
./<project_x>
make clean
```

Notes:
  - Some exercises/projects use the code in `data_structures/`

