/*
** ferari.c for  in /home/hexa/delivery/CGP/raytracer2/src/quadric_eq
** 
** Made by HexA
** Login   <hexa@epitech.net>
** 
** Started on  Sat May 27 17:56:46 2017 HexA
** Last update Sun May 28 16:58:30 2017 HexA
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer.h"
#include "intersect.h"
#include "quadric.h"

static float		get_smallest_x(float x1, float x2, float x3, float x4)
{
  if (x1 > 0 && ((x1 <= x3 || x3 <= 0) || x3 != x3) &&
      ((x1 <= x2 || x2 <= 0) || x2 != x2) &&
      ((x1 <= x4 || x4 <= 0) || x4 != x4))
    return (x1);
  if (x2 > 0 && ((x2 <= x1 || x1 <= 0) || x1 != x1) &&
      ((x2 <= x3 || x3 <= 0) || x3 != x3) &&
      ((x2 <= x4 || x4 <= 0) || x4 != x4))
    return (x2);
  if (x3 > 0 && ((x3 <= x1 || x1 <= 0) || x1 != x1) &&
      ((x3 <= x2 || x2 <= 0) || x2 != x2) &&
      ((x3 <= x4 || x4 <= 0) || x4 != x4))
    return (x3);
  if (x4 > 0 && ((x4 <= x1 || x1 <= 0) || x1 != x1) &&
      ((x4 <= x2 || x2 <= 0) || x2 != x2) &&
      ((x4 <= x3 || x3 <= 0) || x3 != x3))
    return (x4);
  return (-1);
}

static float		delta(t_object *obj, float p, float q, float r)
{
  float			a;
  float			b;
  float			x1;
  float			x2;
  float			x3;
  float			x4;
  float			delta[2];

  x1 = x2 = x3 = x4 = 0;
  a = sqrtf((2 * obj->pos.x) - p);
  if (((2 * obj->pos.x -p) != 0) && a == a)
    b = -q / (2. * a);
  else
    b = sqrtf(P2(obj->pos.x) - r);
  if ((delta[0] = P2(a) - (4 * (obj->pos.x + b))) > 0)
  {
    x1 = (-a + sqrtf(delta[0])) / 2. + obj->pos.z;
    x2 = (-a - sqrtf(delta[0])) / 2. + obj->pos.z;
  }
  if ((delta[0] = P2(a) - (4 * (obj->pos.x - b))) > 0)
  {
    x3 = (-a + sqrtf(delta[0])) / 2. + obj->pos.z;
    x4 = (-a - sqrtf(delta[0])) / 2. + obj->pos.z;
  }
  return (get_smallest_x(x1, x2, x3, x4));
}

float		ferari(t_object *obj, t_tore_poly poly)
{
  float		p;
  float		q;
  float		r;
  float		k;

  obj->pos.z = -poly.b / (4. * poly.a);
  p = (-3. * P2(poly.b)) / (8. * P2(poly.a)) + (poly.c / poly.a);
  q = P3(poly.b * 0.5) / P3(poly.a) - ((0.5 * poly.b * poly.c) / P2(poly.a)) + (poly.d / poly.a);
  r = - 3. * P4((poly.b * 0.25) / poly.a) + (poly.c * (P2((poly.b * 0.25)) / P3(poly.a)))
    - ((0.25 * poly.b * poly.d) / P2(poly.a)) + (poly.e / poly.a);
  cardran(obj, - 4 * p, - 8 * r, (4 * r * p) - P2(q));
  k = delta(obj, p, q, r);
  if (k >= 0)
    return (k);
  else
    return (0);
}
