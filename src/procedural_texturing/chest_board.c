/*
** chest_board.c for raytracer2 in /home/spiki/delivery/B2/GP/RT2_Github/raytracer_github/src/procedural_texturing/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Tue Apr 11 17:26:49 2017 etienne.filliat
** Last update Tue Apr 11 17:49:21 2017 etienne.filliat
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"
#define D	300

static void		positiv_positiv(sfVector2i pos, sfColor *color)
{
  if (((pos.x > (D / 2) && pos.y > (D / 2))
       || (pos.x <= (D / 2) && pos.y <= (D / 2))))
    *color = sfWhite;
  else
    *color = sfBlack;
}

static void		negativ_negativ(sfVector2i pos, sfColor *color)
{
  if ((pos.x > (D / 2 * -1) && pos.y > (D / 2 * -1))
      || (pos.x <= (D / 2 * -1) && pos.y <= (D / 2 * -1)))
    *color = sfWhite;
  else
    *color = sfBlack;
}

static void		positiv_negativ(sfVector2i pos, sfColor *color)
{
  if ((pos.x > (D / 2) && pos.y > (D / 2 * -1))
      || (pos.x <= (D / 2) && pos.y <= (D / 2 * -1)))
    *color = sfWhite;
  else
    *color = sfBlack;
}

static void		negativ_positiv(sfVector2i pos, sfColor *color)
{
  if ((pos.x > (D / 2 * -1) && pos.y > (D / 2))
      || (pos.x <= (D / 2 * -1) && pos.y <= (D / 2)))
    *color = sfWhite;
  else
    *color = sfBlack;
}

void			get_damier_color(sfVector3f last_intersect,
					 sfColor *color)
{
  sfVector2i		pos;

  pos.x = (int) last_intersect.x % D;
  pos.y = (int) last_intersect.y % D;
  if (pos.x >= 0 && pos.y >= 0)
    positiv_positiv(pos, color);
  else if (pos.x < 0 && pos.y < 0)
    negativ_negativ(pos, color);
  else if (pos.x >= 0 && pos.y < 0)
    positiv_negativ(pos, color);
  else
    negativ_positiv(pos, color);
}
