# Read CSV file
data <- read.csv("AverangeWeeksEnFonctionDeN.csv")

# Extract data for plotting
N <- data$N
AverageWeeksWithoutExchange <- data$AverageWeeksWithoutExchange
AverageWeeksWithExchange <- data$AverageWeeksWithExchange

# Plotting
plot(N, AverageWeeksWithoutExchange, type = 'l', col = 'blue', lwd = 2, xlab = 'N', ylab = 'Average Weeks', main = 'Average Weeks vs N')
lines(N, AverageWeeksWithExchange, col = 'red', lwd = 2)

# Add legend
legend('topright', legend = c('Without Exchange', 'With Exchange'), col = c('blue', 'red'), lwd = 2)

# Display the plot
