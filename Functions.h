//
// Created by noure on 26/11/2023.
//

#ifndef COUPON_COLLECTOR_S_SIMULATION_FUNCTIONS_H
#define COUPON_COLLECTOR_S_SIMULATION_FUNCTIONS_H

#include <iostream>
#include <cmath>

int simulateCollection(int collectionNumber);

int simulateCollectionWithExchange(int collectionNumber); //prix d echange = 10

int simulateWithMultipleCollections(int collectionNumber, int vignetteNumber);

int simulateWithMultipleCollectionsWithExchange(int collectionNumber, int vignetteNumber); //prix d echange = 10

double theoricalValueUsingHarmonicSerie(int collectionNumber);

double theoricalValueUsingAsymptoticDevelopment(int collectionNumber);

int simulateCollectionWithExchange(int collectionNumber, int Exchange);

int simulateWithMultipleCollectionsWithExchange(int collectionNumber, int vignetteNumber, int Exchange);

#endif //COUPON_COLLECTOR_S_SIMULATION_FUNCTIONS_H
