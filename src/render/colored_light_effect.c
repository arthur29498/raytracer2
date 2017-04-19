/*
** colored_light_effect.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Apr 19 08:57:36 2017 Arthur Philippe
** Last update Wed Apr 19 10:10:11 2017 Arthur Philippe
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

void	apply_colored_light_effect(sfColor *color, t_object *objects)
{
  while (objects)
    {
      if (objects->type == ID_LIGHT && objects->col.a)
	{
	  color->r = (objects->col.r < color->r) ? objects->col.r : color->r;
	  color->g = (objects->col.g < color->g) ? objects->col.g : color->g;
	  color->b = (objects->col.b < color->b) ? objects->col.b : color->b;
	}
      objects = objects->next;
    }
}
