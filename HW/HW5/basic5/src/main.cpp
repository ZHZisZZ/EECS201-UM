#include <iostream>
#include <string>
#include <cstring>

#include <command.hpp>

int func_help(int argc, const char * const *argv);

extern command cmd_space;
const command cmds[] =
{
    {"help", "help", "Prints command listing", func_help},
    cmd_space
};

#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

int func_help(int argc, const char * const *argv)
{
    std::cout << "usage: memetext <commmand> [command arguments]"
              << std::endl << std::endl;

    for (int i = 0; i < ARRAY_LEN(cmds); ++i) {
        std::cout << cmds[i].name << std::endl <<
            "    usage: " << cmds[i].usage << std::endl <<
            "    " << cmds[i].desc << std::endl << std::endl;
    }

    return 0;
};

int main(int argc, char *argv[])
{
    // if no args, print help prompt
    if (argc <= 1) {
        func_help(argc - 1, &argv[0]);
        return 1;
    }

    // interpret command
    for (int i =0; i < ARRAY_LEN(cmds); ++i) {
        if (!strcmp(argv[1], cmds[i].name)) {
            return cmds[i].func(argc - 1, &argv[1]);
        }
    }

    std::cout << "Command '" << argv[1] << "' not recognized" << std::endl;
    func_help(argc - 1, &argv[0]);
    return 2;
}
