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
        else if (strncmp(argv[i], "-std=", 5) == 0)
        {
            char *suffix = argv[i] + 5;
            char buf[128];
            char type[32];
            strcpy(buf, suffix);
            if (buf[0] == 'c' && buf[1] != '+')
            {
                snprintf(type, sizeof(type), "ISO %s", buf);
            }
            else if (strstr(buf, "c++") == buf)
            {
                snprintf(type, sizeof(type), "ISO %s", buf);
            }
            else if (strstr(buf, "gnu") == buf)
            {
                char *inner = buf + 3;
                if (inner[0] == 'c' && inner[1] != '+')
                {
                    snprintf(type, sizeof(type), "GNU dialect of %s", inner);
                }
                else if (strstr(inner, "c++") == inner)
                {
                    snprintf(type, sizeof(type), "GNU dialect of %s", inner);
                }
            }
            printf("-std=%s: Set the language standard to %s.\n", suffix, type);
            i++;
        }
        else
        {
            char *fn = argv[i];
            char *ext = strrchr(fn, '.');
            char *desc;
            if (ext == NULL)
            {
                desc = "unknown";
            }
            else if (strcmp(ext, ".c") == 0)
            {
                desc = "C source code";
            }
            else if (strcmp(ext, ".h") == 0)
            {
                desc = "C/C++ header file";
            }
            else if (strcmp(ext, ".cpp") == 0 || strcmp(ext, ".cc") == 0 || strcmp(ext, ".cxx") == 0)
            {
                desc = "C++ source code";
            }
            else if (strcmp(ext, ".hpp") == 0 || strcmp(ext, ".hxx") == 0)
            {
                desc = "C++ header file";
            }
            else
            {
                desc = "unknown";
            }
            printf("%s: %s as input file.\n", fn, desc);
            i++;
        }
    }
    return 0;
}
    