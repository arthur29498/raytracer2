/*
** open_window.c for raytracer1 in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Feb  7 10:35:59 2017 Arthur Philippe
** Last update Wed Mar 15 20:10:51 2017 Arthur Philippe
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"
#include "raytracer_messages.h"
#include "acp.h"

int		open_window(t_my_window *w,
			    t_object *list,
			    t_env *env,
			    char *file_name)
{
  char		window_name[256];

  my_strcpy(window_name, file_name);
  my_strcat(window_name, PROGRAM_NAME);
  if (!w && !env)
    return (1);
  w->buffer = my_framebuffer_create(SC_W, SC_H);
  env->screen_size = (sfVector2i) {w->buffer->width, w->buffer->height};
  raytrace_scene(w->buffer, list, env);
  acp_print(MSG_WIN_OPEN);
  w->window = create_window(window_name, SC_W, SC_H);
  w->sprite = sfSprite_create();
  w->tex = sfTexture_create(SC_W, SC_H);
  if (!w->buffer || !w->window)
    return (1);
  sfTexture_updateFromPixels(w->tex, w->buffer->pixels, SC_W, SC_H, 0, 0);
  sfSprite_setTexture(w->sprite, w->tex, sfTrue);
  sfRenderWindow_clear(w->window, sfBlack);
  sfRenderWindow_drawSprite(w->window, w->sprite, NULL);
  sfRenderWindow_display(w->window);
  acp_print(MSG_SUCCES);
  return (0);
}

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  return (window);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*buffer;

  buffer = malloc(sizeof(t_my_framebuffer));
  if (!buffer)
    return ((t_my_framebuffer *) 0);
  (*buffer).pixels = malloc(width * height * 5 * sizeof(sfUint8));
  (*buffer).width = width;
  (*buffer).height = height;
  if (!((*buffer).pixels))
    return ((t_my_framebuffer *) 0);
  i = 0;
  while (i < width * height * 4)
    (*buffer).pixels[i++] = 0;
  return (buffer);
}

void	reset_pixels(t_my_framebuffer *buffer)
{
  int	i;

  i = 0;
  while (i < (*buffer).width * (*buffer).height * 4)
    (*buffer).pixels[i++] = 0;
}
