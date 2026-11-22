# TI301 â€” Partie 3 : analyse des simulations de forÃªts

**Efrei Paris â€” Structures de donnÃ©es et algorithmes**  
**Auteurs : Victor OKOU et Fabio Devine**

## 1. Conditions de simulation

Deux campagnes ont Ã©tÃ© exÃ©cutÃ©es avec les mÃªmes paramÃ¨tres : 50 arbres par forÃªt (`K = 50`), un espacement `E = 3`, une absorption de lumiÃ¨re `A = 0,25`, 120 saisons et une graine initiale de 101. Les troncs ont Ã©tÃ© plantÃ©s Ã  des hauteurs alÃ©atoires (`identique = 0`). Chaque forÃªt utilise une graine diffÃ©rente.

| Campagne | Nombre de forÃªts | Nombre d'arbres | Temps de calcul |
|---|---:|---:|---:|
| C1 | 40 | 2 000 | 4,893 s |
| C2 | 400 | 20 000 | 45,775 s |

Le temps de calcul a Ã©tÃ© multipliÃ© par environ 9,36 entre C1 et C2, pour un nombre de forÃªts multipliÃ© par 10.

La vÃ©rification des donnÃ©es confirme que les 2 000 arbres de C1 correspondent exactement aux 2 000 premiers arbres de C2. Les moyennes par forÃªt sont cohÃ©rentes avec les mesures des arbres, Ã  l'arrondi du CSV prÃ¨s.

## 2. RÃ©sultats statistiques

Les statistiques suivantes ont Ã©tÃ© recalculÃ©es Ã  partir des fichiers CSV produits par nos simulations. L'Ã©cart-type est calculÃ© avec le diviseur `n`, et l'asymÃ©trie comme le moment centrÃ© d'ordre 3 divisÃ© par le cube de l'Ã©cart-type, conformÃ©ment au code statistique fourni. Les quartiles correspondent aux observations de rang `ceil(n/4)` et `ceil(3n/4)`.

| DonnÃ©es Ã©tudiÃ©es | Effectif | Moyenne | Ã‰cart-type | MÃ©diane | AsymÃ©trie |
|---|---:|---:|---:|---:|---:|
| C1 â€” Cime des arbres | 2 000 | 52,3644 | 39,8709 | 35,3910 | 0,7765 |
| C1 â€” Extension des arbres | 2 000 | 16,3505 | 9,4872 | 13,8370 | 1,0683 |
| C2 â€” Cime des arbres | 20 000 | 53,3947 | 39,9240 | 37,2930 | 0,7113 |
| C1 â€” Cime moyenne par forÃªt | 40 | 52,3644 | 2,9141 | 51,5453 | 1,6758 |
| C2 â€” Cime moyenne par forÃªt | 400 | 53,3947 | 3,0653 | 53,2475 | 0,2931 |
| C2 â€” Extension moyenne par forÃªt | 400 | 16,4933 | 0,6047 | 16,4648 | 0,2409 |

### Minimums, maximums et quartiles

| DonnÃ©es Ã©tudiÃ©es | Minimum | Q1 | Q3 | Maximum |
|---|---:|---:|---:|---:|
| C1 â€” Cime des arbres | 3,6910 | 20,3120 | 83,4250 | 124,7050 |
| C1 â€” Extension des arbres | 0,1490 | 9,9210 | 20,7770 | 52,8240 |
| C2 â€” Cime des arbres | 2,7100 | 20,4470 | 85,8370 | 125,2700 |
| C1 â€” Cime moyenne par forÃªt | 48,1917 | 50,1310 | 53,6816 | 63,7965 |
| C2 â€” Cime moyenne par forÃªt | 44,7942 | 51,2240 | 55,2791 | 65,0087 |
| C2 â€” Extension moyenne par forÃªt | 14,8839 | 16,0527 | 16,9055 | 18,3633 |

### Comparaison avec les rÃ©fÃ©rences du sujet

Les rÃ©sultats sont proches des rÃ©fÃ©rences du professeur, mais ils ne sont pas strictement identiques. Les valeurs ci-dessous montrent les principaux Ã©carts, Ã  investiguer si une correspondance numÃ©rique exacte est exigÃ©e.

| Indicateur | Notre simulation | RÃ©fÃ©rence du sujet |
|---|---:|---:|
| C1 â€” Moyenne des cimes des arbres | 52,3644 | 52,3552 |
| C1 â€” Moyenne des extensions des arbres | 16,3505 | 16,3600 |
| C2 â€” Moyenne des cimes moyennes | 53,3947 | 53,3789 |
| C2 â€” Moyenne des extensions moyennes | 16,4933 | 16,4996 |
| C2 â€” AsymÃ©trie des cimes moyennes | 0,2931 | 0,3098 |
| C2 â€” AsymÃ©trie des extensions moyennes | 0,2409 | 0,3126 |

