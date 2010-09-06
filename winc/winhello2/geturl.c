#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <sys/socket.h>   //*nix
#include <winsock.h>    //windows
//#include <netinet/in.h>
//#include <netdb.h>

#define HTTPPORT 80


char* head =
     "GET /u2/76292/ HTTP/1.1\r\n"
     "Accept: */*\r\n"
     "Accept-Language: zh-cn\r\n"
     "Accept-Encoding: gzip, deflate\r\n"
     "User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; CIBA; TheWorld)\r\n"
     "Host:blog.chinaunix.net\r\n"
     "Connection: Keep-Alive\r\n\r\n";

int connect_URL(char *domain,int port)
{
    int sock;
    struct hostent * host;
    struct sockaddr_in server;
    host = gethostbyname(domain);
    if (host == NULL)
     {
      printf("gethostbyname error\n");
      return -2;
     }
   // printf("HostName: %s\n",host->h_name);

   // printf("IP Address: %s\n",inet_ntoa(*((struct in_addr *)host->h_addr)));

    sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock < 0)
    {
      printf("invalid socket\n");
      return -1;
    }
    memset(&server,0,sizeof(struct sockaddr_in));
    memcpy(&server.sin_addr,host->h_addr_list[0],host->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    return (connect(sock,(struct sockaddr *)&server,sizeof(struct sockaddr)) <0) ? -1 : sock;
}


int main()
{
  int sock;
  char buf[100];
  char *domain = "blog.chinaunix.net";

  
  fp = fopen("test.txt","rb");
  if(NULL == fp){
    printf("can't open stockcode file!\n");
    return -1;
  }
  

    sock = connect_URL(domain,HTTPPORT);
    if (sock <0){
       printf("connetc err\n");
       return -1;
        }

    send(sock,head,strlen(head),0);

    while(1)
    {
      if((recv(sock,buf,100,0))<1)
        break;
      fprintf(fp,"%s",bufp); //save http data

      }
    
    fclose(fp);
    close(sock);
  
  printf("bye!\n");
  return 0;
} 
