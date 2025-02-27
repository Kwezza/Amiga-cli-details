# Amiga Console Utilities

This project provides a C program that demonstrates how to detect the size of the console window (in rows and columns) on classic Amiga systems, targeting Workbench 2 upwards.  It also returns the current cursor position. The program utilizes ANSI escape sequences to query the console device for its dimensions and includes a fallback to default values if the query is unsuccessful.

## Description

Accurately determining the console window size is essential for applications that rely on precise text formatting and display. This program:

- Sends an ANSI escape sequence to the console to request its current size.
- Parses the response to extract the number of rows and columns.
- Falls back to default dimensions (24 rows x 80 columns) if the console does not support the query.
- Also uses the ANSI escape sequence to get the current cursor location

## Prerequisites

- **Amiga Workbench 2.04+**: This program has been tested to work with Amiga Workbench 2.04+
- **SAS/C Compiler 6.58**: Ensure you have the SAS/C compiler installed to compile the program.  Use smake to compile.
