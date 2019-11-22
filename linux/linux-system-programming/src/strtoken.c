#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char tokdelim;

char * strtoken( char **string, const char *delimiters);

int main()
{
    char damin_name[]="mta_7d5b9f@cms.pclab.com";
    strtoken(&damin_name,"@");
    printf("%s\n",&damin_name);
    return 0;
}

char * strtoken( char **string, const char *delimiters)
{
   unsigned char *str;
   unsigned long map[8];
   int count;

   char *nextoken;

   /* Clear control map */
   for (count = 0; count < 8; count++)
   {
      map[count] = 0;
   }

   /* Set bits in delimiter table */
   do
   {
      map[*delimiters >> 5] |= (1 << (*delimiters & 31));
   }
   while (*delimiters++);

   str = *string;

   /* Find beginning of token (skip over leading delimiters). Note that
   ** there is no token iff this loop sets str to point to the terminal
   ** null (*str == '\0')
   */
   while (( (map[*str >> 5] & (1 << (*str & 31))) && *str) || (*str == ' '))
   {
      str++;
   }

   nextoken = str;

   /* Find the end of the token. If it is not the end of the string,
   ** put a null there.
   */
   tokdelim = '\0';
   for ( ; *str ; str++ )
   {
      if ( map[*str >> 5] & (1 << (*str & 31)) )
      {
         tokdelim = *str;
         *str++ = '\0';
         break;
      }
   }

   *string = str;

   /* Determine if a token has been found. */
   if ( nextoken == (char *) str )
   {
      return NULL;
   }
   else
   {
      return nextoken;
   }
}
