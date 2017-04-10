/*
** disp2.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Tue Nov 15 15:09:01 2016 Arthur Philippe
** Last update Wed Jan 25 17:49:40 2017 Arthur Philippe
*/

#include "acp_print.h"

int	my_putchar_va(va_list params)
{
  char	l;

  l = (char) va_arg(params, int);
  return (my_putchar(l));
}

int	my_putstr_va(va_list params)
{
  char	*str;
  int	diff;
  int	sum;

  diff = 0;
  sum = 0;
  str = va_arg(params, char *);
  if (!str)
    return (my_putstr("(null)"));
  if (min_char_count(0, 0, 0))
    if (my_strlen(str) < min_char_count(0, 0, 0))
      diff = min_char_count(0, 0, 0) - my_strlen(str);
  while (diff)
    {
      sum += my_putchar(' ');
      diff = diff - 1;
    }
  min_char_count(1, 0, " ");
  return (my_putstr(str) + sum);
}

int	my_putstr_and_nonascii_va(va_list params)
{
  char	*str;

  str = va_arg(params, char *);
  if (!str)
    return (my_putstr("(null)"));
  return (my_putstr_and_nonascii(str));
}

int	my_putnbr_va(va_list params)
{
  int	nb;

  nb = va_arg(params, int);
  return (my_putnbr(nb));
}

int	my_put_sign(long nb)
{
  if (nb < 0)
    return (my_putchar('-'));
  else if (apply_preformat(0, 0) == 1 && nb >= 0)
    {
      apply_preformat(1, 0);
      return (my_putchar('+'));
    }
  else if (apply_preformat(0, 0) == 2 && nb >= 0)
    {
      apply_preformat(1, 0);
      return (my_putchar(' '));
    }
  apply_preformat(1, 0);
  return (0);
}
