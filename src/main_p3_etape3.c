
#include <stdio.h>
#include <stdlib.h>
#include "statistiques.h"

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 5) {
        printf("Utilisation : p3_etape_3 fichier colonne [nb_classes] [fichier_svg]\n");
        return 1;
    }

    const char *fichier = argv[1];
    const char *colonne = argv[2];
    int nb_classes = 20;
    const char *svg = "output/histogramme.svg";

    if (argc >= 4) {
        char *fin;
        long valeur = strtol(argv[3], &fin, 10);
        if (*fin != '\0' || valeur <= 0 || valeur > 1000) {
            printf("Nombre de classes invalide\n");
            return 1;
        }
        nb_classes = (int) valeur;
    }

    if (argc >= 5) {
        svg = argv[4];
    }

    int n = 0;
    double *valeurs = readColumn(fichier, colonne, &n);
    if (valeurs == NULL || n == 0) {
        printf("Impossible de lire les valeurs\n");
        free(valeurs);
        return 1;
    }

    printf("Fichier : %s\n", fichier);
    printf("Colonne : %s\n", colonne);
    displaySummary(valeurs, n);

    double min, largeur;
    int *effectifs = computeHistogram(valeurs, n, nb_classes, &min, &largeur);
    if (effectifs == NULL) {
        free(valeurs);
        return 1;
    }

    printf("\nHistogramme :\n");
    displayHistogram(effectifs, nb_classes, min, largeur);
    histoToSVG(effectifs, nb_classes, min, largeur, colonne, svg);
    printf("\nFichier SVG : %s\n", svg);

    free(effectifs);
    free(valeurs);
    return 0;
}
