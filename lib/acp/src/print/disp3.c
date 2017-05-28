/*
** disp3.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Sun Nov 20 13:03:11 2016 Arthur Philippe
** Last update Sun May 28 18:06:35 2017 Arthur Philippe
*/

#include "acp_print.h"

int	my_put_alt_prefix(char *base, int b_len)
{
  int	sum;
  char	x;

  sum = 0;
  x = 0;
  if (b_len == 16)
    x = base[10] + 23;
  if (apply_preformat(0, 0) == 3)
    {
      sum += my_putchar('0');
      if (x)
	sum += my_putchar(x);
    }
  apply_preformat(1, 0);
  return (sum);
}
