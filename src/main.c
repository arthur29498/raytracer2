/*
** main.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 15 19:36:12 2017 Arthur Philippe
** Last update Sun May 28 21:52:05 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "stdlib.h"
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"
#include "launch.h"
#include "opt.h"

int		start_w_opt(int ac, char **av)
{
  int		st;
  t_rtc_opt	*opt;

  opt = get_rtc_opt(ac, av);
  if (opt && !opt->imprt && !opt->render)
    acp_print("%s\n\n", MSG_IMPL_OPT);
  if (opt && !opt->file_name[0])
    {
      acp_print("%s\n", MSG_NO_FILE);
      st = EXIT_FAIL;
    }
  else if (opt && !opt->imprt)
    st = raytracer_launcher(opt->file_name, opt->exprt, opt->a_aliasing);
  else if (opt)
    st = import_launcher(opt->file_name);
  else
    st = EXIT_FAIL;
  free(opt);
  return (st);
}

int	start_wo_opt(char *file_name)
{
  int	status;

  if (match(file_name, CONF_MATCH))
    status = raytracer_launcher(file_name, FALSE, TRUE);
  else if (match(file_name, EXPORT_MATCH))
    status = import_launcher(file_name);
  else
    status = EXIT_FAIL;
  return (status);
}

int	main(int ac, char **av)
{
  int	status;

  status = 0;
  if (ac >= 2 && match(av[1], "-h"))
    return (helper());
  if (ac < 2)
    {
      acp_putstr(STDERR_FILENO, MSG_TOO_FEW_ARG);
      status = EXIT_FAIL;
    }
  else if (ac > 2)
    status = start_w_opt(ac, av);
  else if (ac == 2)
    status = start_wo_opt(av[1]);
  if (status)
    acp_print(MSG_INTERUPTED, BOLD, RED, RST);
  else
    acp_print(MSG_QUIT);
  return (status);
}
