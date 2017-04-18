/*
** objects_creation.c for raytracer1 in /home/arthur/delivery/raytracer1/src/data_gathering/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Feb 18 11:24:50 2017 Arthur Philippe
** Last update Tue Apr 18 13:52:52 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int	add_size(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'A')
    new_object->size_a = my_getnbr(&buffer[*idx + 2]);
  else if (buffer[*idx] == 'B')
    new_object->size_b = my_getnbr(&buffer[*idx + 2]);
  else
    return (0);
  return (1);
}

int	add_rotation(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'r' && buffer[*idx + 1] == 'X')
    new_object->rot.x = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'r' && buffer[*idx + 1] == 'Y')
    new_object->rot.y = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'r' && buffer[*idx + 1] == 'Z')
    new_object->rot.z = my_getnbr(&buffer[*idx + 3]);
  else
    return (0);
  return (1);
}

t_object	*create_object(char *buffer, int *idx)
{
  t_object	*new_object;

  if (!(new_object = create_list_node()))
    return (NULL);
  new_object->next = NULL;
  while (buffer[*idx])
    {
      add_size(buffer, idx, new_object);
      add_rotation(buffer, idx, new_object);
      if (buffer[*idx] == 'X')
  	new_object->pos.x = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'Y')
	new_object->pos.y = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'Z')
	new_object->pos.z = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'T')
	new_object->type = resolve_object_type(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'E')
	break;
      while (buffer[*idx] && buffer[(*idx)++] != '\n');
    }
  return (new_object);
}
