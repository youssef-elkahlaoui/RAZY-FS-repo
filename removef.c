#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <nom_du_fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (remove(argv[1]) != 0) {
        perror("remove");
        exit(EXIT_FAILURE);
    }

    printf("Fichier '%s' supprimé.\n", argv[1]);

    return 0;
}

