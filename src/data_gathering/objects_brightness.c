/*
** objects_brightness.c for raytracer2 in /home/mael/GitHub/raytracer2/src/data_gathering/
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu>
**
** Started on  Wed May  3 17:41:57 2017 mael drapier
** Last update Thu May  4 12:48:16 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int	add_brightness_reflect(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'm' && buffer[*idx + 1] == 'B')
    new_object->brightness = (float) my_getnbr(&buffer[*idx + 3]) / 1000;
  else if (buffer[*idx] == 'm' && buffer[*idx + 1] == 'R')
    new_object->reflection = (float) my_getnbr(&buffer[*idx + 3]) / 1000;
  else
    return (0);
  return (1);
}