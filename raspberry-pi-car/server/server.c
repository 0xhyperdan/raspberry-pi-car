//
//  server.c
//  C-Socket
//
//  Created by 丛晓丹 on 2018/9/30.
//
#include <stdio.h>
#include <sys/socket.h>
#include <car.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 7891

void init_socket(void);
const int MAX_COUNT = 5;
const char *RESULT_SUCCESS = "ok";

int main(){
    init_car();
    init_socket();
    return 0;
}


void init_socket(){
    int soc, ret;
    char buffer[1];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    
    /*---- Create the socket. The three arguments are: ----*/
    soc = socket(PF_INET, SOCK_STREAM, 0);
    
    /*---- Configure settings of the server address struct ----*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    bind(soc, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    
    if(listen(soc, MAX_COUNT) == 0)
        printf("wait client commond.\n");
    else
        printf("Error\n");
    
    addr_size = sizeof serverStorage;
    
    for (;;) {
        /*---- Accept call creates a new socket for the incoming connection ----*/
        ret = accept(soc, (struct sockaddr *) &serverStorage, &addr_size);
        //printf("socket:%d  ret:%d\n", soc, ret);
        read(ret, buffer, 1024);
        printf("%c\n", buffer[0]);
        do_commond(buffer[0]);
        /*---- Send message to the socket of the incoming connection ----*/
        send(ret, RESULT_SUCCESS, strlen(RESULT_SUCCESS), 0);
    }
}
