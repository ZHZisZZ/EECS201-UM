#include <command.hpp>
#include <cstdio>

int func_space(int argc, const char * const *argv);
command cmd_space = {"space", "space <string>", "Inserts spaces between letters", func_space};

int func_space(int argc, const char * const *argv)
{
    if (argc <= 1) {
        fprintf(stderr, "Expected <string> as argument\n    usage: %s\n",
                cmd_space.usage);
        return 1;
    }

    const char *str = argv[1];
    for (int idx = 0; str[idx] != '\0'; idx++) {
        fputc(str[idx], stderr);
        if (str[idx + 1] != '\0')
            fputc((int) ' ', stderr);
    }
    fputc('\n', stderr);
    return 0;
}
