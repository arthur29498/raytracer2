/*
** raytracer_structs.h for raytracer in /home/arthur/Projects/raytracer2/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 15 12:40:43 2017 Arthur Philippe
** Last update Fri May 26 12:24:29 2017 etienne.filliat
*/

#ifndef RAYTRACER_STRUCTS_H_
# define RAYTRACER_STRUCTS_H_

typedef struct		t_fbuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_fbuffer;

typedef struct		s_my_window
{
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*tex;
  t_fbuffer		*buffer;
}			t_my_window;

typedef struct		s_object
{
  int			id;
  int			type;
  float			size_a;
  float			size_b;
  float			brightness;
  float			reflection;
  float			refraction;
  float			refract_idx;
  sfColor		col;
  sfVector3f		pos;
  sfVector3f		rot;
  int			limit_a;
  int			limit_b;
  struct s_object	*next;
}			t_object;

typedef struct		s_render_in
{
  sfVector3f		eye_pt;
  sfVector3f		eye_rt;
  sfVector3f		dir_vector;
  int			skip;
}			t_render_in;

typedef struct		s_render_out
{
  float			k;
  sfVector3f		hit_pt;
  sfVector3f		normal;
  sfVector3f		last_dir_v;
  int			last_obj;
  float			reflect;
  float			refract;
  float			refract_idx;
  int			type;
}			t_render_out;

typedef struct		s_env
{
  t_my_window		*w;
  t_object		*objects;
  t_object		*lights;
  sfVector3f		eye_pt;
  sfVector3f		eye_rt;
  sfVector3f		light;
  sfVector2i		screen_size;
  int			thread;
  int			tot_thread;
}			t_env;

typedef struct		s_px
{
  int			total_px;
  sfVector2i		pos;
  sfColor		color;
}			t_px;

typedef struct		s_keywords
{
  int			id_type;
  char			*match_name;
  char			*name;
}			t_keywords;

typedef struct		s_Vector4i
{
  int		s;
  int		t;
  int		u;
  int		v;
}			t_Vector4i;

#endif /* !RAYTRACER_STRUCTS_H_ */
