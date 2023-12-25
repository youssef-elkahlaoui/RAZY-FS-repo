#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
    // Nom du fichier
    if(argc!=2){
    fprintf(stderr,"Utilisation : %s <file_name>",argv[0]);
    exit(EXIT_FAILURE);
    }
    char *nom_fichier=argv[1];

    // Ouvrir le fichier en mode écriture
    FILE *fichier = fopen(nom_fichier, "a");

    if (fichier == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Demander à l'utilisateur de saisir du texte
    printf("Écrivez votre texte (appuyez sur Ctrl-D pour terminer) :\n");

    char caractere;
    while ((caractere = getchar()) != EOF) {
        fputc(caractere, fichier);
    }

    // Fermer le fichier
    fclose(fichier);

    printf("Contenu écrit dans le fichier avec succès.\n");

    return 0;
}
