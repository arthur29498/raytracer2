/*
** disp1.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Sat Nov 12 11:45:53 2016 Arthur Philippe
** Last update Wed Jan 25 17:49:35 2017 Arthur Philippe
*/

#include "acp_print.h"

int	my_putstr_and_nonascii(char *str)
{
  int	sum;
  char	code[5];

  sum = 0;
  while (*str)
    {
      if (*str >= 32 && *str < 127)
	sum += write(1, str, 1);
      else
	{
	  code[4] = 0;
	  code[3] = (*str % 10) + 48;
	  code[2] = (*str / 10 % 100) + 48;
	  code[1] = (*str / 100) + 48;
	  code[0] = '\\';
	  sum += my_putstr(code);
	}
      str += 1;
    }
  return (sum);
}

int	my_putlong(va_list params)
{
  long	tmp;
  int	index;
  int	printed;
  int	nb;

  nb = va_arg(params, long);
  index = 0;
  tmp = nb;
  printed = my_put_sign(nb);
  nb = (nb < 0) ? -nb : nb;
  if (!nb)
    return (my_putchar('0'));
  while (tmp)
    {
      tmp = tmp / 10;
      index = index + 1;
    }
  printed += nbr_prefix(tmp + printed);
  while (--index >= 0)
    {
      my_putchar((nb / my_power_long(10, index)) + 48);
      nb = nb % my_power_long(10, index);
      printed += 1;
    }
  return (printed);
}
