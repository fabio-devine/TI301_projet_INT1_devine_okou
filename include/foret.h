
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

/***
 * @brief colonne de la case qui contient l'abscisse x (la forêt fait le tour : modulo C)
 * @param f : la forêt
 * @param x : position, éventuellement négative ou au moins égale à C
 * @return la colonne, entre 0 et C - 1
 */
int columnOf(t_foret *f, float x);

/***
 * @brief rangée de la case qui contient l'altitude y (au moins HMAX : dernière rangée)
 * @param f : la forêt
 * @param y : altitude
 * @return la rangée, entre 0 et HMAX - 1
 */
int rowOf(t_foret *f, float y);

t_foret createForest(int K, int E, int HMAX, double A, int P_max);
void addToGrid(t_foret *f, t_rameau *r);
void addTreeToGrid(t_foret *f, t_rameau *r);

void computeLight(t_foret *f);
double getLight(t_foret *f, t_rameau *r);

#endif //FORET_FORET_H
