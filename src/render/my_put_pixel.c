/*
** my_put_pixel.c for raytracer1 in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb  9 09:00:56 2017 Arthur Philippe
** Last update Mon May 22 12:55:58 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"
#include "acp.h"

void	my_put_pixel(t_fbuffer *framebuffer,
		     int x,
		     int y,
		     sfColor color)
{
  if (x < 0 || y < 0)
    {
      acp_print("put_pixel: invalid negative position.\n");
      return ;
    }
  if (x > (*framebuffer).width || y > (*framebuffer).height)
    {
      acp_print("put_pixel: above limits\n");
      return ;
    }
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4] = color.r;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 1] = color.g;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 2] = color.b;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 3] = color.a;
}
