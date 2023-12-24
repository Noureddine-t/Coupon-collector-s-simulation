//
// Created by noure on 22/12/2023.
//
#include <fstream>
#include "Functions.h"

//point d'intersection des deux courbes dex
int main() {
    int N = 500;
    int simulations = 5000;
    int averageWeeks[2];
    // int equal = 0;
    // Open the CSV file for writing
    std::ofstream outputFile(
            "_CollectionNumber_en_fonction_du_taux_echange_pour_croiser_deux_courbe_avec_vignetteNumber_2.csv");
    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;  // Exit with an error code
    }

    // Write header to the CSV file
    outputFile << "PrixD_Echange,NbrTotalDeCollection"
               << std::endl;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            averageWeeks[0] = 0;
            averageWeeks[1] = 0;
            for (int j = 0; j < simulations; j++) {
                averageWeeks[0] += simulateWithMultipleCollections(i, 2);//vignetteNumber=1 ou 2
                averageWeeks[1] += simulateCollectionWithExchange(i, k);
            }
            averageWeeks[0] /= simulations;
            averageWeeks[1] /= simulations;
            if ((averageWeeks[0] == averageWeeks[1] && i > 1) || averageWeeks[0] > averageWeeks[1]) {
                // Write data to the CSV file
                outputFile << k << "," << i << std::endl;

                std::cout << k << " ";
                std::cout << i << " " << std::endl;
                break;
            }
            if (i == N)// si les courbes ne se croissent pas avant N mais ap
                return 0;

        }
    }
    // Close the CSV file
    outputFile.close();

    return 0;
}