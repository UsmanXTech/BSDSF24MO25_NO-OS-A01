# BSDSF24MO25_NO-OS-A01

Operating Systems Programming Assignment 01

## Project Overview

This repository contains the work for Operating Systems Programming Assignment 01. The project is developed incrementally with separate feature branches, atomic commits, tags, and releases.

## Directory Structure

```text
BSDSF24MO25_NO-OS-A01/
├── src/        # C source files and build rules
├── include/    # Header files
├── lib/        # Compiled static and dynamic libraries
├── bin/        # Final executable programs
├── obj/        # Intermediate object files
├── Makefile    # Top-level build entry point
└── REPORT.md   # Assignment report
```

## Development Branches

- `main`
- `multifile-build`
- `static-build`
- `dynamic-build`
- `man-pages`

## Assignment Progress

| Part | Status |
| --- | --- |
| Project Scaffolding & Version Control | Complete |
| Multi-file Project | Complete |
| Static Library | Pending |
| Dynamic Library | Pending |
| Man Pages & Installation | Pending |
| Final Submission | Pending |

## Building

Run:

```bash
make
```

The multi-file build produces `bin/client`.

To remove generated object files and the executable:

```bash
make clean
```

## Multi-file Interfaces

The string utilities follow the assignment interfaces:

- `mystrlen()`
- `mystrcpy()`
- `mystrncpy()`
- `mystrcat()`

The file utilities follow the assignment interfaces:

- `wordCount(FILE *file, int *lines, int *words, int *chars)`
- `mygrep(FILE *fp, const char *search_str, char ***matches)`

`wordCount()` reports lines, words, and characters. `mygrep()` returns matching lines through the dynamically allocated `matches` array.
