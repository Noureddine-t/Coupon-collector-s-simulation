# Install and load the required library
#install.packages("plotly")
library(plotly)

# Read CSV file
data <- read.csv("G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\3_AverageWeeksVSTotalNumberOfCollection\\_SemainesEnFonctionDeNombreA_Collecte.csv")
data2 <- read.csv("G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\3_AverageWeeksVSTotalNumberOfCollection\\_SemainesEnFonctionDeNombreA_Collecte_Avec_2.csv")

# Extract data for plotting
TotalCollectionNumber <- data$NbrTotalDeCollection
AverageWeeksWithoutExchange <- data$AverageWeeksWithoutExchange
AverageWeeksWithExchange <- data$AverageWeeksWithExchange
AverageWeeksWithoutExchange2 <- data2$AverageWeeksWithoutExchange
AverageWeeksWithExchange2 <- data2$AverageWeeksWithExchange

# Theoretical Value
theoreticalValues <- sapply(TotalCollectionNumber, function(collectionNumber) {
  sum(1 / (1:collectionNumber)) * collectionNumber
})

# Calculate the maximum range for the y-axis
max_range <- max(max(AverageWeeksWithoutExchange, AverageWeeksWithExchange, AverageWeeksWithoutExchange2, AverageWeeksWithExchange2, theoreticalValues)) + 100

# Create a plotly object
p <- plot_ly()

# Add traces for each curve
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithoutExchange, type = 'scatter', mode = 'lines', line = list(color = 'blue'), name = 'Without Exchange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithExchange, type = 'scatter', mode = 'lines', line = list(color = 'red'), name = 'With Exchange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithoutExchange2, type = 'scatter', mode = 'lines', line = list(color = 'purple'), name = '2 Without Exchange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithExchange2, type = 'scatter', mode = 'lines', line = list(color = 'orange'), name = '2 With Exchange')

# Theoretical Value
p <- add_trace(p, x = TotalCollectionNumber, y = theoreticalValues, type = 'scatter', mode = 'lines', line = list(color = 'green'), name = 'Theoretical Value')

# Update layout
p <- p %>%
  layout(
    xaxis = list(title = 'TotalCollectionNumber'),
    yaxis = list(
      title = 'nombres de paquets a acheter/nombre de semaines',
      rangemode = "tozero",
      range = c(0, max_range),
      showline = TRUE
    ),
    title = 'Average Weeks vs TotalCollectionNumber'
  )

# Display the plot
p
