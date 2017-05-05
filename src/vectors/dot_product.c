/*
** dot_product.c for raytracer in /home/arthur/Projects/raytracer2/src/vectors/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu May  4 10:56:49 2017 Arthur Philippe
** Last update Thu May  4 11:18:30 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

float		get_norm(const sfVector3f in)
{
  float		norm;

  norm = sqrtf((in.x * in.x) + (in.y * in.y) + (in.z * in.z));
  return (norm);
}

float	dot_product(sfVector3f v1, sfVector3f v2)
{
  float	dot;

  if (!(get_norm(v1) * get_norm(v2)))
    return (0);
  v1 = normalize_vector(v1);
  v2 = normalize_vector(v2);
  dot = v1.x * v2.x;
  dot += v1.y * v2.y;
  dot += v2.z * v1.z;
  if (dot < 0)
    return (0);
  if (dot > 1)
    return (1);
  return (dot);
}