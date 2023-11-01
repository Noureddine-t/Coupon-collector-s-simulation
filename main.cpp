#include <iostream>
#include <random>

int simulateCollection(int);

int simulateCollectionWithExchange(int);

int simulateWithMultipleCollectionsWithExchange(int, int);

int main() {
    int collectionNumber = 100; //valeur par defaut pour nombre total de collection
    int simulations = 1000;  // Nombre de simulations à exécuter pour avoir une valeur moyenne plus exacte
    int vignetteNumber = 5; //nombre de vignette dans le céréale pour la 3eme fonction
    while (true) {
        //demander nombre de collection
        std::cout << "Entrez nombre de vignettes de votre collection (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici : ";
        std::cin >> collectionNumber;

        //condition d'arret
        if (collectionNumber == 0)
            break;

        //demander nombre de simulations
        std::cout << "Entrez nombre de simulations (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici : ";
        std::cin >> simulations;

        //condition d'arret
        if (simulations == 0)
            break;

        //demander nombre de vignette dans le céréale pour la fonction 3
        std::cout << "Entrez nombre de vignettes (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici : ";
        std::cin >> vignetteNumber;
        std::cout << std::endl;

        //condition d'arret
        if (vignetteNumber == 0)
            break;


        double averageWeeks[] = {0, 0, 0};//semaines necessaires avec echange et sans echange
        //calcule moyenne de semaines
        for (int i = 0; i < simulations; i++) {
            averageWeeks[0] += simulateCollection(collectionNumber);
            averageWeeks[1] += simulateCollectionWithExchange(collectionNumber);
            averageWeeks[2] += simulateWithMultipleCollectionsWithExchange(collectionNumber, vignetteNumber);
        }
        averageWeeks[0] /= simulations;
        averageWeeks[1] /= simulations;
        averageWeeks[2] /= simulations;
        //Affichage
        std::cout << "Il faut en moyenne " << averageWeeks[0] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes sans echange." << std::endl;
        std::cout << "Il faut en moyenne " << averageWeeks[1] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec echange 10 contre 1." << std::endl;
        std::cout << "Il faut en moyenne " << averageWeeks[2] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec echange et " << vignetteNumber << " dans le cereale"
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