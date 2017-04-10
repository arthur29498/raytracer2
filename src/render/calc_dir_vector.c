/*
** calc_dir_vector.c for bsraytracer in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Feb  7 09:45:36 2017 Arthur Philippe
** Last update Thu Feb 23 15:09:59 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size,
				sfVector2i sreeen_pos)
{
  sfVector3f	projection;

  projection.x = dist_to_plane;
  projection.y = (float) (screen_size.x / 2) - sreeen_pos.x;
  projection.z = (float) (screen_size.y / 2) - sreeen_pos.y;
  return (projection);
}
