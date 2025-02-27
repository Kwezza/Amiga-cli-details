/*
 * Amiga CLI Console Utilities - Main File
 *
 * This program retrieves and displays the current cursor position
 * and the size of the CLI window in AmigaOS. It makes use of ANSI
 * escape sequences to communicate with the console device.
 *
 * Works on Amiga Workbench 2.04 and later.
 * Compiles using SAS/C.
 */

 #include <stdio.h>
 #include "cli_utilities.h"
 
 int main(void) {
     CursorPos pos;
     ConsoleSize size;
 
     /* Retrieve cursor position */
     pos = getCursorPos();
     if (pos.xPos != -1 && pos.yPos != -1) {
         printf("Cursor Position - X: %d, Y: %d\n", pos.xPos, pos.yPos);
     } else {
         printf("Failed to retrieve cursor position.\n");
     }
 
     /* Retrieve console window size */
     size = getConsoleSize();
     printf("Console window size: %d rows x %d columns\n", size.rows, size.columns);
 
     return 0;
 }
 