/*
** wf_nuke.c for raytracer1 in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Feb  7 10:43:31 2017 Arthur Philippe
** Last update Mon Feb 20 18:12:51 2017 Arthur Philippe
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

void	window_destroy(t_my_window *w)
{
  if (!w)
    return ;
  free(w->buffer->pixels);
  free(w->buffer);
  sfTexture_destroy(w->tex);
  sfSprite_destroy(w->sprite);
  sfRenderWindow_destroy(w->window);
}

void	destroy_objects(t_object *list)
{
  if (list->next)
    destroy_objects(list->next);
  free(list);
}
