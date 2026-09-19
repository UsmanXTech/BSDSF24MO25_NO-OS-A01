# Operating Systems Programming Assignment 01

## Student Information

- Roll Number: BSDSF24MO25

## Part 1 — Project Scaffolding & Version Control

### Repository

Repository: `BSDSF24MO25_NO-OS-A01`

### Project Structure

The project follows the required structure:

```text
BSDSF24MO25_NO-OS-A01/
├── src/
├── include/
├── lib/
├── bin/
├── obj/
├── Makefile
└── REPORT.md
```

### Work Completed

- Created the project repository.
- Added the required project directories.
- Added the initial project documentation.
- Established incremental Git development.

## Part 2 — Multi-file Project

### Source Files

The multi-file implementation contains:

- `src/main.c`
- `src/mystrfunctions.c`
- `src/myfilefunctions.c`

### Header Files

The interfaces are separated into:

- `include/mystrfunctions.h`
- `include/myfilefunctions.h`

### String Utilities

The string module implements the assignment interfaces:

```c
int mystrlen(const char *s);
int mystrcpy(char *dest, const char *src);
int mystrncpy(char *dest, const char *src, int n);
int mystrcat(char *dest, const char *src);
```

`mystrlen()` returns the string length and the other string operations return `0` on success and `-1` on invalid input.

### File Utilities

The file module implements:

```c
int wordCount(FILE *file, int *lines, int *words, int *chars);
int mygrep(FILE *fp, const char *search_str, char ***matches);
```

`wordCount()` counts lines, words, and characters from the supplied stream and returns `0` on success or `-1` on failure.

`mygrep()` searches the supplied stream for lines containing the requested string. Matching lines are copied into the dynamically allocated `matches` array. The function returns the number of matches or `-1` on failure.

### Build System

A top-level `Makefile` recursively invokes the Makefile in `src/`. The source Makefile compiles the individual source files into object files under `obj/` and links them into:

```text
bin/client
```

The build uses GCC with warnings enabled and the `include/` directory supplied as a header search path.

### Build Commands

```bash
make
make clean
```

### Day 2 Correction

The multi-file interfaces and implementations were aligned with the assignment specification before proceeding to the static-library stage.

### Day 2 Result

The multi-file project structure, assignment-compatible interfaces, implementation, and build system are complete on the `multifile-build` branch. The next stage is the static library build.
