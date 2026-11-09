
/* foret.h : partie 2, étapes 4 à 6 — la forêt, ses grilles d'occupation et de lumière, sa pousse */

#ifndef FORET_FORET_H
#define FORET_FORET_H

#include "arbre_foret.h"

typedef struct s_foret {
    int K, E, C, HMAX;
    double A;
    int P_max;
    t_arbre_foret *arbres;
    int **occupation;
    double **lumiere;
    int saison;
} t_foret;

int columnOf(t_foret *f, float x);
int rowOf(t_foret *f, float y);

t_foret createForest(int K, int E, int HMAX, double A, int P_max);
void addToGrid(t_foret *f, t_rameau *r);
void addTreeToGrid(t_foret *f, t_rameau *r);

void computeLight(t_foret *f);
double getLight(t_foret *f, t_rameau *r);

void plantForest(t_foret *f, int seed, int identique);
void growSeasonInForest(t_foret *f, t_arbre_foret *a);
void growForestSeason(t_foret *f);
void simulateForest(t_foret *f, int S);
void freeForest(t_foret *f);

#endif //FORET_FORET_H
