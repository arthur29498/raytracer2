/*
** maintain_engine.c for raytracer in /home/arthur/Projects/raytracer2/src/launchers/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon May  1 11:36:12 2017 Arthur Philippe
** Last update Mon May  1 11:42:30 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_data.h"
#include "raytracer_messages.h"
#include "launch.h"


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

int		window_loop(t_my_window *w, t_env *env, char *file_name)
{
  sfEvent	event;

  while (sfRenderWindow_waitEvent(w->window, &event))
    {
      if (event.type == sfEvtClosed
	  || (event.type == sfEvtKeyPressed
	      && event.key.code == sfKeyEscape))
	{
	  sfRenderWindow_close(w->window);
	  return (INTERUPT);
	}
      if (env
	  && event.type == sfEvtKeyPressed
	  && event.key.code == sfKeySpace)
	return (refresh_window(w, env, file_name));
    }
  return (CONTINUE);
}
