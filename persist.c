#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

// Main method
int main(int argc, char* argv[])
{
    // Open file (write only, create if doesn't exist, truncate)
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd > -1);

    // Write 'hello world' to file
    int rc = write(fd, "hello world\n", 13);
    assert(rc == 13);

    // Close file
    close(fd);

    return 0;
}
