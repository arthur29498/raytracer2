/*
** calc_dir_vector.c for bsraytracer in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Feb  7 09:45:36 2017 Arthur Philippe
** Last update Wed May 24 17:49:20 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	projection;

  projection.x = dist_to_plane;
  projection.y = (float) (screen_size.x / 2) - screen_pos.x;
  projection.z = (float) (screen_size.y / 2) - screen_pos.y;
  return (projection);
}

sfVector3f	calc_sub_dir_vector(float dist_to_plane,
				    sfVector2i screen_size,
				    sfVector2i screen_pos,
				    int sub_ray)
{
  sfVector3f	projection;
  float		tmp_x;
  float		tmp_y;

  tmp_x = (float) screen_pos.x;
  tmp_y = (float) screen_pos.y;
  if (sub_ray == 1)
    tmp_x -= SUB_RAY_STEP;
  if (sub_ray == 2)
    tmp_y -= SUB_RAY_STEP;
  if (sub_ray == 3)
    tmp_x += SUB_RAY_STEP;
  if (sub_ray == 4)
    tmp_y += SUB_RAY_STEP;
  projection.x = dist_to_plane;
  projection.y = (float) (screen_size.x / 2) - tmp_x;
  projection.z = (float) (screen_size.y / 2) - tmp_y;
  return (projection);
}
