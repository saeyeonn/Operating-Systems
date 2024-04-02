#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(
{
    // shared memory obj
    const int SIZE = 4096;
    const char *name = "OS";
    const char *message0 = "hello";
    const char *message1 = "world";

    int shm_fd;
    void *ptr;

    // create shared memory obj
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    // configure size of shared memory obj
    ftruncate(shm_fd, SIZE);

    // memory map shared memory object
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // write to shared memory obj
    sprintf(ptr, "%s", message0);
    ptr += strlen(message0);
    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);

    return 0;
}
