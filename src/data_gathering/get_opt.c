/*
** get_opt.c for raytracer in /home/arthur/Projects/raytracer2/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 22 14:32:17 2017 Arthur Philippe
** Last update Thu May 25 17:24:40 2017 Arthur Philippe
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
	opt->render = TRUE;
      else if (opt_str[i] == OPT_EXP)
	opt->exprt = TRUE;
      else if (opt_str[i] == OPT_IMP)
	opt->imprt = TRUE;
      else if (opt_str[i] == OPT_AAL)
	opt->a_aliasing = TRUE;
      i += 1;
    }
}

t_rtc_opt	*get_rtc_opt(int ac, char **av)
{
  t_rtc_opt	*opt;
  int		i;

  if (!(opt = malloc(sizeof(t_rtc_opt))))
    return (NULL);
  i = 1;
  my_memset(opt, 0, sizeof(t_rtc_opt));
  while (i < ac)
    {
      if (av[i][0] == '-')
	set_rtc_opt(av[i], opt);
      else
	my_strcpy(opt->file_name, av[i]);
      i += 1;
    }
  return (opt);
}
