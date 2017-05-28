/*
** disp.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Wed Nov  9 16:51:23 2016 Arthur Philippe
** Last update Sun May 28 18:06:05 2017 Arthur Philippe
*/

#include "acp_print.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

int	my_putnbr(int nb)
{
  int	tmp;
  int	index;
  int	printed;

  index = 0;
  tmp = nb;
  printed = my_put_sign((long) nb);
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
      my_putchar(nb / my_power_it(10, index) + 48);
      nb = nb % my_power_it(10, index);
      printed += 1;
    }
  return (printed);
}

int		my_putnbr_base(unsigned int nb, char *base)
{
  unsigned int	tmp;
  int		index;
  int		printed;
  int		b_len;

  b_len = my_strlen(base);
  index = 0;
  tmp = nb;
  if (!nb)
    return (my_putchar('0'));
  printed = my_put_alt_prefix(base, b_len);
  while (tmp)
    {
      tmp = tmp / b_len;
      index = index + 1;
    }
  printed += nbr_prefix(tmp);
  while (--index >= 0)
    {
      my_putchar(base[nb / my_power_it(b_len, index)]);
      nb = nb % my_power_it(b_len, index);
      printed += 1;
    }
  return (printed);
}

int			my_putlong_base(unsigned long nb, char *base)
{
  unsigned long		tmp;
  int			index;
  int			printed;
  int			b_len;

  b_len = my_strlen(base);
  index = 0;
  tmp = nb;
  if (!nb)
    return (my_putchar('0'));
  printed = my_put_alt_prefix(base, b_len);
  while (tmp)
    {
      tmp = tmp / b_len;
      index = index + 1;
    }
  printed += nbr_prefix(tmp);
  while (--index >= 0)
    {
      my_putchar(base[nb / my_power_long(b_len, index)]);
      nb = nb % my_power_long(b_len, index);
      printed += 1;
    }
  return (printed);
}
