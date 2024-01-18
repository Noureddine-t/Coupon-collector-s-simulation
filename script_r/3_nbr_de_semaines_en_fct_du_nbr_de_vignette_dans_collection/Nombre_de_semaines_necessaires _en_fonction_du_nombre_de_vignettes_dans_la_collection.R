# Install and load the required library
#install.packages("plotly")
#1500 650
library(plotly)

# Obtenez le chemin du répertoire du script R
script_directory <- dirname(rstudioapi::getActiveDocumentContext()$path)

# Changez le répertoire de travail
setwd(script_directory)

# Lire fichier CSV
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

# Developpement asymptotique
asymptotiqueDevValues <- sapply(TotalCollectionNumber, function(collectionNumber) {
  collectionNumber * log(collectionNumber) + 0.57721 * collectionNumber + 0.5
})

# Calculate the maximum range for the y-axis
max_range <- max(max(AverageWeeksWithoutExchange, AverageWeeksWithExchange, AverageWeeksWithoutExchange2, AverageWeeksWithExchange2, theoreticalValues)) + 100

# Créer un objet plotly
p <- plot_ly()

# Ajouter des traces pour chaque courbe
#mode = 'lines+markers'
#marker = list(color = 'blue', size = 3)

# Valeur théorique
p <- add_trace(p, x = TotalCollectionNumber, y = theoreticalValues, type = 'scatter', mode = 'lines', line = list(color = 'green'),  name = 'Valeurs théorique')

# Developpement asymptotique
#p <- add_trace(p, x = TotalCollectionNumber, y = asymptotiqueDevValues, type = 'scatter', mode = 'lines', line = list(color = 'purple'),  name = 'Développement asymptotique')

# valeurs calculées
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithoutExchange, type = 'scatter', mode = 'lines', line = list(color = 'blue'),  name = '1 vignette sans echange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithExchange, type = 'scatter', mode = 'lines', line = list(color = 'red'),  name = '1 vignette avec echange de 10 doublons')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithoutExchange2, type = 'scatter', mode = 'lines', line = list(color = 'purple'),  name = '2 vignettes sans echange')
p <- add_trace(p, x = TotalCollectionNumber, y = AverageWeeksWithExchange2, type = 'scatter', mode = 'lines', line = list(color = 'orange'), name = '2 vignettes avec echange de 10 doublons')



# Mise à jour de la mise en page
p <- p %>%
  layout(
    xaxis = list(title = 'Nombre total de vignettes dans la collection'),
    yaxis = list(
      title = 'nombres de paquets à acheter/nombre de semaines',
      rangemode = "tozero",
      range = c(0, max_range),
      showline = TRUE
    ),
    #Nombre de semaines necessaires pour completer la collection en fonction du nombre de vignettes dans la collection (avec ou sans echange, pour 1 ou 2 vignette(s) dans le paquet de céréale)
    title = 'nombre de semaines en fonction du  Nombre de vignettes collectées'
  )

# Afficher le graphique
p
