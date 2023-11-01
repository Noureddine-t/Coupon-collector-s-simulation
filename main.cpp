#include <iostream>
#include <random>

int simulateCollection(int);
int simulateCollectionWithExchange(int);
int simulateWithMultipleCollectionsWithExchange(int,int);

int main() {
    int collectionNumber =100 ; //valeur par defaut pour nombre total de collection

    while (true){
        //demander nombre de collection
        std::cout<<"Entrez nombre de vignettes de votre collection : ";
        std::cin>>collectionNumber;

        //condition d'arret
        if( collectionNumber==0 )
            break;

        int simulations = 1000;  // Nombre de simulations à exécuter pour avoir une valeur moyenne plus exacte
        //demander nombre de simulations
        std::cout<<"Entrez nombre de simulations : ";
        std::cin>>simulations;
        std::cout<<std::endl;

        //condition d'arret
        if( simulations==0 )
            break;

        double averageWeeks[] = {0,0,0};//semaines necessaires avec echange et sans echange
        //calcule moyenne de semaines
        for (int i = 0; i < simulations; i++){
            averageWeeks[0] += simulateCollection(collectionNumber);
            averageWeeks[1] += simulateCollectionWithExchange(collectionNumber);
            averageWeeks[2] +=simulateWithMultipleCollectionsWithExchange(collectionNumber, 5);
        }
        averageWeeks[0] /= simulations;
        averageWeeks[1] /= simulations;
        averageWeeks[2] /= simulations;
        //Affichage
        std::cout << "Il faut en moyenne " << averageWeeks[0] << " semaines pour completer la collection de " << collectionNumber << " vignettes sans echange." << std::endl;
        std::cout << "Il faut en moyenne " << averageWeeks[1] << " semaines pour completer la collection de " << collectionNumber << " vignettes avec echange 10 contre 1." << std::endl;
        std::cout << "Il faut en moyenne " << averageWeeks[2] << " semaines pour completer la collection de " << collectionNumber << " vignettes avec echange et vignette multiple." << std::endl;
    }
    return 0;
}

int simulateCollection(int collectionNumber) {

    bool* collected=new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++) //initialiser tableau de vignettes
        collected[i] = false;

    int weeks = 0;
    while (true) {
        weeks++;
        int newVignette = rand() % collectionNumber; //choisir un valeur alétoire qui represente une vignette

        if (!collected[newVignette])
            collected[newVignette] = true;

        //verifier si tout les vignettes sont collectées pour finir
        bool allCollected = true;
        for (int i = 0; i < collectionNumber; i++) {
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
        if (allCollected)
            break;
    }
    delete[] collected; // Libération de la mémoire allouée dynamiquement
    return weeks;
}
int simulateCollectionWithExchange(int collectionNumber) {

    bool* collected=new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++)
        collected[i] = false;

    int weeks = 0;
    int duplicatesVignette = 0;

    while (true) {
        weeks++;
        int count=0;
        int newVignette = rand() % collectionNumber;
        if (!collected[newVignette])
            collected[newVignette] = true;
        else
            duplicatesVignette++;

        bool allCollected = true;

        for (int i = 0; i < collectionNumber; i++) {
            //echanger 10 vignettes contre une
            if (!collected[i] && duplicatesVignette==10 ) {
                collected[i] = true;
                duplicatesVignette=0;
                break;
            }
            if (!collected[i]) {
                allCollected = false;
                break;
            }

        }
        for (int i = 0; i < collectionNumber; i++){
            if(collected[i])
                count++;
        }
        // std::cout<<"week number: "<<weeks<<" || count: "<<" "<<count<<std::endl;

        //verifier si tout les vignettes collecter pour finir
        if (allCollected)
            break;

    }
    delete[] collected; // Libération de la mémoire allouée dynamiquement
    return weeks;
}

int simulateWithMultipleCollectionsWithExchange(int collectionNumber, int VignetteNumber) {

    bool* collected=new bool[collectionNumber]; // Allocation dynamique du tableau

    for (int i = 0; i < collectionNumber; i++)
        collected[i] = false;

    int weeks = 0;
    int duplicatesVignette = 0;
    while (true) {
        weeks++;
        int* newVignetteTable = new int[VignetteNumber]; //si on a plus d'une vignette dans le céréal

        for (int i = 0; i < VignetteNumber; i++){
            newVignetteTable[i] = rand() % collectionNumber;
            if (!collected[newVignetteTable[i]])
                collected[newVignetteTable[i]] = true;
            else
                duplicatesVignette++;
        }
        bool allCollected = true;

        for (int i = 0; i < collectionNumber; i++) {
            //echanger 10 vignettes contre une
            if (!collected[i] && duplicatesVignette==10 ) {
                collected[i] = true;
                duplicatesVignette=0;
                break;
            }
            //verifier si toutes les vignettes sont collectées
            if (!collected[i]) {
                allCollected = false;
                break;
            }
        }
        //verifier si tout les vignettes collecter pour finir
        if (allCollected)
            break;
    }
    delete[] collected; // Libération de la mémoire allouée dynamiquement
    return weeks;
}