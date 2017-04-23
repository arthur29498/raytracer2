/*
** get_opt.c for raytracer in /home/arthur/Projects/raytracer2/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 22 14:32:17 2017 Arthur Philippe
** Last update Sun Apr 23 13:47:31 2017 Arthur Philippe
*/

#include <stdlib.h>
#include "opt.h"
#include "acp.h"

void	set_rtc_opt(char *opt_str, t_rtc_opt *opt)
{
  int	i;

  i = 1;
  while (opt_str[i])
    {
      if (opt_str[i] == OPT_RDR)
	opt->render = 1;
      else if (opt_str[i] == OPT_EXP)
	opt->exprt = 1;
      else if (opt_str[i] == OPT_IMP)
	opt->imprt = 1;
      i += 1;
    }
}

t_rtc_opt	*get_rtc_opt(int ac, char **av)
{
  t_rtc_opt	*opt;

  if (!(opt = malloc(sizeof(t_rtc_opt))))
    return (NULL);
  my_memset(opt, 0, sizeof(t_rtc_opt));
  if (av[1][0] == '-')
    {
      if (ac == 3)
	{
	  set_rtc_opt(av[1], opt);
	  my_strcpy(opt->file_name, av[2]);
	  return (opt);
	}
      free(opt);
      return (NULL);
    }
  else
    my_strcpy(opt->file_name, av[1]);
  return (opt);
}
