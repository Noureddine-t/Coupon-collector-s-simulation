#include "Functions.h"

int main() {
    int collectionNumber = 500; //valeur par defaut pour nombre total de collection
    int simulations = 1000;  // Nombre de simulations à exécuter pour avoir une valeur moyenne plus exacte
    int vignetteNumber = 2; //nombre de vignette dans la boite de céréales pour la 3eme fonction
    while (collectionNumber != 0 || simulations != 0 || vignetteNumber != 0) {
        //demander nombre de collection
        std::cout << "Entrez nombre de vignettes de votre collection (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici >  ";
        std::cin >> collectionNumber;

        //demander nombre de simulations
        std::cout << "Entrez nombre de simulations (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici >  ";
        std::cin >> simulations;

        //demander nombre de vignette dans la boite de céréales pour la fonction 3
        std::cout << "Entrez nombre de vignettes (0 pour arreter programme)  " << std::endl;
        std::cout << "Ici >  ";
        std::cin >> vignetteNumber;
        std::cout << std::endl;


        double averageWeeks[] = {0, 0, 0, 0};//semaines necessaires avec echange et sans echange

        //calcule moyenne de semaines
        for (int i = 0; i < simulations; i++) {
            averageWeeks[0] += simulateCollection(collectionNumber);
            averageWeeks[1] += simulateCollectionWithExchange(collectionNumber);
            averageWeeks[2] += simulateWithMultipleCollections(collectionNumber, vignetteNumber);
            averageWeeks[3] += simulateWithMultipleCollectionsWithExchange(collectionNumber, vignetteNumber);

        }
        averageWeeks[0] /= simulations;
        averageWeeks[1] /= simulations;
        averageWeeks[2] /= simulations;
        averageWeeks[3] /= simulations;

        //Affichage
        std::cout << "-Simulation :" << std::endl;
        std::cout << ">> Il faut en moyenne " << averageWeeks[0] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes sans echange." << std::endl;
        std::cout << ">> Il faut en moyenne " << averageWeeks[1] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec echange 10 contre 1." << std::endl;

        std::cout << ">> Il faut en moyenne " << averageWeeks[2] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec " << vignetteNumber << " dans la boite de cereales"
                  << std::endl;
        std::cout << ">> Il faut en moyenne " << averageWeeks[3] << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec echange et " << vignetteNumber
                  << " vignette(s) dans la boite de cereales"
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

        std::cout << ">> Il faut en moyenne "
                  << theoricalValueUsingHarmonicSerieMultipleCollections(collectionNumber, vignetteNumber)
                  << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec " << vignetteNumber
                  << " vignettes dans la boite de cereales à l'aide de la formule theorique E(T)/k."
                  << std::endl;
        std::cout << ">> Il faut en moyenne "
                  << theoricalValueUsingAsymptoticDevelopmentMultipleCollections(collectionNumber, vignetteNumber)
                  << " semaines pour completer la collection de "
                  << collectionNumber << " vignettes avec " << vignetteNumber
                  << " vignettes dans la boite de cereales avec la formule de developpement asymptotique de E(T)/k."
                  << std::endl;
    }
    return 0;
}

