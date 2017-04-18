/*
** raytrace.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 15 13:26:22 2017 Arthur Philippe
** Last update Tue Apr 18 14:52:42 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"
#include "launch.h"

float		std_color_effect(t_env *env, t_render_out *pr_out);

static int	hit_single_obj(t_render_in *in,
			       t_render_out *out,
			       t_object *objs)
{
  float		k;

  k = obj_fctn_shunter(objs, in);
  if (k >= 0 && (out->k == -1 || out->k > k))
    {
      out->k = (in->skip && k > 0 && k < 1) ? 1 : k;
      if (in->skip && k > 0 && k < 1)
	return (1);
      out->type = objs->type;
      out->last_obj = objs->id;
    }
  return (0);
}

void		objects_hit_attempt(t_env *env,
				    t_render_in *in,
				    t_render_out *out)
{
  t_object	*objs;

  objs = env->objects;
  if (objs && objs->id == in->skip)
    objs = objs->next;
  my_memset(out, 0, sizeof(t_render_out));
  out->k = -1;
  while (objs)
    {
      if (hit_single_obj(in, out, objs))
	return ;
      objs = objs->next;
      if (objs && objs->id == in->skip)
	objs = objs->next;
    }
  out->k = (out->k >= 0) ? out->k : 0;
  if (out->k >= 0)
    out->hit_pt = get_intersection(in->eye_pt, in->dir_vector, out->k);
}

static void	prep_ray(t_render_in *in,
			 t_env *env,
			 sfVector2i px)
{
  my_memset(in, 0, sizeof(t_render_in));
  in->dir_vector = calc_dir_vector(SC_W, env->screen_size, px);
  in->dir_vector = rotate_xyz(in->dir_vector, env->eye_rt);
  in->eye_pt = env->eye_pt;
}

void		raytrace_full_scene(t_env *env)
{
  t_px		px;
  t_render_in	in;
  t_render_out	out;

  px.total_px = px.pos.x = px.pos.y = 0;
  px.color = sfBlue;
  display_progress(&(px.total_px), 0);
  while (px.pos.y < SC_H)
    {
      prep_ray(&in, env, px.pos);
      objects_hit_attempt(env, &in, &out);
      if (out.k > 0)
	{
	  px.color = get_color_from_objs(env->objects, out.last_obj);
	  if (out.type == ID_PLANE)
	    set_chessboard_color(out.hit_pt, &(px.color));
	  px.color.a *= std_color_effect(env, &out);
	  my_put_pixel(env->w->buffer, px.pos.x - 1, px.pos.y, px.color);
	}
      display_progress(&(px.total_px), 1);
      progress_to_next_px(&(px.total_px), &(px.pos));
    }
  display_progress(&(px.total_px), 0);
}
