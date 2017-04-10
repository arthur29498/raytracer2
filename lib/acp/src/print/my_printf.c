/*
** my_printf.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Wed Nov  9 16:45:17 2016 Arthur Philippe
** Last update Mon Mar 20 12:52:19 2017 Arthur Philippe
*/

#include "acp_print.h"

int	get_flag_rank(char **strptr, va_list params)
{
  char	*ranks;
  int	rank;

  rank = 0;
  ranks = "csSdxXoubp%hlnm";
  *strptr += 1;
  if ((**strptr) == 'i')
    return (3);
  while (ranks[rank])
    {
      if (ranks[rank] == (**strptr))
	return (rank);
      rank += 1;
    }
  return (get_min_char_count(strptr, params));
}

int		flag_manager(char **strptr, va_list params, int o_sum)
{
  int		sum;
  int		(*flag_option[15])(va_list);
  int		rank;

  flag_option[0] = my_putchar_va;
  flag_option[1] = my_putstr_va;
  flag_option[2] = my_putstr_and_nonascii_va;
  flag_option[3] = my_putnbr_va;
  flag_option[4] = flag_x_hexa;
  flag_option[5] = flag_X_hexa;
  flag_option[6] = flag_o_octal;
  flag_option[7] = flag_u_unsigned;
  flag_option[8] = flag_b_binary;
  flag_option[9] = flag_p_pointer;
  rank = get_flag_rank(strptr, params);
  sum = 0;
  sum += (rank == 10) ? write(1, "%", 1) : 0;
  sum += (rank == 13) ? flag_n_store(params, o_sum) : 0;
  if (rank == 11 || rank == 12)
    return (long_flags(strptr, params));
  else if (rank != 10 && rank < 13)
    return (flag_option[rank](params));
  return (sum);
}

int		acp_print(char *str, ...)
{
  va_list	params;
  int		sum_printed;
  char		**strptr;

  sum_printed = 0;
  if (!str)
    return (0);
  strptr = malloc(sizeof(char *));
  if (!strptr)
    return (0);
  (*strptr) = str;
  va_start(params, str);
  while (**strptr)
    {
      if (**strptr != '%')
	sum_printed += my_putchar(**strptr);
      else
	sum_printed += flag_manager(strptr, params, sum_printed);
      *strptr += 1;
    }
  va_end(params);
  free(strptr);
  return (sum_printed);
}
