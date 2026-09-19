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
| Static Library | Complete |
| Dynamic Library | Pending |
| Man Pages & Installation | Pending |
| Final Submission | Pending |

## Building

Run:

```bash
make
```

On the `static-build` branch, the build creates:

```text
lib/libmyutils.a
bin/client_static
```

To remove generated object files, the static library, and the static executable:

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

## Static Library

The static build packages the utility object files into:

```text
lib/libmyutils.a
```

The client program links against the library to produce:

```text
bin/client_static
```

Useful inspection commands are:

```bash
ar -t lib/libmyutils.a
nm lib/libmyutils.a
readelf -Ws bin/client_static
```

These commands can be used to inspect archive members and symbols in the static library and executable.
