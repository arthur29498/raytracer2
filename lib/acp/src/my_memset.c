/*
** my_memset.c for libacp in /lib/acp/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sun Feb 26 20:01:51 2017 Arthur Philippe
** Last update Mon Apr 10 09:10:49 2017 Arthur Philippe
*/

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
