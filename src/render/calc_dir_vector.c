/*
** calc_dir_vector.c for bsraytracer in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Feb  7 09:45:36 2017 Arthur Philippe
** Last update Tue May 23 16:44:16 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

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

  screen_size.x *= 2;
  screen_size.y *= 2;
  screen_pos.x *= 2;
  screen_pos.y *= 2;
  if (sub_ray == 1)
    screen_pos.x -= 1;
  if (sub_ray == 2)
    screen_pos.x -= 2;
  if (sub_ray == 3)
    screen_pos.x += 1;
  if (sub_ray == 4)
    screen_pos.y += 1;
  projection.x = dist_to_plane;
  projection.y = (float) (screen_size.x / 2) - screen_size.x;
  projection.z = (float) (screen_size.y / 2) - screen_size.y;
  return (projection);
}
