/*
** set_color.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed May 24 16:07:04 2017 Arthur Philippe
** Last update Fri May 26 18:03:09 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

sfColor		set_initial_color(t_object *objs, t_render_out *out)
{
  sfColor	outp;

  outp = sfBlack;
  while (objs)
    {
      if (objs->id == out->last_obj)
	{
	  if (objs->col.a)
	    outp = objs->col;
	  else
	    outp = get_def_color_ob(objs);
	  if (objs->chess_board_f)
	    set_chessboard_color(out->hit_pt, &outp);
	  if (objs->chess_board_f)
	    perlin_noised_color(out->hit_pt, &outp);
	  return (outp);
	}
      objs = objs->next;
    }
  return (sfBlue);
}

sfColor	set_color(t_env *env, sfColor *color, t_render_out *out, int iter)
{
  float	coef;

  *color = set_initial_color(env->objects, out);
  coef = std_color_effect(env, out);
  if (out->reflect != 0.00)
    reflect_effect(env, out, color, iter);
  if (out->refract != 0.00)
    refract_effect(env, out, color, iter);
  color->a *= coef;
  apply_colored_light_effect(color, env->objects);
  set_brightness(color, env->objects, out->last_obj, coef);
  return (*color);
}

sfColor		get_color_avg(sfColor color1, sfColor color2, int iter)
{
  sfColor	out;

  if (!iter)
    return (color2);
  out.r = (color1.r + color2.r) / 2;
  out.g = (color1.g + color2.g) / 2;
  out.b = (color1.b + color2.b) / 2;
  out.a = (color1.a + color2.a) / 2;
  return (out);
}
