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
├── man/        # Linux manual pages
│   └── man3/   # Function manual pages
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
| Dynamic Library | Complete |
| Man Pages & Installation | In Progress |
| Final Submission | Pending |

## Building

Run:

```bash
make
```

On the `dynamic-build` and `man-pages` stages, the build creates:

```text
lib/libmyutils.so
bin/client_dynamic
```

To remove generated object files, the shared library, and the dynamic executable:

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

## Dynamic Library

The dynamic build compiles the utility modules with Position-Independent Code and creates:

```text
lib/libmyutils.so
```

The client links against the shared library to produce:

```text
bin/client_dynamic
```

At runtime, the dynamic loader must be able to locate `libmyutils.so`. For a local project build, this can be demonstrated with:

```bash
export LD_LIBRARY_PATH="$PWD/lib:$LD_LIBRARY_PATH"
./bin/client_dynamic
```

The dependency can be inspected with:

```bash
ldd bin/client_dynamic
```

## Man Pages

The `man-pages` branch provides manual pages for all six project functions:

```text
man/man3/mystrlen.1
man/man3/mystrcpy.1
man/man3/mystrncpy.1
man/man3/mystrcat.1
man/man3/wordCount.1
man/man3/mygrep.1
```

Each page contains the required `.TH`, `.SH NAME`, `.SH SYNOPSIS`, `.SH DESCRIPTION`, and `.SH AUTHOR` sections.

Preview a page locally with:

```bash
man -l man/man3/mystrlen.1
```

## Installation

The top-level Makefile provides an `install` target that installs the dynamic client as `client` and copies the function man pages into the system manual-page directory.

Run:

```bash
sudo make install
```

Then the installed program can be invoked with:

```bash
client
```

and an installed function manual page can be viewed with:

```bash
man mystrlen
```
