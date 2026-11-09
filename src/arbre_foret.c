/* arbre_foret.c : partie 2, étapes 1 et 3 — l'arbre de la forêt, ses mesures et sa pousse à la lumière (fichier fourni vide, à compléter) */

#include "arbre_foret.h"
#include <stdlib.h>

int countBranches(t_rameau *r) {
    if (r == NULL) {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < r->nb_fils; i++) {
        count += countBranches(r->p_fils[i]);
    }
    return count;
}


int computeHeight(t_rameau *r) {
    if (r == NULL) {
        return -1;
    }
    int max = r->gen;

    for (int i = 0; i < r->nb_fils; i++) {
        int h = computeHeight(r->p_fils[i]);
        if (h > max) {
            max = h;
        }
    }
    return max;
}
