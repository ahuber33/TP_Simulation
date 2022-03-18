# TPSim for Thomson Parabola Simulation


#commit #1 le 23/02/2022 [TPSim.0.0.0]:
#-Reprise en main du code GMSim de la version G4-9.6p02 pour le mettre sur la version G4-11.0
#-Changement de l'intégralité des noms GMSim en TPSim
#-Premier nettoyage rapide du code sur certaines fonctions
#-Création Tree electrons + fonctions en vue de vérifier les PhysicsList

#commit #2 le 24/02/2022 (Validation G4EM-electrons) [TPSim.0.1.0]:
#-Changement de la définition du Scintillateur pour coller aux données de ESTAR
#-Création matériau Carbon pour tests avec ESTAR
#-Géométrie basique pour le moment pour tests G4EM
#-Ajout d'un Script bash permettant de lancer plusieurs simulations tout en controlant le nombre de process => Script.sh qui utilise le vrml_base.mac pour créer des macro base_{i}.mac qui seront utilisés pour lancer la simulation
#-Mise au point d'un code d'analyse Plot.C et Plot.hh afin de comparer les CSDA des électrons dans plusieurs matériaux (Lecture fichier txt, lecture Tree, création TGraph)
#-Nettoyage du dossier bin (Scripts, macros et fichiers txt correspondants à la simulation GMSim)
#-De nombreux tests avec .gitignore pour faciliter l'utilisation

#commit #3 le 25/02/2022 (Validation G4EM-protons) [TPSim.0.1.1]
#-Changement taille scintillateur pour pouvoir suivre le proton de 500 MeV sur toute sa trajectoire dans le Scintillateur
#-Changement définition holder de Orb en Box
#-Ajout d'un StopandKill pour gagner du temps sur les particules secondaires générées
#-Ajout des données de pstar pour comparaison avec simulation
#-Ajout d'un script (Script_rapide) permettant de lancer la même simulation sur plusieurs coeurs utilisant la même macro
#-Changement de valeur du Cut dans la PhysicsList (passage de 1mm à 1µm) afin de pouvoir suivre correctement le proton dans les différents matériaux
#-Le tree electrons est juste utilisé ici pour avoir les informations sur les protons -> Nécessité de faire attention par la suite et de surement créer un autre tree pour les protons
#-Du aux nombreux gammas crées, la condition de remplissage du tree (Estart=Edep) a été enlevé.

#commit #4 le 28/02/2022 (Mise en place partie Optique) [TPSim.0.2.0]
#-Ajout des fichiers Coupling et PMT (temporairement ou non) afin de pouvoir vérifier la partie optique sur les scintillateurs SuperNEMO
#- Ajout de l'ensemble des fonctions, géométries, matériaux et variables liés à SuperNEMO (temporaire ou non) nécessaire pour la vérification de la partie optique
#- Ajout propriétés optique du scintillateur, mylar, teflon, colle, photocathode et PM
#- Lecture des fichiers config à base de vecteurs et plus de tableau (a nécessité la mise au point d'un petit code Reverse_file.C permettant de changer l'ordre de lecture du fichier. Précédemment de la plus petite à la plus grande longueur d'onde, maintenant c'est l'inverse d'où la présence des fichiers reverse).
#-Accès à l'ensemble des informations liéss à la scintillation et/ou Cerenkov puis transfert dans un Tree (pris en grande partie du code de SuperNEMO mais nettoyé et mis à jour).
#-Possibilité d'activer ou de désactiver la scintillation et/ou Cerenkov
#-Possibilité de considérer uniquement les photons détectés et/ou transmis
#-Changement du Cut dans la PhysicsList à 1mm pour faciliter/accélerer l'analyse optique avec électrons

#commit #5 le 07/03/2022 (Ajout partie LaBr3 + nettoyage) [TPSim.0.3.0]
#-Ajout des fichiers géométries correspondant à la configuration HPD et PMT (fichiers de config inclus pour le scintillateur LaBr3 et le PM)
#-Ajout des spectres réels de flash X issues de l'expérience de Emmanuel au CELIA dans Geant4
#-Ajout de fonctions pour ploter les résultats dans Plot.hh
#-Création code LaBr3 attenuation pour vérification que Labs est bien pris en compte dans la simulation
#-Création code rapide permettant d'obtenir un étalonnage entre énergie et photons générés/détectés (etalonnage_LaBr3.C)
#-Remise en forme de l'ensemble des fichiers hh et cc avec l'indentation automatique
#-Ajout de commentaires sur certaines parties du code
#-Mise en forme du code plus propre avec déclarations des variables et fonctions en début de fichier pour faciliter la lecture
#-Ajout de la données "Time" dans le root de sortie permettant de connaitre la répartition temporelle des photons sur la photocathode

#commit #6 le 09/03/2022 [TPSim.0.3.1]
# - Ajout de la propriété Rayleigh scattering et donc split de l'attenuation length en absorption length et scattering length selon [https://www.researchgate.net/publication/254060762_Optical_Absorption_Length_Scattering_Length_and_Refractive_Index_of_LaBr3Ce3]
# - Selon cette référence, l'absorption entraine quasi à chaque fois la réémission d'un photon derrière donc à investiguer dans le futur !!!
# - Changement de position de certaines lignes de code pour plus de clarté

#commit #7 le 16/03/2022 [TPSim0.4.0]
# - Ajout des longueurs de référence de la TP dans le fichier de config. L'ensemble des distances pour le placement des éléments dépend de ces paramètres. Ensemble des liens effectués
# - Ajout dans le vis.mac des lignes permettant d'afficher la direction des champs magnétiques et électriques
# - Création de l'ensemble des volumes principaux de la TP. La zone de champ magnétique est électrique est crée et englobe la partie créant le champ.
# - Ajout des fonctions permettant d'obtenir et de stocker les positions d'interaction des particules dans le détecteur.
# - Ajout des élements permettant de générer un champ magnétique et électrique uniforme dans le TPSimGeometry.cc. ATTENTION : La vérification des déviations pour le champ magnétique laissé apparaitre des écarts de plus en plus important entre la simu et les équations pour les trajectoires très déviées. A suivre et investiguer !!!!!!!!!! Ok pour le champ électrique !!!!
# - PROBLEME AVEC LA GENERATION DES IONS AVEC Z>2. NE PREND PAS EN COMPTE LA CHARGE IONIQUE DANS LE GPS/ION. INVESTIGATION EN COURS !!!!

#commit #8 le 18/03/2022 [TPSim.0.4.1]
# - Ajout des propriétés du scintillateur ZnS et ajout dans la simulation
# - Création des variables associées au ZnS
