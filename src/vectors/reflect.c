/*
** reflect.c for raytracer in /home/arthur/Projects/raytracer2/src/vectors/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu May  4 10:33:17 2017 Arthur Philippe
** Last update Mon May  8 21:34:43 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdio.h>
#include "math.h"
#include "raytracer.h"

static sfVector3f	reflect_vector(sfVector3f dir_v,
				       sfVector3f normal_v)
{
  sfVector3f		reflected_v;
  float			dot;

  dot = dot_product(dir_v, normal_v);
  dir_v = normalize_vector(dir_v);
  normal_v = normalize_vector(normal_v);
  reflected_v.x = -2 * dot * normal_v.x + dir_v.x;
  reflected_v.y = -2 * dot * normal_v.y + dir_v.y;
  reflected_v.z = -2 * dot * normal_v.z + dir_v.z;
  return (reflected_v);
}

static void	prep_ray(t_render_in *in,
			 t_render_out *pr_out)
{
  sfVector3f	reflected_v;

  reflected_v = reflect_vector(pr_out->last_dir_v, pr_out->normal);
  in->dir_vector = reflected_v;
  in->eye_pt = pr_out->hit_pt;
  in->skip = pr_out->last_obj;
}

void		reflect_effect(t_env *env,
			       t_render_out *pr_out,
			       sfColor *color)
{
  t_render_in	in;
  t_render_out	nw_out;
  sfColor	new_color;
  float		coef;

  my_memset(&in, 0, sizeof(t_render_in));
  prep_ray(&in, pr_out);
  objects_hit_attempt(env, &in, &nw_out);
  if (nw_out.k > 0)
    {
      new_color = get_color_from_objs(env->objects, nw_out.last_obj);
      if (nw_out.type == ID_PLANE)
	set_chessboard_color(nw_out.hit_pt, &new_color);
      coef = std_color_effect(env, &nw_out);
      new_color.a *= coef;
      *color = reflect_color(*color, new_color, 0.3);
    }
}