Les rÃ©ponses ci-dessous s'appuient sur **nos donnÃ©es rÃ©elles**, et non sur les chiffres de rÃ©fÃ©rence.

## 3. RÃ©ponses aux questions du sujet

### Question 1 â€” Distribution des cimes des 2 000 arbres (C1)

![Histogramme des cimes des arbres â€” C1](C1_cime.svg)

L'histogramme prÃ©sente **deux bosses principales**. La premiÃ¨re correspond aux arbres de faible cime, avec un maximum dans la classe **[13,78 ; 18,82[** (239 arbres). La seconde se situe tout Ã  droite, dans la classe **[119,66 ; 124,71]** (284 arbres). Elles reprÃ©sentent respectivement le groupe des arbres restÃ©s relativement petits et celui des arbres ayant atteint une cime Ã©levÃ©e, proche de la hauteur maximale observÃ©e. Entre ces deux groupes, les effectifs sont beaucoup plus faibles.

### Question 2 â€” Distribution des extensions et comparaison des asymÃ©tries (C1)

![Histogramme des extensions des arbres â€” C1](C1_extension.svg)

L'histogramme des extensions prÃ©sente **une seule bosse principale**, autour de **11 Ã  13 unitÃ©s**. Les effectifs diminuent ensuite progressivement vers les grandes extensions : la distribution possÃ¨de une longue queue Ã  droite. Contrairement aux cimes, on n'observe pas une seconde concentration comparable prÃ¨s du maximum.

L'extension possÃ¨de une asymÃ©trie positive de **1,0683**, supÃ©rieure Ã  celle des cimes (**0,7765**). **L'extension est donc la mesure la plus asymÃ©trique**. Les valeurs exceptionnellement grandes se trouvent **Ã  droite** de l'histogramme.

### Question 3 â€” Moyenne, mÃ©diane et caractÃ¨re reprÃ©sentatif de la cime (C1)

La moyenne des cimes vaut **52,3644**, alors que la mÃ©diane vaut **35,3910** : la moyenne est nettement plus Ã©levÃ©e.

