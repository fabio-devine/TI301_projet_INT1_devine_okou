
/* foret.c : partie 2, étapes 4 à 6 — la forêt, ses grilles d'occupation et de lumière, sa pousse */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "foret.h"

/* ---------------------------------------------------------------- code fourni */

int columnOf(t_foret *f, float x) {
    int c = (int) floorf(x) % f->C;
    if (c < 0) {
        c += f->C;
    }
    return c;
}

int rowOf(t_foret *f, float y) {
    int r = (int) floorf(y);
    if (r >= f->HMAX) {
        r = f->HMAX - 1;
    } else if (r < 0) {
        r = 0;
    }
    return r;
}

/* ---------------------------------------------------------------- étape 4 */

t_foret createForest(int K, int E, int HMAX, double A, int P_max) {
    t_foret f;
    f.K = K;
    f.E = E;
    f.C = K * E;
    f.HMAX = HMAX;
    f.A = A;
    f.P_max = P_max;
    f.saison = 0;
    f.arbres = calloc(K, sizeof(t_arbre_foret));
    f.occupation = malloc(HMAX * sizeof(int *));
    f.lumiere = malloc(HMAX * sizeof(double *));
    if (f.arbres == NULL || f.occupation == NULL || f.lumiere == NULL) {
        perror("createForest");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < HMAX; i++) {
        f.occupation[i] = calloc(f.C, sizeof(int));
        f.lumiere[i] = calloc(f.C, sizeof(double));
        if (f.occupation[i] == NULL || f.lumiere[i] == NULL) {
            perror("createForest");
            exit(EXIT_FAILURE);
        }
    }
    return f;
}

void addToGrid(t_foret *f, t_rameau *r) {
    int ligne = rowOf(f, r->y);
    int colonne = columnOf(f, r->x);
    f->occupation[ligne][colonne]++;
}

void addTreeToGrid(t_foret *f, t_rameau *r) {
    if (r == NULL) {
        return;
    }
    addToGrid(f, r);

    for (int i = 0; i < r->nb_fils; i++) {
        addTreeToGrid(f, r->p_fils[i]);
    }
}

/* ---------------------------------------------------------------- étape 5 */

void computeLight(t_foret *f) {
    for (int c = 0; c < f->C; c++) {
        double lumiere = 1.0;

        for (int r = f->HMAX - 1; r >= 0; r--) {
            f->lumiere[r][c] = lumiere;

            for (int i = 0; i < f->occupation[r][c]; i++) {
                lumiere *= 1.0 - f->A;
            }
        }
    }
}

double getLight(t_foret *f, t_rameau *r) {
    int ligne = rowOf(f, r->y);
    int colonne = columnOf(f, r->x);
    return f->lumiere[ligne][colonne];
}
