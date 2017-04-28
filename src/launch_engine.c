/*
** launch.c for raytracer in /home/arthur/Projects/raytracer2/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Apr 19 15:52:50 2017 Arthur Philippe
** Last update Fri Apr 28 13:38:48 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"
#include "launch.h"

void	*raytrace_bridge(void *env);

int		raytracer_thread_launch(t_env *env)
{
  int		thread_id;
  pthread_t	thrds[5];

  thread_id = 0;
  display_progress(&thread_id, 0);
  while (thread_id < 4)
    {
      if (pthread_create(&thrds[thread_id], NULL,
			 raytrace_bridge, (void *) env))
	return (-1);
      thread_id += 1;
    }
  while (--thread_id >= 0)
    pthread_join(thrds[thread_id], NULL);
  thread_id = 1;
  display_progress(&thread_id, 0);
  return (0);
}

int		raytracer_launcher(char *file_name, int exprt)
{
  t_my_window	w;
  t_env		env;

  env.w = &w;
  env.objects = get_objects_from_file(file_name);
  if (!env.objects)
    return (EXIT_FAIL);
  find_eye(&env);
  find_light(&env);
  env.screen_size.x = SC_W;
  env.screen_size.y = SC_H;
  if (!(w.buffer = my_framebuffer_create(SC_W, SC_H)))
    return (EXIT_FAIL);
  raytracer_thread_launch(&env);
  open_window(&w, file_name);
  if (exprt && export_render("rt_export", env.w->buffer) == -1)
    acp_print("export error");
  while (window_loop(&w, &env, file_name));
  destroy_objects(env.objects);
  window_destroy(&w);
  return (0);
}

int	refresh_window(t_my_window *w, t_env *env, char *file_name)
{
  destroy_objects(env->objects);
  acp_print(MSG_RELOAD);
  env->objects = get_objects_from_file(file_name);
  if (!env->objects)
    return (0);
  find_eye(env);
  find_light(env);
  reset_pixels(w->buffer);
  raytracer_thread_launch(env);
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
      if (env
	  && event.type == sfEvtKeyPressed
	  && event.key.code == sfKeySpace)
	return (refresh_window(w, env, file_name));
    }
  return (1);
}
