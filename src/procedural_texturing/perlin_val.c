/*
** perlin.c for raytracer in /home/spiki/delivery/B2/GP/RT2_Github/raytracer_github/src/procedural_texturing/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed May 24 15:11:30 2017 etienne.filliat
** Last update Fri May 26 14:40:07 2017 etienne.filliat
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"
#include "perlin.h"
#include <stdio.h>

static int	noise2(int x, int y)
{
  int		tmp;

  tmp = g_hash[(y + SEED) % 256];
  return (g_hash[(tmp + x) % 256]);
}

static float	lin_inter(float x, float y, float s)
{
  return (x + s * (y-x));
}

static float	smooth_inter(float x, float y, float s)
{
  return (lin_inter(x, y, s * s * (3-2*s)));
}

static float	noise2d(float x, float y)
{
  sfVector2i	int_v;
  sfVector2f	frac;
  t_Vector4i	vec;
  sfVector2f	height;

  int_v.x = x;
  int_v.y = y;
  frac.x = x - int_v.x;
  frac.y = y - int_v.y;
  vec.s = noise2(int_v.x, int_v.y);
  vec.t = noise2(int_v.x + 1, int_v.y);
  vec.u = noise2(int_v.x, int_v.y + 1);
  vec.v = noise2(int_v.x + 1, int_v.y + 1);
  height.x = smooth_inter(vec.s, vec.t, frac.x);
  height.y = smooth_inter(vec.u, vec.v, frac.x);
  return (smooth_inter(height.x, height.y, frac.y));
}

float 		perlin2d(float x, float y, float freq, int depth)
{
  sfVector2f	pos_freq;
  sfVector3f	use;
  int		i;

  use.x = 1.0;
  use.y = use.z = 0.0;
  i = 0;
  pos_freq.x = x*freq;
  pos_freq.y = y*freq;
  while (i < depth)
    {
      use.z += 256 * use.x;
      use.y += noise2d(pos_freq.x, pos_freq.y) * use.x;
      use.x /= 2;
      pos_freq.x *= 2;
      pos_freq.y *= 2;
      i++;
    }
  if (use.y < 0)
    use.y *= -1;
  return (use.y/use.z);
}
