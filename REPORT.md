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

### Static Library Analysis

The following commands were used to inspect the generated library and executable:

```bash
ar -t lib/libmyutils.a
nm lib/libmyutils.a
nm bin/client_static
readelf -Ws bin/client_static
```

`ar -t` listed the object files stored in the archive. `nm` and `readelf -Ws` confirmed the required utility symbols in the library and final executable.

### Feature-3 Report Questions

#### 1. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?

In Part 2, the Makefile compiled the source files into object files and linked all object files directly to create `bin/client`.

In Part 3, the Makefile introduced a library directory and separate library targets:

- `LIBDIR = ../lib`
- `LIB_OBJS = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o`
- `LIBRARY = $(LIBDIR)/libmyutils.a`
- `TARGET = $(BINDIR)/client_static`

A library rule uses `ar rcs` to create `lib/libmyutils.a` from the utility object files, followed by `ranlib` to create or update the archive index. The client target then links `main.o` against the library using `-L$(LIBDIR) -lmyutils`.

#### 2. What is the purpose of the ar command? Why is ranlib often used immediately after it?

The `ar` utility creates and manages archive files. In this project, `ar rcs` creates `lib/libmyutils.a` and stores `mystrfunctions.o` and `myfilefunctions.o` inside it.

`ranlib` generates or updates the archive symbol index, allowing the linker to find symbols in the archive. Modern `ar rcs` commonly creates the index automatically, but `ranlib` was used explicitly in this project.

#### 3. When you run nm on your client_static executable, are the symbols for functions like mystrlen present? What does this tell you about how static linking works?

Yes. The verified `nm bin/client_static` output contained:

```text
T mystrlen
T mystrcpy
T mystrncpy
T mystrcat
T wordCount
T mygrep
```

This shows that the required utility functions are present in the final executable. The utility code from the static library was incorporated into the executable during the static-linking process.

### Day 3 Verification

The static build was compiled successfully with `make` and `bin/client_static` executed successfully.

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

## Part 4 — Dynamic Library

### Day 4 Objective

The purpose of Feature-4 is to create and use a shared library instead of linking the utility object files statically.

### Dynamic Library

The utility modules are compiled with Position-Independent Code using `-fPIC`, then combined into:

```text
lib/libmyutils.so
```

The client is linked against the shared library to produce:

```text
bin/client_dynamic
```

### Makefile Changes

The dynamic build introduces:

- `PICFLAGS = -fPIC`
- `LIBRARY = $(LIBDIR)/libmyutils.so`
- `TARGET = $(BINDIR)/client_dynamic`

The utility object rules use `$(PICFLAGS)`, and the shared-library rule uses GCC's `-shared` option.

### Position-Independent Code

Position-Independent Code is code that can execute correctly regardless of the memory address at which it is loaded. The `-fPIC` compiler option is used when preparing the utility object files for the shared library.

For a shared library, this allows the operating system's loader to map the library at an appropriate address without requiring the compiled library code to depend on one fixed address.

### Dynamic Runtime Loading

The dynamic executable depends on `libmyutils.so` at runtime. The library must be discoverable by the system's dynamic loader.

For a local project build, the library directory can be added temporarily with:

```bash
export LD_LIBRARY_PATH="$PWD/lib:$LD_LIBRARY_PATH"
```

Then:

```bash
./bin/client_dynamic
```

The `LD_LIBRARY_PATH` variable provides additional directories for the dynamic loader to search for shared libraries. It was necessary for the local custom `.so` file because the project library directory is not automatically one of the loader's standard search locations.

### Dynamic Library Analysis

The runtime dependency can be inspected using:

```bash
ldd bin/client_dynamic
```

This shows the shared-library dependencies of the executable and can be used to verify that `libmyutils.so` is being resolved from the project's library directory when the environment is configured.

### Feature-4 Verification

The dynamic build was compiled successfully with `make`. The verified file sizes were:

```text
bin/client_dynamic   17K
bin/client_static    17K
lib/libmyutils.so    16K
```

The first execution of `./bin/client_dynamic` produced the expected shared-library lookup error because the project's `lib` directory was not in the loader search path:

```text
error while loading shared libraries: libmyutils.so: cannot open shared object file: No such file or directory
```

After setting:

```bash
export LD_LIBRARY_PATH="$PWD/lib:$LD_LIBRARY_PATH"
```

the dynamic executable ran successfully and produced:

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

The dependency check with `ldd bin/client_dynamic` resolved:

```text
libmyutils.so => /home/uzzyhassan/BSDSF24MO25_NO-OS-A01/lib/libmyutils.so
```

These results demonstrate that the dynamic client loads the shared library at runtime after the library search path is configured.

## Part 5 — Man Pages and Installation

### Man Page Structure

The project now contains the required manual-page directory structure:

```text
man/
└── man3/
```

Manual pages were created for all six project functions:

```text
mystrlen.1
mystrcpy.1
mystrncpy.1
mystrcat.1
wordCount.1
mygrep.1
```

Each man page uses groff formatting and contains the required sections:

- `.TH`
- `.SH NAME`
- `.SH SYNOPSIS`
- `.SH DESCRIPTION`
- `.SH AUTHOR`

### Man Page Preview

A page can be previewed from the project root with:

```bash
man -l man/man3/mystrlen.1
```

### Makefile Install Target

The top-level Makefile provides an `install` target. It builds the project first and installs:

- `bin/client_dynamic` as `client` under `/usr/local/bin`
- `lib/libmyutils.so` under `/usr/local/lib`
- the project man pages under `/usr/local/share/man/man3` using section-3 filenames

The installation target also runs `ldconfig` to update the shared-library cache and `mandb` to refresh the manual-page database when installing directly to the system.

The installation command is:

```bash
sudo make install
```

After installation, the intended result is that a new user can run:

```bash
client
man mystrlen
```

from any directory without manually setting `LD_LIBRARY_PATH` or running `mandb`.

### Installation Issue Found and Corrected

The first installation attempt exposed two integration issues. The installed `client` could not locate `libmyutils.so`, and the man database rejected the installed `.1` files as bogus filenames inside `man3`.

The Makefile was corrected so that installation now also installs the shared library into `/usr/local/lib`, refreshes the dynamic linker cache with `ldconfig`, and installs the repository's `.1` source man pages as `.3` files in the `man3` directory. This keeps the assignment source files unchanged while using the standard installed filename convention required by the man database.

### Verified Failure That Led to the Fix

The first installation produced:

```text
client: error while loading shared libraries: libmyutils.so: cannot open shared object file: No such file or directory
No manual entry for mystrlen
```

`ldd /usr/local/bin/client` confirmed:

```text
libmyutils.so => not found
```

The installed source man page existed at `/usr/local/share/man/man3/mystrlen.1`, but `mandb` reported it as a bogus filename because the `man3` directory expects a section-3 filename.

The corrected installation logic addresses both issues for a new installation.

### Day 5 Result

Feature-5 now contains the required man pages and an installation target that also handles the runtime shared-library dependency and system man-page database integration. Final local reinstallation and verification are the remaining validation steps before the final release.
