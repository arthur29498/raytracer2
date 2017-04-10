/*
** flags3.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Sat Nov 12 14:30:37 2016 Arthur Philippe
** Last update Wed Jan 25 17:50:22 2017 Arthur Philippe
*/

#include "acp_print.h"

int	flag_b_binary(va_list params)
{
  return (my_putnbr_base(va_arg(params, unsigned int), "01"));
}

int	flag_b_binary_long(va_list params)
{
  return (my_putlong_base(va_arg(params, unsigned long), "01"));
}

int	flag_n_store(va_list params, int sum)
{
  int	*ptr;

  ptr = va_arg(params, int *);
  *ptr = sum;
  return (0);
}
