#include <stdio.h>

const char * plugin_name = "Test Plugin 2";
const char * plugin_version = "1.0.3";

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
