/*
** set_brightness.c for raytracer2 in /home/mael/GitHub/raytracer2/src/render/
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu>
**
** Started on  Tue May  2 15:24:50 2017 mael drapier
** Last update Wed May  3 17:29:30 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

void	calc_brightness(sfColor *color, sfColor obj_color,
			float brightness, float coef)
{
  if (color->r + (int) (brightness * obj_color.r * coef) <= 255)
    color->r += (int) (brightness * obj_color.r * coef);
  else
    color->r = 255;
  if (color->g + (int) (brightness * obj_color.g * coef) <= 255)
    color->g += (int) (brightness * obj_color.g * coef);
  else
    color->g = 255;
  if (color->b + (int) (brightness * obj_color.b * coef) <= 255)
    color->b += (int) (brightness * obj_color.b * coef);
  else
    color->b = 255;
}

void	set_brightness(sfColor *color, t_object *objects, float coef)
{
  while (objects)
    {
      if (objects->type == ID_LIGHT && objects->col.a)
	calc_brightness(color, objects->col, 0.5, coef);
      objects = objects->next;
    }
}
