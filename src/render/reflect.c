/*
** merge_reflected_color.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu May  4 11:10:58 2017 Arthur Philippe
** Last update Thu May  4 11:18:24 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

sfColor		reflect_color(const sfColor pt1,
			      const sfColor pt2,
			      const float reflection)
{
  sfColor	out;

  out.r = (pt2.r * reflection) + (pt1.r * (1 - reflection));
  out.g = (pt2.g * reflection) + (pt1.g * (1 - reflection));
  out.b = (pt2.b * reflection) + (pt1.b * (1 - reflection));
  out.a = 255;
  return (out);
}
