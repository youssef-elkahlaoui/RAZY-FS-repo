#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {

    if(argc!=2){
       fprintf(stderr,"Utilisation: %s <chemin_du_repertoire>",argv[0]);
       exit(EXIT_FAILURE);
    }
    const char *directory_path = argv[1];

    // Crée le répertoire
    if (mkdir(directory_path, 0777) == -1) {
        perror("Erreur lors de la création du répertoire");
        return 1;
    }

    // Ouvre le répertoire
    DIR *dir = opendir(directory_path);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return 1;
    }

    // Ferme le répertoire
    closedir(dir);

    return 0;
}
