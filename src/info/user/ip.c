#include <sys/socket.h> /* socket */
#include <netinet/in.h> /* sockaddr_ini */
#include <arpa/inet.h>  /* getsockname */
#include <unistd.h>
#include <assert.h>
#include <malloc.h>

#define GOOGLE_DNS "8.8.8.8"
#define RLEN				50
#define DNSPORT			53

extern void *memset(void *, int, size_t);
const char *ip(void)
{ 
    struct sockaddr_in serv;     
    char	*r;
    int		 sock;
     
    /* Socket could not be created */
    assert( (sock = socket ( AF_INET, SOCK_DGRAM, 0)) >= 0);
     
    memset( &serv, 0, sizeof(serv) );
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr( GOOGLE_DNS );
    serv.sin_port = htons( DNSPORT );
 
    int err = connect( sock , (const struct sockaddr*) &serv , sizeof(serv) ); 
    struct sockaddr_in name;
    socklen_t namelen = sizeof(name);
    err = getsockname(sock, (struct sockaddr*) &name, &namelen);
         
		if (inet_ntop(AF_INET, &name.sin_addr, (r = malloc(RLEN)), RLEN))
			return r;
 
    close(sock);
		return "(none)";
}
