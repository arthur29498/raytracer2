/*
** object_limit.c for raytracer in /home/arthur/Projects/raytracer2/src/data_gathering/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Apr 27 14:05:42 2017 Arthur Philippe
** Last update Thu Apr 27 14:33:36 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int	add_limit(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'l' && buffer[*idx + 1] == 'A')
    new_object->limit_a = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'l' && buffer[*idx + 1] == 'B')
    new_object->limit_b = my_getnbr(&buffer[*idx + 3]);
  else
    return (0);
  return (1);
}
