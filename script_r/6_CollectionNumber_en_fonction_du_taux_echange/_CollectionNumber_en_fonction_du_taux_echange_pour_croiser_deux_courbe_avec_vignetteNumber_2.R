# Installer la bibliothèque Plotly si ce n'est pas déjà fait
# install.packages("plotly")

# Charger la bibliothèque Plotly
library(plotly)

# Les données du fichier CSV
data <- read.csv("G:\\dossier bureau\\workspace\\CLionProjects\\ESIREM\\Coupon_collection\\Coupon-collector-s-simulation\\script_r\\6_CollectionNumber_en_fonction_du_taux_echange\\_CollectionNumber_en_fonction_du_taux_echange_pour_croiser_deux_courbe_avec_vignetteNumber_2.csv")

# Tracer la courbe
plot <- plot_ly(data, x = ~PrixD_Echange, y = ~NbrTotalDeCollection, type = 'scatter', mode = 'lines+markers')

# Ajouter un titre au graphique
plot <- plot %>% layout(title = "Courbe de NbrTotalDeCollection en fonction de PrixD_Echange")

# Afficher la figure
print(plot)
