//
// Created by noure on 25/12/2023.
//
#include "Functions.h"

int simulateCollection(int collectionNumber) {
    bool *collected = new bool[collectionNumber]; // Allocation dynamique du tableau
    for (int i = 0; i < collectionNumber; i++) //initialiser tableau de vignettes
        collected[i] = false;
    int weeks = 0;
    bool allCollected = false;
    while (!allCollected) {
        weeks++;
        int newVignette = rand() % collectionNumber; //choisir un valeur alétoire qui represente une vignette
        if (!collected[newVignette])
            collected[newVignette] = true;
        //verifier si tout les vignettes sont collectées pour finir, si la nouvelle vignette est déja présente je verifie pas
        allCollected = true;
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
    }
    delete[] collected; // Libération de la mémoire allouée dynamiquement
    return weeks;
}

int simulateCollectionWithExchange(int collectionNumber) {

    bool *collected = new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++)
        collected[i] = false;

    int weeks = 0;
    int duplicatesVignette = 0;
    bool allCollected = false;
    int notCollectedCounter = collectionNumber;
    while (!allCollected) {
        weeks++;

        int newVignette = rand() % collectionNumber;
        if (!collected[newVignette]) {
            collected[newVignette] = true;
            //compter vignettes restantes
            notCollectedCounter--;
        } else
            duplicatesVignette++;

        //faire echange a la fin (si nombre de vignettes manquantes = doublons/10 on echange) et mettre fin
        if (notCollectedCounter <= duplicatesVignette / 10) {
            break;
        }


        //verifier si tout les vignettes collecter pour finir
        allCollected = true;
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
    }
    delete[] collected; // Libération de la mémoire allouée dynamiquement
    return weeks;
}

int simulateWithMultipleCollections(int collectionNumber, int vignetteNumber) {

    bool *collected = new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++)
        collected[i] = false;

    int weeks = 0;
    bool allCollected = false;

    //exception si collectionNumber<vignetteNumber alors weeks = 1
    if (collectionNumber < vignetteNumber) {
        return 1;
    }
    int *newVignetteTable = new int[vignetteNumber]; // si on a plus d'une vignette dans la boite de céréales

    while (!allCollected) {
        weeks++;

        for (int i = 0; i < vignetteNumber; i++) {
            int randomVignette;
            bool isUnique; //Assurer que les vignettes trouvées dans le céréale soient différentes
            do {
                // Générer un nombre aléatoire entre 0 et collectionNumber - 1
                randomVignette = rand() % collectionNumber;
                // Vérifier si le nombre généré est déjà présent dans le tableau
                isUnique = true;
                for (int j = 0; j < i; j++) {
                    if (newVignetteTable[j] == randomVignette) {
                        isUnique = false;
                        break;
                    }
                }
            } while (!isUnique);
            // Assigner le nombre aléatoire unique au tableau
            newVignetteTable[i] = randomVignette;
            // Marquer la vignette comme collectée
            if (!collected[newVignetteTable[i]])
                collected[newVignetteTable[i]] = true;
        }

        //verifier si toutes les vignettes sont collectées
        allCollected = true;
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
    }
    delete[] newVignetteTable;
    delete[] collected; // Libération de la mémoire allouée dynamiquement
    return weeks;
}

int simulateWithMultipleCollectionsWithExchange(int collectionNumber, int vignetteNumber) {

    bool *collected = new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++)
        collected[i] = false;

    int weeks = 0;
    int duplicatesVignette = 0;
    bool allCollected = false;
    int notCollectedCounter = collectionNumber;

    if (collectionNumber < vignetteNumber) {
        return 1;
    }
    int *newVignetteTable = new int[vignetteNumber]; //si on a plus d'une vignette dans la boite de céréales

    while (!allCollected) {
        weeks++;

        for (int i = 0; i < vignetteNumber; i++) {
            int randomVignette;
            bool isUnique; //Assurer que les vignettes trouvées dans le céréal soient différentes

            do {
                // Générer un nombre aléatoire entre 0 et collectionNumber - 1
                randomVignette = rand() % collectionNumber;

                // Vérifier si le nombre généré est déjà présent dans le tableau
                isUnique = true;
                for (int j = 0; j < i; j++) {
                    if (newVignetteTable[j] == randomVignette) {
                        isUnique = false;
                        break;
                    }
                }
            } while (!isUnique);

            // Assigner le nombre aléatoire unique au tableau
            newVignetteTable[i] = randomVignette;

            // Marquer la vignette comme collectée
            if (!collected[newVignetteTable[i]]) {
                collected[newVignetteTable[i]] = true;
                notCollectedCounter--;
            } else
                duplicatesVignette++;

        }
        if (notCollectedCounter <= duplicatesVignette / 10) {
            break;
        }

        //verifier si toutes les vignettes sont collectées
        allCollected = true;
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
    }
    delete[] newVignetteTable;
    delete[] collected; // Libération de la mémoire allouée dynamiquement

    return weeks;
}

