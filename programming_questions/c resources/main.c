#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


#define MAX 1000
#define SIZE 50
#define swap(x, y) { int tmp=x; x=y; y=tmp; }
#define PORT 8080


int main(){

    /*          SERVER              */

    struct sockaddr_in socket_addr;
    //create socket
    int fd;

    fd = socket(AF_NET, SOCK_STREAM, 0); //address family and stream
    //attach ip address

    // bind socket
    bind(fd, (struct sockaddr_in *)&socket_addr, SIZE, 0);
    socket_addr.sin_family = AF_INET;
    socket_add.sin_addr = INADDR_ANY;
    socker_add.port = hton(PORT)

    // listen
    listen(fd);

    // accept the input requests 
    int socket = accept(fd, address, size(address))

    int buffer[50]
    read(socket, buffer, size)

    write(socket, "message from server", size);

    return 0;


    /*              CLIENT              */

    int fd
    //create socket 
    fd = socket(AF_INET, SOCk_STEAM, 0);

    struct sockaddr_in sock_addr;

    // inet_pton - presentation to network
    inet_pton(fd,"127.0.0.1", srv_address, size)

    socket = connect(fd, srv_address, sizeofaddress )

    write(socket, "message", size)
    read(socket, buffer, size)





}