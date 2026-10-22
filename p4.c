/* CS100 Fall 2026 - HW2 Problem 4: GCC argument descriptor
 *
 * Read GCC-style command-line arguments (argv) and print a description
 * for each of them, in order. No standard input in this problem.
 * Do not rename this file.
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* TODO: your code here */
    (void)argc;
    (void)argv;
   int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "-Wall") == 0)
        {
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
            i++;
        }
        else if (strcmp(argv[i], "-Wpedantic") == 0)
        {
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
            i++;
        }
        else if (strcmp(argv[i], "-Wextra") == 0)
        {
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
            i++;
        }
        else if (strcmp(argv[i], "-Werror") == 0)
        {
            printf("-Werror: Make all warnings into errors.\n");
            i++;
        }
        else if (strcmp(argv[i], "-o") == 0)
        {
            printf("-o %s: Place the primary output in file %s.\n", argv[i+1], argv[i+1]);
            i += 2;
        }
        else if (strcmp(argv[i], "-I") == 0)
        {
            printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", argv[i+1], argv[i+1]);
            i += 2;
        }
        else if (strstr(argv[i], "-std=") == argv[i])
        {
            const char *val = argv[i] + 5;
            char buf[128];
            if (val[0] == 'c' && val[1] != '+')
            {
                snprintf(buf, sizeof(buf), "ISO %s", val);
            }
            else if (strncmp(val, "c++", 3) == 0)
            {
                snprintf(buf, sizeof(buf), "ISO %s", val);
            }
            else if (strncmp(val, "gnu", 3) == 0)
            {
                snprintf(buf, sizeof(buf), "GNU dialect of %s", val + 3);
            }
            else
            {
                snprintf(buf, sizeof(buf), "%s", val);
            }
            printf("%s: Set the language standard to %s.\n", argv[i], buf);
            i++;
        }
        else
        {
            const char *fn = argv[i];
            const char *ext = strrchr(fn, '.');
            const char *type;
            if (ext == NULL)
            {
                type = "unknown";
            }
            else if (strcmp(ext, ".c") == 0)
            {
                type = "C source code";
            }
            else if (strcmp(ext, ".h") == 0)
            {
                type = "C/C++ header file";
            }
            else if (strcmp(ext, ".cpp") == 0 || strcmp(ext, ".cc") == 0 || strcmp(ext, ".cxx") == 0)
            {
                type = "C++ source code";
            }
            else if (strcmp(ext, ".hpp") == 0 || strcmp(ext, ".hxx") == 0)
            {
                type = "C++ header file";
            }
            else
            {
                type = "unknown";
            }
            printf("%s: %s as input file.\n", fn, type);
            i++;
        }
    }
    return 0;
}
