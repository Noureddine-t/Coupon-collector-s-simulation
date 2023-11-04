# Définir le nombre total de vignettes dans la collection
N <- 500

# Fonction pour simuler une semaine d'achat de paquets de céréales
achat_semaine <- function(N) {
  # Initialiser un vecteur pour suivre les vignettes collectées
  collection <- rep(0, N)
  
  # Compteur de semaines
  semaines <- 0
  semaines_vs_vignettes <- numeric(N)
  
  # Tant qu'il reste des vignettes à collecter
  while (sum(collection) < N) {
    # Acheter un paquet de céréales
    paquet <- sample(1:N, 1)
    
    # Mettre à jour la collection
    collection[paquet] <- 1
    
    # Augmenter le compteur de semaines
    semaines <- semaines + 1
    
    # Enregistrer le nombre de semaines pour le nombre de vignettes collectées
    semaines_vs_vignettes[sum(collection)] <- semaines
  }
  
  return(semaines_vs_vignettes)
}

# Répéter la simulation un grand nombre de fois pour obtenir une estimation
# du nombre moyen de semaines nécessaires pour compléter la collection
nombre_simulations <- 1000
resultats <- replicate(nombre_simulations, achat_semaine(N))

# Calculer la moyenne des résultats
moyenne <- apply(resultats, 1, mean)

# Afficher le résultat
cat("Nombre moyen de semaines pour compléter la collection :", moyenne[N], "\n")

# Tracer la courbe
plot(moyenne, 1:N, type = "l", xlab = "Nombre de semaines" , ylab = "Nombre de vignettes collectées")

