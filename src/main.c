/*
** main.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 15 19:36:12 2017 Arthur Philippe
** Last update Mon May  1 22:30:48 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"
#include "launch.h"
#include "opt.h"

int		start_w_opt(int ac, char **av)
{
  int		status;
  t_rtc_opt	*opt;

  status = 0;
  opt = get_rtc_opt(ac, av);
  if (opt && !opt->imprt)
    status = raytracer_launcher(opt->file_name, opt->exprt);
  else if (opt)
    status = import_launcher(opt->file_name);
  else
    status = EXIT_FAIL;
  return (status);
}

int	start_wo_opt(char *file_name)
{
  int	status;

  status = 0;
  if (match(file_name, CONF_MATCH))
    status = raytracer_launcher(file_name, FALSE);
  else if (match(file_name, EXPORT_MATCH))
    status = import_launcher(file_name);
  else
    status = EXIT_FAIL;
  return (status);
}

int		main(int ac, char **av)
{
  int		status;

  status = 0;
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
