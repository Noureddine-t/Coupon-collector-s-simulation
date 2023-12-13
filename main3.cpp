#include <fstream>
#include "Functions.h"

int main() {
    int N = 1000;
    int simulations = 1000;
    int averageWeeks[2];

    // Open the CSV file for writing
    //std::ofstream outputFile("AverangeWeeksEnFonctionDeNombreA_Collecter.csv");
    std::ofstream outputFile("AverangeWeeksEnFonctionDeNombreA_Collecter_Avec_5.csv");
    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;  // Exit with an error code
    }

    // Write header to the CSV file
    //outputFile << "NbrTotalDeCollection, AverageWeeksWithoutExchange, AverageWeeksWithExchange" << std::endl;
    outputFile << "NbrTotalDeCollection, AverageWeeksWithoutExchange, AverageWeeksWithExchange" << std::endl;
    for (int i = 1; i <= N; i++) {
        std::cout << "N=" << i << std::endl;
        averageWeeks[0] = 0;
        averageWeeks[1] = 0;
        for (int j = 0; j < simulations; j++) {
            averageWeeks[0] += simulateWithMultipleCollections(i, 5);
            averageWeeks[1] += simulateWithMultipleCollectionsWithExchange(i, 5);
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
