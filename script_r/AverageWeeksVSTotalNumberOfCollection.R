# Read CSV file
data <- read.csv('G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\AverangeWeeksEnFonctionDeNombreA_Collecter.csv')
data2 <- read.csv('G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\AverangeWeeksEnFonctionDeNombreA_Collecter_Avec_5.csv')
# Extract data for plotting
NbrTotalDeCollection <- data$NbrTotalDeCollection
AverageWeeksWithoutExchange <- data$AverageWeeksWithoutExchange
AverageWeeksWithExchange <- data$AverageWeeksWithExchange
AverageWeeksWithoutExchange2 <- data2$AverageWeeksWithoutExchange
AverageWeeksWithExchange2 <- data2$AverageWeeksWithExchange

# Plotting
plot(NbrTotalDeCollection, AverageWeeksWithoutExchange, type = 'l', col = 'blue', lwd = 2, xlab = 'NbrTotalDeCollection', ylab = 'AverageWeeksWithoutExchange', main = 'Average Weeks vs NbrTotalDeCollection')
lines(NbrTotalDeCollection, AverageWeeksWithExchange, col = 'red', lwd = 2)
lines(NbrTotalDeCollection, AverageWeeksWithoutExchange2, col = 'purple', lwd = 2, lty = 2)
lines(NbrTotalDeCollection, AverageWeeksWithExchange2, col = 'orange', lwd = 2, lty = 2)
# fifth curve - Theoretical Value
theoreticalValues <- sapply(NbrTotalDeCollection, function(collectionNumber) {
  somme <- sum(1 / (1:collectionNumber))
  return(collectionNumber * somme)
})

lines(NbrTotalDeCollection, theoreticalValues, col = 'green', lwd = 2)

# Add legend
legend('topright', legend = c('Without Exchange', 'With Exchange', 'Theoretical Value', 'New Without Exchange', 'New With Exchange'), col = c('blue', 'red', 'green', 'purple', 'orange'), lwd = 2)


# Display the plot
