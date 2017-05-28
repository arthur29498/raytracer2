/*
** tore.c for  in /home/hexa/delivery/CGP/raytracer2/src/objects
** 
** Made by HexA
** Login   <hexa@epitech.net>
** 
** Started on  Tue May 09 12:44:05 2017 HexA
** Last update Sun May 28 17:02:55 2017 HexA
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer.h"
#include "intersect.h"
#include "quadric.h"

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

float				intersect_tore(t_object *obj,
					       sfVector3f eye_pos,
					       sfVector3f dir_vector,
					       float mradius)
{
  t_tore_poly			poly;
  float				sol;

  poly = define_tetra_eq_vars(eye_pos, dir_vector, obj->size_a, mradius);
  sol = ferari(obj, poly);
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
    k = intersect_tore(object, new_eye, new_dir_v, 10);
  return (k);
}
