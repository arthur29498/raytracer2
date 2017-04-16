/*
** main.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 15 19:36:12 2017 Arthur Philippe
** Last update Sat Apr 15 17:28:51 2017 Arthur Philippe
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

int	main(int ac, char **av)
{
  int	status;

  status = 0;
  if (ac < 2)
    {
      acp_putstr(STDERR_FILENO, MSG_TOO_FEW_ARG);
      status = 84;
    }
  else
    status = raytracer_launcher(av[1]);
  if (status)
    acp_print(MSG_INTERUPTED, BOLD, RED, RST);
  else
    acp_print(MSG_QUIT);
  return (status);
}

int		raytracer_launcher(char *file_name)
{
  t_my_window	w;
  t_env		env;

  env.w = &w;
  env.objects = get_objects_from_file(file_name);
  if (!env.objects)
    return (84);
  find_eye(&env);
  find_light(&env);
  env.screen_size.x = SC_W;
  env.screen_size.y = SC_H;
  if (!(w.buffer = my_framebuffer_create(SC_W, SC_H)))
    return (84);
  raytrace_full_scene(&env);
  open_window(&w, file_name);
  window_loop(&w, &env, file_name);
  destroy_objects(env.objects);
  window_destroy(&w);
  return (0);
}

int	window_loop(t_my_window *w, t_env *env, char *file_name)
{
  sfEvent	event;

  while (sfRenderWindow_waitEvent(w->window, &event))
    {
      if (event.type == sfEvtClosed
	  || (event.type == sfEvtKeyPressed
	      && event.key.code == sfKeyEscape))
	{
	  sfRenderWindow_close(w->window);
	  return (0);
	}
    }
  return (1);
}
