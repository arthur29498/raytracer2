/*
** reflect.c for raytracer in /home/arthur/Projects/raytracer2/src/vectors/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu May  4 10:33:17 2017 Arthur Philippe
** Last update Thu May  4 11:18:58 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

sfVector3f	reflect_vector(const sfVector3f dir_v,
			       const sfVector3f normal_v)
{
  sfVector3f	reflected_v;
  float		dot;

  dot = dot_product(dir_v, normal_v);
  reflected_v.x = (normal_v.x * -2 * dot) + dir_v.x;
  reflected_v.y = (normal_v.y * -2 * dot) + dir_v.y;
  reflected_v.z = (normal_v.z * -2 * dot) + dir_v.z;
  return (reflected_v);
}
