/*
** set_brightness.c for raytracer2 in /home/mael/GitHub/raytracer2/src/render/
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu>
**
** Started on  Tue May  2 15:24:50 2017 mael drapier
** Last update Wed May  3 16:25:12 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

void	set_brightness(sfColor *color, t_object *objects, float coef)
{
  while (objects)
    {
      if (objects->type == ID_LIGHT && objects->col.a)
	{
	  color->r += 0.5 * objects->col.r * coef;
	  color->g += 0.1 * objects->col.g * coef;
	  color->b += 0.5 * objects->col.b * coef;
	}
      objects = objects->next;
    }
}
