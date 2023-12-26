#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINES 10
#define MAX_LINE_LENGTH 1024

void print_tail(FILE *file, int num_lines) {
    long pos;
    char line[MAX_LINE_LENGTH];
    int lines = 0;

    fseek(file, 0, SEEK_END);
    pos = ftell(file);

    while (pos) {
        fseek(file, --pos, SEEK_SET);

        if (fgetc(file) == '\n') {
            if (lines++ == num_lines) {
                break;
            }
        }
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
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

    print_tail(file, num_lines);

    fclose(file);

    return 0;
}
