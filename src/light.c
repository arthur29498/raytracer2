/*
** light.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Mar  7 12:15:12 2017 Arthur Philippe
** Last update Thu May  4 10:50:58 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer.h"

float		get_norm(sfVector3f in)
{
  float		norm;

  norm = sqrtf((in.x * in.x) + (in.y * in.y) + (in.z * in.z));
  return (norm);
}

float	get_light_coef(sfVector3f light_vector,
		       sfVector3f normal_vector)
{
  return (dot_product(light_vector, normal_vector));
}
