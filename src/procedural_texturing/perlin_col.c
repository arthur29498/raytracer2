/*
** perlin_col.c for raytracer in /home/spiki/delivery/B2/GP/RT2_Github/raytracer_github/src/procedural_texturing/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed May 24 16:04:19 2017 etienne.filliat
** Last update Sat May 27 12:01:08 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"

void		perlin_noised_color(sfVector3f pos, sfColor *color,
				    float x, float y)
{
  float		p_noise;
  int		cast;

  if (pos.x < 0.0)
    pos.x = pos.x * -1.0;
  if (pos.y < 0.0)
    pos.y = pos.y * -1.0;
  p_noise = perlin2d(pos.x, pos.y, x, y);
  if (p_noise >= 1.0)
    {
      cast = p_noise;
      p_noise = p_noise - cast;
    }
    color->r = color->r * p_noise;
    color->g = color->g * p_noise;
    color->b = color->b * p_noise;
}
