#ifndef CAT_FUNCTIONS_H
#define CAT_FUNCTIONS_H

typedef struct {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
} Flags;

void file_reader(char *name, Flags *flags);
int parse_flags(int argc, char *argv[], Flags *flags);
void print_line_number(int *line_count, int is_empty, Flags *flags);
void print_special_char(int c, Flags *flags);

#endif