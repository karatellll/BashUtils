#include <stdio.h>
#include <unistd.h>
#include "cat_functions.h"

extern int optind;

void file_reader(char *file_name, Flags *flags) {
    FILE * fp = fopen(file_name, "r");

    int c;
    int last = '\n';
    int line_count = 1;
    int is_empty = 0;

    if (fp != NULL) {
        while ((c = fgetc(fp)) != EOF) {
            if (last == '\n') {
                print_line_number(&line_count, is_empty, flags);
            }
            print_special_char(c, flags);
            last = c;
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

void print_line_number(int *line_count, int is_empty, Flags *flags) {
    if (flags -> b) {
        if (!is_empty) {
            printf("%6d", (*line_count)++);
            printf("\t");
        } else if (flags -> n) {
            printf("%6d", (*line_count)++);
            printf("\t");
        }
    }
}

void print_special_char(int c, Flags *flags) {
    if (c = '\n' && flags -> e) {
        printf("$");
    }
    if (c = '\t' && flags -> t) {
        printf("^I");
    } else {
        putc(c, stdout);
    }

}

