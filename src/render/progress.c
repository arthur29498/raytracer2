/*
** progress.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon Apr 17 14:00:50 2017 Arthur Philippe
** Last update Mon Apr 17 14:59:05 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"

void	display_progress(int *pr, int runing)
{
  if (!runing && *pr)
    acp_print("\r[%s", MSG_RENDER_DONE);
  else if (!runing && *pr == 0)
    acp_print("%s[", MSG_RENDER);
  else if (*pr >= SC_W * SC_H / 10)
    {
      acp_print("%c", LOAD_CHAR);
      *pr = 0;
    }
}

void	progress_to_next_px(int *total_px, sfVector2i *px)
{
  px->y = (px->x < SC_W) ? px->y : px->y + 1;
  px->x = (px->x < SC_W) ? px->x + 1 : 0;
  *total_px += 1;

}
