#Dépot pour le cours réseau-sans-fil et iot:
##Application sur Sockets:
###Application client-serveur:
	-Le serveur crée un socket en écoutant sur un port donné.
	-Le client crée un socket et se connecte au serveur en utilisant l'adresse IP et le port du serveur.
	-Le serveur accepte la connexion du client et crée un nouveau socket pour cette connexion.
	-Le client et le serveur peuvent maintenant s'envoyer des données via les sockets.
	-Une fois la communication terminée, le client et le serveur ferment leurs sockets respectifs.
