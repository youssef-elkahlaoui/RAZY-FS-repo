#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Construire le chemin complet du fichier
    char filepath[1024];
    snprintf(filepath, sizeof(filepath), "%s/%s", argv[1], argv[2]);

    // Vérifier si le fichier existe déjà
    FILE *file = fopen(filepath, "r");
    if (file != NULL) {
        fclose(file);
        fprintf(stderr, "Error: File '%s' already exists.\n", filepath);
        closedir(dir);
        exit(EXIT_FAILURE);
    }

    // Créer le fichier
    file = fopen(filepath, "w");
    if (file == NULL) {
        perror("fopen");
        closedir(dir);
        exit(EXIT_FAILURE);
    }

    printf("File '%s' created in directory '%s'.\n", argv[2], argv[1]);

    // Fermer le fichier et le répertoire
    fclose(file);
    closedir(dir);

    return 0;
}

