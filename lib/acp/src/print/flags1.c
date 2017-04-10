/*
** flags1.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Wed Nov  9 21:38:24 2016 Arthur Philippe
** Last update Wed Jan 25 17:50:09 2017 Arthur Philippe
*/

#include "acp_print.h"

int	flag_x_hexa(va_list params)
{
  return (my_putnbr_base(va_arg(params, unsigned int), "0123456789abcdef"));
}

int	flag_X_hexa(va_list params)
{
  return (my_putnbr_base(va_arg(params, unsigned int), "0123456789ABCDEF"));
}

int	flag_o_octal(va_list params)
{
  return (my_putnbr_base(va_arg(params, unsigned int), "01234567"));
}

int	flag_u_unsigned(va_list params)
{
  return (my_putnbr_base(va_arg(params, unsigned int), "0123456789"));
}

int	flag_p_pointer(va_list param)
{
  int	sum;

  sum = write(1, "0x", 2);
  sum += my_putlong_base(va_arg(param, unsigned long), "0123456789abcdef");
  return (sum);
}
