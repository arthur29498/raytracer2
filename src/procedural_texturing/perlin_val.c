/*
** perlin.c for raytracer in /home/spiki/delivery/B2/GP/RT2_Github/raytracer_github/src/procedural_texturing/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed May 24 15:11:30 2017 etienne.filliat
** Last update Fri May 26 14:48:40 2017 etienne.filliat
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"
#include <stdio.h>

static int g_hash[] = {208,
  34,
  231,
  213,
  32,
  248,
  233,
  56,
  161,
  78,
  24,
  140,
  71,
  48,
  140,
  254,
  245,
  255,
  247,
  247,
  40,
  185,
  248,
  251,
  245,
  28,
  124,
  204,
  204,
  76,
  36,
  1,
  107,
  28,
  234,
  163,
  202,
  224,
  245,
  128,
  167,
  204,
  9,
  92,
  217,
  54,
  239,
  174,
  173,
  102,
  193,
  189,
  190,
  121,
  100,
  108,
  167,
  44,
  43,
  77,
  180,
  204,
  8,
  81,
  70,
  223,
  11,
  38,
  24,
  254,
  210,
  210,
  177,
  32,
  81,
  195,
  243,
  125,
  8,
  169,
  112,
  32,
  97,
  53,
  195,
  13,
  203,
  9,
  47,
  104,
  125,
  117,
  114,
  124,
  165,
  203,
  181,
  235,
  193,
  206,
  70,
  180,
  174,
  0,
  167,
  181,
  41,
  164,
  30,
  116,
  127,
  198,
  245,
  146,
  87,
  224,
  149,
  206,
  57,
  4,
  192,
  210,
  65,
  210,
  129,
  240,
  178,
  105,
  228,
  108,
  245,
  148,
  140,
  40,
  35,
  195,
  38,
  58,
  65,
  207,
  215,
  253,
  65,
  85,
  208,
  76,
  62,
  3,
  237,
  55,
  89,
  232,
  50,
  217,
  64,
  244,
  157,
  199,
  121,
  252,
  90,
  17,
  212,
  203,
  149,
  152,
  140,
  187,
  234,
  177,
  73,
  174,
  193,
  100,
  192,
  143,
  97,
  53,
  145,
  135,
  19,
  103,
  13,
  90,
  135,
  151,
  199,
  91,
  239,
  247,
  33,
  39,
  145,
  101,
  120,
  99,
  3,
  186,
  86,
  99,
  41,
  237,
  203,
  111,
  79,
  220,
  135,
  158,
  42,
  30,
  154,
  120,
  67,
  87,
  167,
  135,
  176,
  183,
  191,
  253,
  115,
  184,
  21,
  233,
  58,
  129,
  233,
  142,
  39,
  128,
  211,
  118,
  137,
  139,
  255,
  114,
  20,
  218,
  113,
  154,
  27,
  127,
  246,
  250,
  1,
  8,
  198,
  250,
  209,
  92,
  222,
  173,
  21,
  88,
  102,
219};

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
