#ifndef __VOD_H__
#define __VOD_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT    80
#define dprint 0

#if dprint
#define dprintf(args...)  printf(args)
#else
#define dprintf(args...)  do{}while(0)
#endif

#define SERVER_DIR  "/var/www/html/MediaFiles/"
//#define FILE_NAME   "/var/www/html/MediaFiles/list.txt"
#define FILE_NAME   "list.txt"

#define SERVERIP    "192.168.0.101"

#define ASK_TXT 'a' + 's' + 'k' + 't'
#define ACK_TXT 'a' + 'c' + 'k' + 't'
#define ASK_VID 'a' + 's' + 'k' + 'v'
#define ACK_VID 'a' + 'c' + 'k' + 'v'

/*#define MAGIC   'l' + 'z' + 'c'*/
#define MAGIC   0x12345678
#define ACK     0x87654321
/*#define ACK     'l' + 'z' + 'c'*/

#define debug() printf("line: %d func: %s\n", __LINE__, __FUNCTION__)

#define PERROR(con, func, ret)                      \
            do{                                     \
                if(con)                             \
                {                                   \
                    func;                           \
                    return (ret);                   \
                }                                   \
            }while(0)


#define ERR(con, func, ret)                         \
            do{                                     \
                if(con)                             \
                {                                   \
                    fprintf(stderr,                 \
                    "file: [%s] line: %d: %s error\n",         \
                    __FILE__, __LINE__, #func);     \
                    ret;                            \
                }                                   \
            }while(0)

#endif  /* __VOD_H__ */
