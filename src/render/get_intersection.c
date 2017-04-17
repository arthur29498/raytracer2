/*
** get_intersection.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon Apr 17 18:34:40 2017 Arthur Philippe
** Last update Mon Apr 17 18:34:56 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

sfVector3f	get_intersection(sfVector3f eye_pos,
				 sfVector3f dir_vector,
				 float k)
{
  sfVector3f	out;

  out.x = dir_vector.x * k + eye_pos.x;
  out.y = dir_vector.y * k + eye_pos.y;
  out.z = dir_vector.z * k + eye_pos.z;
  return (out);
}
