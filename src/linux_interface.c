#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "linux_interface.h"

int read_linux_random_value(void) {

    int fd;
    unsigned char value;

    fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return -1;
    }

    if (read(fd, &value, sizeof(value)) != sizeof(value)) {
        perror("read");
        close(fd);
        return -1;
    }

    close(fd);

    return (int)value;
}
