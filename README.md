# study_c

Code written for the purpose of studying C the programming language.

## Resources

- Books
  - K&R: The C Programming Language. 2nd Edition
  - Kim N. King: C Programming: A Modern Approach
  - Peter van der Linden: Expert C Programming, Deep C Secrets.
  - Robert Sedgewick: Algorithms in C, Parts 1-4: Fundamentals, Data Structures, Sorting, Searching: Fundamentals, Data Structures, Sorting, Searching
- Articles
  - [How to C in 2016](https://matt.sh/howto-c)
  - [C FAQ](http://c-faq.com/)
- Slides
  - [Programming in C - Lecture 6: The Memory Hierarchy and Cache Optimization](https://www.cl.cam.ac.uk/teaching/1718/ProgC/lectures/lecture6.pdf)

## Projects

- Projects implemented in C
    - [cnake](https://github.com/SourenP/cnake): Terminal snake written in C that uses a custom memory allocator
    - [hisho](https://github.com/SourenP/cnake): A memory allocator in C99 written for learning purposes.

## Problems

- Programming problems/challenges implemented in C
  - [advent_of_code 2019](https://github.com/SourenP/advent_of_code/tree/master/2019): Solutions to Advent Of Code 2019 problems.
  - [leetcode 30 day challenge](https://github.com/SourenP/leetcode/tree/master/30_day_challenge/solutions_c): Solutions to Leetcode April 2020 30 Day Challenge

## Data structures

- Common data structures implemented in C
    - [X] [stack](data_structures/stack.c)
    - [X] [priority_queue](data_structures/priority_queue.c)
    - [X] [vector](data_structures/vector.c)
    - [X] [dag](data_structures/dag.c)
    - [X] [map](data_structures/map.c)
    - [X] [trie](data_structures/trie.c)
      - [ ] Fix remove
    - [X] [circlular buffer](data_structures/circular_buffer.c)
    - [X] [deque](data_structures/deque.c)
    - [ ] quadtree

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

## Books

### C Programming: A Modern Approach

- Solutions to the exercises and projects in the book "C Programming: A Modern Approach (2nd Edition)".
- Some exercises and projects are skipped.
- Answers can be found here: http://knking.com/books/c2/answers/index.html
- Chapters:
    - Basic Features of C
        - [X] Chp 1: Introducing C
        - [X] [Chp 2: C fundamentals](c_programming_a_modern_approach/chapter_02)
        - [X] Chp 3: Formatted Input/Output
        - [X] Chp 4: Expression
        - [X] Chp 5: Selection Statements
        - [X] Chp 6: Loops
        - [X] Chp 7: Basic Types
        - [X] Chp 8: Arrays
        - [X] Chp 9: Functions
        - [X] Chp 10: Program Organization
    - Advanced Features of C
        - [X] [Chp 11: Pointers](c_programming_a_modern_approach/chapter_11)
        - [X] [Chp 12: Pointers and Arrays](c_programming_a_modern_approach/chapter_12)
        - [X] [Chp 13: Strings](c_programming_a_modern_approach/chapter_13)
        - [X] Chp 14: The Preprocessor
        - [X] Chp 15: Writing Large Programs
        - [X] [Chp 16: Structures, Unions, and Enumerations](c_programming_a_modern_approach/chapter_16)
        - [X] [Chp 17: Advanced Uses of Pointers](c_programming_a_modern_approach/chapter_17)
        - [X] Chp 18: Declarations
        - [X] Chp 19: Program Design
        - [X] [Chp 20: Low-Level Programming](c_programming_a_modern_approach/chapter_20)
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

