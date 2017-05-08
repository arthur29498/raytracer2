/*
** my_memset.c for libacp in /lib/acp/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sun Feb 26 20:01:51 2017 Arthur Philippe
** Last update Sun May  7 18:12:22 2017 Arthur Philippe
*/

#include <stdlib.h>

void	*my_memset(void *str, int c, int size)
{
  int	i;
  char	*out;

  i = 0;
  out = str;
  while (i < size)
    {
      out[i] = c;
      i += 1;
    }
  return ((void *) out);
}

void	*ub_malloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    return (NULL);
  my_memset(ptr, 0, size);
  return (ptr);
}
