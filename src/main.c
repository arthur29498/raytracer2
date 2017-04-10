/*
** main.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 15 19:36:12 2017 Arthur Philippe
** Last update Mon Apr 10 09:33:41 2017 Arthur Philippe
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

  env.list = get_objects_from_file(file_name);
  if (!env.list)
    return (84);
  find_eye(env.list, &env);
  find_light(env.list, &env);
  open_window(&w, env.list, &env, file_name);
  while (window_loop(&w, &env, file_name));
  destroy_objects(env.list);
  window_destroy(&w);
  return (0);
}

int	resfresh_window(t_my_window *w, t_env *env, char *file_name)
{
  destroy_objects(env->list);
  acp_print(MSG_RELOAD);
  env->list = get_objects_from_file(file_name);
  if (!env->list)
    return (0);
  find_light(env->list, env);
  find_eye(env->list, env);
  raytrace_scene(w->buffer, env->list, env);
  sfTexture_updateFromPixels(w->tex, w->buffer->pixels, SC_W, SC_H, 0, 0);
  sfRenderWindow_clear(w->window, sfBlack);
  sfRenderWindow_drawSprite(w->window, w->sprite, NULL);
  sfRenderWindow_display(w->window);
  return (1);
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
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
	return (resfresh_window(w, env, file_name));
    }
  return (1);
}
