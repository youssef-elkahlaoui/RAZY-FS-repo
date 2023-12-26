#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINES 10

void print_head(FILE *file, int num_lines) {
    int c;
    int lines = 0;

    while ((c = fgetc(file)) != EOF) {
        putchar(c);

        if (c == '\n') {
            lines++;
            if (lines == num_lines) {
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    int num_lines = DEFAULT_LINES;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename [num_lines]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (argc == 3) {
        num_lines = atoi(argv[2]);
    }

    print_head(file, num_lines);

    fclose(file);

    return 0;
}
