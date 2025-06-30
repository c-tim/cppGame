# cppGame
## Nom : The Agricult

## Synopsis :
Dans un monde parfait ou l'agriculture n'a jamais existé, un groupe de séparatistes utilise une machine à voyager dans le temps pour partager la technologie à des êtres humains à l'ère préhistorique, tout en prenant garde à ne pas se faire prendre par la police temporelle.

## Description :
Le jeu a deux équipes : 2 voyageurs cachés parmi la foule, et le chercheur (qui a la souris).

### Joueurs cachés (2 joueurs):
#### touches :
premier joueur :ZQSD (E pour planter)
deuxième joueur : flèches directionnelles ( touche ; pour planter)

objectif : imiter les humains dans la scènes et planter des plants de pommes de terre pour marquer des points.

### Joueur chercheur 
#### touches :
clic gauche pour deplacer un humain (joueur ou non-joueurs), clic-droit pour "vérifier" l'humain sélectionné.
Si l'humain sélectionné est bien un joueur, la partie s'arrête.


## Image :

![Copie d'écran_20250618_004448](https://github.com/user-attachments/assets/8c48e105-f29a-4615-a6e2-a49d1b878572)

## Lancer le jeu
Sur Vscode le jeu peut être compilé et lancé avec le module officiel de Microsoft CMakeTools.
Dans le fichier gameDatas.hpp, vous pouvez modifiez les variables constantes du jeu pour s'amuser, dont :
- le nombre de joueurs cachés (1 ou 2)
- le nombre d'humains non jouables (stable jusqua 200 sur mon pc 8gb de RAM)
- la vitesse des humains et des plants de pommes de terre
- les ratios d'activations des humains (1 ils bougent tout le temps)
- en milliSeconde, le temps d'attente pour planter (commun aux joueurs)




##English

## author : Timothée Cuq
## subject : Agriculture is the worst error of mankind

## Synopsis :
In a perfect society where agriculture never existed, a group of separatists acquired a time machine to go back in time and share this technology to humans in the Prehistoric era. While doing so, they have to mingle with the population before getting caught by the time police.

## Description :
The game has two teams : one catcher and one hider (there may be more hiders later).
The hiders have to mimic the non playable humans that are wandering on the map. The catcher has to select the humans he thinks are the real players to win.
The hiders can plant crops secretely to score points. They will grow and can be used as a visual hint to know the position of the player at the time he planted it.

If the hiders have planted enough crops, they win. Otherwise the catcher wins.
