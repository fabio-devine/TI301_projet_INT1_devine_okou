
#ifndef FORET_CAMPAGNE_H
#define FORET_CAMPAGNE_H

#define LONGUEUR_NOM 256
#define HMAX_CAMPAGNE 160
#define PMAX_CAMPAGNE 20000

typedef struct s_campagne {
    int K, E, S;
    double A;
    int R;
    int graine;
    int identique;
    char sortie[LONGUEUR_NOM];
} t_campagne;

t_campagne createCampaign(void);
int runCampaign(t_campagne c);

#endif
