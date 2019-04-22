/* @brief A program to seed fake entropy bits to /dev/random and /dev/urandom
 * @author Haris O. at NI.
 */

// https://github.com/waywardgeek/infnoise/blob/master/software/writeentropy.c#L22

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <linux/random.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, const char** argv) {
    int entropy_count = 10;
    int fd;
    int result = 1;
    struct rand_pool_info pool_info;

    memset(&pool_info, 0, sizeof(struct rand_pool_info));
    errno = ERANGE;
    pool_info.entropy_count = entropy_count;

    fd = open("/dev/random", O_RDWR);
    if (rand == -1) {
      perror("failed to open /dev/random");
      return 1;
    }

    int res = ioctl(fd, RNDADDENTROPY, &pool_info);

    printf("%d", RNDADDENTROPY);

    /* if ( != 0) { */
    /*   perror("failed to ioctl(RNDADDENTROPY) on /dev/random"); */
    /*   return 1; */
    /* } */

    return 0;
}
