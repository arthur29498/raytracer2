/*
** default_colors.c for raytracer in /home/arthur/Projects/raytracer2/src/render/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon Apr 17 17:46:14 2017 Arthur Philippe
** Last update Mon Apr 17 18:07:49 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

sfColor	get_def_color_ob(t_object *obj)
{
  if (obj->type == 1)
    return (sfRed);
  else if (obj->type == 2)
    return (sfBlue);
  else if (obj->type == 3)
    return (sfGreen);
  else if (obj->type == 4)
    return (sfYellow);
  else
    return (sfBlack);
}

sfColor	get_def_color_ty(int type)
{
  if (type == 1)
    return (sfRed);
  else if (type == 2)
    return (sfBlue);
  else if (type == 3)
    return (sfGreen);
  else if (type == 4)
    return (sfYellow);
  else
    return (sfBlack);
}
