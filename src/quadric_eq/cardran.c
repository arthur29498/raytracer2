/*
** cardran.c for  in /home/hexa/deliverobj->pos.y/CGP/raobj->pos.ytracer2/src/quadric_eq
** 
** Made bobj->pos.y HexA
** Login   <hexa@epitech.net>
** 
** Started on  Sun Maobj->pos.y 28 16:47:55 2017 HexA
** Last update Sun May 28 17:04:56 2017 HexA
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer.h"
#include "intersect.h"
#include "quadric.h"

int		delta_neg(t_object *obj, float p, float q, float z)
{
  float	x1;
  float	x2;
  float	x3;

  x1 = 2. * sqrtf(-p / 3) * cos(1. / 3. * acos((-q / 2.) * sqrtf( 27. / P3(-p))))
    - z;
  x2 = 2. * sqrtf(-p / 3) * cos(1. / 3. * acos((-q / 2.) * sqrtf( 27. / P3(-p)))
			       + ((2 * M_PI) / 3.)) - z;
  x3 = 2. * sqrtf(-p / 3) * cos(1. / 3. * acos((-q / 2.) * sqrtf( 27. / P3(-p)))
			       + ((4 * M_PI) / 3.)) - z;
  if (x1 > 0 && ((x1 >= x3  || x3 != x3)) &&
      ((x1 >= x2 || x2 != x2)))
    obj->pos.x = x1;
  else if (x2 > 0 && ((x2 >= x1 || x1 != x1)) &&
	   ((x2 >= x3 || x3 != x3)))
    obj->pos.x = x2;
  else if (x3 > 0 && ((x3 >= x1 || x1 != x1)) &&
	   ((x3 >= x2 || x2 != x2)))
    obj->pos.x = x3;
  else
    obj->pos.x = x1;
  return (1);
}

static int	get_smallest_x(t_object *obj, float p, float q, float z)
{
  float	k1;
  float	k2;
  float	delta;

  delta = P2(q) + ((4. / 27.) * P3(p));
  if (delta > 0)
    {
      obj->pos.x = cbrtf((-q + sqrtf(delta)) / 2.)
	+ cbrt((-q - sqrtf(delta)) / 2.) - z;
    }
  else if (delta == 0)
    {
      k1 = (3 * q) / p - z;
      k2 = (-3 * q) / (2 * p) - z;
      if ((k1 < k2 || k2 < 0) && k1 > 0)
	obj->pos.x = k1;
      else if (k2 > 0 && (k2 <= k1 || k1 < 0))
	obj->pos.x = k2;
      else
	obj->pos.x = k1;
    }
  else if (delta < 0)
    return (delta_neg(obj, p, q, z));
  return (1);
}

int		cardran(t_object *obj, float b, float c, float d)
{
  float	p;
  float	q;
  float	a;
  float	z;

  a = 8;
  z = b / (3 * a);
  p = - P2(b) / (3. * P2(a)) + (c / a);
  q = b / (27. * a) * (((2. * P2(b)) / P2(a)) - ((9. * c) / a)) + (d / a);
  return (get_smallest_x(obj, p, q, z));
}
