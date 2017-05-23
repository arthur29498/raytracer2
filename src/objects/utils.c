/*
** utils.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Mar  3 13:45:30 2017 Arthur Philippe
** Last update Tue May 23 13:19:24 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>

float		solve_quadric_eq(float discriminant, float a, float b)
{
  float		sol;
  float		tmp;

  if (discriminant == 0)
    {
      sol = -b;
      sol /= 2 * a;
      if (sol > 0)
	return (sol);
    }
  else if (discriminant > 0)
    {
      sol = -b + sqrtf(discriminant);
      sol /= 2 * a;
      tmp = -b - sqrtf(discriminant);
      tmp /= 2 * a;
      if (tmp > 0 && tmp < sol)
	return (tmp);
      if (sol > 0)
	return (sol);
    }
  return (-1);
}
