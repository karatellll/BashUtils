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

void file_reader(char *name);
int parse_flags(int argc, char *argv[], Flags flags);

#endif