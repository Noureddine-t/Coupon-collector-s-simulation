# Définir le nombre total de vignettes dans la collection
N <- 100

# Calculer l'espérance en utilisant la formule de la série harmonique
esperance <- N*(log(N) + 0.57721)

# Initialiser la somme
somme <- 0

# Utiliser une boucle for pour calculer la somme
for (i in 1:N) {
  somme <- somme + 1/i
}

# Afficher le résultat
cat("La somme est égale à :", N*somme, "\n")

# Afficher le résultat
cat("Nombre moyen de semaines pour compléter la collection (approximation) :", esperance, "\n")

