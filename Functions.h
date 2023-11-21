//
// Created by noure on 26/11/2023.
//

#ifndef COUPON_COLLECTOR_S_SIMULATION_FUNCTIONS_H
#define COUPON_COLLECTOR_S_SIMULATION_FUNCTIONS_H

#include <iostream>
#include <cmath>

int simulateCollection(int);

int simulateCollectionWithExchange(int);

int simulateWithMultipleCollections(int, int);

int simulateWithMultipleCollectionsWithExchange(int, int);

double theoricalValueUsingHarmonicSerie(int);

double theoricalValueUsingAsymptoticDevelopment(int);

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
        for (int i = 0; i < collectionNumber && !collected[newVignette]; i++) {
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

    while (!allCollected) {
        weeks++;

        int newVignette = rand() % collectionNumber;
        if (!collected[newVignette])
            collected[newVignette] = true;
        else
            duplicatesVignette++;

        //echanger 10 vignettes contre une
        for (int i = 0; i < collectionNumber; i++) {

            if (!collected[i] && duplicatesVignette == 10) {
                collected[i] = true;
                duplicatesVignette -= 10;
                break;
            }
        }


        //verifier si tout les vignettes collecter pour finir
        allCollected = true;
        for (int i = 0; i < collectionNumber && !collected[newVignette]; i++) {
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

    while (!allCollected) {
        weeks++;

        int *newVignetteTable = new int[vignetteNumber]; //si on a plus d'une vignette dans la boite de céréales
        for (int i = 0; i < vignetteNumber; i++) {
            newVignetteTable[i] = rand() % collectionNumber;
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

    while (!allCollected) {
        weeks++;
        //std::cout << "semaine:" << weeks << std::endl;

        //for (int i = 0; i < collectionNumber; i++)
        // std::cout << "tableau collected:" << collected[i] << std::endl;

        int *newVignetteTable = new int[vignetteNumber]; //si on a plus d'une vignette dans la boite de céréales
        for (int i = 0; i < vignetteNumber; i++) {
            newVignetteTable[i] = rand() % collectionNumber;
            if (!collected[newVignetteTable[i]])
                collected[newVignetteTable[i]] = true;
            else
                duplicatesVignette++;

            //std::cout << "vignette dupliquee :" << duplicatesVignette << std::endl;

        }

        //echanger 10 vignettes contre une
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i] && duplicatesVignette >= 10) {
                collected[i] = true;
                duplicatesVignette -= 10;

                //std::cout << "vignette after -10:" << duplicatesVignette << std::endl;
                break;
            }
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

#endif //COUPON_COLLECTOR_S_SIMULATION_FUNCTIONS_H