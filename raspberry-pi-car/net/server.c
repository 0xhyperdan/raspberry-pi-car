//
//  server.c
//  C-Socket
//
//  Created by 丛晓丹 on 2018/9/30.
//
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "car.h"
#include <arpa/inet.h>
#define PORT 7891
#define HOST "127.0.0.1"
int main(){
    initCar();
    int welcomeSocket, newSocket;
    char buffer[1024];
    char input;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    
    /*---- Create the socket. The three arguments are: ----*/
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    
    /*---- Configure settings of the server address struct ----*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(HOST);
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    
    if(listen(welcomeSocket, 5) == 0)
        printf("Listening\n");
    else
        printf("Error\n");
    
    /*---- Accept call creates a new socket for the incoming connection ----*/
    addr_size = sizeof serverStorage;
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
    
    /*---- Send message to the socket of the incoming connection ----*/
    recv(welcomeSocket, &input, 1024, 0);
    printf("client message: %c", input);
    switch (input) {
        case 'w': // forward
            stop();
            forward();
            break;
        case 'a': // left
            stop();
            left();
            break;
        case 'd': // right
            stop();
            right();
            break;
        case 's': // back
            stop();
            back();
            break;
        case 'p': // stop
            stop();
            break;
        default:
            break;
    }
    strcpy(buffer, "ok\n");
    send(newSocket, buffer, 13, 0);
    
    return 0;
}
