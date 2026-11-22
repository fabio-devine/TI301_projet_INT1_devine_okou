
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "campagne.h"

int main(int argc, char *argv[]) {
    t_campagne c = createCampaign();
    int ok = 1;

    for (int i = 1; i < argc && ok; i++) {
        if (strcmp(argv[i], "--K") == 0 && i + 1 < argc) {
            c.K = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--E") == 0 && i + 1 < argc) {
            c.E = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--A") == 0 && i + 1 < argc) {
            c.A = atof(argv[++i]);
        } else if (strcmp(argv[i], "--S") == 0 && i + 1 < argc) {
            c.S = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--R") == 0 && i + 1 < argc) {
            c.R = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--graine") == 0 && i + 1 < argc) {
            c.graine = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--identique") == 0) {
            c.identique = 1;
        } else if (strcmp(argv[i], "--sortie") == 0 && i + 1 < argc) {
            const char *nom = argv[++i];
            if (strlen(nom) >= LONGUEUR_NOM) {
                printf("Nom de sortie trop long\n");
                ok = 0;
            } else {
                strcpy(c.sortie, nom);
            }
        } else {
            printf("Parametre inconnu ou incomplet : %s\n", argv[i]);
            ok = 0;
        }
    }

    if (c.K <= 0 || c.E <= 0 || c.R <= 0 || c.S < 0 ||
        c.A < 0 || c.A > 1) {
        printf("Parametres invalides\n");
        ok = 0;
        }

    if (!ok) {
        return 1;
    }
    return runCampaign(c) ? 0 : 1;
}
