#include <exec/types.h>
#include <dos/dos.h>
#include <proto/dos.h>
#include <stdio.h>

int main(void) {
    BPTR fh;
    char buffer[64];
    int pos = 0;
    char ch;
    LONG bytesRead;
    int rows = 0, cols = 0;

    fh = Open("CONSOLE:", MODE_OLDFILE);
    if (fh == 0) {
        printf("Cannot open CONSOLE:\n");
        return 1;
    }

    // Set RAW mode so that escape sequences are passed through
    SetMode(fh, 1);

    // Send the window status request sequence: CSI '0' ' ' 'q'
    if (Write(fh, "\x9b" "0 q", 4) != 4) {
        printf("Write failed.\n");
        SetMode(fh, 0);
        Close(fh);
        return 1;
    }

    // Give the console device a little time to respond
    Delay(5);  // delay for about 5 ticks (~100ms on PAL)

    // Read one character at a time until we see the terminating 'r' or until the buffer is full
    while (pos < (int)(sizeof(buffer) - 1)) {
        bytesRead = Read(fh, &ch, 1);
        if (bytesRead <= 0)
            break;
        buffer[pos++] = ch;
        if (ch == 'r')
            break;
    }
    buffer[pos] = '\0';

    // Expected reply format: "\x9b1;1;<rows>;<cols> r"
    if (sscanf(buffer, "\x9b" "1;1;%d;%d r", &rows, &cols) == 2) {
        printf("Console window size: %d rows x %d columns\n", rows, cols);
    } else {
        // Fallback to default size
        rows = 24;
        cols = 80;
        printf("Failed to retrieve window size. Falling back to default: %d rows x %d columns\n", rows, cols);
    }

    // Restore normal (cooked) mode
    SetMode(fh, 0);
    Close(fh);
    return 0;
}
