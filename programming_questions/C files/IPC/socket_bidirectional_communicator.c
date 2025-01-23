#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 8080 //http port



void server(){

    struct sockaddr_in address; // address family
    int new_socket;
    int server_fd;

    //create socket fd // SOCK_DGRAM - use UDP else TCP for STREAM
    server_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (server_fd == 0) {
        printf("socket create failed\n")
    }

    //socket is IP and Port. so now attach ip and port to the socket
    // bind socket fd to the ipv4adress and port
    if((bind(server_fd, (struct sockaddr *)&address), sizeof(address)) < 0){
        printf("bind failed");
    }

    address.sin_family = AF_INET; // ipv4 address
    address.sin_addr.s_addr = INADDR_ANY // any address
    address.sin_port = htons(PORT)    // convert from short interger to host byte order

    // after bind, listen to the incomming req
    if(listen(server_fd, 3)<0) {
        printf("failed to listen\n"); //passivlt listen to the port
    }

    if (new_socket = accept(server_fd, (struct sockaddr_in *)&address, strlen(address)) < 0){
        printf("failed to accept\n");
    }

    char buffer[1024];
    read(new_socket, buffer, 1024);
    printf("msg from client: %s", buffer);

    send(new_socket, "hello from server", 1024, 0);
    printf("msg sent from server");

}


void client(){

    int client_sock; // client_sock is the client file descriptor
    struct sockaddr_in srv_address;
    int buffer[1024];

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("failed to create socket\n");
    }

    srv_address.sin_family = AF_INET; //ipv4 family
    srv_address.sin_port = htons(PORT); // convert short to host byte format
    
    if((inet_pton(AF_INET, "127.0.0.1", &srv_address.sin_addr)) <= 0){  // inet_pton = presentation to network. convert from text to binary form
        printf("invalid address")
    }

    if(connect(client_sock, (struct sockaddr_in *)&srv_address, sizeof(srv_address))<0){
        printf("connetion failed\n");
    }

    send(client_sock, "hello from client", 1024, 0);
    printf("sent msg from client");
    read(client_sock, buffer, 1024, 0);
    printf("recevied msg from server");
    close(client_sock);

}


int main(){

    client();
    server();

    return 0;
}