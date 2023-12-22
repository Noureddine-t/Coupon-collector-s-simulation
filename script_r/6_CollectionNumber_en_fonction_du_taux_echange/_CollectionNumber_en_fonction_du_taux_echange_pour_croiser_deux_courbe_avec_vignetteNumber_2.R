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


# Tracer la courbe
plot <- plot_ly(data, x = ~PrixD_Echange, y = ~NbrTotalDeCollection, type = 'scatter', mode = 'lines+markers', name="points de croissement")

# Ajouter un titre au graphique
plot <- plot %>% layout(title = "Courbe de NbrTotalDeCollection en fonction de PrixD_Echange")

# Ajuster un modèle linéaire
model <- lm(NbrTotalDeCollection ~ PrixD_Echange, data = data)

# Ajouter la droite d'approximation
plot <- add_trace(plot, x = data$PrixD_Echange, y = predict(model), mode = 'lines', type = 'scatter', name = 'Droite d\'approximation')

# Afficher la figure
print(plot)