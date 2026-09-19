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

### Report Questions

#### 1. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?

In Part 2, the Makefile compiled the source files into object files and linked all object files directly to create `bin/client`.

In Part 3, the Makefile introduces a library directory and separate library targets:

- `LIBDIR = ../lib`
- `LIB_OBJS = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o`
- `LIBRARY = $(LIBDIR)/libmyutils.a`
- `TARGET = $(BINDIR)/client_static`

A new library rule uses `ar rcs` to create `lib/libmyutils.a` from the utility object files, followed by `ranlib` to create or update the archive index. The client target then links `main.o` against the library using `-L$(LIBDIR) -lmyutils`. This separates the utility functions into a reusable static library instead of linking their object files directly into the client command.

#### 2. What is the purpose of the ar command? Why is ranlib often used immediately after it?

The `ar` utility creates and manages archive files. In this project, `ar rcs` creates `lib/libmyutils.a` and stores the utility object files `mystrfunctions.o` and `myfilefunctions.o` inside it.

`ranlib` generates or updates the archive symbol index. The index allows the linker to locate required symbols in the archive efficiently. Modern versions of `ar rcs` commonly create the index automatically, but running `ranlib` explicitly is still useful for clarity and compatibility with traditional static-library workflows.

#### 3. When you run nm on your client_static executable, are the symbols for functions like mystrlen present?

Yes. The verified `nm bin/client_static` output contains the required utility symbols:

```text
00000000000016a8 T mystrlen
00000000000016e6 T mystrcpy
0000000000001760 T mystrncpy
00000000000017fb T mystrcat
000000000000189f T wordCount
00000000000019ab T mygrep
```

The `T` symbol type indicates that these functions are present in the executable's text/code section. The `readelf -Ws bin/client_static` output also confirmed these functions as global function symbols.

### Day 3 Verification

The static build was compiled successfully with `make` and the resulting `bin/client_static` executed successfully.

Verified output included:

```text
String: Day 2: Operating Systems
Length: 24
Copied: Multi-file C
Lines: 3
Words: 9
Characters: 65
Matches: 1
Static library comes next
```

The generated files were:

```text
bin/client_static  17K
lib/libmyutils.a   5.5K
```

The archive inspection showed:

```text
mystrfunctions.o
myfilefunctions.o
```

The required utility symbols were also confirmed using `nm` and `readelf`.

### Day 3 Result

The static-library build system is implemented on the `static-build` branch. The branch produces both the required static archive and the statically linked client executable.
