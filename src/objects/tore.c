/*
** tore.c for  in /home/hexa/delivery/CGP/raytracer2/src/objects
** 
** Made by HexA
** Login   <hexa@epitech.net>
** 
** Started on  Tue May 09 12:44:05 2017 HexA
** Last update Sat May 27 16:11:23 2017 HexA
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer.h"
#include "intersect.h"

#define P2(x) (x * x)
#define P3(x) (x * x * x)
#define P4(x) (x * x * x * x)
#define absf(x) ((x < 0) ? -x : x)

static inline t_tore_poly	define_tetra_eq_vars(sfVector3f p,
						    sfVector3f d,
						    float radius,
						    float mradius)
{
  t_tore_poly			poly;

  poly.a = powf(P2(d.x) + P2(d.y) + P2(d.z), 2);
  poly.b = P2(d.x) + P2(d.y) + P2(d.z);
  poly.b = poly.b * (d.x * p.x + d.y * p.y + d.z * p.z);
  poly.b = poly.b * 4;
  poly.c = P2(d.x) + P2(d.y) + P2(d.z);
  poly.c = poly.c * (P2(p.x) + P2(p.y) + P2(p.z) + P2(radius) - P2(mradius));
  poly.c = poly.c * 2;
  poly.c = poly.c + P2(d.x * p.x + d.y * p.y + d.z * p.z);
  poly.c = poly.c - 4 * P2(radius) * (P2(d.x) + P2(d.z));
  poly.d = 4 * (d.x * p.x + d.y * p.y + d.z * p.z);
  poly.d = poly.d * (P2(p.x) + P2(p.y) + P2(p.z) + P2(radius) - P2(mradius));
  poly.d = poly.d - 8 * P2(radius) * (d.x * p.x + d.z * p.z);
  poly.e = P2(P2(p.x) + P2(p.y) + P2(p.z) + P2(radius) - P2(mradius));
  poly.e = poly.e - 4 * P2(radius) * (P2(p.x) + P2(p.z));
  return (poly);
}

static inline float		do_tore(t_tore_poly poly, float x, int d)
{
  float				r;

  if (d != 1)
  {
    r = ((poly.e * (P4(x))) + (poly.d * (P3(x))) + (poly.c * (P2(x))));
    r = r + (poly.b * x) + poly.a;
  }
  else
  {
    r = ((4 * poly.e * P3(x)) + (3 * poly.d * P2(x)) + (2 * poly.c * x));
    r = r + poly.b;
  }
  return (r);
}

static inline float		newton(t_tore_poly poly, float xnewton, float N)
{
  float				c;

  if (N > 100)
    return (-1);
  c = xnewton - (do_tore(poly, xnewton, 0) / do_tore(poly, xnewton, 1));
  if (absf((c - xnewton)) / absf(c) > powf(10, -5))
    newton(poly, c, N + 1);
  return (xnewton);
}

float				intersect_tore(sfVector3f eye_pos,
					       sfVector3f dir_vector,
					       float radius,
					       float mradius)
{
  t_tore_poly			poly;
  float				sol;

  poly = define_tetra_eq_vars(eye_pos, dir_vector, radius, mradius);
  sol = newton(poly, 0.5, 0);
  return (sol);
}

float				obj_fctn_tore(t_object *object,
					      t_render_in *in_arg)
{
  sfVector3f		new_eye;
  sfVector3f		new_dir_v;
  float			k;

  new_eye.x = in_arg->eye_pt.x - object->pos.x;
  new_eye.y = in_arg->eye_pt.y - object->pos.y;
  new_eye.z = in_arg->eye_pt.z - object->pos.z;
  new_eye = rotate_xyz_inv(new_eye, object->rot);
  new_dir_v = rotate_xyz_inv(in_arg->dir_vector, object->rot);
  if (object->limit_a == 0 && object->limit_b == 0)
    k = intersect_tore(new_eye, new_dir_v, object->size_a, 10);
  return (k);
}
