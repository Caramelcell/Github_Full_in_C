#include "finddir.h"

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,3)
    DIR* dir;

    dir = opendir(argv[1]);
    find_dir(argv[1], argv[2], 0);

    return 0;
}