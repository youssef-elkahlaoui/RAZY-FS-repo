#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
    // Nom du fichier
    if(argc!=2){
    fprintf(stderr,"Utilisation : %s <file_name>",argv[0]);
    exit(EXIT_FAILURE);
    }
    char *nom_fichier=argv[1];
// Ouvrir le fichier en mode lecture
    FILE *fichier = fopen(nom_fichier, "r");

    if (fichier == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Lire et afficher le contenu du fichier
    int caractere;
    while ((caractere = fgetc(fichier)) != EOF) {
        putchar(caractere);
    }

    // Fermer le fichier
    fclose(fichier);

    return 0;
}
