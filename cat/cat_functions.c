#include <stdio.h>
#include <unistd.h>
#include "cat_functions.h"

extern int optind;

void file_reader(char *file_name) {
    FILE * fp = fopen(file_name, "r");
    if (fp != NULL) {
        int c;
        while ((c = fgetc(fp)) != EOF) {
            putc(c, stdout);
        }
        fclose(fp);

    } else {
        printf("file not found");
    }
}

int parse_flags(int argc, char *argv[], Flags *flags) {
    int opt;
    while ((opt = getopt(argc, argv, "beEnstT")) != -1) {
        switch(opt) {
            case 'b':
                flags -> b = 1;
                break;
            case 'e':
                flags -> e = 1;
                flags -> v = 1;
                break;
            case 'E':
                flags -> e = 1;
                break;
            case 'n':
                flags -> n = 1;
                break;
            case 's':
                flags -> s = 1;
                break;
            case 't':
                flags -> t = 1;
                flags -> v = 1;
                break;
            case 'T':
                flags -> t= 1;
                break;
            default: 
                fprintf(stderr, "usage cat [beEnstT]");
                return -1;
        }
    }
    if (flags -> b) {
        flags -> n = 0;
    }

    return optind;


}
