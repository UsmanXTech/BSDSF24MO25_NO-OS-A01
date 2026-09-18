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

The string module implements:

- `mystrlen()`
- `mystrcpy()`
- `mystrncpy()`
- `mystrcat()`

### File Utilities

The file module implements:

- `wordCount()`
- `mygrep()`

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

### Day 2 Result

The multi-file project structure and build system have been added on the `multifile-build` branch. The next stage is the static library build.
