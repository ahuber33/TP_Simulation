# TPSim for Thomson Parabola Simulation


#commit #1 le 23/02/2022 :
#-Reprise en main du code GMSim de la version G4-9.6p02 pour le mettre sur la version G4-11.0
#-Changement de l'intégralité des noms GMSim en TPSim
#-Premier nettoyage rapide du code sur certaines fonctions
#-Création Tree electrons + fonctions en vue de vérifier les PhysicsList

#commit #2 le 24/02/2022 (Validation G4EM-electrons):
#-Changement de la définition du Scintillateur pour coller aux données de ESTAR
#-Création matériau Carbon pour tests avec ESTAR
#-Géométrie basique pour le moment pour tests G4EM
#-Ajout d'un Script bash permettant de lancer plusieurs simulations tout en controlant le nombre de process => Script.sh qui utilise le vrml_base.mac pour créer des macro base_{i}.mac qui seront utilisés pour lancer la simulation
#-Mise au point d'un code d'analyse Plot.C et Plot.hh afin de comparer les CSDA des électrons dans plusieurs matériaux (Lecture fichier txt, lecture Tree, création TGraph)
#-Nettoyage du dossier bin (Scripts, macros et fichiers txt correspondants à la simulation GMSim)
#-De nombreux tests avec .gitignore pour faciliter l'utilisation

#commit #3 le 25/02/2022 (Validation G4EM-protons)
#-Changement taille scintillateur pour pouvoir suivre le proton de 500 MeV sur toute sa trajectoire dans le Scintillateur
#-Changement définition holder de Orb en Box
#-Ajout d'un StopandKill pour gagner du temps sur les particules secondaires générées
#-Ajout des données de pstar pour comparaison avec simulation
#-Ajout d'un script (Script_rapide) permettant de lancer la même simulation sur plusieurs coeurs utilisant la même macro
#-Changement de valeur du Cut dans la PhysicsList (passage de 1mm à 1µm) afin de pouvoir suivre correctement le proton dans les différents matériaux
#-Le tree electrons est juste utilisé ici pour avoir les informations sur les protons -> Nécessité de faire attention par la suite et de surement créer un autre tree pour les protons
#-Du aux nombreux gammas crées, la condition de remplissage du tree (Estart=Edep) a été enlevé.

#commit #4 le 28/02/2022 (Mise en place partie Optique)
#-Ajout des fichiers Coupling et PMT (temporairement ou non) afin de pouvoir vérifier la partie optique sur les scintillateurs SuperNEMO
#- Ajout de l'ensemble des fonctions, géométries, matériaux et variables liés à SuperNEMO (temporaire ou non) nécessaire pour la vérification de la partie optique
#- Ajout propriétés optique du scintillateur, mylar, teflon, colle, photocathode et PM
#- Lecture des fichiers config à base de vecteurs et plus de tableau (a nécessité la mise au point d'un petit code Reverse_file.C permettant de changer l'ordre de lecture du fichier. Précédemment de la plus petite à la plus grande longueur d'onde, maintenant c'est l'inverse d'où la présence des fichiers reverse).
#-Accès à l'ensemble des informations liéss à la scintillation et/ou Cerenkov puis transfert dans un Tree (pris en grande partie du code de SuperNEMO mais nettoyé et mis à jour).
#-Possibilité d'activer ou de désactiver la scintillation et/ou Cerenkov
#-Possibilité de considérer uniquement les photons détectés et/ou transmis 
#-Changement du Cut dans la PhysicsList à 1mm pour faciliter/accélerer l'analyse optique avec électrons
