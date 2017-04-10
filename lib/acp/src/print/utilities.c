/*
** utilities.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Thu Nov 17 11:04:24 2016 Arthur Philippe
** Last update Mon Apr 10 09:10:27 2017 Arthur Philippe
*/

#include "acp_print.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i] && str[i] != -1)
    i += 1;
  return (i);
}

int	my_power_it(int nb, int p)
{
  int	original_nb;
  int	out;

  out = 1;
  original_nb = nb;
  if (!p)
    return (1);
  if (p < 0)
    return (0);
  while (p >= 1)
    {
      out *= original_nb;
      p--;
    }
  return (out);
}

long	my_power_long(long nb, int p)
{
  long	original_nb;
  long	out;

  out = 1;
  original_nb = nb;
  if (!p)
    return (1);
  if (p < 0)
    return (0);
  while (p >= 1)
    {
      out *= original_nb;
      p--;
    }
  return (out);
}

int		min_char_count(int mode, int new_count, char *c)
{
  static int	count;
  static char	replacement;

  if (mode)
    {
      if (c)
	replacement = *c;
      count = new_count;
    }
  else
    {
      if (c)
	*c = replacement;
      return (count);
    }
  return (0);
}

int	nbr_prefix(int len)
{
  int	diff;
  int	sum;
  char	letter;

  sum = 0;
  diff = 0;
  letter = ' ';
  if (min_char_count(0, 0, &letter))
    if (min_char_count(0, 0, 0) > len)
      diff = (min_char_count(0, 0, 0) - len) - 2;
  while (diff--)
    sum += my_putchar(letter);
  min_char_count(1, 0, " ");
  return (sum);
}
