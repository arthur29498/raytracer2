/*
** obj_fctn_shunter.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 12:56:37 2017 Arthur Philippe
** Last update Thu May 25 19:28:08 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

inline static float	obj_fctn_sphere(t_object *object,
					t_render_in *in_arg)
{
  sfVector3f		new_eye;
  float			k;

  new_eye.x = in_arg->eye_pt.x - object->pos.x;
  new_eye.y = in_arg->eye_pt.y - object->pos.y;
  new_eye.z = in_arg->eye_pt.z - object->pos.z;
  if (object->limit_a == 0 && object->limit_b == 0)
    k = intersect_sphere(new_eye, in_arg->dir_vector, object->size_a);
  else
    k = intersect_ltd_sphere(new_eye, in_arg->dir_vector,
			     object->size_a, object);
  return (k);
}

inline static float	obj_fctn_plane(t_object *object,
				       t_render_in *in_arg)
{
  sfVector3f		new_eye;
  sfVector3f		new_dir_v;
  float			k;

  new_eye.x = in_arg->eye_pt.x;
  new_eye.y = in_arg->eye_pt.y;
  new_eye.z = in_arg->eye_pt.z - object->pos.z;
  new_eye = rotate_xyz_inv(new_eye, object->rot);
  new_dir_v = rotate_xyz_inv(in_arg->dir_vector, object->rot);
  k = intersect_plane(new_eye, new_dir_v);
  return (k);
}

inline static float	obj_fctn_cylinder(t_object *object,
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
    k = intersect_cylinder(new_eye, new_dir_v, object->size_a);
  else
    k = intersect_ltd_cylinder(new_eye, new_dir_v, object->size_a, object);
  return (k);
}

inline static float	obj_fctn_cone(t_object *object,
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
    k = intersect_cone(new_eye, new_dir_v, object->size_a);
  else
    k = intersect_ltd_cone(new_eye, new_dir_v, object->size_a, object);
  return (k);

}

float			obj_fctn_shunter(t_object *object, t_render_in *in_arg)
{
  static float		(*obj_intersect[5])(t_object *, t_render_in *);

  obj_intersect[1] = obj_fctn_sphere;
  obj_intersect[2] = obj_fctn_plane;
  obj_intersect[3] = obj_fctn_cylinder;
  obj_intersect[4] = obj_fctn_cone;
  if (object->type > 0 && object->type <= 4)
    return (obj_intersect[object->type](object, in_arg));
  else
    return (-1);
}
	
