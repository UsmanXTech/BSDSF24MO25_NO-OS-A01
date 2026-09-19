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

A top-level `Makefile` recursively invokes the Makefile in `src/`. The source Makefile compiles the individual source files into object files under `obj/`.

## Part 3 — Static Library

### Static Library Build

The utility object files are packaged into:

```text
lib/libmyutils.a
```

The archive contains:

- `mystrfunctions.o`
- `myfilefunctions.o`

The client object file is linked with the static library to produce:

```text
bin/client_static
```

The static link uses the library search path and library name:

```text
-L../lib -lmyutils
```

### Build Commands

```bash
make clean
make
./bin/client_static
```

### Static Library Analysis

The following commands are used to inspect the generated library and executable:

```bash
ar -t lib/libmyutils.a
nm lib/libmyutils.a
readelf -Ws bin/client_static
```

`ar -t` lists the object files stored in the archive. `nm` displays symbols from the static library. `readelf -Ws` displays the symbol table of the final executable.

### Day 3 Result

The static-library build system is implemented on the `static-build` branch. The branch produces both the required static archive and the statically linked client executable.
