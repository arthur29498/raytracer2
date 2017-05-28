/*
** my_putstr.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 16 16:27:32 2017 Arthur Philippe
** Last update Sun May 28 21:34:57 2017 Arthur Philippe
*/

#include <unistd.h>
#include "acp.h"

int	acp_putstr(int fd, char *str)
{
  if (str)
    return (write(fd, str, my_strlen(str)));
  return (-1);
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
