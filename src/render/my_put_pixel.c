/*
** my_put_pixel.c for raytracer1 in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb  9 09:00:56 2017 Arthur Philippe
** Last update Sat Mar 18 10:14:00 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x,
		     int y,
		     sfColor color)
{
  if (x < 0 || y < 0)
    return ;
  if (x > (*framebuffer).width || y > (*framebuffer).height)
    return ;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4] = color.r;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 1] = color.g;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 2] = color.b;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 3] = color.a;
}
