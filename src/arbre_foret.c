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


float computeTop(t_rameau *r) {
    if (r == NULL) {
        return 0;
    }
    float max = r->y;

    for (int i = 0; i < r->nb_fils; i++) {
        float y = computeTop(r->p_fils[i]);
        if (y > max) {
            max = y;
        }
    }
    return max;
}


float computeXMin(t_rameau *r) {
    if (r == NULL) {
        return 0;
    }
    float min = r->x;

    for (int i = 0; i < r->nb_fils; i++) {
        float x = computeXMin(r->p_fils[i]);
        if (x < min) {
            min = x;
        }
    }
    return min;
}


float computeXMax(t_rameau *r) {
    if (r == NULL) {
        return 0;
    }
    float max = r->x;

    for (int i = 0; i < r->nb_fils; i++) {
        float x = computeXMax(r->p_fils[i]);
        if (x > max) {
            max = x;
        }
    }
    return max;
}



