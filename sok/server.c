#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888 // Définit le port sur lequel le serveur écoutera les connexions entrantes

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the server!"; // Message de bienvenue que le serveur envoie au client lorsqu'une connexion est établie

    // Crée un socket pour le serveur
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attache le socket du serveur à une adresse et un port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Met le socket en mode écoute pour les connexions entrantes
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepte une connexion entrante et crée un nouveau socket pour la communication avec le client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Envoie le message de bienvenue au client
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    printf("Welcome message sent\n");

    // Lit le message envoyé par le client
    int valread = read(new_socket, buffer, 1024);
    printf("Received message from client: %s\n", buffer);

    // Envoie un message echo au client
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Echo message sent\n");

    return 0;
}
