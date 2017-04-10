/*
** color_modifier.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Mar  8 20:17:05 2017 Arthur Philippe
** Last update Sun Mar 19 22:14:42 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

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

static inline int	is_obj_lighten(t_object *list,
				       t_env *env,
				       int skip)
{
  float			k;

  k = -1;
  while (list)
    {
      if (list->id != skip)
	{
	  k = obj_fctn_shunter(list, env);
	  if (k > 0 && k < 1)
	    return (0);
	}
      list = list->next;
    }
  return (1);
}

sfVector3f	set_light_and_normal(sfVector3f *light,
				     sfVector3f *normal,
				     t_env *env,
				     t_object *obj)
{
  sfVector3f	intersect_pt;

  intersect_pt = translate_inv(env->last_intersect, obj->pos);
  *light = rotate_zyx(*light, obj->rot);
  intersect_pt = rotate_zyx(intersect_pt, obj->rot);
  if (obj->type == 1)
    *normal = get_normal_sphere(intersect_pt);
  else if (obj->type == 2)
    *normal = get_normal_plane(1);
  else if (obj->type == 3)
    *normal = get_normal_cylinder(intersect_pt);
  else if (obj->type == 4)
    *normal = get_normal_cone(intersect_pt, obj->size_a);
  *normal = rotate_zyx(*normal, obj->rot);
  return (intersect_pt);
}

float		color_modifier(t_env *env,
			       t_object *obj,
			       sfVector3f intersect_pt)
{
  sfVector3f	light_vector;
  sfVector3f	dir_v_save;
  sfVector3f	eye_save;
  sfVector3f	normal;
  int		lighten;
  float		coef;

  light_vector.x = env->light.x - intersect_pt.x;
  light_vector.y = env->light.y - intersect_pt.y;
  light_vector.z = env->light.z - intersect_pt.z;
  dir_v_save = env->curr_dir_vector;
  eye_save = env->eye;
  env->curr_dir_vector = light_vector;
  env->eye = intersect_pt;
  intersect_pt = set_light_and_normal(&light_vector, &normal, env, obj);
  lighten = is_obj_lighten(env->list, env, obj->id);
  if (lighten)
    coef = get_light_coef(light_vector, normal);
  else
    coef = 0;
  env->curr_dir_vector = dir_v_save;
  env->eye = eye_save;
  return (coef);
}
