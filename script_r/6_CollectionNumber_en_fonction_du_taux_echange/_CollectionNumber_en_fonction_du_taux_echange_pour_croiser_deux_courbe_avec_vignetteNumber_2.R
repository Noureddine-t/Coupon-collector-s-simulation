# Installer la bibliothèque Plotly si ce n'est pas déjà fait
# install.packages("plotly")

# Charger la bibliothèque Plotly
library(plotly)

# Obtenez le chemin du répertoire du script R
script_directory <- dirname(rstudioapi::getActiveDocumentContext()$path)

# Changez le répertoire de travail
setwd(script_directory)

# Les données du fichier CSV
data <- read.csv("_CollectionNumber_en_fonction_du_taux_echange_pour_croiser_deux_courbe_avec_vignetteNumber_2.csv")

# Ajuster un modèle linéaire
model <- lm(NbrTotalDeCollection ~ PrixD_Echange, data = data)

# Tracer la courbe
plot <- plot_ly(data, x = ~PrixD_Echange, y = ~NbrTotalDeCollection, type = 'scatter', mode = 'lines+markers', name="points de croisement") %>%
  layout(title = 'Point de croissement des deux courbes (2 vignettes sans échange et 1 vignette avec échange) en fonction du prix d\'échange', 
         xaxis = list(title = 'Prix d\'échange'),
         yaxis = list(title = 'Nombre total de vignettes dans la collection')) %>%
  # Ajouter la droite d'approximation
  add_trace(x = data$PrixD_Echange, y = predict(model, newdata = data), mode = 'lines', type = 'scatter', name = 'Droite d\'approximation')

# Afficher la figure
print(plot)
