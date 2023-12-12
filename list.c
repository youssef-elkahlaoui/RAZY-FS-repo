#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;

    int show_files = 1; // Flag to indicate whether to show files (default is true)
    int opt;

    // Process command-line options
    while ((opt = getopt(argc, argv, "d")) != -1) {
        switch (opt) {
            case 'd':
                show_files = 0; // Set flag to false to show only directories
                break;
            default:
                fprintf(stderr, "Usage: %s [-d] <directory_path>\n", argv[0]);
                return 1;
        }
    }

    // Check if a directory path is provided as a command-line argument
    if (optind >= argc) {
        fprintf(stderr, "Usage: %s [-d] <directory_path>\n", argv[0]);
        return 1;
    }

    const char *path = argv[optind];

    // Open the directory
    dir = opendir(path);

    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Read and print directory entries based on the show_files flag
    while ((entry = readdir(dir)) != NULL) {
        if (show_files || entry->d_type == DT_DIR) {
            printf("%s\n", entry->d_name);
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}
