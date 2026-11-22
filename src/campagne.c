
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "campagne.h"
#include "foret.h"

t_campagne createCampaign(void) {
    t_campagne c;
    c.K = 50;
    c.E = 3;
    c.S = 120;
    c.A = 0.25;
    c.R = 1;
    c.graine = 1;
    c.identique = 0;
    strcpy(c.sortie, "output/campagne");
    return c;
}

int runCampaign(t_campagne c) {
    char nomArbres[LONGUEUR_NOM + 32];
    char nomForets[LONGUEUR_NOM + 32];
    snprintf(nomArbres, sizeof(nomArbres), "%s_arbres.csv", c.sortie);
    snprintf(nomForets, sizeof(nomForets), "%s_forets.csv", c.sortie);

    FILE *arbres = fopen(nomArbres, "wt");
    FILE *forets = fopen(nomForets, "wt");
    if (arbres == NULL || forets == NULL) {
        perror("Impossible de creer les fichiers");
        if (arbres != NULL) {
            fclose(arbres);
        }
        if (forets != NULL) {
            fclose(forets);
        }
        return 0;
    }

    fprintf(arbres, "# K=%d E=%d A=%.3f S=%d R=%d graine=%d identique=%d HMAX=%d P_max=%d\n",
            c.K, c.E, c.A, c.S, c.R, c.graine, c.identique, HMAX_CAMPAGNE, PMAX_CAMPAGNE);
    fprintf(arbres, "foret;arbre;rameaux;hauteur;cime;extension;tronque\n");

    fprintf(forets, "# K=%d E=%d A=%.3f S=%d R=%d graine=%d identique=%d HMAX=%d P_max=%d\n",
            c.K, c.E, c.A, c.S, c.R, c.graine, c.identique, HMAX_CAMPAGNE, PMAX_CAMPAGNE);
    fprintf(forets, "foret;rameaux;cime_moy;extension_moy\n");

    clock_t debut = clock();

    for (int r = 0; r < c.R; r++) {
        t_foret f = createForest(c.K, c.E, HMAX_CAMPAGNE, c.A, PMAX_CAMPAGNE);
        plantForest(&f, c.graine + r, c.identique);
        simulateForest(&f, c.S);

        long total = 0;
        double sommeCime = 0;
        double sommeExtension = 0;

        for (int k = 0; k < c.K; k++) {
            t_arbre_foret *a = &f.arbres[k];
            float extension = a->xmax - a->xmin;

            fprintf(arbres, "%d;%d;%d;%d;%.3f;%.3f;%d\n",
                    r, k, a->step.arbre.nb_rameaux, a->hauteur,
                    a->cime, extension, a->tronque);

            total += a->step.arbre.nb_rameaux;
            sommeCime += a->cime;
            sommeExtension += extension;
        }

        fprintf(forets, "%d;%ld;%.4f;%.4f\n",
                r, total, sommeCime / c.K, sommeExtension / c.K);

        printf("Foret %d/%d, graine %d : %ld rameaux\n",
               r + 1, c.R, c.graine + r, total);

        freeForest(&f);
    }

    fclose(arbres);
    fclose(forets);

    double duree = (double) (clock() - debut) / CLOCKS_PER_SEC;
    printf("Temps de calcul : %.3f secondes\n", duree);
    printf("Fichiers crees : %s et %s\n", nomArbres, nomForets);
    return 1;
}
