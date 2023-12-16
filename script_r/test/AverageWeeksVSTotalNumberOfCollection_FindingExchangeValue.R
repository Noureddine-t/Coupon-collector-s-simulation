# Read CSV file
data <- read.csv("G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\test\\_SemaineEnFonctionDeNombreA_Collecte_Avec_2_Determiner_taux_d_echange.csv")

# Extract data for plotting
TotalCollectionNumber <- data$NbrTotalDeCollection
AverageWeeksWithoutExchange <- data$AverageWeeksWithoutExchange
AverageWeeksWithExchange <- data$AverageWeeksWithExchange

# Plotting
plot(TotalCollectionNumber, AverageWeeksWithoutExchange, type = 'l', lwd = 2, col = 'purple', xlab = 'TotalCollectionNumber', ylab = 'AverageWeeks', main = 'Average Weeks vs TotalCollectionNumber')
lines(TotalCollectionNumber,AverageWeeksWithExchange , col = 'red', lwd = 2)

#tracer y=0 et x=0
y_zero <- rep(0, length(TotalCollectionNumber))
lines(TotalCollectionNumber, y_zero, col = 'black', lwd = 2)
x_zero <- rep(0, length(AverageWeeksWithoutExchange))
lines(x_zero, AverageWeeksWithoutExchange, col = 'black', lwd = 2)

# Add legend
legend('top', legend = c( 'With Exchange', '2 Without Exchange'), col = c( 'red',  'purple'), lwd = 2)


# Display the plot

