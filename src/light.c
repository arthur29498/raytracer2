/*
** light.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Mar  7 12:15:12 2017 Arthur Philippe
** Last update Tue May  9 09:11:29 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer.h"

float	get_light_coef(sfVector3f light_vector,
		       sfVector3f normal_vector)
{
  float	light_coef;

  light_coef = dot_product(light_vector, normal_vector);
  if (light_coef < 0)
    return (0);
  return (light_coef);
}
