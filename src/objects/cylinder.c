/*
** cylinder.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Feb 24 15:24:47 2017 Arthur Philippe
** Last update Sat May 27 15:58:27 2017 HexA
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "intersect.h"
#include "raytracer_structs.h"

static inline sfVector3f	define_quad_eq_vars(sfVector3f eye_pos,
						    sfVector3f dir_vector,
						    float radius)
{
  sfVector3f			abc;

  abc.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  abc.y = (eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y);
  abc.y *= 2;
  abc.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2);
  abc.z -= powf(radius, 2);
  return (abc);
}

float		intersect_cylinder(sfVector3f eye_pos,
				   sfVector3f dir_vector,
				   float radius)
{
  sfVector3f	abc;
  float		discriminant;
  float		sol;

  abc = define_quad_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  sol = solve_quadric_eq(discriminant, abc.x, abc.y);
  return (sol);
}

float		intersect_ltd_cylinder(sfVector3f eye_pos,
				       sfVector3f dir_vector,
				       float radius,
				       t_object *object)
{
  sfVector3f	abc;
  float		discriminant;
  float		sol;

  abc = define_quad_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  abc.z = discriminant;
  sol = solve_ltd_quadric_eq(abc, eye_pos, dir_vector, object);
  return (sol);
}

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0;
  return (intersection_point);
}
