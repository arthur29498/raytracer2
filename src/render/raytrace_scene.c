/*
** raytrace_scene.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 22 18:45:40 2017 Arthur Philippe
** Last update Sun Mar 19 22:05:28 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

inline static sfColor	get_def_color(t_object *obj)
{
  if (obj->type == 1)
    return (sfRed);
  else if (obj->type == 2)
    return (sfBlue);
  else if (obj->type == 3)
    return (sfGreen);
  else if (obj->type == 4)
    return (sfYellow);
  else
    return (sfBlack);
}

inline static int	raytrace(t_object *list,
				 t_env *env,
				 sfColor *color)
{
  float			last_k;
  float			k;
  float			coef;

  last_k = k = -1;
  *color = DEFAULT_COLOR;
  while (list)
    {
      k = obj_fctn_shunter(list, env);
      if (k >= 0 && (last_k == -1 || last_k > k))
	{
	  *color = get_def_color(list);
	  last_k = k;
          env->last_intersect = get_intersection(env->eye,
						 env->curr_dir_vector,
						 k);
	  coef = color_modifier(env, list, env->last_intersect);
	  coef += (coef < 0.9) ? 0.1 : 1 - coef;
	  color->a *= coef;
	}
      list = list->next;
    }
  k = (k >= 0) ? k : 0;
  return (k);
}

void	set_dir_v(float dist, t_env *env, sfVector2i screen_pos)
{
  env->curr_dir_vector = calc_dir_vector(dist,
					 env->screen_size,
					 screen_pos);
  env->curr_dir_vector = rotate_xyz(env->curr_dir_vector,
				    env->eye_rot);
}

void		raytrace_scene(t_my_framebuffer *buffer,
			       t_object *list,
			       t_env *env)
{
  sfVector2i	sc_pos;
  sfColor	hit_color;
  int		total;

  total = 0;
  sc_pos = (sfVector2i) {0, 0};
  acp_print("%s[", MSG_RENDER);
  while (sc_pos.y < buffer->height)
    {
      if (total >= env->screen_size.x * env->screen_size.y / 10)
	{
	  acp_print("%c", LOAD_CHAR);
	  total = 0;
	}
      set_dir_v(buffer->width, env, sc_pos);
      if (raytrace(list, env, &hit_color) >= 0)
	my_put_pixel(buffer, sc_pos.x, sc_pos.y, hit_color);
      sc_pos.y = (sc_pos.x < buffer->width) ? sc_pos.y : sc_pos.y + 1;
      sc_pos.x = (sc_pos.x < buffer->width) ? sc_pos.x + 1 : 0;
      total += 1;
    }
  acp_print("\r[%s", MSG_RENDER_DONE);
}
