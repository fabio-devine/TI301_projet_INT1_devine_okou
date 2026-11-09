/* arbre_foret.c : partie 2, étapes 1 et 3 — l'arbre de la forêt, ses mesures et sa pousse à la lumière (fichier fourni vide, à compléter) */

#include "arbre_foret.h"
#include <stdlib.h>
#include "croissance.h"
#include "croissance_lumiere.h"

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

int countBuds(t_rameau *r) {
    if (r == NULL) {
        return 0;
    }
    if (r->nb_fils == 0) {
        return 1;
    }
    int count = 0;

    for (int i = 0; i < r->nb_fils; i++) {
        count += countBuds(r->p_fils[i]);
    }
    return count;
}

void freeBranches(t_rameau *r) {
    if (r == NULL) {
        return;
    }

    for (int i = 0; i < r->nb_fils; i++) {
        freeBranches(r->p_fils[i]);
    }
    free(r->p_fils);
    free(r);
}

t_arbre_foret createForestTree(int id, float x, float y, int seed) {
    t_arbre_foret a;
    a.step = createTreeStep(x, y, seed);
    a.id = id;
    a.hauteur = 0;
    a.cime = y;
    a.xmin = x;
    a.xmax = x;
    a.nb_bourgeons = 1;
    a.tronque = 0;
    return a;
}


void freeForestTree(t_arbre_foret *a) {
    clearBuds(&a->step);
    freeBranches(a->step.arbre.pied);
    a->step.arbre.pied = NULL;
}

void growSeason(t_arbre_foret *a, double lumiere) {
    t_queue G = createEmptyQueue();
    a->step.saison++;
    while (!isEmptyQueue(a->step.bourgeons)) {
        t_rameau *b = dequeue(&a->step.bourgeons);
        if (canGrowInLight(lumiere)) {
            int n = howManyBranchesInLight(lumiere);
            growBud(&a->step.arbre, b, n, a->step.saison);
            a->nb_bourgeons += n - 1;
            for (int i = 0; i < n; i++) {
                t_rameau *fils = b->p_fils[i];
                enqueue(&G, fils);
                if (fils->gen > a->hauteur) {
                    a->hauteur = fils->gen;
                }
                if (fils->y > a->cime) {
                    a->cime = fils->y;
                }
                if (fils->x < a->xmin) {
                    a->xmin = fils->x;
                }
                if (fils->x > a->xmax) {
                    a->xmax = fils->x;
                }
            }
        } else {
            enqueue(&G, b);
        }
    }
    a->step.bourgeons = G;
}


