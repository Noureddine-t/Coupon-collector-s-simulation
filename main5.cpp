//
// Created by noure on 20/12/2023.
//

#include <fstream>
#include "Functions.h"

//influence du prix d echange sur la durée pour completer la collection dans le cas de 1 2 3 4 5 vignettes dans le céréale
int main() {
    int N = 500;
    int simulations = 5000;
    int averageWeeks[5];

    // Open the CSV file for writing
    std::ofstream outputFile(
            "nombre_paquet_a_acheter_en_fct_de_prix_echange_avec_1_2_3_4_5_vignette_par_cereale.csv");
    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;  // Exit with an error code
    }

    // Write header to the CSV file
    outputFile
            << "PrixD_Echange, AverageWeeksWithExchangeVaries_1, AverageWeeksWithExchangeVaries_2,AverageWeeksWithExchangeVaries_3,AverageWeeksWithExchangeVaries_4,AverageWeeksWithExchangeVaries_5"
            << std::endl;
    for (int i = 1; i <= N; i++) {
        std::cout << "N=" << i << std::endl;
        for (int k = 0; k < 5; k++)
            averageWeeks[k] = 0;

        for (int j = 0; j < simulations; j++) {
            //vignetteNumber varie de 1 a 5 (nombre de vignettes dans céréale)
            for (int k = 0; k < 5; k++)
                averageWeeks[k] += simulateWithMultipleCollectionsWithExchange(500, k + 1, i);
        }
        for (int k = 0; k < 5; k++)
            averageWeeks[k] /= simulations;

        // Write data to the CSV file
        outputFile << i << "," << averageWeeks[0] << "," << averageWeeks[1] << "," << averageWeeks[2] << ","
                   << averageWeeks[3] << "," << averageWeeks[4] << std::endl;

        std::cout << averageWeeks[0] << " ";
        std::cout << averageWeeks[1] << " ";
        std::cout << averageWeeks[2] << " ";
        std::cout << averageWeeks[3] << " ";
        std::cout << averageWeeks[4] << " " << std::endl;

    }

    // Close the CSV file
    outputFile.close();

    return 0;
}
