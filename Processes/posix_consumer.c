#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(
{
    // shared memory obj
    const int SIZE = 4096;
    const char *name = "OS";

    int shm_fd;
    void *ptr;

    // create shared memory obj
    shm_fd = shm_open(name, O_RDONLY, 0666);

    // memory map shared memory object
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    // read from shared memory obj
    printf("%s", (char *)ptr);

    // remove shared memory obj
    shm_unlink(name);

    return 0;
}
