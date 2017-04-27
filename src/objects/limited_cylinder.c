/*
** limited_cylinder.c for raytracer2 in /home/mael/GitHub/raytracer2
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu>
**
** Started on  Thu Apr 27 15:39:44 2017 mael drapier
** Last update Thu Apr 27 17:13:13 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "intersect.h"
#include "raytracer.h"

float	check_limit(float k1, float k2,
		    sfVector3f eye_pos,
		    sfVector3f dir_vector)
{
  sfVector3f	intersect_pt1;
  sfVector3f	intersect_pt2;

  intersect_pt1 = get_intersection(eye_pos, dir_vector, k1);
  intersect_pt2 = get_intersection(eye_pos, dir_vector, k2);
  if (k1 > 0 && k1 < k2)
    {
      if (intersect_pt1.z > CUT_UP && intersect_pt2.z > CUT_UP)
	return (-1);
      if (intersect_pt1.z > CUT_UP && intersect_pt2.z <= CUT_UP && k2 > 0)
	return (k2);
      if (intersect_pt1.z < CUT_DOWN && intersect_pt2.z < CUT_DOWN)
	return (-1);
      if (intersect_pt1.z < CUT_DOWN && intersect_pt2.z >= CUT_DOWN && k2 > 0)
	return (k2);
      return (k1);
    }
  if (k2 > 0)
    {
      if (intersect_pt1.z > CUT_UP && intersect_pt2.z > CUT_UP)
	return (-1);
      if (intersect_pt2.z > CUT_UP && intersect_pt1.z <= CUT_UP && k1 > 0)
	return (k1);
      if (intersect_pt1.z < CUT_DOWN && intersect_pt2.z < CUT_DOWN)
	return (-1);
      if (intersect_pt2.z < CUT_DOWN && intersect_pt1.z >= CUT_DOWN && k1 > 0)
	return (k1);
      return (k2);
    }
  return (-1);
}

float		solve_ltd_quadric_eq(float discriminant, sfVector3f abc,
				     sfVector3f eye_pos,
				     sfVector3f dir_vector)
{
  float		sol;
  float		tmp;

  tmp = 0;
  if (discriminant == 0)
    {
      sol = -abc.y;
      sol /= 2 * abc.x;
      if (sol > 0)
	return (sol);
    }
  else if (discriminant > 0)
    {
      sol = -abc.y + sqrtf(discriminant);
      sol /= 2 * abc.x;
      tmp = -abc.y - sqrtf(discriminant);
      tmp /= 2 * abc.x;
      return (check_limit(tmp, sol, eye_pos, dir_vector));
    }
  return (-1);
}

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

float		intersect_ltd_cylinder(sfVector3f eye_pos,
				   sfVector3f dir_vector,
				   float radius)
{
  sfVector3f	abc;
  float		discriminant;
  float		sol;

  abc = define_quad_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  sol = solve_ltd_quadric_eq(discriminant, abc, eye_pos, dir_vector);
  return (sol);
}
