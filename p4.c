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
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (strcmp(arg, "-Wall") == 0) {
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        } 
        else if (strcmp(arg, "-Wpedantic") == 0) {
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        } 
        else if (strcmp(arg, "-Wextra") == 0) {
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        } 
        else if (strcmp(arg, "-Werror") == 0) {
            printf("-Werror: Make all warnings into errors.\n");
        }
        else if (strcmp(arg, "-o") == 0) {
            // 题目保证参数合法，所以 i+1 一定存在           
            printf("-o %s: Place the primary output in file %s.\n", argv[i+1], argv[i+1]);
            i++; // 跳过下一个参数，因为它已经被处理了
        } 
        else if (strcmp(arg, "-I") == 0) {
            printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", argv[i+1], argv[i+1]);
            i++;
        else if (strncmp(arg, "-std=", 5) == 0) {
            char *std_val = arg + 5; 
            
            char *prefix = "";
            if (strncmp(std_val, "c++", 3) == 0) {
                prefix = "ISO C++";
                std_val += 3; // 移动指针跳过 "c++"
            } else if (strncmp(std_val, "gnu++", 5) == 0) {
                prefix = "GNU dialect of C++";
                std_val += 5; // 移动指针跳过 "gnu++"
            } else if (strncmp(std_val, "gnu", 3) == 0) {
                prefix = "GNU dialect of C";
                std_val += 3; // 移动指针跳过 "gnu"
            } else if (strncmp(std_val, "c", 1) == 0) {
                prefix = "ISO C";
                std_val += 1; // 移动指针跳过 "c"
            }
            
            printf("-std=%s: Set the language standard to %s %s.\n", arg + 5, prefix, std_val);
        }

        else {
            char *type = "";
            int len = strlen(arg);
            
            if (strstr(arg, ".c") == arg + len - 2) {
                type = "C source code";
            } else if (strstr(arg, ".h") == arg + len - 2) {
                type = "C/C++ header file";
            } else if (strstr(arg, ".hpp") == arg + len - 4 || strstr(arg, ".hxx") == arg + len - 4) {
                type = "C++ header file";
            } else if (strstr(arg, ".cpp") == arg + len - 4 || 
                       strstr(arg, ".cc") == arg + len - 3 || 
                       strstr(arg, ".cxx") == arg + len - 4) {
                type = "C++ source code";
            }
            
            printf("%s: %s as input file.\n", arg, type);
        }
    }

 
    return 0;
}
    