La moyenne se situe dans la classe **[49,07 ; 54,11[**, qui contient **54 arbres sur 2 000**, soit **2,7 %** des valeurs. Elle se trouve **entre les deux bosses principales**, dans une zone relativement peu reprÃ©sentÃ©e. La mÃ©diane se trouve plus prÃ¨s du groupe des petits arbres.

Ainsi, la moyenne dÃ©crit le niveau gÃ©nÃ©ral des cimes, mais elle n'est **pas une cime typique** d'un arbre tirÃ© au hasard dans cette distribution. Les deux groupes d'arbres sont mieux visibles sur l'histogramme que dans la seule valeur moyenne.

### Question 4 â€” Distribution des cimes des 20 000 arbres (C2)

![Histogramme des cimes des arbres â€” C2](C2_cime.svg)

Avec **20 000 arbres**, la distribution conserve **les deux mÃªmes bosses** que dans C1. La premiÃ¨re se situe vers **13 Ã  18 unitÃ©s** et la seconde vers **120 Ã  125 unitÃ©s**. Les classes les plus remplies contiennent respectivement **2 256** et **2 265** arbres.

L'histogramme est plus rÃ©gulier, car il contient dix fois plus d'observations, mais sa structure d'ensemble ne change pas. La moyenne passe de **52,3644** (C1) Ã  **53,3947** (C2). L'asymÃ©trie reste positive : **0,7765** (C1), puis **0,7113** (C2).

### Question 5 â€” Distribution des cimes moyennes par forÃªt (C1 et C2)

**C1 â€” 40 forÃªts, 10 classes**

![Histogramme de la cime moyenne â€” C1](C1_cime_moy.svg)

Les 40 moyennes prÃ©sentent une concentration principale autour de **50 Ã  54 unitÃ©s**, mais la forme est irrÃ©guliÃ¨re. Une forÃªt possÃ¨de une moyenne particuliÃ¨rement Ã©levÃ©e, **63,7965**, ce qui allonge la queue vers la droite. L'asymÃ©trie est **1,6758**.

**C2 â€” 400 forÃªts, 20 classes**

![Histogramme de la cime moyenne â€” C2](C2_cime_moy.svg)

Avec 400 forÃªts, l'histogramme possÃ¨de **une seule bosse dominante**, centrÃ©e autour de **53 Ã  54 unitÃ©s**. Il est nettement plus proche d'une courbe en cloche, mÃªme s'il n'est pas parfaitement symÃ©trique. Son asymÃ©trie vaut **0,2931**, contre **0,7113** pour les cimes individuelles de C2.

La dispersion est Ã©galement beaucoup plus faible pour les moyennes par forÃªt : leur Ã©cart-type est **3,0653**, contre **39,9240** pour les cimes individuelles. Cette observation est cohÃ©rente avec la forme gÃ©nÃ©rale annoncÃ©e par le thÃ©orÃ¨me central limite, sans constituer Ã  elle seule une dÃ©monstration de ce thÃ©orÃ¨me.

### Question 6 â€” Distribution des extensions moyennes par forÃªt (C2)

![Histogramme des extensions moyennes â€” C2](C2_extension_moy.svg)

Les extensions moyennes prÃ©sentent Ã©galement **une seule bosse principale**, autour de **16,45 Ã  16,62 unitÃ©s**. La distribution est assez resserrÃ©e et approximativement symÃ©trique, avec une lÃ©gÃ¨re queue vers les grandes valeurs.

L'asymÃ©trie des extensions moyennes vaut **0,2409**, contre **1,0683** pour les extensions des arbres pris individuellement dans C1 (**1,0402** si l'on prend les 20 000 arbres de C2). L'Ã©cart-type des extensions moyennes est **0,6047**, contre **9,4766** pour les extensions individuelles de C2.

L'histogramme des extensions individuelles est nettement Ã©tirÃ© Ã  droite, tandis que celui des extensions moyennes se rapproche d'une forme en cloche.

### Question 7 â€” Les 40 forÃªts de C1 suffisent-elles ? Comparaison gÃ©nÃ©rale

**Non, pas pour reconnaÃ®tre clairement la forme de la distribution des moyennes de cimes.** Avec 40 valeurs seulement, l'histogramme de C1 est assez irrÃ©gulier et sensible aux valeurs extrÃªmes. L'asymÃ©trie de **1,6758** peut donner l'impression d'une distribution fortement dÃ©sÃ©quilibrÃ©e. Avec les 400 moyennes de C2, la forme en cloche devient bien plus nette et l'asymÃ©trie baisse Ã  **0,2931**.

Les cimes et les extensions individuelles ont des distributions diffÃ©rentes : **deux bosses** pour les cimes, contre **une bosse avec une longue queue Ã  droite** pour les extensions. En revanche, leurs **moyennes par forÃªt** prÃ©sentent toutes deux une distribution plus concentrÃ©e, avec une seule bosse principale et une asymÃ©trie faible dans C2 (**0,2931** pour les cimes moyennes et **0,2409** pour les extensions moyennes).

La diffÃ©rence entre les deux mesures est donc beaucoup moins visible dans la forme de leurs distributions de moyennes que dans celle de leurs distributions individuelles.

## 4. Pourquoi la moyenne de `cime_moy` est-elle Ã©gale Ã  celle de `cime` ?

Chaque forÃªt contient exactement 50 arbres. Si l'on note `cime(r,k)` la cime de l'arbre `k` dans la forÃªt `r`, la moyenne des cimes moyennes des 40 forÃªts vaut :

\[
\frac{1}{40}\sum_{r=1}^{40}\left(\frac{1}{50}\sum_{k=1}^{50}\operatorname{cime}(r,k)\right)
=\frac{1}{2000}\sum_{r=1}^{40}\sum_{k=1}^{50}\operatorname{cime}(r,k).
\]

Il s'agit exactement de la moyenne des 2 000 arbres rÃ©unis. Dans nos donnÃ©es, les deux valent **52,3644**, Ã  l'arrondi des fichiers CSV prÃ¨s. Cette Ã©galitÃ© repose sur le fait que **toutes les forÃªts ont le mÃªme nombre d'arbres**.

## 5. Conclusion

Les campagnes confirment que les cimes et les extensions des arbres individuels ne sont pas rÃ©parties de la mÃªme faÃ§on. Les cimes se regroupent principalement autour de deux niveaux, tandis que les extensions forment une distribution Ã  une seule bosse et plus asymÃ©trique.

Lorsqu'on Ã©tudie les moyennes de 50 arbres par forÃªt, les distributions sont beaucoup plus concentrÃ©es. L'analyse des 400 forÃªts de C2 montre des histogrammes proches d'une forme en cloche pour les deux mesures. Les 40 forÃªts de C1 permettent d'observer les premiÃ¨res tendances, mais elles ne suffisent pas Ã  en apprÃ©cier clairement la forme.

**Remarque sur la reproductibilitÃ© :** les campagnes C1 et C2 sont cohÃ©rentes entre elles, mais quelques statistiques diffÃ¨rent lÃ©gÃ¨rement des rÃ©fÃ©rences numÃ©riques du sujet. Cela doit Ãªtre signalÃ© si une validation exacte est attendue.

## Source

Sujet officiel : https://nicolas-flasque-efrei.github.io/TI-301/projet/partie3/EN/

