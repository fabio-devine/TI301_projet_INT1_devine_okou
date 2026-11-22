
#include <stdio.h>
#include "foret.h"

int main(void) {
    int K = 24;
    int E = 3;
    int S = 32;
    int graine = 1;
    double A = 0.25;
    long total = 0;

    t_foret f = createForest(K, E, 160, A, 20000);
    plantForest(&f, graine, 0);
    simulateForest(&f, S);

    for (int k = 0; k < f.K; k++) {
        total += f.arbres[k].step.arbre.nb_rameaux;
    }

    printf("Nombre de rameaux : %ld\n", total);
    printf("Arbre 0 : %d rameaux\n", f.arbres[0].step.arbre.nb_rameaux);
    printf("Hauteur : %d\n", f.arbres[0].hauteur);
    printf("Cime : %.3f\n", f.arbres[0].cime);

    freeForest(&f);
    return 0;
}
