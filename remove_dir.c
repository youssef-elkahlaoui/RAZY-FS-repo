#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void supprimerFichier(const char *chemin) {
    if (remove(chemin) == -1) {
        perror("Erreur lors de la suppression du fichier");
        exit(EXIT_FAILURE);
    }
}

void supprimerRepertoire(const char *chemin) {
    DIR *dir = opendir(chemin);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char chemin_complet[PATH_MAX];
            snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", chemin, entry->d_name);

            struct stat st;
            if (stat(chemin_complet, &st) == -1) {
                perror("Erreur lors de la récupération des informations sur le fichier");
                exit(EXIT_FAILURE);
            }

            if (S_ISDIR(st.st_mode)) {
                // Récursivement supprimer le répertoire
                supprimerRepertoire(chemin_complet);
            } else {
                // Supprimer le fichier
                supprimerFichier(chemin_complet);
            }
        }
    }

    closedir(dir);

    // Supprimer le répertoire une fois vide
    if (rmdir(chemin) == -1) {
        perror("Erreur lors de la suppression du répertoire");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Utilisation: %s <chemin_du_repertoire>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *directory_path = argv[1];

    // Supprime le répertoire récursivement
    supprimerRepertoire(directory_path);

    printf("Répertoire supprimé avec succès.\n");

    return 0;
}
