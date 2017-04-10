/*
** intersect_plane.c for raytracer1 in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb  9 13:20:41 2017 Arthur Philippe
** Last update Thu Mar  9 16:18:15 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (!dir_vector.z)
    return (-1);
  k = -(eye_pos.z / dir_vector.z);
  if (k > 0)
    return (k);
  else
    return (-1);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	normal;

  normal.x = 0;
  normal.y = 0;
  normal.z = (upward) ? 1 : -1;
  return (normal);
}
