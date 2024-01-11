library(plotly)

# Obtenez le chemin du répertoire du script R
script_directory <- dirname(rstudioapi::getActiveDocumentContext()$path)

# Changez le répertoire de travail
setwd(script_directory)

# Les données fournies
data <- read.csv("nombre_paquet_a_acheter_en_fct_de_prix_echange_avec_1_2_3_4_5_vignette_par_cereale.csv")

# Renommer les colonnes pour éviter les problèmes avec plot_ly
colnames(data) <- c("PrixD_Echange", "Function_1", "Function_2", "Function_3", "Function_4", "Function_5")

# Extraire les variables
PrixD_Echange <- data$PrixD_Echange
Function_1 <- data$Function_1
Function_2 <- data$Function_2
Function_3 <- data$Function_3
Function_4 <- data$Function_4
Function_5 <- data$Function_5

# Trouver la plage maximale pour l'axe des ordonnées
max_range <- max(Function_1, Function_2, Function_3, Function_4, Function_5) + 100

# Tracer les courbes interactives avec Plotly
plot_ly() %>%
  add_trace(x = ~PrixD_Echange, y = ~Function_1, name = '1 vignette dans le céréale', type = 'scatter', mode = 'lines') %>%
  add_trace(x = ~PrixD_Echange, y = ~Function_2, name = '2 vignette dans le céréale', type = 'scatter', mode = 'lines') %>%
  add_trace(x = ~PrixD_Echange, y = ~Function_3, name = '3 vignette dans le céréale', type = 'scatter', mode = 'lines') %>%
  add_trace(x = ~PrixD_Echange, y = ~Function_4, name = '4 vignette dans le céréale', type = 'scatter', mode = 'lines') %>%
  add_trace(x = ~PrixD_Echange, y = ~Function_5, name = '5 vignette dans le céréale', type = 'scatter', mode = 'lines') %>%
  layout(title = 'Nombre de semaines nécessaires pour completer la collection de 500 vignettes en fonction du prix d\'échange pour nombre de vignettes 1 2 3 4 5',
         xaxis = list(title = 'Prix d\'echange'),
         yaxis = list(title = 'nombres de paquets a acheter/nombre de semaines', rangemode = "tozero", range = c(0, max_range), showline = TRUE))

# Afficher le graphique interactif
