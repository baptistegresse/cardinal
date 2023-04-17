#include "../../includes/cardinal.h"

size_t  count_words(const char *string)
{
    size_t count;
    size_t in_word;

    count = 0;
    in_word = 0;
    while (*string!= '\0')
    {
        if (isspace(*string))
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        string++;
    }
    return (count);
}

char ** split(const char * str, const char * delim)
{
  /* count words */
  char * s = strdup(str);

  if (strtok(s, delim) == 0)
    /* no word */
    return NULL;

  int nw = 1;

  while (strtok(NULL, delim) != 0)
    nw += 1;

  strcpy(s, str); /* restore initial string modified by strtok */

  /* split */
  char ** v = malloc((nw + 1) * sizeof(char *));
  int i;

  v[0] = strdup(strtok(s, delim));

  for (i = 1; i != nw; ++i)
    v[i] = strdup(strtok(NULL, delim));

  v[i] = NULL; /* end mark */

  free(s);

  return v;
}
