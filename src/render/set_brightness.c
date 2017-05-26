/*
** set_brightness.c for raytracer2 in /home/mael/GitHub/raytracer2/src/render/
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu>
**
** Started on  Tue May  2 15:24:50 2017 mael drapier
** Last update Tue May 23 13:07:31 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

void	calc_brightness(sfColor *color, sfColor light_color,
			float brightness, float coef)
{
  if (color->r + (int) (brightness * light_color.r * coef) <= 255)
    color->r += (int) (brightness * light_color.r * coef);
  else
    color->r = 255;
  if (color->g + (int) (brightness * light_color.g * coef) <= 255)
    color->g += (int) (brightness * light_color.g * coef);
  else
    color->g = 255;
  if (color->b + (int) (brightness * light_color.b * coef) <= 255)
    color->b += (int) (brightness * light_color.b * coef);
  else
    color->b = 255;
}

void		set_brightness(sfColor *color, t_object *objects,
			       int object_nb, float coef)
{
  t_object	*objs_save;
  float		brightness;

  brightness = 0;
  objs_save = objects;
  while (objects)
    {
      if (objects->id == object_nb)
	brightness = objects->brightness;
      objects = objects->next;
    }
  while (objs_save)
    {
      if (objs_save->type == ID_LIGHT && objs_save->col.a)
	calc_brightness(color, objs_save->col, brightness, coef);
      objs_save = objs_save->next;
    }
}
