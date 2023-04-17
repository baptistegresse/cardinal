#include "../../includes/cardinal.h"

char    *strjoin(const char *s1, char *s2)
{
    char    *result; 
    
    result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result)
    {
        strcpy(result, s1);
        strcat(result, s2);
    }
    return (result);
}
