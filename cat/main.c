#include <stdio.h>

typedef struct {
    int b;
    int e;
    int n; 
    int s;
    int t;
    int v;
} flags;

void file_reader(char *name);

int main(int argc, char *argv[]) {
    file_reader("file1.txt");
}

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
