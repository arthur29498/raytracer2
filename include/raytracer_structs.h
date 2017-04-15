/*
** raytracer_structs.h for raytracer in /home/arthur/Projects/raytracer2/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 15 12:40:43 2017 Arthur Philippe
** Last update Sat Apr 15 14:22:32 2017 Arthur Philippe
*/

#ifndef RAYTRACER_STRUCTS_H_
# define RAYTRACER_STRUCTS_H_

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_my_window
{
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*tex;
  t_my_framebuffer	*buffer;
}			t_my_window;

typedef struct		s_object
{
  int			id;
  int			type;
  float			size_a;
  float			size_b;
  sfVector3f		pos;
  sfVector3f		rot;
  struct s_object	*next;
}			t_object;

typedef struct		s_render_in
{
  sfVector3f		eye_pt;
  sfVector3f		eye_rt;
  sfVector3f		dir_vector;
}			t_render_in;

typedef struct		s_render_out
{
  sfVector3f		k;
  sfVector3f		hit_pt;
  int			last_obj;
}			t_render_out;

typedef struct		s_env
{
  t_object		*objects;
  t_object		*lights;
  sfVector3f		eye_pt;
  sfVector3f		eye_rt;
  sfVector3f		light;
  sfVector2i		screen_size;
}			t_env;

#endif /* !RAYTRACER_STRUCTS_H_ */
