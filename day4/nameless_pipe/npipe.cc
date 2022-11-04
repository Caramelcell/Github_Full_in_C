#include "main.h"

int main()
{
    int fds[2] = {0};
    int ret = pipe(fds);
    int status;
    ERROR_CHECK(ret, -1, "pipe");
    char buf[128] = "Hello";

    if (0 == fork())
    {
        close(fds[0]);
        write(fds[1], buf, strlen(buf));
        close(fds[1]);
        return 0;
    }
    else
    {
        close(fds[1]);
        sleep(1);
        read(fds[0], &buf, sizeof(buf));
        puts(buf);
        close(fds[0]);
        return 0;
    }
}