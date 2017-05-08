/*
** my_strdup.c for lacp in /home/arthur/Projects/new_gnl/lib/acp/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sun May  7 19:53:38 2017 Arthur Philippe
** Last update Sun May  7 20:12:24 2017 Arthur Philippe
*/

#include <stdlib.h>
#include "str.h"

char	*my_strcpy(char *dest, char *src)
{
  if (!src || !dest)
    return (NULL);
  while (*src)
    {
      *dest = *src;
      src += 1;
      dest += 1;
    }
  *dest = 0;
  return (dest);
}

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  if (!src)
    return (NULL);
  if (!((dest = malloc(my_strlen(src) + 1))))
    return (NULL);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = 0;
  return (dest);
}
