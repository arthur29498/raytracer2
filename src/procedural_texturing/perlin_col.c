/*
** perlin_col.c for raytracer in /home/spiki/delivery/B2/GP/RT2_Github/raytracer_github/src/procedural_texturing/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed May 24 16:04:19 2017 etienne.filliat
** Last update Wed May 24 17:07:24 2017 etienne.filliat
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer.h"

void		perlin_noised_color(sfVector3f pos, sfColor *color)
{
  float		p_noise;
  //sfColor	new_color;

  p_noise = perlin2d(pos.x, pos.y, 0.3, 3);
  color->r = color->r * p_noise;
  color->g = color->g * p_noise;
  color->b = color->b * p_noise;
  color->a = color->a * p_noise;
  /*if (p_noise <= -0.5)
    color->r = color->r * 0.5;
  else if (p_noise <= 0)
    color->g = color->g * 0.5;
  else if (p_noise <= 0.5)
    color->b = color->b * 0.5;
  else
    color->a = color->a * 0.5;*/
}
