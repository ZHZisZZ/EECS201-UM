#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

void print_usage(FILE *f)
{
    fprintf(f, "usage: runner <plugin path>\n");
    fprintf(f, "  <plugin path> refers to a *.so file\n");
    fprintf(f, "  e.g. \"runner plugin1.so\"\n");
}

typedef struct plugin_
{
    void *handle;           // handle from dlopen(); NULL represents unloadable
    const char * name;      // plugin name:             symbol name is "plugin_name"
    const char * version;   // plugin version:          symbol name is "plugin_version"
    int (*init)(void);      // plugin init function:    symbol name is "plugin_init"
    int (*run)(void);       // plugin run function:     symbol name is "plugin_run"
    int (*cleanup)(void);   // plugin cleanup function: symbol name is "plugin_cleanup"
} plugin;

/**
 * Load a plugin and populate the plugin struct fields
 * If any part of loading process fails, the p->handle is set to NULL
 * @param file_path String representing the path to a plugin SO file
 * @param p         Pointer to plugin struct to set values for
 */
void load_plugin(const char *file_path, plugin *p)
{
    // TODO load the plugin and setup the plugin struct
    // TODO print "Loaded '<PLUGIN_NAME>' <PLUGIN_VERSION>" with a new line
    p->handle = dlopen(file_path, RTLD_LAZY);
    if (!p->handle) { p->handle = NULL; return;} 
    p->name = *(const char **)dlsym(p->handle, "plugin_name");
    p->version = *(const char **)dlsym(p->handle, "plugin_version");
    p->init = dlsym(p->handle, "plugin_init");
    p->run = dlsym(p->handle, "plugin_run");
    p->cleanup = dlsym(p->handle, "plugin_cleanup");
    printf("Loaded '%s' %s\n", p->name, p->version);
    //      e.g.: "Loaded 'Test Plugin 1' 1.0.1"
    //            (don't include the double quotes ;P)
}

/**
 * Closes the plugin's library
 * If the handle is NULL, simply ignore it
 * @param p         Pointer to plugin struct to close
 */
void close_plugin(plugin *p)
{
    // TODO
    if (!p->handle) return;
    dlclose(p->handle);
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        print_usage(stderr);
        return 1;
    }

    int num_plugins = argc - 1;
    plugin *plugins = malloc(sizeof(plugin) * (num_plugins));

    char *buffer = malloc(sizeof(char)*256);

    // load each plugin
    for (int i = 1; i < argc; ++i) {
        const char *file_path = argv[i];
        size_t len = strlen(argv[i]);

        // we're taking only paths
        // if it has a slash, no need to prepend ./
        int contains_slash = 0;
        for (int j = 0; j < len; ++j) {
            if (file_path[j] == '/') {
                contains_slash = 1;
                break;
            }
        }

        if (!contains_slash) {
            if (len + 2 > 256 - 1)
                buffer = realloc(buffer, sizeof(char) * (len + 2 + 1));

            sprintf(buffer, "./%s", file_path);
            // look at me, I'm the file_path now
            file_path = buffer;
        }

        load_plugin(file_path, &plugins[i-1]);
    }

    // initialize each plugin
    for (int i = 0; i < num_plugins; ++i) {
        if (plugins[i].handle != NULL) {
            // TODO
            (*plugins[i].init)();
        }
    }

    // run each plugin
    for (int i = 0; i < num_plugins; ++i) {
        if (plugins[i].handle != NULL) {
            // TODO
            (*plugins[i].run)();
        }
    }

    // cleanup each plugin
    for (int i = 0; i < num_plugins; ++i) {
        if (plugins[i].handle != NULL) {
            // TODO
            (*plugins[i].cleanup)();
        }
    }

    // close each plugin
    for (int i = 0; i < num_plugins; ++i) {
        close_plugin(&plugins[i]);
    }

    free(buffer);
    free(plugins);
    return 0;
}


