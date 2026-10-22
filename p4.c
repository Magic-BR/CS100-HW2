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
      while (i < argc) {
        if (strcmp(argv[i], "-o") == 0) {
            printf("option -o, output file: %s\n", argv[i+1]);
            i += 2;
        } else if (strcmp(argv[i], "-I") == 0) {
            printf("option -I, include directory: %s\n", argv[i+1]);
            i += 2;
        } else if (strncmp(argv[i], "-std=", 5) == 0) {
            printf("option -std, standard: %s\n", argv[i] + 5);
            i += 1;
        } else if (strncmp(argv[i], "-W", 2) == 0) {
            printf("warning flag %s\n", argv[i]);
            i += 1;
        } else {
            // source / header file
            printf("source file: %s\n", argv[i]);
            i += 1;
        }
    }
    return 0;
}
    