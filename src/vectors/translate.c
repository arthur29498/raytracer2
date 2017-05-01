/*
** translate.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 21:11:07 2017 Arthur Philippe
** Last update Sat Mar 18 09:58:30 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

sfVector3f	translate_inv(sfVector3f to_translate,
			      sfVector3f translations)
{
  to_translate.x -= translations.x;
  to_translate.y -= translations.y;
  to_translate.z -= translations.z;
  return (to_translate);
}

sfVector3f	translate(sfVector3f to_translate,
			  sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
