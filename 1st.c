#include <unistd.h>

int main() {
    const char *source = "./original";
    const char *softlink = "./softlink";
    symlink(source, softlink);
    return 0;
}

