/*
** utilities1.c for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Thu Nov 17 09:08:17 2016 Arthur Philippe
** Last update Mon Apr 10 09:10:36 2017 Arthur Philippe
*/

#include "acp_print.h"

int	get_min_char_count(char **strptr, va_list params)
{
  int	min_c;
  char	c;

  min_c = 0;
  c = get_preformat(strptr);
  if ((**strptr) >= '0' && (**strptr) <= '9')
    {
      while ((**strptr) >= '0' && (**strptr) <= '9')
	{
	  min_c = (min_c * 10) + ((**strptr) - 48);
	  *strptr += 1;
	}
      min_char_count(1, min_c, &c);
      *strptr = *strptr - 1;
      return (get_flag_rank(strptr, params));
    }
  else if ((**strptr) == '*')
    {
      min_char_count(1, va_arg(params, int), &c);
      return (get_flag_rank(strptr, params));
    }
  else if (apply_preformat(2, 0))
    return (get_flag_rank(strptr, params));
  return (84);
}

char	get_preformat(char **strptr)
{
  char	c;

  c = ' ';
  if ((**strptr) == '0')
    {
      c = '0';
      *strptr += 1;
    }
  if ((**strptr) == '+')
    apply_preformat(1, 1);
  else if ((**strptr) == ' ')
    apply_preformat(1, 2);
  else if ((**strptr) == '#')
    apply_preformat(1, 3);
  return (c);
}

int		apply_preformat(int mode, int n_preformat)
{
  static int	preformat;
  static int	checked;

  if (mode == 1)
    {
      preformat = n_preformat;
      checked = 0;
    }
  else if (!mode)
    return (preformat);
  else if (mode == 2 && !checked)
    {
      checked = 1;
      return (preformat);
    }
  return (0);
}
