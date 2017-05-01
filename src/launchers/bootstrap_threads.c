/*
** launch_threads.c for raytracer in /home/arthur/Projects/raytracer2/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Apr 28 13:25:00 2017 Arthur Philippe
** Last update Mon May  1 11:34:05 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"

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
