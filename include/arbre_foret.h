#ifndef FORET_ARBRE_FORET_H
#define FORET_ARBRE_FORET_H

#include "croissance_step.h"

typedef struct s_arbre_foret {
    t_arbre_step step;
    int id;
    int hauteur;
    float cime;
    float xmin;
    float xmax;
    int nb_bourgeons;
    int tronque;
} t_arbre_foret;

int countBranches(t_rameau *r);
int computeHeight(t_rameau *r);
float computeTop(t_rameau *r);
float computeXMin(t_rameau *r);
float computeXMax(t_rameau *r);
int countBuds(t_rameau *r);
void freeBranches(t_rameau *r);
t_arbre_foret createForestTree(int id, float x, float y, int seed);
void freeForestTree(t_arbre_foret *a);

#endif
