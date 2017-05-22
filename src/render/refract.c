/*
** refract.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu May 11 14:01:29 2017 Arthur Philippe
** Last update Mon May 22 12:28:03 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

static sfVector3f	refract_vector(sfVector3f dir_v,
				       sfVector3f normal_v,
				       float n1,
				       float n2)
{
  sfVector3f		out;
  float			n;
  float			dot;

  n = n2 / n1;
  dot = dot_product(dir_v, normal_v);
  out.x = n * dot - sqrtf(1 + (n * n * (dot * dot - 1))) * normal_v.x;
  out.x += n * dir_v.x;
  out.y = n * dot - sqrtf(1 + (n * n * (dot * dot - 1))) * normal_v.y;
  out.y += n * dir_v.y;
  out.z = n * dot - sqrtf(1 + (n * n * (dot * dot - 1))) * normal_v.z;
  out.z += n * dir_v.z;
  return (out);
}

static void	prep_ray(t_render_in *in,
			 t_render_out *pr_out)
{
  sfVector3f	refracted_v;

  refracted_v = refract_vector(pr_out->last_dir_v, pr_out->normal,
			       1, pr_out->refract_idx);
  in->dir_vector = refracted_v;
  in->eye_pt = pr_out->hit_pt;
  in->skip = pr_out->last_obj;
}

void		refract_effect(t_env *env,
			       t_render_out *pr_out,
			       sfColor *color,
			       int iter)
{
  t_render_in	in;
  t_render_out	nw_out;
  sfColor	new_color;

  if (iter > MAX_REFRACT || !pr_out->refract)
    return ;
  my_memset(&in, 0, sizeof(t_render_in));
  prep_ray(&in, pr_out);
  objects_hit_attempt(env, &in, &nw_out);
  new_color = sfBlack;
  if (nw_out.k > 0)
    {
      nw_out.last_dir_v = in.dir_vector;
      set_pixel(env, &new_color, &nw_out, iter + 1);
    }
  *color = reflect_color(*color, new_color, pr_out->refract);
}
