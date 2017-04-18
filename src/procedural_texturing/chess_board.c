/*
** chest_board.c for raytracer2 in /home/spiki/delivery/B2/GP/RT2_Github/raytracer_github/src/procedural_texturing/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Tue Apr 11 17:26:49 2017 etienne.filliat
** Last update Tue Apr 18 11:27:32 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

static void		positive_positive(sfVector2i pos, sfColor *color)
{
  if (((pos.x > (TILE_SIZE / 2) && pos.y > (TILE_SIZE / 2))
       || (pos.x <= (TILE_SIZE / 2) && pos.y <= (TILE_SIZE / 2))))
    *color = sfWhite;
  else
    *color = sfBlack;
}

static void		negative_negative(sfVector2i pos, sfColor *color)
{
  if ((pos.x > (TILE_SIZE / 2 * -1) && pos.y > (TILE_SIZE / 2 * -1))
      || (pos.x <= (TILE_SIZE / 2 * -1) && pos.y <= (TILE_SIZE / 2 * -1)))
    *color = sfWhite;
  else
    *color = sfBlack;
}

static void		positive_negative(sfVector2i pos, sfColor *color)
{
  if ((pos.x > (TILE_SIZE / 2) && pos.y > (TILE_SIZE / 2 * -1))
      || (pos.x <= (TILE_SIZE / 2) && pos.y <= (TILE_SIZE / 2 * -1)))
    *color = sfWhite;
  else
    *color = sfBlack;
}

static void		negative_positive(sfVector2i pos, sfColor *color)
{
  if ((pos.x > (TILE_SIZE / 2 * -1) && pos.y > (TILE_SIZE / 2))
      || (pos.x <= (TILE_SIZE / 2 * -1) && pos.y <= (TILE_SIZE / 2)))
    *color = sfWhite;
  else
    *color = sfBlack;
}

void			set_chessboard_color(sfVector3f last_intersect,
					     sfColor *color)
{
  sfVector2i		pos;

  pos.x = (int) last_intersect.x % TILE_SIZE;
  pos.y = (int) last_intersect.y % TILE_SIZE;
  if (pos.x >= 0 && pos.y >= 0)
    positive_positive(pos, color);
  else if (pos.x < 0 && pos.y < 0)
    negative_negative(pos, color);
  else if (pos.x >= 0 && pos.y < 0)
    positive_negative(pos, color);
  else
    negative_positive(pos, color);
}
