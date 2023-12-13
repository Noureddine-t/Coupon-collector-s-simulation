# Read CSV file
data <- read.csv("G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\_SemainesEnFonctionDeNombreA_Collecte.csv")
data2 <- read.csv("G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\_SemaineEnFonctionDeNombreA_Collecte_Avec_2.csv")
# Extract data for plotting
TotalCollectionNumber <- data$NbrTotalDeCollection
AverageWeeksWithoutExchange <- data$AverageWeeksWithoutExchange
AverageWeeksWithExchange <- data$AverageWeeksWithExchange
AverageWeeksWithoutExchange2 <- data2$AverageWeeksWithoutExchange
AverageWeeksWithExchange2 <- data2$AverageWeeksWithExchange

# Plotting
plot(TotalCollectionNumber, AverageWeeksWithoutExchange, type = 'l', lwd = 2, col = 'blue', xlab = 'TotalCollectionNumber', ylab = 'AverageWeeks', main = 'Average Weeks vs TotalCollectionNumber')
lines(TotalCollectionNumber, AverageWeeksWithExchange, col = 'red', lwd = 2)
lines(TotalCollectionNumber, AverageWeeksWithoutExchange2, col = 'purple', lwd = 2)
lines(TotalCollectionNumber, AverageWeeksWithExchange2, col = 'orange', lwd = 2)
# fifth curve - Theoretical Value
theoreticalValues <- sapply(TotalCollectionNumber, function(collectionNumber) {
  somme <- sum(1 / (1:collectionNumber))
  return(collectionNumber * somme)
})

lines(TotalCollectionNumber, theoreticalValues, col = 'green', lwd = 2)

#tracer y=0 et x=0
y_zero <- rep(0, length(TotalCollectionNumber))
lines(TotalCollectionNumber, y_zero, col = 'black', lwd = 2)
x_zero <- rep(0, length(AverageWeeksWithoutExchange2))
lines(x_zero, AverageWeeksWithoutExchange, col = 'black', lwd = 2)

# Add legend
legend('top', legend = c('Without Exchange', 'With Exchange', 'Theoretical Value', '2 Without Exchange', '2 With Exchange'), col = c('blue', 'red', 'green', 'purple', 'orange'), lwd = 2)


# Display the plot

