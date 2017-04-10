/*
** cone.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Mar  3 15:52:08 2017 Arthur Philippe
** Last update Sun Mar 19 21:50:01 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "intersect.h"

static inline sfVector3f	define_quad_eq_vars(sfVector3f eye_pos,
						    sfVector3f dir_vector,
						    float radius)
{
  sfVector3f		abc;

  abc.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  abc.x -= powf(tanf(radius), 2) * powf(dir_vector.z, 2);
  abc.y = (2 * dir_vector.x * eye_pos.x) + (2 * dir_vector.y * eye_pos.y);
  abc.y -= powf(tanf(radius), 2) * (2 * dir_vector.z * eye_pos.z);
  abc.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2);
  abc.z -= powf(eye_pos.z, 2) * powf(tanf(radius), 2);
  return (abc);
}

float		intersect_cone(sfVector3f eye_pos,
			       sfVector3f dir_vector,
			       float radius)
{
  sfVector3f	abc;
  float		discriminant;
  float		sol;

  radius = radius * (M_PI / 180);
  abc = define_quad_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  sol = solve_quadric_eq(discriminant, abc.x, abc.y);
  return (sol);
}

sfVector3f	get_normal_cone(sfVector3f intersection_point,
				float semiangle)
{
  semiangle = semiangle * (M_PI / 180);
  intersection_point.z *= -semiangle;
  return (intersection_point);
}
