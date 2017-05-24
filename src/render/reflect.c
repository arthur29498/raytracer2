/*
** merge_reflected_color.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu May  4 11:10:58 2017 Arthur Philippe
** Last update Wed May 10 13:11:17 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

sfColor		reflect_color(const sfColor pt1,
			      const sfColor pt2,
			      const float reflection)
{
  sfColor	out;

  out.r = (pt2.r * reflection) + (pt1.r * (1 - reflection));
  out.g = (pt2.g * reflection) + (pt1.g * (1 - reflection));
  out.b = (pt2.b * reflection) + (pt1.b * (1 - reflection));
  out.a = (pt2.a * reflection) + (pt1.a * (1 - reflection));
  return (out);
}

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
			       sfColor *color,
			       int iter)
{
  t_render_in	in;
  t_render_out	nw_out;
  sfColor	new_color;

  if (iter > MAX_REFLECT || !pr_out->reflect)
    return ;
  my_memset(&in, 0, sizeof(t_render_in));
  prep_ray(&in, pr_out);
  objects_hit_attempt(env, &in, &nw_out);
  if (nw_out.k > 0)
    {
      nw_out.last_dir_v = in.dir_vector;
      set_color(env, &new_color, &nw_out, iter + 1);
      *color = reflect_color(*color, new_color, pr_out->reflect);
    }
}
