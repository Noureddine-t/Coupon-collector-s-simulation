# Install and load the required library
#install.packages("plotly")
library(plotly)
# Obtenez le chemin du répertoire du script R
script_directory <- dirname(rstudioapi::getActiveDocumentContext()$path)

# Changez le répertoire de travail
setwd(script_directory)
# Read CSV file
data <- read.csv("_SemainesEnFonctionDeNombreA_Collecte.csv")
data2 <- read.csv("_SemainesEnFonctionDeNombreA_Collecte_Avec_2.csv")

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

# Créer un objet plotly
p <- plot_ly()

# Ajouter des traces pour chaque courbe
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithoutExchange, type = 'scatter', mode = 'lines+markers', line = list(color = 'blue'), marker = list(color = 'blue', size = 3), name = 'Without Exchange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithExchange, type = 'scatter', mode = 'lines+markers', line = list(color = 'red'), marker = list(color = 'red', size = 3), name = 'With Exchange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithoutExchange2, type = 'scatter', mode = 'lines+markers', line = list(color = 'purple'), marker = list(color = 'purple', size = 3), name = '2 Without Exchange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithExchange2, type = 'scatter', mode = 'lines+markers', line = list(color = 'orange'), marker = list(color = 'orange', size = 3), name = '2 With Exchange')

# Valeur théorique
p <- add_trace(p, x = TotalCollectionNumber, y = theoreticalValues, type = 'scatter', mode = 'lines+markers', line = list(color = 'green'), marker = list(color = 'green', size = 3), name = 'Theoretical Value')

# Mise à jour de la mise en page
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

# Afficher le graphique
p
