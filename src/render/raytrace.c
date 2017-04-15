/*
** raytrace.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 15 13:26:22 2017 Arthur Philippe
** Last update Sat Apr 15 14:08:04 2017 Arthur Philippe
*/

static void	send_ray(t_env *env, sfVector2i px)
{
  t_render_in	in;

  in.dir_vector = calc_dir_vector(SC_W, env->screen_size, px);
  in.dir_vector = rotate_xyz(in.dir_vector, env->eye_rt);
}

void		raytrace_full_scene(t_env *env)
{
  int		total_px;
  sfVector2i	px;

  total_px = 0;
  while (px.y < SC_H)
    {
      if (total_px >= SC_W * SC_H / 10)
	{
	  acp_print("%c", LOAD_CHAR);
	  total_px = 0;
	}

      total_px += 1;
    }
}
