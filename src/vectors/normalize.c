/*
** normalize.c for raytracer in /home/arthur/Projects/raytracer2/src/vectors/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon May  1 11:04:54 2017 Arthur Philippe
** Last update Mon May  1 11:07:54 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

sfVector3f	normalize_vector(sfVector3f in)
{
  sfVector3f	out;
  float		norm;

  norm = get_norm(in);
  out.x = in.x / norm;
  out.y = in.y / norm;
  out.z = in.z / norm;
  return (out);
}
