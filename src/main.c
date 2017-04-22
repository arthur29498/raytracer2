/*
** main.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 15 19:36:12 2017 Arthur Philippe
** Last update Sat Apr 22 15:25:13 2017 Arthur Philippe
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

int		main(int ac, char **av)
{
  int		status;
  t_rtc_opt	*opt;

  status = 0;
  if (ac < 3)
    {
      acp_putstr(STDERR_FILENO, MSG_TOO_FEW_ARG);
      status = EXIT_FAIL;
    }
  else
    {
      opt = get_rtc_opt(ac, av);
      status = raytracer_launcher(opt->file_name);
    }
  if (status)
    acp_print(MSG_INTERUPTED, BOLD, RED, RST);
  else
    acp_print(MSG_QUIT);
  return (status);
}
