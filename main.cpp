#include <iostream>
#include <random>

int simulateCollection(int);

int simulateCollectionWithExchange(int);

int simulateWithMultipleCollectionsWithExchange(int, int);

double theoricalValueUsingHarmonicSerie(int);

double theoricalValueUsingAsymptoticDevelopment(int);

int main() {
    int collectionNumber = 100; //valeur par defaut pour nombre total de collection
    int simulations = 1000;  // Nombre de simulations à exécuter pour avoir une valeur moyenne plus exacte
    int vignetteNumber = 5; //nombre de vignette dans le céréale pour la 3eme fonction
    while (true) {
        //demander nombre de collection
        std::cout << "Entrez nombre de vignettes de votre collection (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici >  ";
        std::cin >> collectionNumber;

        //condition d'arret
        if (collectionNumber == 0)
            break;

        //demander nombre de simulations
        std::cout << "Entrez nombre de simulations (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici >  ";
        std::cin >> simulations;

        //condition d'arret
        if (simulations == 0)
            break;

        //demander nombre de vignette dans le céréale pour la fonction 3
        std::cout << "Entrez nombre de vignettes (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici >  ";
        std::cin >> vignetteNumber;
        std::cout << std::endl;

        //condition d'arret
        if (vignetteNumber == 0)
            break;

        double averageWeeks[] = {0, 0, 0};//semaines necessaires avec echange et sans echange

        //calcule moyenne de semaines
        for (int i = 0; i < simulations; i++) {
            //std::cout << "Simulation " << i << "/" << simulations << std::endl;
            averageWeeks[0] += simulateCollection(collectionNumber);
            averageWeeks[1] += simulateCollectionWithExchange(collectionNumber);
            averageWeeks[2] += simulateWithMultipleCollectionsWithExchange(collectionNumber, vignetteNumber);
        }
        averageWeeks[0] /= simulations;
        averageWeeks[1] /= simulations;
        averageWeeks[2] /= simulations;

        //Affichage
        std::cout << "-Simulation :" << std::endl;
        std::cout << ">> Il faut en moyenne " << averageWeeks[0] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes sans echange." << std::endl;
        std::cout << ">> Il faut en moyenne " << averageWeeks[1] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec echange 10 contre 1." << std::endl;
        std::cout << ">> Il faut en moyenne " << averageWeeks[2] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec echange et " << vignetteNumber << " dans le cereale"
                  << std::endl << std::endl;
        std::cout << "-Valeur theorique :" << std::endl;
        std::cout << ">> Il faut en moyenne " << theoricalValueUsingHarmonicSerie(collectionNumber)
                  << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes sans echange a l'aide de la formule theorique n*somme(1/k)."
                  << std::endl;
        std::cout << ">> Il faut en moyenne " << theoricalValueUsingAsymptoticDevelopment(collectionNumber)
                  << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes sans echange a l'aide de l'approximation de la forumule theorique."
                  << std::endl;
    }
    return 0;
}

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

        //verifier si tout les vignettes sont collectées pour finir
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
                duplicatesVignette = 0;
                break;
            }
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

        int *newVignetteTable = new int[vignetteNumber]; //si on a plus d'une vignette dans le céréale
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
                duplicatesVignette = duplicatesVignette - 10;

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
    return collectionNumber * (std::log(collectionNumber) + 0.57721 + 1. / 2);  // Utilise ln(n) + γ;
}