//on utilisant série harmonique: N*sum(1/k) de 1 a N
double theoricalValueUsingHarmonicSerie(int collectionNumber) {
    double somme = 0;
    for (int i = 1; i <= collectionNumber; i++)
        somme += 1.0 / i;
    return collectionNumber * somme;
}

//on utilisant En utilisant le développement asymptotique E(Tn)=n⋅Hn=nln(n)+γ⋅n+1/2+o(1) où γ≈0.5772156649 est la constante d'Euler-Mascheroni.
double theoricalValueUsingAsymptoticDevelopment(int collectionNumber) {
    return collectionNumber * (std::log(collectionNumber) + 0.57721) + 1. / 2;  // Utilise ln(n) + γ;
}

int simulateCollectionWithExchange(int collectionNumber, int Exchange) {

    bool *collected = new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++)
        collected[i] = false;

    int weeks = 0;
    int duplicatesVignette = 0;
    bool allCollected = false;
    int notCollectedCounter = collectionNumber;
    while (!allCollected) {
        weeks++;

        int newVignette = rand() % collectionNumber;
        if (!collected[newVignette]) {
            collected[newVignette] = true;
            //compter vignettes restantes
            notCollectedCounter--;
        } else
            duplicatesVignette++;


        //faire echange a la fin (si nombre de vignettes manquantes = doublons/10 on echange) et mettre fin
        if (notCollectedCounter <= duplicatesVignette / Exchange) {
            break;
        }


        //verifier si tout les vignettes collecter pour finir
        allCollected = true;
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
    }
    delete[] collected; // Libération de la mémoire allouée dynamiquement
    return weeks;
}

int simulateWithMultipleCollectionsWithExchange(int collectionNumber, int vignetteNumber, int exchange) {

    bool *collected = new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++)
        collected[i] = false;

    int weeks = 0;
    int duplicatesVignette = 0;
    bool allCollected = false;
    int notCollectedCounter = collectionNumber;

    if (collectionNumber < vignetteNumber) {
        return 1;
    }
    int *newVignetteTable = new int[vignetteNumber]; //si on a plus d'une vignette dans la boite de céréales

    while (!allCollected) {
        weeks++;

        for (int i = 0; i < vignetteNumber; i++) {
            int randomVignette;
            bool isUnique; //Assurer que les vignettes trouvées dans le céréal soient différentes

            do {
                // Générer un nombre aléatoire entre 0 et collectionNumber - 1
                randomVignette = rand() % collectionNumber;

                // Vérifier si le nombre généré est déjà présent dans le tableau
                isUnique = true;
                for (int j = 0; j < i; j++) {
                    if (newVignetteTable[j] == randomVignette) {
                        isUnique = false;
                        break;
                    }
                }
            } while (!isUnique);

            // Assigner le nombre aléatoire unique au tableau
            newVignetteTable[i] = randomVignette;

            // Marquer la vignette comme collectée
            if (!collected[newVignetteTable[i]]) {
                collected[newVignetteTable[i]] = true;
                notCollectedCounter--;
            } else
                duplicatesVignette++;

        }
        if (notCollectedCounter <= duplicatesVignette / exchange) {
            break;
        }

        //verifier si toutes les vignettes sont collectées
        allCollected = true;
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
    }
    delete[] newVignetteTable;
    delete[] collected; // Libération de la mémoire allouée dynamiquement

    return weeks;
}