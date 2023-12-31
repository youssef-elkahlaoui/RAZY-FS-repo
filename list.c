#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {

    if(argc!=2){
       fprintf(stderr,"Utilisation: %s <chemin_du_repertoire>",argv[0]);
       exit(EXIT_FAILURE);
    }
    const char *directory_path = argv[1]; // Lit chaque entrée du répertoire
 
    // Ouvre le répertoire
    DIR *dir = opendir(directory_path);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return 1;
    }
    
     // Lit chaque entrée du répertoire
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Affiche le nom de l'entrée
        printf("%s\n", entry->d_name);
    }

    // Ferme le répertoire
    closedir(dir);

    return 0;
}
