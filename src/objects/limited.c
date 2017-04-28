/*
** limited.c for raytracer2 in /home/mael/GitHub/raytracer2/src/objects/
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu>
**
** Started on  Fri Apr 28 14:54:39 2017 mael drapier
** Last update Fri Apr 28 15:22:16 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer_structs.h"
#include "raytracer.h"

float	check_limit_k1(sfVector3f intersect_pt1,
		       sfVector3f intersect_pt2,
		       sfVector2f k,
		       t_object *object)
{
  int	lmt_a;
  int	lmt_b;

  lmt_a = object->limit_a;
  lmt_b = object->limit_b;
  if (intersect_pt1.z > lmt_a && intersect_pt2.z > lmt_a)
    return (-1);
  if (intersect_pt1.z > lmt_a && intersect_pt2.z <= lmt_a && k.y > 0)
    return (k.y);
  if (intersect_pt1.z < lmt_b && intersect_pt2.z < lmt_b)
    return (-1);
  if (intersect_pt1.z < lmt_b && intersect_pt2.z >= lmt_b && k.y > 0)
    return (k.y);
  return (k.x);
}

float	check_limit_k2(sfVector3f intersect_pt1,
		       sfVector3f intersect_pt2,
		       sfVector2f k,
		       t_object *object)
{
  int	lmt_a;
  int	lmt_b;

  lmt_a = object->limit_a;
  lmt_b = object->limit_b;
  if (intersect_pt1.z > lmt_a && intersect_pt2.z > lmt_a)
    return (-1);
  if (intersect_pt2.z > lmt_a && intersect_pt1.z <= lmt_a && k.x > 0)
    return (k.x);
  if (intersect_pt1.z < lmt_b && intersect_pt2.z < lmt_b)
    return (-1);
  if (intersect_pt2.z < lmt_b && intersect_pt1.z >= lmt_b && k.x > 0)
    return (k.x);
  return (k.y);
}

float		check_limit(sfVector2f k,
			    sfVector3f eye_pos,
			    sfVector3f dir_vector,
			    t_object *object)
{
  sfVector3f	intersect_pt1;
  sfVector3f	intersect_pt2;

  intersect_pt1 = get_intersection(eye_pos, dir_vector, k.x);
  intersect_pt2 = get_intersection(eye_pos, dir_vector, k.y);
  if (k.x > 0 && k.x < k.y)
    return (check_limit_k1(intersect_pt1, intersect_pt2, k, object));
  if (k.y > 0)
    return (check_limit_k1(intersect_pt1, intersect_pt2, k, object));
  return (-1);
}

float		solve_ltd_quadric_eq(sfVector3f abc,
				     sfVector3f eye_pos,
				     sfVector3f dir_vector,
				     t_object *object)
{
  sfVector2f	k;

  k.x = 0;
  if (abc.z == 0)
    {
      k.y = -abc.y;
      k.y /= 2 * abc.x;
      if (k.y > 0)
	return (k.y);
    }
  else if (abc.z > 0)
    {
      k.y = -abc.y + sqrtf(abc.z);
      k.y /= 2 * abc.x;
      k.x = -abc.y - sqrtf(abc.z);
      k.x /= 2 * abc.x;
      return (check_limit(k, eye_pos, dir_vector, object));
    }
  return (-1);
}
