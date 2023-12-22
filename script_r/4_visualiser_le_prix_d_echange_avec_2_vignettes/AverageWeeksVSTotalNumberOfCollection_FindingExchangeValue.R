# install.packages("plotly")

library(plotly)
# Obtenez le chemin du répertoire du script R
script_directory <- dirname(rstudioapi::getActiveDocumentContext()$path)

# Changez le répertoire de travail
setwd(script_directory)

# Lire le fichier CSV
data <- read.csv("_SemaineEnFonctionDeNombreA_Collecte_Avec_2_Determiner_taux_d_echange.csv")
AverageWeeksWithExchange<-data$AverageWeeksWithExchange
AverageWeeksWithoutExchange<-data$AverageWeeksWithoutExchange
TotalCollectionNumber<-data$NbrTotalDeCollection

# Trouver l'index du point de croisement des courbes
crossing_point_index <- which(AverageWeeksWithExchange < AverageWeeksWithoutExchange)[1]

max_range <- max(AverageWeeksWithExchange, AverageWeeksWithoutExchange) + 100

# Créer le graphique interactif avec plotly
plot_ly(x = ~TotalCollectionNumber, y = ~AverageWeeksWithoutExchange, type = 'scatter', mode = 'lines', line = list(color = 'purple'), name = 'Without Exchange 2') %>%
  add_trace(x = ~TotalCollectionNumber, y = ~AverageWeeksWithExchange, type = 'scatter', mode = 'lines', line = list(color = 'red'), name = 'With Exchange') %>%
  layout(title = 'Average Weeks vs TotalCollectionNumber', 
         xaxis = list(title = 'TotalCollectionNumber'),
         yaxis = list(title = 'AverageWeeks',rangemode = "tozero", range = c(0, max_range), showline = TRUE)) %>%
  
# Ajouter une annotation pour le point de croisement
add_annotations(x = TotalCollectionNumber[crossing_point_index],
                y = AverageWeeksWithExchange[crossing_point_index],
                text = paste("Point de croisement:<br>x =", TotalCollectionNumber[crossing_point_index], "<br>y =", AverageWeeksWithExchange[crossing_point_index]),
                showarrow = TRUE, arrowhead = 100, ax = 0, ay = -45,arrowcolor = "blue",  arrowsize = 1,
                arrowwidth = 3,
                xref = 'x', yref = 'y')
