
#include <stdio.h>
#include "utilities.h"

// This function just waits for the user to press Enter.
void pauseScreen(void) {
    printf("\nPress Enter to continue...");
    getchar(); getchar();
}