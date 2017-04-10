/*
** my_putstr.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 16 16:27:32 2017 Arthur Philippe
** Last update Wed Mar 15 10:27:36 2017 Arthur Philippe
*/

#include <unistd.h>
#include "acp.h"

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

char	*my_strcat(char *dest, char *src)
{
  if (!src || !dest)
    return (0);
  while (*dest)
    dest += 1;
  while (*src)
    {
      *dest = *src;
      src += 1;
      dest += 1;
  }
  *dest = 0;
  return (dest);
}

int	acp_putstr(int fd, char *str)
{
  if (str)
    return (write(fd, str, my_strlen(str)));
  return (-1);
}

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

int	my_getnbr(char *str)
{
  int	nb;
  int	sign;

  nb = 0;
  sign = 1;
  if (*str == '-')
    {
      sign = -1;
      str += 1;
    }
  while (*str >= '0' && *str <= '9')
    {
      nb = (nb * 10) + ((*str) - 48);
      str += 1;
    }
  return (sign * nb);
}
