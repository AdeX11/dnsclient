#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
/*
  Use the `getaddrinfo` and `inet_ntop` functions to convert a string host and
  integer port into a string dotted ip address and port.
 */
int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Invalid arguments - %s <host> <port>", argv[0]);
    return -1;
  }
  char* host = argv[1];
  struct addrinfo hints = { .ai_flags = AI_PASSIVE, .ai_family = AF_UNSPEC,
                          .ai_socktype = SOCK_STREAM,
                          .ai_protocol = IPPROTO_TCP,
                          .ai_addrlen =0,
                          .ai_addr = 0,
                          .ai_canonname = 0,
                          .ai_next = 0,
           };
  struct addrinfo* res =  malloc(sizeof(struct addrinfo));
  getaddrinfo(host,argv[2],&hints,&res);
  struct addrinfo* addr = res;
   while (addr != NULL)
  {
    char buff[1024];
    void* raw_addr;
    if (addr->ai_family == AF_INET) { // Address is IPv4
      struct sockaddr_in* tmp = (struct sockaddr_in*)addr->ai_addr; // Cast addr into AF_INET container
      raw_addr = &(tmp->sin_addr); // Extract the address from the container
      printf("IPv4 %s\n", inet_ntop(AF_INET,raw_addr,buff,1024));
    }
    else { // Address is IPv6
      struct sockaddr_in6* tmp = (struct sockaddr_in6*)addr->ai_addr; // Cast addr into AF_INET6 contai>
      raw_addr = &(tmp->sin6_addr); // Extract the address from the container
      printf("IPv6 %s\n", inet_ntop(AF_INET6,raw_addr,buff,1024));
    }
    addr = addr->ai_next;
  }

  return 0;
}
