#include <stdio.h>

const char * plugin_name = "Test Plugin 1";
const char * plugin_version = "1.0.1";

int plugin_init(void)
{
    printf("%s initializing!\n", plugin_name);
    return 0;
}

int plugin_run(void)
{
    printf("%s running!\n", plugin_name);
    return 0;
}

int plugin_cleanup(void)
{
    printf("%s cleaning up!\n", plugin_name);
    return 0;
}
