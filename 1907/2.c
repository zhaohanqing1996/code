/*************************************************************************
	> File Name: 2.c
	> Author: zhq
	> E-mail: zhaohanqing1996@outlook.com
	> Created Time: Fri Jul 19 13:16:35 2019
 ************************************************************************/

#include <stdio.h>
#include <assert.h>

#define assert( x ) { int *null = (int*)0; if ( x == 0 ) *null = 1; }


const char *ares_strerror(int code,char **memptr);

int main(int argc,char *argv[])
{
	 
	return 0;
}

const char *ares_strerror(int code,char **memptr)
{
	const char *errtext[] = {
    "Successful completion",
    "DNS server returned answer with no data",
    "DNS server claims query was misformatted",
    "DNS server returned general failure",
    "Domain name not found",
    "DNS server does not implement requested operation",
    "DNS server refused query",
    "Misformatted DNS query",
    "Misformatted domain name",
    "Unsupported address family",
    "Misformatted DNS reply",
    "No DNS resolution found",
    "Timeout while contacting DNS servers",
    "End of file",
    "Error reading file",
    "Out of memory",
    "Destruction",
    "IP stack down or UDP failure"
	};
	assert(code >= 0 && (unsigned int)code < (sizeof(errtext) / sizeof(*errtext)));
	return errtext[code];
}
