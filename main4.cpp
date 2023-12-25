//
// Created by noure on 13/12/2023.
//
#include <fstream>
#include "Functions.h"

//
int main() {
    int N = 500;
    int simulations = 5000;
    int averageWeeks[2];
    // int equal = 0;
    // Open the CSV file for writing
    std::ofstream outputFile("_SemaineEnFonctionDeNombreA_Collecte_Avec_2_Determiner_taux_d_echange.csv");
    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;  // Exit with an error code
    }

    // Write header to the CSV file
    outputFile << "NbrTotalDeCollection, AverageWeeksWithoutExchange, AverageWeeksWithExchange" << std::endl;
    for (int i = 1; i <= N; i++) {
        std::cout << "N=" << i << std::endl;
        averageWeeks[0] = 0;
        averageWeeks[1] = 0;
        for (int j = 0; j < simulations; j++) {
            averageWeeks[0] += simulateWithMultipleCollections(i, 2);//vignetteNumber=1 ou 2
            averageWeeks[1] += simulateCollectionWithExchange(i, 10);
        }
        averageWeeks[0] /= simulations;
        averageWeeks[1] /= simulations;

        // Write data to the CSV file
        outputFile << i << "," << averageWeeks[0] << "," << averageWeeks[1] << std::endl;

        std::cout << averageWeeks[0] << " ";
        std::cout << averageWeeks[1] << " " << std::endl;
    }

    // Close the CSV file
    outputFile.close();

    return 0;
}
