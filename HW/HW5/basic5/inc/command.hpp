#ifndef __COMMAND_H__
#define __COMMAND_H__

struct command
{
    const char *name;
    const char *usage;
    const char *desc;
    int (* func)(int argc, const char * const*argv);
};

#endif//__COMMAND_H__
