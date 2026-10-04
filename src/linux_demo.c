#include <stdio.h>
#include "linux_interface.h"

int main(void) {

    int value = read_linux_random_value();

    if (value < 0) {
        printf("Failed to read Linux system source.\n");
        return 1;
    }

    printf("========================================\n");
    printf("       LINUX SYSTEM INTERFACE\n");
    printf("========================================\n");

    printf("Linux system value : %d\n", value);
    printf("System interface   : /dev/urandom\n");

    return 0;
}
