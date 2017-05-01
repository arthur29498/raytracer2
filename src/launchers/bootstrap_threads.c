/*
** launch_threads.c for raytracer in /home/arthur/Projects/raytracer2/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Apr 28 13:25:00 2017 Arthur Philippe
** Last update Mon May  1 11:44:52 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <pthread.h>
#include "acp.h"
#include "raytracer.h"

int		raytracer_thread_launch(t_env *env)
{
  int		thread_id;
  pthread_t	thrds[5];

  thread_id = 0;
  display_progress(&thread_id, 0);
  while (thread_id < 4)
    {
      if (pthread_create(&thrds[thread_id], NULL,
			 raytrace_bridge, (void *) env))
	return (-1);
      thread_id += 1;
    }
  while (--thread_id >= 0)
    pthread_join(thrds[thread_id], NULL);
  thread_id = 1;
  display_progress(&thread_id, 0);
  return (0);
}

int		get_id_thread(void)
{
  static int	id_thread = 0;

  if (id_thread == 4)
    id_thread = 0;
  return (id_thread++);
}

void	*raytrace_bridge(void *env)
{
  raytrace_full_scene((t_env *) env, get_id_thread());
  return (NULL);
}
