# Amiga Console Window Size Detection

This project provides a C program that detects the size of the console window (in rows and columns) on AmigaOS systems, specifically targeting AmigaOS 3.2. The program utilizes ANSI escape sequences to query the console device for its dimensions and includes a fallback to default values if the query is unsuccessful.

## Description

Accurately determining the console window size is essential for applications that rely on precise text formatting and display. This program:

- Sends an ANSI escape sequence to the console to request its current size.
- Parses the response to extract the number of rows and columns.
- Falls back to default dimensions (24 rows x 80 columns) if the console does not support the query.

## Prerequisites

- **AmigaOS 3.2**: This program is designed and tested for AmigaOS 3.2.
- **SAS/C Compiler 6.58**: Ensure you have the SAS/C compiler installed to compile the program.
